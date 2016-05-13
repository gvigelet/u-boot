/*
 * Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com
 * Copyright (C) 2015 D3 Engineering
 *
 * Based on board/ti/beagle_x15/board.c
 * Author: Felipe Balbi <balbi@ti.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <palmas.h>
#include <usb.h>
#include <asm/omap_common.h>
#include <asm/emif.h>
#include <asm/gpio.h>
#include <asm/arch/gpio.h>
#include <asm/arch/clock.h>
#include <asm/arch/dra7xx_iodelay.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/mmc_host_def.h>
#include <asm/arch/gpio.h>
#include <asm/arch/omap.h>
#include <environment.h>
#include <usb.h>
#include <linux/usb/gadget.h>
#include <dwc3-uboot.h>
#include <dwc3-omap-uboot.h>
#include <ti-usb-phy-uboot.h>

#include "mux_data.h"

#ifdef CONFIG_DRIVER_TI_CPSW
#include <cpsw.h>
#endif

#define BOARD_ID_ADDR	0x74
#define BOARD_ID_REG_P0	0x00
#define BOARD_ID_MASK	0x07

enum board_id {
	BOARD_TDA2ECO_TDA2 = 0x00,
};

DECLARE_GLOBAL_DATA_PTR;

static const struct dmm_lisa_map_regs DDR3L_532MHz_D3_TDA2ECO_rev1_0_dmm_regs = {
    .dmm_lisa_map_0 = 0x80700100,
    .dmm_lisa_map_1 = 0x00000000,
    .dmm_lisa_map_2 = 0x00000000,
    .dmm_lisa_map_3 = 0x00000000,
    .is_ma_present = 0x1
};

static const struct emif_regs DDR3L_532MHz_D3_TDA2ECO_rev1_0_emif_regs = {
    .sdram_config_init = 0x61851BB2,
    .sdram_config = 0x61851BB2,
    .sdram_config2 = 0x00000000,
    .ref_ctrl = 0x000040F1,
    .ref_ctrl_final = 0x00001035,
    .sdram_tim1 = 0xCEEF265B,
    .sdram_tim2 = 0x30BF7FDA,
    .sdram_tim3 = 0x409F8BA8,
    .read_idle_ctrl = 0x00050000,
    .zq_config = 0x5007190B,
    .temp_alert_config = 0x00000000,
    .emif_rd_wr_lvl_rmp_ctl = 0x80000000,
    .emif_rd_wr_lvl_ctl = 0x00000000,
    .emif_ddr_phy_ctlr_1_init = 0x0024400B,
    .emif_ddr_phy_ctlr_1 = 0x0E24400B,
    .emif_rd_wr_exec_thresh = 0x00000305
};

static const unsigned int DDR3L_532MHz_D3_TDA2ECO_rev1_0_emif1_ext_phy_regs [] = {
    0x10040100, // EMIF1_EXT_PHY_CTRL_1
    0x007e007e, // EMIF1_EXT_PHY_CTRL_2
    0x007e007e, // EMIF1_EXT_PHY_CTRL_3
    0x008a008a, // EMIF1_EXT_PHY_CTRL_4
    0x00850085, // EMIF1_EXT_PHY_CTRL_5
    0x07000085, // EMIF1_EXT_PHY_CTRL_6
    0x00330033, // EMIF1_EXT_PHY_CTRL_7
    0x00320032, // EMIF1_EXT_PHY_CTRL_8
    0x00340034, // EMIF1_EXT_PHY_CTRL_9
    0x00320032, // EMIF1_EXT_PHY_CTRL_10
    0x00000038, // EMIF1_EXT_PHY_CTRL_11
    0x006c006c, // EMIF1_EXT_PHY_CTRL_12
    0x006a006a, // EMIF1_EXT_PHY_CTRL_13
    0x00720072, // EMIF1_EXT_PHY_CTRL_14
    0x00760076, // EMIF1_EXT_PHY_CTRL_15
    0x02f20076, // EMIF1_EXT_PHY_CTRL_16
    0x00470047, // EMIF1_EXT_PHY_CTRL_17
    0x00450045, // EMIF1_EXT_PHY_CTRL_18
    0x004d004d, // EMIF1_EXT_PHY_CTRL_19
    0x00510051, // EMIF1_EXT_PHY_CTRL_20
    0x02d20056, // EMIF1_EXT_PHY_CTRL_21
    0x00800080, // EMIF1_EXT_PHY_CTRL_22
    0x00800080, // EMIF1_EXT_PHY_CTRL_23
    0x40010080, // EMIF1_EXT_PHY_CTRL_24
    0x08102040, // EMIF1_EXT_PHY_CTRL_25
    0x005b0075, // EMIF1_EXT_PHY_CTRL_26
    0x005b0076, // EMIF1_EXT_PHY_CTRL_27
    0x005b007b, // EMIF1_EXT_PHY_CTRL_28
    0x005b0077, // EMIF1_EXT_PHY_CTRL_29
    0x005b0081, // EMIF1_EXT_PHY_CTRL_30
    0x00300038, // EMIF1_EXT_PHY_CTRL_31
    0x00300038, // EMIF1_EXT_PHY_CTRL_32
    0x0030003b, // EMIF1_EXT_PHY_CTRL_33
    0x0030003f, // EMIF1_EXT_PHY_CTRL_34
    0x0030003e, // EMIF1_EXT_PHY_CTRL_35
    0x00000177, // EMIF1_EXT_PHY_CTRL_36
};

const struct omap_sysinfo sysinfo = {
	"Board: D3 TDA2Eco\n"
};

static int read_board_id(void)
{
	unsigned char val;
	int board_id = -1;

	if (!i2c_read(BOARD_ID_ADDR, BOARD_ID_REG_P0, 1, &val, sizeof(val))) {
		switch (val & BOARD_ID_MASK) {
		case BOARD_TDA2ECO_TDA2:
			board_id = val;
			break;
		default:
			break;
		}
	}

	return board_id;
}

static const struct dmm_lisa_map_regs tda2eco_lisa_regs = {
	.dmm_lisa_map_3 = 0x80600100,
	.is_ma_present  = 0x1
};

void emif_get_dmm_regs(const struct dmm_lisa_map_regs **dmm_lisa_regs)
{
	*dmm_lisa_regs = &DDR3L_532MHz_D3_TDA2ECO_rev1_0_dmm_regs;
}

void emif_get_reg_dump(u32 emif_nr, const struct emif_regs **regs)
{
	*regs = &DDR3L_532MHz_D3_TDA2ECO_rev1_0_emif_regs;
}

void emif_get_ext_phy_ctrl_const_regs(u32 emif_nr, const u32 **regs, u32 *size)
{
	*regs = DDR3L_532MHz_D3_TDA2ECO_rev1_0_emif1_ext_phy_regs;
	*size = ARRAY_SIZE(DDR3L_532MHz_D3_TDA2ECO_rev1_0_emif1_ext_phy_regs);
}

struct vcores_data tda2eco_volts = {
	.mpu.value		= VDD_MPU_DRA752,
	.mpu.efuse.reg		= STD_FUSE_OPP_VMIN_MPU_NOM,
	.mpu.efuse.reg_bits     = DRA752_EFUSE_REGBITS,
	.mpu.addr		= TPS659038_REG_ADDR_SMPS12,
	.mpu.pmic		= &tps659038,

	.eve.value		= VDD_EVE_DRA752,
	.eve.efuse.reg		= STD_FUSE_OPP_VMIN_DSPEVE_NOM,
	.eve.efuse.reg_bits	= DRA752_EFUSE_REGBITS,
	.eve.addr		= TPS659038_REG_ADDR_SMPS45,
	.eve.pmic		= &tps659038,

	.gpu.value		= VDD_GPU_DRA752,
	.gpu.efuse.reg		= STD_FUSE_OPP_VMIN_GPU_NOM,
	.gpu.efuse.reg_bits	= DRA752_EFUSE_REGBITS,
	.gpu.addr		= TPS659038_REG_ADDR_SMPS45,
	.gpu.pmic		= &tps659038,

	.core.value		= VDD_CORE_DRA752,
	.core.efuse.reg		= STD_FUSE_OPP_VMIN_CORE_NOM,
	.core.efuse.reg_bits	= DRA752_EFUSE_REGBITS,
	.core.addr		= TPS659038_REG_ADDR_SMPS6,
	.core.pmic		= &tps659038,

	.iva.value		= VDD_IVA_DRA752,
	.iva.efuse.reg		= STD_FUSE_OPP_VMIN_IVA_NOM,
	.iva.efuse.reg_bits	= DRA752_EFUSE_REGBITS,
	.iva.addr		= TPS659038_REG_ADDR_SMPS45,
	.iva.pmic		= &tps659038,
};

void hw_data_init(void)
{
	*prcm = &dra7xx_prcm;
	*dplls_data = &dra7xx_dplls;
	*omap_vcores = &tda2eco_volts;
	*ctrl = &dra7xx_ctrl;
}

int board_init(void)
{
	gpmc_init();
	gd->bd->bi_boot_params = (CONFIG_SYS_SDRAM_BASE + 0x100);

	return 0;
}

int board_late_init(void)
{
	int board_id;
	u8 c32k = 0;
	int err;

	c32k = RSC_MODE_SLEEP | RSC_MODE_ACTIVE;
	/*
	 * DEV_CTRL.DEV_ON = 1 please - else palmas switches off in 8 seconds
	 * This is the POWERHOLD-in-Low behavior.
	 */
	palmas_i2c_write_u8(TPS65903X_CHIP_P1, 0xA0, 0x1);

	/* Output 32 kHz clock on or off */
	err = palmas_i2c_write_u8(TPS65903X_CHIP_P1, CLK32KGAUDIO_CTRL, c32k);
	if (err) {
		printf("tps65903x: could not turn CLK32KGAUDIO %s: err = %d\n",
		       c32k ? "on" : "off", err);
	}

	board_id = read_board_id();
	switch(board_id) {
	case BOARD_TDA2ECO_TDA2:
		setenv("board_name", "tda2eco_tda2x");
		break;
	case -1:
		printf("Unabled to read Board-ID\n");
		setenv("board_name", "unknown_board");
		break;
	default:
		printf("Invalid Board-ID detected\n");
		setenv("board_name", "invalid_board");
		break;
	}

	return 0;
}

