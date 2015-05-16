#ifndef _ASM_X86_INTEL_SCU_FLIS_H_
#define _ASM_X86_INTEL_SCU_FLIS_H_

enum flis_param_t {
	PULL,
	MUX,
	OPEN_DRAIN,
};

#ifndef CONFIG_X86_MRFLD
/* For CTP */
/*
 * Config value for PULL
 */
#define NONE		(0 << 0)
#define DOWN_20K	(1 << 0)
#define DOWN_2K		(1 << 1)
/* DOWN_75K is reserved */
#define UP_20K		(1 << 3)
#define UP_2K		(1 << 4)
/*910 Weak Pull-Up*/
#define UP_910		(1 << 5)

/*
 * Config value for OPEN_DRAIN
 */
#define OD_DISABLE	(1 << 0)
#define OD_ENABLE	(0 << 0)

/*
 * Config value for MUX
 */
/*Bit0: Mux Enable for Input Enable*/
#define MUX_EN_INPUT_EN		(1<<0)
/*Bit1: Input Enable for*/
#define INPUT_EN		(1<<1)
/*Bit2: Mux Enable for Output Enable*/
#define MUX_EN_OUTPUT_EN	(1<<2)
/*Bit3: Output Enable*/
#define OUTPUT_EN		(1<<3)

#define PULL_MASK		0x3F
#define MUX_MASK		0xF
#define OPEN_DRAIN_MASK		0x1

#else
/* For MERR */

#define PULL_MASK	((7 << 4) | (3 << 8))
#define MUX_MASK	(0xF << 12)
#define OPEN_DRAIN_MASK	BIT(21)

#define PULL_UP		(1 << 8)
#define PULL_DOWN	(2 << 8)
#define R2Kohms		(0 << 4)
#define R20Kohms	(1 << 4)
#define R50Kohms	(2 << 4)
#define R910ohms	(3 << 4)

#define UP_2K		(PULL_UP | R2Kohms)
#define UP_20K		(PULL_UP | R20Kohms)
#define UP_50K		(PULL_UP | R50Kohms)
#define UP_910		(PULL_UP | R910ohms)
#define DOWN_2K		(PULL_DOWN | R2Kohms)
#define DOWN_20K	(PULL_DOWN | R20Kohms)
#define DOWN_50K	(PULL_DOWN | R50Kohms)
#define DOWN_910	(PULL_DOWN | R910ohms)

#define OD_DISABLE	(0 << 21)
#define OD_ENABLE	(1 << 21)

#define MUX_EN_INPUT_EN		(2 << 12)
#define INPUT_EN		(1 << 12)
#define MUX_EN_OUTPUT_EN	(8 << 12)
#define OUTPUT_EN		(4 << 12)

#endif

