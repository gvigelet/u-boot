/*
 * (C) Copyright 2014
 * Texas Instruments Incorporated.
 * Felipe Balbi <balbi@ti.com>
 *
 * Configuration settings for the TI Beagle x15 board.
 * See ti_omap5_common.h for omap5 common settings.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_D3_TDA2ECO_H
#define __CONFIG_D3_TDA2ECO_H

#define CONFIG_DRA7XX
#define CONFIG_TDA2ECO_BOARD
#define CONFIG_BOARD_EARLY_INIT_F

#ifdef CONFIG_SPL_BUILD
#define CONFIG_IODELAY_RECALIBRATION
#endif

#define CONFIG_NR_DRAM_BANKS		1

#define CONFIG_ENV_SIZE			(64 << 10)
#define CONFIG_ENV_IS_IN_FAT
#define FAT_ENV_INTERFACE		"mmc"
#define FAT_ENV_DEVICE_AND_PART		"0:1"
#define FAT_ENV_FILE			"uboot.env"

#define CONSOLEDEV			"ttyS2"
#define CONFIG_SYS_NS16550_COM1		UART1_BASE	/* Base EVM has UART0 */
#define CONFIG_SYS_NS16550_COM2		UART2_BASE	/* UART2 */
#define CONFIG_SYS_NS16550_COM3		UART3_BASE	/* UART3 */
#define CONFIG_BAUDRATE			115200

#define CONFIG_SYS_OMAP_ABE_SYSCK

/* Define the default GPT table for eMMC */
#define PARTS_DEFAULT \
	"uuid_disk=${uuid_gpt_disk};" \
	"name=rootfs,start=2MiB,size=-,uuid=${uuid_gpt_rootfs}"

#define CONFIG_EXTRA_BOARD_ENV_SETTINGS \
	"board_findfdt=" \
		"if test $board_name = tda2eco_tda2x; then " \
			"setenv fdtfile d3_tda2x_fpd4ch.dtb; fi;" \
		"if test $fdtfile = undefined; then " \
			"setenv fdtfile d3_tda2eco_som.dtb; fi;\0"

#include <configs/ti_omap5_common.h>

/* Enhance our eMMC support / experience. */
#define CONFIG_CMD_GPT
#define CONFIG_EFI_PARTITION


/* This must be defined to enable GMAC PLL configuration in clock.c (Linux is not able to do this for itself) */
#define CONFIG_DRIVER_TI_CPSW		/* Driver for IP block */

#ifndef CONFIG_SPL_BUILD
/* CPSW Ethernet */

#define CONFIG_CMD_DHCP
#define CONFIG_BOOTP_DNS		/* Configurable parts of CMD_DHCP */
#define CONFIG_BOOTP_DNS2
#define CONFIG_BOOTP_SEND_HOSTNAME
#define CONFIG_BOOTP_GATEWAY
#define CONFIG_BOOTP_SUBNETMASK
#define CONFIG_NET_RETRY_COUNT		10
#define CONFIG_CMD_PING
#define CONFIG_CMD_MII
#define CONFIG_DRIVER_TI_CPSW		/* Driver for IP block */
#define CONFIG_MII			/* Required in net/eth.c */
#define CONFIG_PHY_GIGE			/* per-board part of CPSW */
#define CONFIG_PHYLIB
#define PHY_ANEG_TIMEOUT	8000	/* PHY needs longer aneg time at 1G */


#endif /* !CONFIG_SPL_BUILD */

#define CONFIG_SUPPORT_EMMC_BOOT

/* USB xHCI HOST  (not included in SPL due to size limit) */
#undef CONFIG_CMD_USB
#undef CONFIG_USB_HOST
#undef CONFIG_USB_XHCI
#undef CONFIG_USB_STORAGE

#define CONFIG_BOARD_LATE_INIT

/* MEMTEST Support */
#define CONFIG_CMD_MEMTEST
/* 32MiB carve-out at beginning of memory for u-boot  */
#define CONFIG_SYS_MEMTEST_START (0x82000000)
/* Leave 32MiB carve-out at end of memory for u-boot  */
#define CONFIG_SYS_MEMTEST_END   (0x9e000000)
#define CONFIG_SYS_MEMTEST_SCRATCH (CONFIG_SYS_MEMTEST_START - 4)

#endif /* __CONFIG_D3_TDA2ECO_H */