#ifdef CONFIG_IODELAY_RECALIBRATION
void recalibrate_iodelay(void)
{
	const struct pad_conf_entry *pconf;
	const struct iodelay_cfg_entry *iod;
	int pconf_sz, iod_sz;
	int ret;
		
	/* D3 TDA2Eco */

	pconf = core_padconf_array_essential_d3_tda2eco;
	pconf_sz = ARRAY_SIZE(core_padconf_array_essential_d3_tda2eco);
		
	iod = iodelay_cfg_array_d3_tda2eco;
	iod_sz = ARRAY_SIZE(iodelay_cfg_array_d3_tda2eco);
		
	/* Setup I/O isolation */
	ret = __recalibrate_iodelay_start();
	if (ret)
		goto err;

	/* Do the muxing here */
	do_set_mux32((*ctrl)->control_padconf_core_base, pconf, pconf_sz); 

	/* Setup IOdelay configuration */
	ret = do_set_iodelay((*ctrl)->iodelay_config_base, iod, iod_sz);
err:
	/* Closeup.. remove isolation */
	__recalibrate_iodelay_end(ret);
}
#endif

void set_muxconf_regs_essential(void)
{
	do_set_mux32((*ctrl)->control_padconf_core_base,
		     early_padconf, ARRAY_SIZE(early_padconf));
}