enum ctp_pinname_t {
	i2s_2_clk = 0,
	i2s_2_fs = 1,
	i2s_2_rxd = 2,
	i2s_2_txd = 3,
	msic_reset_b = 4,
	spi_0_clk = 5,
	spi_0_sdi = 6,
	spi_0_sdo = 7,
	spi_0_ss = 8,
	svid_clkout = 9,
	svid_clksynch = 10,
	svid_din = 11,
	svid_dout = 12,
	usb_ulpi_clk = 13,
	usb_ulpi_data0 = 14,
	usb_ulpi_data1 = 15,
	usb_ulpi_data2 = 16,
	usb_ulpi_data3 = 17,
	usb_ulpi_data4 = 18,
	usb_ulpi_data5 = 19,
	usb_ulpi_data6 = 20,
	usb_ulpi_data7 = 21,
	usb_ulpi_dir = 22,
	usb_ulpi_nxt = 23,
	usb_ulpi_refclk = 24,
	usb_ulpi_stp = 25,
	ulpi1lpc_gpe_b = 26,
	ulpi1lpc_lpc_ad0 = 27,
	ulpi1lpc_lpc_ad1 = 28,
	ulpi1lpc_lpc_ad2 = 29,
	ulpi1lpc_lpc_ad3 = 30,
	ulpi1lpc_lpc_clkout = 31,
	ulpi1lpc_lpc_clkrun = 32,
	ulpi1lpc_lpc_frame_b = 33,
	ulpi1lpc_lpc_reset_b = 34,
	ulpi1lpc_lpc_serirq = 35,
	ulpi1lpc_lpc_smi_b = 36,
	ulpi1lpc_usb_ulpi_1_clk = 37,
	ulpi1lpc_usb_ulpi_1_data0 = 38,
	ulpi1lpc_usb_ulpi_1_data1 = 39,
	ulpi1lpc_usb_ulpi_1_data2 = 40,
	ulpi1lpc_usb_ulpi_1_data3 = 41,
	ulpi1lpc_usb_ulpi_1_data4 = 42,
	ulpi1lpc_usb_ulpi_1_data5 = 43,
	ulpi1lpc_usb_ulpi_1_data6 = 44,
	ulpi1lpc_usb_ulpi_1_data7 = 45,
	ulpi1lpc_usb_ulpi_1_dir = 46,
	ulpi1lpc_usb_ulpi_1_nxt = 47,
	ulpi1lpc_usb_ulpi_1_refclk = 48,
	ulpi1lpc_usb_ulpi_1_stp = 49,
	kbd_dkin0 = 50,
	kbd_dkin1 = 51,
	kbd_dkin2 = 52,
	kbd_dkin3 = 53,
	kbd_mkin0 = 54,
	kbd_mkin1 = 55,
	kbd_mkin2 = 56,
	kbd_mkin3 = 57,
	kbd_mkin4 = 58,
	kbd_mkin5 = 59,
	kbd_mkin6 = 60,
	kbd_mkin7 = 61,
	kbd_mkout0 = 62,
	kbd_mkout1 = 63,
	kbd_mkout2 = 64,
	kbd_mkout3 = 65,
	kbd_mkout4 = 66,
	kbd_mkout5 = 67,
	kbd_mkout6 = 68,
	kbd_mkout7 = 69,
	camerasb10 = 70,
	camerasb4 = 71,
	camerasb5 = 72,
	camerasb6 = 73,
	camerasb7 = 74,
	camerasb8 = 75,
	camerasb9 = 76,
	i2c_4_scl = 77,
	i2c_4_sda = 78,
	i2c_5_scl = 79,
	i2c_5_sda = 80,
	intd_dsi_te1 = 81,
	intd_dsi_te2 = 82,
	stio_0_cd_b = 83,
	stio_0_clk = 84,
	stio_0_cmd = 85,
	stio_0_dat0 = 86,
	stio_0_dat1 = 87,
	stio_0_dat2 = 88,
	stio_0_dat3 = 89,
	stio_0_dat4 = 90,
	stio_0_dat5 = 91,
	stio_0_dat6 = 92,
	stio_0_dat7 = 93,
	stio_0_wp_b = 94,
	camerasb0 = 95,
	camerasb1 = 96,
	camerasb2 = 97,
	camerasb3 = 98,
	ded_gpio10 = 99,
	ded_gpio11 = 100,
	ded_gpio12 = 101,
	ded_gpio13 = 102,
	ded_gpio14 = 103,
	ded_gpio15 = 104,
	ded_gpio16 = 105,
	ded_gpio17 = 106,
	ded_gpio18 = 107,
	ded_gpio19 = 108,
	ded_gpio20 = 109,
	ded_gpio21 = 110,
	ded_gpio22 = 111,
	ded_gpio23 = 112,
	ded_gpio24 = 113,
	ded_gpio25 = 114,
	ded_gpio26 = 115,
	ded_gpio27 = 116,
	ded_gpio28 = 117,
	ded_gpio29 = 118,
	ded_gpio30 = 119,
	ded_gpio8 = 120,
	ded_gpio9 = 121,
	mpti_nidnt_clk = 122,
	mpti_nidnt_data0 = 123,
	mpti_nidnt_data1 = 124,
	mpti_nidnt_data2 = 125,
	mpti_nidnt_data3 = 126,
	stio_1_clk = 127,
	stio_1_cmd = 128,
	stio_1_dat0 = 129,
	stio_1_dat1 = 130,
	stio_1_dat2 = 131,
	stio_1_dat3 = 132,
	stio_2_clk = 133,
	stio_2_cmd = 134,
	stio_2_dat0 = 135,
	stio_2_dat1 = 136,
	stio_2_dat2 = 137,
	stio_2_dat3 = 138,
	coms_int0 = 139,
	coms_int1 = 140,
	coms_int2 = 141,
	coms_int3 = 142,
	ded_gpio4 = 143,
	ded_gpio5 = 144,
	ded_gpio6 = 145,
	ded_gpio7 = 146,
	i2s_0_clk = 147,
	i2s_0_fs = 148,
	i2s_0_rxd = 149,
	i2s_0_txd = 150,
	i2s_1_clk = 151,
	i2s_1_fs = 152,
	i2s_1_rxd = 153,
	i2s_1_txd = 154,
	mslim_1_bclk = 155,
	mslim_1_bdat = 156,
	resetout_b = 157,
	spi_2_clk = 158,
	spi_2_sdi = 159,
	spi_2_sdo = 160,
	spi_2_ss0 = 161,
	spi_2_ss1 = 162,
	spi_3_clk = 163,
	spi_3_sdi = 164,
	spi_3_sdo = 165,
	spi_3_ss0 = 166,
	spi_3_ss1 = 167,
	uart_0_cts = 168,
	uart_0_rts = 169,
	uart_0_rx = 170,
	uart_0_tx = 171,
	uart_1_rx = 172,
	uart_1_sd = 173,
	uart_1_tx = 174,
	uart_2_rx = 175,
	uart_2_tx = 176,
	aclkph = 177,
	dclkph = 178,
	dsiclkph = 179,
	ierr = 180,
	jtag_tckc = 181,
	jtag_tdic = 182,
	jtag_tdoc = 183,
	jtag_tmsc = 184,
	jtag_trst_b = 185,
	lclkph = 186,
	lfhclkph = 187,
	osc_clk_ctrl0 = 188,
	osc_clk_ctrl1 = 189,
	osc_clk_out0 = 190,
	osc_clk_out1 = 191,
	osc_clk_out2 = 192,
	osc_clk_out3 = 193,
	prochot_b = 194,
	thermtrip_b = 195,
	uclkph = 196,
	ded_gpio31 = 197,
	ded_gpio32 = 198,
	ded_gpio33 = 199,
	hdmi_cec = 200,
	i2c_3_scl_hdmi_ddc = 201,
	i2c_3_sda_hdmi_ddc = 202,
	i2c_0_scl = 203,
	i2c_0_sda = 204,
	i2c_1_scl = 205,
	i2c_1_sda = 206,
	i2c_2_scl = 207,
	i2c_2_sda = 208,
	spi_1_clk = 209,
	spi_1_sdi = 210,
	spi_1_sdo = 211,
	spi_1_ss0 = 212,
	spi_1_ss1 = 213,
	spi_1_ss2 = 214,
	spi_1_ss3 = 215,
	spi_1_ss4 = 216,
	CTP_PIN_NUM,
};

