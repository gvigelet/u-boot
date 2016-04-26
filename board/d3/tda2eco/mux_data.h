/*
 * Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com
 * Copyright (C) 2015 D3 Engineering
 *
 * Based on board/ti/beagle_x15/mux_data.c
 * Author: Felipe Balbi <balbi@ti.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */
#ifndef _MUX_DATA_D3_TDA2ECO_H_
#define _MUX_DATA_D3_TDA2ECO_H_

#include <asm/arch/mux_dra7xx.h>

const struct pad_conf_entry core_padconf_array_essential_d3_tda2eco[] = {
	{GPMC_AD0, (M0 | PIN_INPUT)},		/* gpmc_ad0.gpmc_ad0 */
	{GPMC_AD1, (M0 | PIN_INPUT)},		/* gpmc_ad1.gpmc_ad1 */
	{GPMC_AD2, (M0 | PIN_INPUT)},		/* gpmc_ad2.gpmc_ad2 */
	{GPMC_AD3, (M0 | PIN_INPUT)},		/* gpmc_ad3.gpmc_ad3 */
	{GPMC_AD4, (M0 | PIN_INPUT)},		/* gpmc_ad4.gpmc_ad4 */
	{GPMC_AD5, (M0 | PIN_INPUT)},		/* gpmc_ad5.gpmc_ad5 */
	{GPMC_AD6, (M0 | PIN_INPUT)},		/* gpmc_ad6.gpmc_ad6 */
	{GPMC_AD7, (M0 | PIN_INPUT)},		/* gpmc_ad7.gpmc_ad7 */
	{GPMC_AD8, (M0 | PIN_INPUT)},		/* gpmc_ad8.gpmc_ad8 */
	{GPMC_AD9, (M0 | PIN_INPUT)},		/* gpmc_ad9.gpmc_ad9 */
	{GPMC_AD10, (M0 | PIN_INPUT)},		/* gpmc_ad10.gpmc_ad10 */
	{GPMC_AD11, (M0 | PIN_INPUT)},		/* gpmc_ad11.gpmc_ad11 */
	{GPMC_AD12, (M0 | PIN_INPUT)},		/* gpmc_ad12.gpmc_ad12 */
	{GPMC_AD13, (M0 | PIN_INPUT)},		/* gpmc_ad13.gpmc_ad13 */
	{GPMC_AD14, (M0 | PIN_INPUT)},		/* gpmc_ad14.gpmc_ad14 */
	{GPMC_AD15, (M0 | PIN_INPUT)},		/* gpmc_ad15.gpmc_ad15 */

	{GPMC_A0, (M14 | PIN_INPUT_PULLUP)},	/* gpmc_a0.gpio7_3 */
	{GPMC_A1, (M14 | PIN_INPUT_PULLUP)},	/* gpmc_a1.gpio7_4 */
	{GPMC_A2, (M14 | PIN_INPUT_PULLUP)},	/* gpmc_a2.gpio7_5 */
	{GPMC_A3, (M14 | PIN_INPUT_PULLUP)},	/* gpmc_a3.gpio_7_6 */

	{GPMC_A4, (M7 | PIN_OUTPUT)},		/* gpmc_a4.i2c5_scl */
	{GPMC_A5, (M7 | PIN_INPUT)},		/* gpmc_a5.i2c5_sda */
	{GPMC_A6, (M8 | PIN_OUTPUT)},		/* gpmc_a6.uart6_ctsn */
	{GPMC_A7, (M8 | PIN_INPUT)},		/* gpmc_a7.uart6_rtsn */
	{GPMC_A8, (M14 | PIN_INPUT_PULLUP)},	/* gpmc_a8.gpio1_30 */
	{GPMC_A9, (M14 | PIN_INPUT_PULLUP)},	/* gpmc_a9.gpio1_31 */
	{GPMC_A10, (M14 | PIN_INPUT_PULLUP)},	/* gpmc_a10.gpio2_0 */
	{GPMC_A11, (M14 | PIN_INPUT_PULLUP)},	/* gpmc_a11.gpio2_1 */
	{GPMC_A12, (M9 | PIN_INPUT_PULLUP)},	/* gpmc_a12.dma_evt1 */
	{GPMC_A13, (M1 | PIN_INPUT_PULLDOWN)},	/* gpmc_a13.qspi1_rtclk */
	{GPMC_A14, (M1 | PIN_INPUT_PULLUP)},	/* gpmc_a14.qspi1_d3 */
	{GPMC_A15, (M1 | PIN_INPUT_PULLUP)},	/* gpmc_a15.qspi1_d2 */
	{GPMC_A16, (M1 | PIN_INPUT_PULLDOWN)},	/* gpmc_a16.qspi1_d0 */
	{GPMC_A17, (M1 | PIN_INPUT_PULLDOWN)},	/* gpmc_a17.qspi1_d1 */
	{GPMC_A18, (M1 | PIN_INPUT_PULLDOWN)},	/* gpmc_a18.qspi1_sclk */
	{GPMC_A19, (M1 | PIN_INPUT_PULLUP)},	/* gpmc_a19.mmc2_dat4 */
	{GPMC_A20, (M1 | PIN_INPUT_PULLUP)},	/* gpmc_a20.mmc2_dat5 */
	{GPMC_A21, (M1 | PIN_INPUT_PULLUP)},	/* gpmc_a21.mmc2_dat6 */
	{GPMC_A22, (M1 | PIN_INPUT_PULLUP)},	/* gpmc_a22.mmc2_dat7 */
	{GPMC_A23, (M1 | PIN_INPUT_PULLUP)},	/* gpmc_a23.mmc2_clk */
	{GPMC_A24, (M1 | PIN_INPUT_PULLUP)},	/* gpmc_a24.mmc2_dat0 */
	{GPMC_A25, (M1 | PIN_INPUT_PULLUP)},	/* gpmc_a25.mmc2_dat1 */
	{GPMC_A26, (M1 | PIN_INPUT_PULLUP)},	/* gpmc_a26.mmc2_dat2 */
	{GPMC_A27, (M1 | PIN_INPUT_PULLUP)},	/* gpmc_a27.mmc2_dat3 */
	{GPMC_CS0, (M0 | PIN_OUTPUT)},		/* gpmc_cs0.gpmc_cs0 */
	{GPMC_CS1, (M1 | PIN_INPUT_PULLUP)},	/* gpmc_cs1.mmc2_cmd */
	{GPMC_CS2, (M1 | PIN_INPUT_PULLUP)},	/* gpmc_cs2.qspi1_cs0 */
	{GPMC_CS3, (M0 | PIN_OUTPUT)},		/* gpmc_cs3.gpmc_cs3 */
	{GPMC_CLK, (M0 | PIN_OUTPUT)},		/* gpmc_clk.gpmc_clk */
	{GPMC_ADVN_ALE, (M0 | PIN_OUTPUT)},   /* gpmc_advn_ale.gpmc_advn_ale */
	{GPMC_OEN_REN, (M0 | PIN_OUTPUT)},	/* gpmc_oen_ren.gpmc_oen_ren */
	{GPMC_WEN, (M0 | PIN_OUTPUT)},		/* gpmc_wen.gpmc_wen */
	{GPMC_BEN0, (M0 | PIN_OUTPUT)},		/* gpmc_ben0.gpmc_ben0 */
	{GPMC_BEN1, (M0 | PIN_OUTPUT)},		/* gpmc_ben1.gpmc_ben1 */
	{GPMC_WAIT0, (M0 | PIN_INPUT_PULLUP)},	/* gpmc_wait0.gpmc_wait0 */
	{VIN2A_CLK0, (M14 | PIN_INPUT_PULLUP)},	/* vin2a_clk0.gpio3_28 */
	{VIN2A_DE0, (M4 | PIN_OUTPUT)},		/* vin2a_de0.vout2_de */
	{VIN2A_FLD0, (M4 | PIN_OUTPUT)},	/* vin2a_fld0.vout2_clk */
	{VIN2A_HSYNC0, (M4 | PIN_OUTPUT)},	/* vin2a_hsync0.vout2_hsync */
	{VIN2A_VSYNC0, (M4 | PIN_OUTPUT)},	/* vin2a_vsync0.vout2_vsync */
	{VIN2A_D0, (M14 | PIN_INPUT_PULLUP)},	/* vin2a_d0.gpio4_1 */
	{VIN2A_D1, (M14 | PIN_INPUT_PULLUP)},	/* vin2a_d1.gpio4_2 */
	{VIN2A_D2, (M14 | PIN_INPUT_PULLUP)},	/* vin2a_d2.gpio4_3 */
	{VIN2A_D3, (M12 | PIN_INPUT_PULLDOWN)},	/* vin2a_d3.pr1_pru1_gpi0 */
	{VIN2A_D4, (M12 | PIN_INPUT_PULLDOWN)},	/* vin2a_d4.pr1_pru1_gpi1 */
	{VIN2A_D5, (M12 | PIN_INPUT_PULLDOWN)},	/* vin2a_d5.pr1_pru1_gpi2 */
	{VIN2A_D6, (M11 | PIN_INPUT_PULLDOWN)},	/* vin2a_d6.pr1_mii_mt1_clk */
	{VIN2A_D7, (M11 | PIN_OUTPUT)},		/* vin2a_d7.pr1_mii1_txen */
	{VIN2A_D8, (M11 | PIN_OUTPUT)},		/* vin2a_d8.pr1_mii1_txd3 */
	{VIN2A_D9, (M11 | PIN_OUTPUT)},		/* vin2a_d9.pr1_mii1_txd2 */
	{VIN2A_D10, (M11 | PIN_OUTPUT)},	/* vin2a_d10.pr1_mdio_mdclk */
	{VIN2A_D11, (M11 | PIN_INPUT_PULLUP)},	/* vin2a_d11.pr1_mdio_data */
	{VIN2A_D12, (M11 | PIN_OUTPUT)},	/* vin2a_d12.pr1_mii1_txd1 */
	{VIN2A_D13, (M11 | PIN_OUTPUT)},	/* vin2a_d13.pr1_mii1_txd0 */
	{VIN2A_D14, (M11 | PIN_INPUT_PULLDOWN)},/* vin2a_d14.pr1_mii_mr1_clk */
	{VIN2A_D15, (M11 | PIN_INPUT_PULLDOWN)},/* vin2a_d15.pr1_mii1_rxdv */
	{VIN2A_D16, (M11 | PIN_INPUT_PULLDOWN)},/* vin2a_d16.pr1_mii1_rxd3 */
	{VIN2A_D17, (M11 | PIN_INPUT_PULLDOWN)},/* vin2a_d17.pr1_mii1_rxd2 */
	{VIN2A_D18, (M11 | PIN_INPUT_PULLDOWN)},/* vin2a_d18.pr1_mii1_rxd1 */
	{VIN2A_D19, (M11 | PIN_INPUT_PULLDOWN)},/* vin2a_d19.pr1_mii1_rxd0 */
	{VIN2A_D20, (M11 | PIN_INPUT_PULLDOWN)},/* vin2a_d20.pr1_mii1_rxer */
	{VIN2A_D21, (M11 | PIN_INPUT_PULLDOWN)},/* vin2a_d21.pr1_mii1_rxlink */
	{VIN2A_D22, (M11 | PIN_INPUT_PULLDOWN)},/* vin2a_d22.pr1_mii1_col */
	{VIN2A_D23, (M11 | PIN_INPUT_PULLDOWN)},/* vin2a_d23.pr1_mii1_crs */
	{VOUT1_CLK, (M8 | PIN_OUTPUT)},		/* vout1_clk.spi3_cs0 */
	{VOUT1_DE, (M8 | PIN_INPUT_PULLDOWN)},	/* vout1_de.spi3_d1 */
	{VOUT1_FLD, (M14 | PIN_INPUT_PULLUP)},	/* vout1_fld.gpio4_21 */
	{VOUT1_HSYNC, (M8 | PIN_INPUT_PULLDOWN)},/* vout1_hsync.spi3_d0 */
	{VOUT1_VSYNC, (M8 | PIN_OUTPUT)},	/* vout1_vsync.spi3_sclk */
	{VOUT1_D0, (M14 | PIN_INPUT_PULLDOWN)},	/* vout1_d0.gpio8_0 */
	{VOUT1_D1, (M14 | PIN_INPUT_PULLDOWN)},	/* vout1_d1.gpio8_1 */
	{VOUT1_D2, (M10 | PIN_INPUT_PULLDOWN)},	/* vout1_d2.pr1_uart0_rxd */
	// VOUT1_D4 is in early_padconf
	{VOUT1_D3, (M10 | PIN_OUTPUT)},		/* vout1_d3.pr1_uart0_txd */
	{VOUT1_D5, (M10 | PIN_INPUT_PULLDOWN)},	/* vout1_d5.pr2_edc_latch0_in */
	{VOUT1_D6, (M14 | PIN_INPUT_PULLDOWN)},	/* vout1_d6.gpio8_6 */
	{VOUT1_D7, (M10 | PIN_OUTPUT)},		/* vout1_d7.pr2_edc_sync0_out */
	{VOUT1_D8, (M2 | PIN_INPUT_PULLDOWN)},	/* vout1_d8.uart6_rxd */
	{VOUT1_D9, (M2 | PIN_OUTPUT)},		/* vout1_d9.uart6_txd */
	{VOUT1_D10, (M14 | PIN_INPUT_PULLUP)},	/* vout1_d10.gpio8_10 */
	{VOUT1_D11, (M10 | PIN_OUTPUT)},	/* vout1_d11.pr2_uart0_cts_n */
	{VOUT1_D12, (M10 | PIN_INPUT_PULLUP)},	/* vout1_d12.pr2_uart0_rts_n */
	{VOUT1_D13, (M10 | PIN_INPUT_PULLUP)},	/* vout1_d13.pr2_uart0_rxd */
	{VOUT1_D14, (M10 | PIN_OUTPUT)},	/* vout1_d14.pr2_uart0_txd */
	{VOUT1_D15, (M14 | PIN_INPUT_PULLUP)},	/* vout1_d15.gpio8_15 */
	{VOUT1_D16, (M14 | PIN_INPUT_PULLUP)},	/* vout1_d16.gpio8_16 */
	{VOUT1_D17, (M14 | PIN_INPUT_PULLUP)},	/* vout1_d17.gpio8_17 */
	{VOUT1_D18, (M14 | PIN_INPUT_PULLUP)},	/* vout1_d18.gpio8_18 */
	{VOUT1_D19, (M14 | PIN_INPUT_PULLUP)},	/* vout1_d19.gpio8_19 */
	{VOUT1_D20, (M14 | PIN_INPUT_PULLUP)},	/* vout1_d20.gpio8_20 */
	{VOUT1_D21, (M14 | PIN_INPUT_PULLUP)},	/* vout1_d21.gpio8_21 */
	{VOUT1_D22, (M14 | PIN_INPUT_PULLUP)},	/* vout1_d22.gpio8_22 */
	{VOUT1_D23, (M14 | PIN_INPUT_PULLUP)},	/* vout1_d23.gpio8_23 */
	{MDIO_MCLK, (M11 | PIN_INPUT_PULLUP)},	/* mdio_mclk.pr1_mii0_col */
	{MDIO_D, (M11 | PIN_INPUT_PULLUP)},	/* mdio_d.pr1_mii0_rxlink */
	{RMII_MHZ_50_CLK, (M14 | PIN_INPUT_PULLUP)},/* RMIIMHZ50CLK.gpio5_17 */
	{UART3_RXD, (M11 | PIN_INPUT_PULLUP)},	/* uart3_rxd.pr1_mii0_rxdv */
	{UART3_TXD, (M11 | PIN_INPUT_PULLUP)},	/* uart3_txd.pr1_mii_mr0_clk */
	{RGMII0_TXC, (M11 | PIN_INPUT_PULLDOWN)},	/* rgmii0_txc.pr1_mii0_rxd3 */
	{RGMII0_TXCTL, (M11 | PIN_INPUT_PULLDOWN)},	/* rgmii0_txctl.pr1_mii0_rxd2 */
	{RGMII0_TXD3, (M11 | PIN_INPUT_PULLDOWN)},	/* rgmii0_txd3.pr1_mii0_crs */
	{RGMII0_TXD2, (M11 | PIN_INPUT_PULLDOWN)},	/* rgmii0_txd2.pr1_mii0_rxer */
	{RGMII0_TXD1, (M11 | PIN_INPUT_PULLDOWN)},	/* rgmii0_txd1.pr1_mii0_rxd1 */
	{RGMII0_TXD0, (M11 | PIN_INPUT_PULLDOWN)},	/* rgmii0_txd0.pr1_mii0_rxd0 */
	{RGMII0_RXC, (M11 | PIN_INPUT_PULLDOWN)},	/* rgmii0_rxc.pr1_mii_mt0_clk */
	{RGMII0_RXCTL, (M11 | PIN_INPUT_PULLDOWN)},	/* rgmii0_rxctl.pr1_mii0_txd3 */
	{RGMII0_RXD3, (M11 | PIN_INPUT_PULLDOWN)},	/* rgmii0_rxd3.pr1_mii0_txd2 */
	{RGMII0_RXD2, (M11 | PIN_INPUT_PULLDOWN)},	/* rgmii0_rxd2.pr1_mii0_txen */
	{RGMII0_RXD1, (M11 | PIN_INPUT_PULLDOWN)},	/* rgmii0_rxd1.pr1_mii0_txd1 */
	{RGMII0_RXD0, (M11 | PIN_INPUT_PULLDOWN)},	/* rgmii0_rxd0.pr1_mii0_txd0 */
	{USB1_DRVVBUS, (M0 | PIN_INPUT_SLEW)},	/* usb1_drvvbus.usb1_drvvbus */
	{USB2_DRVVBUS, (M0 | PIN_INPUT_SLEW)},	/* usb2_drvvbus.usb2_drvvbus */
	{GPIO6_14, (M2 | PIN_INPUT_PULLUP)},	/* gpio6_14.dcan2_tx */
	{GPIO6_15, (M2 | PIN_INPUT_PULLUP)},	/* gpio6_15.dcan2_rx */
	{GPIO6_16, (M10 | PIN_INPUT_PULLDOWN)},	/* gpio6_16.timer3 */
	{XREF_CLK0, (M11 | PIN_INPUT_PULLDOWN)},	/* xref_clk0.pr2_mii1_col */
	{XREF_CLK1, (M11 | PIN_INPUT_PULLDOWN)},	/* xref_clk1.pr2_mii1_crs */
	{XREF_CLK2, (M15 | PIN_INPUT_PULLDOWN)},	/* xref_clk2.timer15 */
	{XREF_CLK3, (M15 | PIN_INPUT_PULLDOWN)},	/* xref_clk3.timer16 */
	{MCASP1_ACLKX, (M11 | PIN_INPUT_PULLDOWN)},	/* mcasp1_aclkx.pr2_mdio_mdclk */
	{MCASP1_FSX, (M11 | PIN_INPUT_SLEW)},	/* mcasp1_fsx.pr2_mdio_data */
	{MCASP1_ACLKR, (M6 | PIN_OUTPUT)},	/* mcasp1_aclkr.vout2_d0 */
	{MCASP1_FSR, (M6 | PIN_OUTPUT)},	/* mcasp1_fsr.vout2_d1 */
	{MCASP1_AXR0, (M11 | PIN_INPUT_PULLDOWN)},	/* mcasp1_axr0.pr2_mii0_rxer */
	{MCASP1_AXR1, (M11 | PIN_INPUT_SLEW)},	/* mcasp1_axr1.pr2_mii_mt0_clk */
	{MCASP1_AXR2, (M6 | PIN_OUTPUT)},	/* mcasp1_axr2.vout2_d2 */
	{MCASP1_AXR3, (M6 | PIN_OUTPUT)},	/* mcasp1_axr3.vout2_d3 */
	{MCASP1_AXR4, (M6 | PIN_OUTPUT)},	/* mcasp1_axr4.vout2_d4 */
	{MCASP1_AXR5, (M6 | PIN_OUTPUT)},	/* mcasp1_axr5.vout2_d5 */
	{MCASP1_AXR6, (M6 | PIN_OUTPUT)},	/* mcasp1_axr6.vout2_d6 */
	{MCASP1_AXR7, (M6 | PIN_OUTPUT)},	/* mcasp1_axr7.vout2_d7 */
	{MCASP1_AXR8, (M11 | PIN_INPUT_SLEW)},	/* mcasp1_axr8.pr2_mii0_txen */
	{MCASP1_AXR9, (M11 | PIN_INPUT_SLEW)},	/* mcasp1_axr9.pr2_mii0_txd3 */
	{MCASP1_AXR10, (M11 | PIN_INPUT_SLEW)},	/* mcasp1_axr10.pr2_mii0_txd2 */
	{MCASP1_AXR11, (M11 | PIN_INPUT_SLEW)},	/* mcasp1_axr11.pr2_mii0_txd1 */
	{MCASP1_AXR12, (M11 | PIN_INPUT_SLEW)},	/* mcasp1_axr12.pr2_mii0_txd0 */
	{MCASP1_AXR13, (M11 | PIN_INPUT_SLEW)},	/* mcasp1_axr13.pr2_mii_mr0_clk */
	{MCASP1_AXR14, (M11 | PIN_INPUT_SLEW)},	/* mcasp1_axr14.pr2_mii0_rxdv */
	{MCASP1_AXR15, (M11 | PIN_INPUT_SLEW)},	/* mcasp1_axr15.pr2_mii0_rxd3 */
	{MCASP2_ACLKX, (M11 | PIN_INPUT_PULLDOWN)},	/* mcasp2_aclkx.pr2_mii0_rxd2 */
	{MCASP2_FSX, (M11 | PIN_INPUT_SLEW)},	/* mcasp2_fsx.pr2_mii0_rxd1 */
	{MCASP2_ACLKR, (M6 | PIN_OUTPUT)},	/* mcasp2_aclkr.vout2_d8 */
	{MCASP2_FSR, (M6 | PIN_OUTPUT)},	/* mcasp2_fsr.vout2_d9 */
	{MCASP2_AXR0, (M6 | PIN_OUTPUT)},	/* mcasp2_axr0.vout2_d10 */
	{MCASP2_AXR1, (M6 | PIN_OUTPUT)},	/* mcasp2_axr1.vout2_d11 */
	{MCASP2_AXR2, (M11 | PIN_INPUT_SLEW)},	/* mcasp2_axr2.pr2_mii0_rxd0 */
	{MCASP2_AXR3, (M11 | PIN_INPUT_SLEW)},	/* mcasp2_axr3.pr2_mii0_rxlink */
	{MCASP2_AXR4, (M6 | PIN_OUTPUT)},	/* mcasp2_axr4.vout2_d12 */
	{MCASP2_AXR5, (M6 | PIN_OUTPUT)},	/* mcasp2_axr5.vout2_d13 */
	{MCASP2_AXR6, (M6 | PIN_OUTPUT)},	/* mcasp2_axr6.vout2_d14 */
	{MCASP2_AXR7, (M6 | PIN_OUTPUT)},	/* mcasp2_axr7.vout2_d15 */
	{MCASP3_ACLKX, (M11 | PIN_INPUT_PULLDOWN)},	/* mcasp3_aclkx.pr2_mii0_crs */
	{MCASP3_FSX, (M11 | PIN_INPUT_SLEW)},	/* mcasp3_fsx.pr2_mii0_col */
	{MCASP3_AXR0, (M11 | PIN_INPUT_SLEW)},	/* mcasp3_axr0.pr2_mii1_rxer */
	{MCASP3_AXR1, (M11 | PIN_INPUT_SLEW)},	/* mcasp3_axr1.pr2_mii1_rxlink */
	{MCASP4_ACLKX, (M6 | PIN_OUTPUT)},	/* mcasp4_aclkx.vout2_d16 */
	{MCASP4_FSX, (M6 | PIN_OUTPUT)},	/* mcasp4_fsx.vout2_d17 */
	{MCASP4_AXR0, (M15 | PIN_INPUT_PULLDOWN)},	/* mcasp4_axr0.Driveroff */
	{MCASP4_AXR1, (M15 | PIN_INPUT_PULLDOWN)},	/* mcasp4_axr1.Driveroff */
	{MCASP5_ACLKX, (M1 | PIN_INPUT_PULLDOWN)},	/* mcasp5_aclkx.mcasp5_aclkr */
	{MCASP5_FSX, (M1 | PIN_INPUT_PULLDOWN)},	/* mcasp5_fsx.mcasp5_fsr */
	{MCASP5_AXR0, (M0 | PIN_INPUT_PULLDOWN)},	/* mcasp5_axr0.mcasp5_axr0 */
	{MCASP5_AXR1, (M0 | PIN_INPUT_PULLDOWN)},	/* mcasp5_axr1.mcasp5_axr1 */
	{MMC1_CLK, (M0 | PIN_INPUT_PULLUP)},	/* mmc1_clk.mmc1_clk */
	{MMC1_CMD, (M0 | PIN_INPUT_PULLUP)},	/* mmc1_cmd.mmc1_cmd */
	{MMC1_DAT0, (M0 | PIN_INPUT_PULLUP)},	/* mmc1_dat0.mmc1_dat0 */
	{MMC1_DAT1, (M0 | PIN_INPUT_PULLUP)},	/* mmc1_dat1.mmc1_dat1 */
	{MMC1_DAT2, (M0 | PIN_INPUT_PULLUP)},	/* mmc1_dat2.mmc1_dat2 */
	{MMC1_DAT3, (M0 | PIN_INPUT_PULLUP)},	/* mmc1_dat3.mmc1_dat3 */
	{MMC1_SDCD, (M0 | PIN_INPUT_PULLUP | SLEWCONTROL)},	/* mmc1_sdcd.mmc1_sdcd */
	{MMC1_SDWP, (M0 | 0x000d0000)},		/* mmc1_sdwp.mmc1_sdwp */
	{GPIO6_10, (M11 | PIN_INPUT_PULLUP)},	/* gpio6_10.pr2_mii_mt1_clk */
	{GPIO6_11, (M11 | PIN_INPUT_PULLUP)},	/* gpio6_11.pr2_mii1_txen */
	{MMC3_CLK, (M11 | PIN_INPUT_PULLUP)},	/* mmc3_clk.pr2_mii1_txd3 */
	{MMC3_CMD, (M11 | PIN_INPUT_PULLUP)},	/* mmc3_cmd.pr2_mii1_txd2 */
	{MMC3_DAT0, (M11 | PIN_INPUT_PULLUP)},	/* mmc3_dat0.pr2_mii1_txd1 */
	{MMC3_DAT1, (M11 | PIN_INPUT_PULLUP)},	/* mmc3_dat1.pr2_mii1_txd0 */
	{MMC3_DAT2, (M11 | PIN_INPUT_PULLUP)},	/* mmc3_dat2.pr2_mii_mr1_clk */
	{MMC3_DAT3, (M11 | PIN_INPUT_PULLUP)},	/* mmc3_dat3.pr2_mii1_rxdv */
	{MMC3_DAT4, (M11 | PIN_INPUT_PULLUP)},	/* mmc3_dat4.pr2_mii1_rxd3 */
	{MMC3_DAT5, (M11 | PIN_INPUT_PULLUP)},	/* mmc3_dat5.pr2_mii1_rxd2 */
	{MMC3_DAT6, (M11 | PIN_INPUT_PULLUP)},	/* mmc3_dat6.pr2_mii1_rxd1 */
	{MMC3_DAT7, (M11 | PIN_INPUT_PULLUP)},	/* mmc3_dat7.pr2_mii1_rxd0 */
	{SPI1_SCLK, (M0 | PIN_OUTPUT)},		/* spi1_sclk.spi1_sclk */
	{SPI1_D1, (M0 | PIN_INPUT_SLEW)},	/* spi1_d1.spi1_d1 */
	{SPI1_D0, (M0 | PIN_INPUT_SLEW)},	/* spi1_d0.spi1_d0 */
	{SPI1_CS0, (M0 | PIN_OUTPUT)},		/* spi1_cs0.spi1_cs0 */
	{SPI1_CS1, (M0 | PIN_OUTPUT)},		/* spi1_cs1.spi1_cs1 */
	{SPI1_CS2, (M5 | PIN_OUTPUT)},		/* spi1_cs2.mdio_mclk */
	{SPI1_CS3, (M5 | PIN_INPUT_PULLUP)},	/* spi1_cs3.mdio_d */
	{SPI2_SCLK, (M0 | PIN_OUTPUT)},		/* spi2_sclk.spi2_sclk */
	{SPI2_D1, (M0 | PIN_INPUT_SLEW)},	/* spi2_d1.spi2_d1 */
	{SPI2_D0, (M0 | PIN_INPUT_SLEW)},	/* spi2_d0.spi2_d0 */
	{SPI2_CS0, (M0 | PIN_OUTPUT | SLEWCONTROL)},	/* spi2_cs0.spi2_cs0 */
	{DCAN1_TX, (M0 | PIN_INPUT_PULLUP | SLEWCONTROL)},	/* dcan1_tx.dcan1_tx */
	{DCAN1_RX, (M0 | PIN_INPUT_PULLUP | SLEWCONTROL)},	/* dcan1_rx.dcan1_rx */
	{UART1_RXD, (M0 | PIN_INPUT_PULLUP | SLEWCONTROL)},	/* uart1_rxd.uart1_rxd */
	{UART1_TXD, (M0 | PIN_INPUT_PULLUP | SLEWCONTROL)},	/* uart1_txd.uart1_txd */
	{UART1_CTSN, (M0 | PIN_INPUT_PULLUP)},	/* uart1_ctsn.uart1_ctsn */
	{UART1_RTSN, (M0 | PIN_INPUT_PULLUP)},	/* uart1_rtsn.uart1_rtsn */
	{UART2_RXD, (M14 | PIN_INPUT_PULLUP)},	/* uart2_rxd.gpio7_26 */
	{UART2_TXD, (M14 | PIN_INPUT_PULLUP)},	/* uart2_txd.uart7_27 */
	/*
	 * The following are in early padconf:
	 * UART2_CTSN, UART2_RTSN (used for UART3/console) I2C1_SDA, I2C1_SCL,
	 * I2C2_SDA, I2C2_SCL (used for TPM).
	 */
	{WAKEUP0, (M14 | PIN_INPUT_PULLUP)},	/* Wakeup0.gpio1_0 */
	{WAKEUP3, (M14 | PIN_INPUT_PULLUP)},	/* Wakeup3.gpio1_3 */
	{ON_OFF, (M0 | PIN_OUTPUT_PULLUP)},	/* on_off.on_off */
	{RTC_PORZ, (M0 | PIN_OUTPUT)},		/* rtc_porz.rtc_porz */
	{TMS, (M0 | PIN_INPUT_PULLUP)},		/* tms.tms */
	{TDI, (M0 | PIN_INPUT_PULLUP | SLEWCONTROL)},	/* tdi.tdi */
	{TDO, (M0 | PIN_INPUT_PULLUP)},		/* tdo.tdo */
	{TCLK, (M0 | PIN_INPUT_PULLUP)},	/* tclk.tclk */
	{TRSTN, (M0 | PIN_INPUT_PULLDOWN)},	/* trstn.trstn */
	{RTCK, (M0 | PIN_INPUT)},		/* rtck.rtck */
	{EMU0, (M0 | PIN_INPUT_PULLUP)},	/* emu0.emu0 */
	{EMU1, (M0 | PIN_INPUT_PULLUP)},	/* emu1.emu1 */
	{RESETN, (M0 | PIN_OUTPUT_PULLUP)},	/* resetn.resetn */
	{RSTOUTN, (M0 | PIN_OUTPUT_PULLDOWN)},	/* rstoutn.rstoutn */
};

const struct pad_conf_entry early_padconf[] = {
	{UART2_CTSN, (M2 | PIN_INPUT_SLEW)},	/* uart2_ctsn.uart3_rxd */
	{UART2_RTSN, (M1 | PIN_INPUT_SLEW)},	/* uart2_rtsn.uart3_txd */
	{I2C1_SDA, (PIN_INPUT_PULLUP | M0)},	/* I2C1_SDA */
	{I2C1_SCL, (PIN_INPUT_PULLUP | M0)},	/* I2C1_SCL */
	{I2C2_SDA, (PIN_INPUT_PULLDOWN | M0)},  /* I2C2_SDA -- used for TPM */
	{I2C2_SCL, (PIN_INPUT_PULLDOWN | M0)},  /* I2C2_SCL -- used for TPM */
	{VOUT1_D4, (M14 | PIN_OUTPUT)},		/* vout1_d4.gpio8_4 TPM RST */
};

#endif /* _MUX_DATA_D3_TDA2ECO_H_ */