#if !defined(CONFIG_SPL_BUILD) && defined(CONFIG_GENERIC_MMC)
int board_mmc_init(bd_t *bis)
{
	omap_mmc_init(0, 0, 0, -1, -1);
	omap_mmc_init(1, 0, 0, -1, -1);
	return 0;
}
#endif

#if defined(CONFIG_SPL_BUILD) && defined(CONFIG_SPL_OS_BOOT)
int spl_start_uboot(void)
{
	/* break into full u-boot on 'c' */
	if (serial_tstc() && serial_getc() == 'c')
		return 1;

#ifdef CONFIG_SPL_ENV_SUPPORT
	env_init();
	env_relocate_spec();
	if (getenv_yesno("boot_os") != 1)
		return 1;
#endif

	return 0;
}
#endif

#ifdef CONFIG_USB_DWC3
static struct dwc3_device usb_otg_ss1 = {
	.maximum_speed = USB_SPEED_SUPER,
	.base = DRA7_USB_OTG_SS1_BASE,
	.tx_fifo_resize = false,
	.index = 0,
};

static struct dwc3_omap_device usb_otg_ss1_glue = {
	.base = (void *)DRA7_USB_OTG_SS1_GLUE_BASE,
	.utmi_mode = DWC3_OMAP_UTMI_MODE_SW,
	.index = 0,
};

