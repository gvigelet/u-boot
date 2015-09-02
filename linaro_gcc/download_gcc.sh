#!/bin/bash
#
# Copyright (C) 2015 Peloton Technology, Inc. - All Rights Reserved
# Author: Philipp Schrader (philipp@peloton-tech.com)
#
# The purpose of this file is to download the Linaro GCC toolchain so
# that it can be used to compile the kernel for ARM.

# Generate errors when using undefined variables.
set -u

set -o pipefail

# Get the current folder.
readonly CURRENT_DIR="${BASH_SOURCE[0]%/*}"

# Which tarball we're interested in.
readonly GCC_TARBALL=gcc-linaro-4.9-2015.05-x86_64_arm-linux-gnueabihf.tar.gz

# Checksum to use for verifying that the tarball was downloaded correctly.
readonly GCC_SHA256_SUM=60f06237c3358aa9658e0f57064e74c69e9890748feb19235036b740c7612871

# Where we are getting the tarball from.
readonly GCC_URL=http://gerrit.peloton-tech.net/Build-Dependency-Files/"${GCC_TARBALL}"

err() {
  echo "++ ERROR:" "$@" >&2
}

info() {
  echo "-- INFO:" "$@"
}

check_return_code() {
  local label="$1"
  local return_code="$2"

  if ((return_code != 0)); then
    err "$label exited with error code $return_code"
    exit $return_code
  fi
}

download_tarball_if_necessary() {
  local destination="$1"
  local desired_checksum="$2"
  local url="$3"

  local existing_checksum=''
  local download_necessary=false

  if [[ -r "$destination" ]]; then
    # Compute the checksum of the tarball that's already there.
    info "Computing checksum of existing $destination"
    existing_checksum="$(sha256sum "$destination" | cut -d' ' -f1)"
    check_return_code "sha256sum $destination" "$?"

    # If the checksum doesn't match we should download the tarball again.
    if [[ "$existing_checksum" != "$desired_checksum" ]]; then
      info "Checksum is incorrect. Forcing download."
      download_necessary=true
    else
      info "Checksum validated correctly. Skipping download."
    fi
  else
    info "Tarball not found. Forcing download."
    download_necessary=true
  fi

  if [[ "$download_necessary" == true ]]; then
    info "Downloading from $url"
    curl -L -o "$destination" "$url"
    check_return_code "curl $url" "$?"
  fi
}

unpack_tarball() {
  local tarball="$1"
  local target_dir="$2"

  info "Creating $target_dir directory"
  mkdir -p "$target_dir"
  check_return_code "mkdir $target_dir" "$?"

  info "Unpacking $tarball"
  tar -C "$target_dir" -xaf "$tarball"
  check_return_code "tar xaf $tarball" "$?"
}

main() {
  # Make sure we've got the GCC tarball downloaded.
  download_tarball_if_necessary \
      "$CURRENT_DIR/$GCC_TARBALL" \
      "$GCC_SHA256_SUM" \
      "$GCC_URL"

  # Unpack the tarball in the directory where this script is located.
  unpack_tarball "$CURRENT_DIR/$GCC_TARBALL" "$CURRENT_DIR"
}

main "$@"