/* Add prefix "tng_" to avoid name duplication with ctp pins */
enum tng_pinname_t {
	tng_usb_ulpi_0_clk = 0,
	tng_usb_ulpi_0_data_0 = 1,
	tng_usb_ulpi_0_data_1 = 2,
	tng_usb_ulpi_0_data_2 = 3,
	tng_usb_ulpi_0_data_3 = 4,
	tng_usb_ulpi_0_data_4 = 5,
	tng_usb_ulpi_0_data_5 = 6,
	tng_usb_ulpi_0_data_6 = 7,
	tng_usb_ulpi_0_data_7 = 8,
	tng_usb_ulpi_0_dir = 9,
	tng_usb_ulpi_0_nxt = 10,
	tng_usb_ulpi_0_refclk = 11,
	tng_usb_ulpi_0_stp = 12,
	tng_emmc_0_clk = 13,
	tng_emmc_0_cmd = 14,
	tng_emmc_0_d_0 = 15,
	tng_emmc_0_d_1 = 16,
	tng_emmc_0_d_2 = 17,
	tng_emmc_0_d_3 = 18,
	tng_emmc_0_d_4 = 19,
	tng_emmc_0_d_5 = 20,
	tng_emmc_0_d_6 = 21,
	tng_emmc_0_d_7 = 22,
	tng_emmc_0_rst_b = 23,
	tng_gp_emmc_1_clk = 24,
	tng_gp_emmc_1_cmd = 25,
	tng_gp_emmc_1_d_0 = 26,
	tng_gp_emmc_1_d_1 = 27,
	tng_gp_emmc_1_d_2 = 28,
	tng_gp_emmc_1_d_3 = 29,
	tng_gp_emmc_1_d_4 = 30,
	tng_gp_emmc_1_d_5 = 31,
	tng_gp_emmc_1_d_6 = 32,
	tng_gp_emmc_1_d_7 = 33,
	tng_gp_emmc_1_rst_b = 34,
	tng_gp_28 = 35,
	tng_gp_29 = 36,
	tng_gp_sdio_0_cd_b = 37,
	tng_gp_sdio_0_clk = 38,
	tng_gp_sdio_0_cmd = 39,
	tng_gp_sdio_0_dat_0 = 40,
	tng_gp_sdio_0_dat_1 = 41,
	tng_gp_sdio_0_dat_2 = 42,
	tng_gp_sdio_0_dat_3 = 43,
	tng_gp_sdio_0_lvl_clk_fb = 44,
	tng_gp_sdio_0_lvl_cmd_dir = 45,
	tng_gp_sdio_0_lvl_dat_dir = 46,
	tng_gp_sdio_0_lvl_sel = 47,
	tng_gp_sdio_0_powerdown_b = 48,
	tng_gp_sdio_0_wp = 49,
	tng_gp_sdio_1_clk = 50,
	tng_gp_sdio_1_cmd = 51,
	tng_gp_sdio_1_dat_0 = 52,
	tng_gp_sdio_1_dat_1 = 53,
	tng_gp_sdio_1_dat_2 = 54,
	tng_gp_sdio_1_dat_3 = 55,
	tng_gp_sdio_1_powerdown_b = 56,
	tng_mhsi_acdata = 57,
	tng_mhsi_acflag = 58,
	tng_mhsi_acready = 59,
	tng_mhsi_acwake = 60,
	tng_mhsi_cadata = 61,
	tng_mhsi_caflag = 62,
	tng_mhsi_caready = 63,
	tng_mhsi_cawake = 64,
	tng_gp_mslim_0_bclk = 65,
	tng_gp_mslim_0_bdat = 66,
	tng_gp_ssp_0_clk = 67,
	tng_gp_ssp_0_fs = 68,
	tng_gp_ssp_0_rxd = 69,
	tng_gp_ssp_0_txd = 70,
	tng_gp_ssp_1_clk = 71,
	tng_gp_ssp_1_fs = 72,
	tng_gp_ssp_1_rxd = 73,
	tng_gp_ssp_1_txd = 74,
	tng_gp_ssp_2_clk = 75,
	tng_gp_ssp_2_fs = 76,
	tng_gp_ssp_2_rxd = 77,
	tng_gp_ssp_2_txd = 78,
	tng_gp_ssp_3_clk = 79,
	tng_gp_ssp_3_fs = 80,
	tng_gp_ssp_3_rxd = 81,
	tng_gp_ssp_3_txd = 82,
	tng_gp_ssp_4_clk = 83,
	tng_gp_ssp_4_fs_0 = 84,
	tng_gp_ssp_4_fs_1 = 85,
	tng_gp_ssp_4_fs_2 = 86,
	tng_gp_ssp_4_fs_3 = 87,
	tng_gp_ssp_4_rxd = 88,
	tng_gp_ssp_4_txd = 89,
	tng_gp_ssp_5_clk = 90,
	tng_gp_ssp_5_fs_0 = 91,
	tng_gp_ssp_5_fs_1 = 92,
	tng_gp_ssp_5_fs_2 = 93,
	tng_gp_ssp_5_fs_3 = 94,
	tng_gp_ssp_5_rxd = 95,
	tng_gp_ssp_5_txd = 96,
	tng_gp_ssp_6_clk = 97,
	tng_gp_ssp_6_fs = 98,
	tng_gp_ssp_6_rxd = 99,
	tng_gp_ssp_6_txd = 100,
	tng_gp_i2c_1_scl = 101,
	tng_gp_i2c_1_sda = 102,
	tng_gp_i2c_2_scl = 103,
	tng_gp_i2c_2_sda = 104,
	tng_gp_i2c_3_scl = 105,
	tng_gp_i2c_3_sda = 106,
	tng_gp_i2c_4_scl = 107,
	tng_gp_i2c_4_sda = 108,
	tng_gp_i2c_5_scl = 109,
	tng_gp_i2c_5_sda = 110,
	tng_gp_i2c_6_scl = 111,
	tng_gp_i2c_6_sda = 112,
	tng_gp_i2c_7_scl = 113,
	tng_gp_i2c_7_sda = 114,
	tng_gp_uart_0_cts = 115,
	tng_gp_uart_0_rts = 116,
	tng_gp_uart_0_rx = 117,
	tng_gp_uart_0_tx = 118,
	tng_gp_uart_1_cts = 119,
	tng_gp_uart_1_rts = 120,
	tng_gp_uart_1_rx = 121,
	tng_gp_uart_1_tx = 122,
	tng_gp_uart_2_cts = 123,
	tng_gp_uart_2_rts = 124,
	tng_gp_uart_2_rx = 125,
	tng_gp_uart_2_tx = 126,
	tng_gp_13 = 127,
	tng_gp_14 = 128,
	tng_gp_15 = 129,
	tng_gp_16 = 130,
	tng_gp_17 = 131,
	tng_gp_18 = 132,
	tng_gp_19 = 133,
	tng_gp_20 = 134,
	tng_gp_21 = 135,
	tng_gp_22 = 136,
	tng_gp_23 = 137,
	tng_gp_24 = 138,
	tng_gp_25 = 139,
	tng_gp_fast_int_0 = 140,
	tng_gp_fast_int_1 = 141,
	tng_gp_fast_int_2 = 142,
	tng_gp_fast_int_3 = 143,
	tng_gp_pwm_0 = 144,
	tng_gp_pwm_1 = 145,
	tng_gp_camerasb_0 = 146,
	tng_gp_camerasb_1 = 147,
	tng_gp_camerasb_2 = 148,
	tng_gp_camerasb_3 = 149,
	tng_gp_camerasb_4 = 150,
	tng_gp_camerasb_5 = 151,
	tng_gp_camerasb_6 = 152,
	tng_gp_camerasb_7 = 153,
	tng_gp_camerasb_8 = 154,
	tng_gp_camerasb_9 = 155,
	tng_gp_camerasb_10 = 156,
	tng_gp_camerasb_11 = 157,
	tng_gp_clkph_0 = 158,
	tng_gp_clkph_1 = 159,
	tng_gp_clkph_2 = 160,
	tng_gp_clkph_3 = 161,
	tng_gp_clkph_4 = 162,
	tng_gp_clkph_5 = 163,
	tng_gp_hdmi_hpd = 164,
	tng_gp_intd_dsi_te1 = 165,
	tng_gp_intd_dsi_te2 = 166,
	tng_osc_clk_ctrl_0 = 167,
	tng_osc_clk_ctrl_1 = 168,
	tng_osc_clk_out_0 = 169,
	tng_osc_clk_out_1 = 170,
	tng_osc_clk_out_2 = 171,
	tng_osc_clk_out_3 = 172,
	tng_osc_clk_out_4 = 173,
	tng_resetout_b = 174,
	tng_xxpmode = 175,
	tng_xxprdy = 176,
	tng_xxpreq_b = 177,
	tng_gp_26 = 178,
	tng_gp_27 = 179,
	tng_i2c_0_scl = 180,
	tng_i2c_0_sda = 181,
	tng_ierr_b = 182,
	tng_jtag_tckc = 183,
	tng_jtag_tdic = 184,
	tng_jtag_tdoc = 185,
	tng_jtag_tmsc = 186,
	tng_jtag_trst_b = 187,
	tng_prochot_b = 188,
	tng_rtc_clk = 189,
	tng_svid_vclk = 190,
	tng_svid_vdio = 191,
	tng_thermtrip_b = 192,
	tng_standby = 193,
	tng_gp_kbd_dkin_0 = 194,
	tng_gp_kbd_dkin_1 = 195,
	tng_gp_kbd_dkin_2 = 196,
	tng_gp_kbd_dkin_3 = 197,
	tng_gp_kbd_mkin_0 = 198,
	tng_gp_kbd_mkin_1 = 199,
	tng_gp_kbd_mkin_2 = 200,
	tng_gp_kbd_mkin_3 = 201,
	tng_gp_kbd_mkin_4 = 202,
	tng_gp_kbd_mkin_5 = 203,
	tng_gp_kbd_mkin_6 = 204,
	tng_gp_kbd_mkin_7 = 205,
	tng_gp_kbd_mkout_0 = 206,
	tng_gp_kbd_mkout_1 = 207,
	tng_gp_kbd_mkout_2 = 208,
	tng_gp_kbd_mkout_3 = 209,
	tng_gp_kbd_mkout_4 = 210,
	tng_gp_kbd_mkout_5 = 211,
	tng_gp_kbd_mkout_6 = 212,
	tng_gp_kbd_mkout_7 = 213,
	tng_gp_0 = 214,
	tng_gp_1 = 215,
	tng_gp_2 = 216,
	tng_gp_3 = 217,
	tng_gp_4 = 218,
	tng_gp_5 = 219,
	tng_gp_6 = 220,
	tng_gp_7 = 221,
	tng_gp_8 = 222,
	tng_gp_9 = 223,
	tng_gp_10 = 224,
	tng_gp_11 = 225,
	tng_gp_12 = 226,
	tng_gp_mpti_clk = 227,
	tng_gp_mpti_data_0 = 228,
	tng_gp_mpti_data_1 = 229,
	tng_gp_mpti_data_2 = 230,
	tng_gp_mpti_data_3 = 231,
	TNG_PIN_NUM,
};