static struct ti_usb_phy_device usb_phy1_device = {
	.pll_ctrl_base = (void *)DRA7_USB3_PHY1_PLL_CTRL,
	.usb2_phy_power = (void *)DRA7_USB2_PHY1_POWER,
	.usb3_phy_power = (void *)DRA7_USB3_PHY1_POWER,
	.index = 0,
};

static struct dwc3_device usb_otg_ss2 = {
	.maximum_speed = USB_SPEED_HIGH,
	.base = DRA7_USB_OTG_SS2_BASE,
	.tx_fifo_resize = false,
	.index = 1,
};

static struct dwc3_omap_device usb_otg_ss2_glue = {
	.base = (void *)DRA7_USB_OTG_SS2_GLUE_BASE,
	.utmi_mode = DWC3_OMAP_UTMI_MODE_SW,
	.index = 1,
};

static struct ti_usb_phy_device usb_phy2_device = {
	.usb2_phy_power = (void *)DRA7_USB2_PHY2_POWER,
	.index = 1,
};

int board_usb_init(int index, enum usb_init_type init)
{
	enable_usb_clocks(index);
	switch (index) {
	case 0:
		if (init == USB_INIT_DEVICE) {
			printf("port %d can't be used as device\n", index);
			return -EINVAL;
		} else {
			usb_otg_ss1.dr_mode = USB_DR_MODE_HOST;
			usb_otg_ss1_glue.vbus_id_status = OMAP_DWC3_ID_GROUND;
			setbits_le32((*prcm)->cm_l3init_usb_otg_ss1_clkctrl,
				     OTG_SS_CLKCTRL_MODULEMODE_HW |
				     OPTFCLKEN_REFCLK960M);
		}

		ti_usb_phy_uboot_init(&usb_phy1_device);
		dwc3_omap_uboot_init(&usb_otg_ss1_glue);
		dwc3_uboot_init(&usb_otg_ss1);
		break;
	case 1:
		if (init == USB_INIT_DEVICE) {
			usb_otg_ss2.dr_mode = USB_DR_MODE_PERIPHERAL;
			usb_otg_ss2_glue.vbus_id_status = OMAP_DWC3_VBUS_VALID;
		} else {
			printf("port %d can't be used as host\n", index);
			return -EINVAL;
		}

		ti_usb_phy_uboot_init(&usb_phy2_device);
		dwc3_omap_uboot_init(&usb_otg_ss2_glue);
		dwc3_uboot_init(&usb_otg_ss2);
		break;
	default:
		printf("Invalid Controller Index\n");
	}

	return 0;
}

int board_usb_cleanup(int index, enum usb_init_type init)
{
	switch (index) {
	case 0:
	case 1:
		ti_usb_phy_uboot_exit(index);
		dwc3_uboot_exit(index);
		dwc3_omap_uboot_exit(index);
		break;
	default:
		printf("Invalid Controller Index\n");
	}
	disable_usb_clocks(index);
	return 0;
}

int usb_gadget_handle_interrupts(int index)
{
	u32 status;

	status = dwc3_omap_uboot_interrupt_status(index);
	if (status)
		dwc3_uboot_handle_interrupt(index);

	return 0;
}
#endif

#ifdef CONFIG_MII

/* Delay value to add to calibrated value */
#define RGMII0_TXCTL_DLY_VAL		((0x3 << 5) + 0x8)
#define RGMII0_TXD0_DLY_VAL		((0x3 << 5) + 0x8)
#define RGMII0_TXD1_DLY_VAL		((0x3 << 5) + 0x2)
#define RGMII0_TXD2_DLY_VAL		((0x4 << 5) + 0x0)
#define RGMII0_TXD3_DLY_VAL		((0x4 << 5) + 0x0)
#define VIN2A_D13_DLY_VAL		((0x3 << 5) + 0x8)
#define VIN2A_D17_DLY_VAL		((0x3 << 5) + 0x8)
#define VIN2A_D16_DLY_VAL		((0x3 << 5) + 0x2)
#define VIN2A_D15_DLY_VAL		((0x4 << 5) + 0x0)
#define VIN2A_D14_DLY_VAL		((0x4 << 5) + 0x0)

static void cpsw_control(int enabled)
{
	/* VTP can be added here */
}

static struct cpsw_slave_data cpsw_slaves[] = {
	{
		.slave_reg_ofs	= 0x208,
		.sliver_reg_ofs	= 0xd80,
		.phy_addr	= 0,				// originally set to 0
	},{
		.slave_reg_ofs	= 0x308,
		.sliver_reg_ofs	= 0xdc0,
		.phy_addr	= 1,
	},
};

static struct cpsw_platform_data cpsw_data = {
	.mdio_base		= CPSW_MDIO_BASE,
	.cpsw_base		= CPSW_BASE,
	.mdio_div		= 0xff,
	.channels		= 8,
	.cpdma_reg_ofs		= 0x800,
	.slaves			= 1,
	.slave_data		= cpsw_slaves,
	.ale_reg_ofs		= 0xd00,
	.ale_entries		= 1024,
	.host_port_reg_ofs	= 0x108,
	.hw_stats_reg_ofs	= 0x900,
	.bd_ram_ofs		= 0x2000,
	.mac_control		= (1 << 5),
	.control		= cpsw_control,
	.host_port_num		= 0,
	.version		= CPSW_CTRL_VERSION_2,
};

static u64 mac_to_u64(u8 mac[6])
{
	int i;
	u64 addr = 0;

	for (i = 0; i < 6; i++) {
		addr <<= 8;
		addr |= mac[i];
	}

	return addr;
}

static void u64_to_mac(u64 addr, u8 mac[6])
{
	mac[5] = addr;
	mac[4] = addr >> 8;
	mac[3] = addr >> 16;
	mac[2] = addr >> 24;
	mac[1] = addr >> 32;
	mac[0] = addr >> 40;
}

static void __maybe_unused board_ti_get_eth_mac_addr(int index,
					      u8 mac_addr[TI_EEPROM_HDR_ETH_ALEN])
{
	struct ti_common_eeprom *ep = TI_EEPROM_DATA;

	if (ep->header == TI_DEAD_EEPROM_MAGIC)
		goto fail;

	if (index < 0 || index >= TI_EEPROM_HDR_NO_OF_MAC_ADDR)
		goto fail;

	memcpy(mac_addr, ep->mac_addr[index], TI_EEPROM_HDR_ETH_ALEN);
	return;

fail:
	memset(mac_addr, 0, TI_EEPROM_HDR_ETH_ALEN);
}