struct pinstruct_t {
	bool valid;	/* the pin is allowed to be configured or not */
	u8 bus_address;
	u8 pullup_offset;
	u8 pullup_lsb_pos;
	u8 direction_offset;
	u8 direction_lsb_pos;
	u8 open_drain_offset;
	u8 open_drain_bit;
};

enum ACCESS_CTRL {
	readonly = (1 << 0),
	writable = (1 << 1),
};

struct pin_mmio_flis_t {
	u8 access_ctrl; /* mmio flis access control */
	u32 offset;	/* pin offset from flis base address */
};

struct intel_scu_flis_platform_data {
	struct pinstruct_t *pin_t;
	int pin_num;
	u32 flis_base;
	u32 flis_len;
	struct pin_mmio_flis_t *mmio_flis_t;
	bool shim_access;
};

#define OPS_STR_LEN 10

enum {
	DBG_SHIM_FLIS_ADDR,
	DBG_SHIM_OFFSET,
	DBG_SHIM_DATA,

	DBG_PARAM_VAL,
	DBG_PARAM_TYPE,
	DBG_PIN_NAME,
};

int intel_scu_ipc_write_shim(u32 data, u32 flis_addr, u32 offset);
int intel_scu_ipc_read_shim(u32 *data, u32 flis_addr, u32 offset);
int intel_scu_ipc_update_shim(u32 data, u32 mask, u32 flis_addr, u32 offset);
int config_pin_flis(unsigned int name, enum flis_param_t param, u32 val);
int get_pin_flis(unsigned int name, enum flis_param_t param, u32 *val);
u32 get_flis_value(u32 offset);
void set_flis_value(u32 value, u32 offset);

extern struct pinstruct_t ctp_pin_table[];
#endif