int board_eth_init(bd_t *bis)
{
	int ret;
	uint8_t mac_addr[6];
	uint32_t mac_hi, mac_lo;
	uint32_t ctrl_val;

	/* try reading mac address from efuse */
	mac_lo = readl((*ctrl)->control_core_mac_id_0_lo);
	mac_hi = readl((*ctrl)->control_core_mac_id_0_hi);
	mac_addr[0] = (mac_hi & 0xFF0000) >> 16;
	mac_addr[1] = (mac_hi & 0xFF00) >> 8;
	mac_addr[2] = mac_hi & 0xFF;
	mac_addr[3] = (mac_lo & 0xFF0000) >> 16;
	mac_addr[4] = (mac_lo & 0xFF00) >> 8;
	mac_addr[5] = mac_lo & 0xFF;

	if (!getenv("ethaddr")) {
		printf("<ethaddr> not set. Validating first E-fuse MAC\n");

		if (is_valid_ethaddr(mac_addr))
			eth_setenv_enetaddr("ethaddr", mac_addr);
	}

	mac_lo = readl((*ctrl)->control_core_mac_id_1_lo);
	mac_hi = readl((*ctrl)->control_core_mac_id_1_hi);
	mac_addr[0] = (mac_hi & 0xFF0000) >> 16;
	mac_addr[1] = (mac_hi & 0xFF00) >> 8;
	mac_addr[2] = mac_hi & 0xFF;
	mac_addr[3] = (mac_lo & 0xFF0000) >> 16;
	mac_addr[4] = (mac_lo & 0xFF00) >> 8;
	mac_addr[5] = mac_lo & 0xFF;

	if (!getenv("eth1addr")) {
		if (is_valid_ethaddr(mac_addr))
			eth_setenv_enetaddr("eth1addr", mac_addr);
	}

	ctrl_val = readl((*ctrl)->control_core_control_io1) & (~0x33);
	ctrl_val |= 0x22;
	writel(ctrl_val, (*ctrl)->control_core_control_io1);

	ret = cpsw_register(&cpsw_data);
	if (ret < 0)
		printf("Error %d registering CPSW switch\n", ret);


	board_ti_get_eth_mac_addr(0, mac_addr1);
	board_ti_get_eth_mac_addr(1, mac_addr2);
	
	if (is_valid_ethaddr(mac_addr1) && is_valid_ethaddr(mac_addr2)) {
		mac1 = mac_to_u64(mac_addr1);
		mac2 = mac_to_u64(mac_addr2);

		/* must contain an address range */
		num_macs = mac2 - mac1 + 1;
		/* <= 50 to protect against user programming error */
		if (num_macs > 0 && num_macs <= 50) {
			for (i = 0; i < num_macs; i++) {
				u64_to_mac(mac1 + i, mac_addr);
				if (is_valid_ethaddr(mac_addr)) {
					eth_setenv_enetaddr_by_index("eth",
								     i + 2,
								     mac_addr);
				}
			}
		}
	}
	
	return ret;
}
#endif

#ifdef CONFIG_TPM
static inline void tpm_io_init(void)
{
	if (gpio_request(CONFIG_TPM_ATMEL_RST_GPIO, "tpm_rst")) {
		printf("%s: unable to request GPIO %d for TPM reset\n",
			__func__, CONFIG_TPM_ATMEL_RST_GPIO);
		return;
	}
	if (gpio_direction_output(CONFIG_TPM_ATMEL_RST_GPIO, 0)) {
		printf("%s: unable to set GPIO %d for TPM reset to 0\n",
			__func__, CONFIG_TPM_ATMEL_RST_GPIO);
		return;
	}
	mdelay(100);
	if (gpio_direction_output(CONFIG_TPM_ATMEL_RST_GPIO, 1)) {
		printf("%s: unable to set GPIO %d for TPM reset to 1\n",
			__func__, CONFIG_TPM_ATMEL_RST_GPIO);
		return;
	}
}
#endif

#ifdef CONFIG_BOARD_EARLY_INIT_F
int board_early_init_f(void)
{
#ifdef CONFIG_TPM
	tpm_io_init();
#endif
	return 0;
}
#endif