
/*****************************************************************************

File Name  : reg.h

Description: Register Address Description header

COPYRIGHT (C) 2004 STMicroelectronics

*****************************************************************************/

/* Define to prevent recursive inclusion */

#ifndef __REG_H
#define __REG_H

/* Includes ------------------------------------------------------------ */

/* Exported Types ------------------------------------------------------ */

/* Exported Constants -------------------------------------------------- */

/* Exported Variables -------------------------------------------------- */

/* Exported Macros ----------------------------------------------------- */

#define STI5100_LMI_BASEADDRESS             (0XE0000000)
#define STI5100_FMI_BASEADDRESS             (0X20200000)
#define STI5100_SYSTEM_SERV_BASEADDRESS     (0X20F00000)
#define STI5100_CONFIG_CONTROL_BASEADDRESS  (0X20D00000)


#define STI5100_LMI_MIM                     (STI5100_LMI_BASEADDRESS+0X08)
#define STI5100_LMI_SCR                     (STI5100_LMI_BASEADDRESS+0X10)
#define STI5100_LMI_STR                     (STI5100_LMI_BASEADDRESS+0X18)
#define STI5100_LMI_COC_LOWER               (STI5100_LMI_BASEADDRESS+0X28)
#define STI5100_LMI_COC_UPPER               (STI5100_LMI_BASEADDRESS+0X2C)
#define STI5100_LMI_SDRA0                   (STI5100_LMI_BASEADDRESS+0X30)
#define STI5100_LMI_SDRA1                   (STI5100_LMI_BASEADDRESS+0X38)
#define STI5100_LMI_SDMR0                   (STI5100_LMI_BASEADDRESS+0X48)
#define STI5100_LMI_SDMR1                   (STI5100_LMI_BASEADDRESS+0X50)


#define STI5100_FMI_STATUS_CFG             (STI5100_FMI_BASEADDRESS+0X010)
#define STI5100_FMI_STATUS_LOCK            (STI5100_FMI_BASEADDRESS+0X018)
#define STI5100_FMI_LOCK                   (STI5100_FMI_BASEADDRESS+0X020)
#define STI5100_FMI_GEN_CFG                (STI5100_FMI_BASEADDRESS+0X028)
#define STI5100_FMI_FLASH_CLK_SEL          (STI5100_FMI_BASEADDRESS+0X050)
#define STI5100_FMI_CLK_ENABLE             (STI5100_FMI_BASEADDRESS+0X068)

#define STI5100_FMI_BANK0_DATA0            (STI5100_FMI_BASEADDRESS+0X100)
#define STI5100_FMI_BANK0_DATA1            (STI5100_FMI_BASEADDRESS+0X108)
#define STI5100_FMI_BANK0_DATA2            (STI5100_FMI_BASEADDRESS+0X110)
#define STI5100_FMI_BANK0_DATA3            (STI5100_FMI_BASEADDRESS+0X118)

#define STI5100_FMI_BANK1_DATA0            (STI5100_FMI_BASEADDRESS+0X140)
#define STI5100_FMI_BANK1_DATA1            (STI5100_FMI_BASEADDRESS+0X148)
#define STI5100_FMI_BANK1_DATA2            (STI5100_FMI_BASEADDRESS+0X150)
#define STI5100_FMI_BANK1_DATA3            (STI5100_FMI_BASEADDRESS+0X158)

#define STI5100_FMI_BANK2_DATA0            (STI5100_FMI_BASEADDRESS+0X180)
#define STI5100_FMI_BANK2_DATA1            (STI5100_FMI_BASEADDRESS+0X188)
#define STI5100_FMI_BANK2_DATA2            (STI5100_FMI_BASEADDRESS+0X190)
#define STI5100_FMI_BANK2_DATA3            (STI5100_FMI_BASEADDRESS+0X198)

#define STI5100_FMI_BANK3_DATA0             (STI5100_FMI_BASEADDRESS+0X1C0)
#define STI5100_FMI_BANK3_DATA1             (STI5100_FMI_BASEADDRESS+0X1C8)
#define STI5100_FMI_BANK3_DATA2             (STI5100_FMI_BASEADDRESS+0X1D0)
#define STI5100_FMI_BANK3_DATA3             (STI5100_FMI_BASEADDRESS+0X1D8)
 
#define STI5100_FMI_BANK0_BASE              (STI5100_FMI_BASEADDRESS+0XFF820)
#define STI5100_FMI_BANK1_BASE              (STI5100_FMI_BASEADDRESS+0XFF830)
#define STI5100_FMI_BANK2_BASE              (STI5100_FMI_BASEADDRESS+0XFF840)
#define STI5100_FMI_BANK3_BASE              (STI5100_FMI_BASEADDRESS+0XFF850)
#define STI5100_FMI_BANK_ENABLE             (STI5100_FMI_BASEADDRESS+0XFF860)


#define STI5100_PLLA_CONFIG0                (STI5100_SYSTEM_SERV_BASEADDRESS+0X00)
#define STI5100_PLLA_CONFIG1                (STI5100_SYSTEM_SERV_BASEADDRESS+0X04)
#define STI5100_PLLB_CONFIG0                (STI5100_SYSTEM_SERV_BASEADDRESS+0X08)
#define STI5100_PLLB_CONFIG1                (STI5100_SYSTEM_SERV_BASEADDRESS+0X0C)
#define STI5100_FSA_SETUP                   (STI5100_SYSTEM_SERV_BASEADDRESS+0X10)
#define STI5100_PIX_CLK_SETUP0              (STI5100_SYSTEM_SERV_BASEADDRESS+0X14)
#define STI5100_PIX_CLK_SETUP1              (STI5100_SYSTEM_SERV_BASEADDRESS+0X18)
#define STI5100_PCM_CLK_SETUP0              (STI5100_SYSTEM_SERV_BASEADDRESS+0X20)
#define STI5100_PCM_CLK_SETUP1              (STI5100_SYSTEM_SERV_BASEADDRESS+0X24)
#define STI5100_SPDIF_CLK_SETUP0            (STI5100_SYSTEM_SERV_BASEADDRESS+0X30)
#define STI5100_SPDIF_CLK_SETUP1            (STI5100_SYSTEM_SERV_BASEADDRESS+0X34)
#define STI5100_SC_CLK_SETUP0               (STI5100_SYSTEM_SERV_BASEADDRESS+0X40)
#define STI5100_SC_CLK_SETUP1               (STI5100_SYSTEM_SERV_BASEADDRESS+0X44)
#define STI5100_FSB_SETUP                   (STI5100_SYSTEM_SERV_BASEADDRESS+0X50)
#define STI5100_DAA_CLK_SETUP0              (STI5100_SYSTEM_SERV_BASEADDRESS+0X54)
#define STI5100_DAA_CLK_SETUP1              (STI5100_SYSTEM_SERV_BASEADDRESS+0X58)
#define STI5100_USB_CLK_SETUP0              (STI5100_SYSTEM_SERV_BASEADDRESS+0X60)
#define STI5100_USB_CLK_SETUP1              (STI5100_SYSTEM_SERV_BASEADDRESS+0X64)
#define STI5100_AUX_CLK_SETUP0              (STI5100_SYSTEM_SERV_BASEADDRESS+0X70)
#define STI5100_AUX_CLK_SETUP1              (STI5100_SYSTEM_SERV_BASEADDRESS+0X74)
#define STI5100_AUDIO_CLK_SETUP0            (STI5100_SYSTEM_SERV_BASEADDRESS+0X80)
#define STI5100_AUDIO_CLK_SETUP1            (STI5100_SYSTEM_SERV_BASEADDRESS+0X84)
#define STI5100_CPU_CLKDIV_CONFIG0          (STI5100_SYSTEM_SERV_BASEADDRESS+0X90)
#define STI5100_CPU_CLKDIV_CONFIG1          (STI5100_SYSTEM_SERV_BASEADDRESS+0X94)
#define STI5100_CPU_CLKDIV_CONFIG2          (STI5100_SYSTEM_SERV_BASEADDRESS+0X98)
#define STI5100_LMI_CLKDIV_CONFIG0          (STI5100_SYSTEM_SERV_BASEADDRESS+0XA0)
#define STI5100_LMI_CLKDIV_CONFIG1          (STI5100_SYSTEM_SERV_BASEADDRESS+0XA4)
#define STI5100_LMI_CLKDIV_CONFIG2          (STI5100_SYSTEM_SERV_BASEADDRESS+0XA8)
#define STI5100_BLT_CLKDIV_CONFIG0          (STI5100_SYSTEM_SERV_BASEADDRESS+0XB0)
#define STI5100_BLT_CLKDIV_CONFIG1          (STI5100_SYSTEM_SERV_BASEADDRESS+0XB4)
#define STI5100_BLT_CLKDIV_CONFIG2          (STI5100_SYSTEM_SERV_BASEADDRESS+0XB8)
#define STI5100_LS_IC_CLKDIV_CONFIG0        (STI5100_SYSTEM_SERV_BASEADDRESS+0XC0)
#define STI5100_LS_IC_CLKDIV_CONFIG1        (STI5100_SYSTEM_SERV_BASEADDRESS+0XC4)
#define STI5100_LS_IC_CLKDIV_CONFIG2        (STI5100_SYSTEM_SERV_BASEADDRESS+0XC8)
#define STI5100_FDMA_CLKDIV_CONFIG0         (STI5100_SYSTEM_SERV_BASEADDRESS+0XD0)
#define STI5100_FDMA_CLKDIV_CONFIG1         (STI5100_SYSTEM_SERV_BASEADDRESS+0XD4)
#define STI5100_FDMA_CLKDIV_CONFIG2         (STI5100_SYSTEM_SERV_BASEADDRESS+0XD8)
#define STI5100_VID_CLKDIV_CONFIG0          (STI5100_SYSTEM_SERV_BASEADDRESS+0XE0)
#define STI5100_VID_CLKDIV_CONFIG1          (STI5100_SYSTEM_SERV_BASEADDRESS+0XE4)
#define STI5100_VID_CLKDIV_CONFIG2          (STI5100_SYSTEM_SERV_BASEADDRESS+0XE8)
#define STI5100_HS_CLKDIV_CONFIG0           (STI5100_SYSTEM_SERV_BASEADDRESS+0XF0)
#define STI5100_HS_CLKDIV_CONFIG1           (STI5100_SYSTEM_SERV_BASEADDRESS+0XF4)
#define STI5100_HS_CLKDIV_CONFIG2           (STI5100_SYSTEM_SERV_BASEADDRESS+0XF8)
#define STI5100_FLASH_CLKDIV_CONFIG0        (STI5100_SYSTEM_SERV_BASEADDRESS+0X100)
#define STI5100_FLASH_CLKDIV_CONFIG1        (STI5100_SYSTEM_SERV_BASEADDRESS+0X104)
#define STI5100_FLASH_CLKDIV_CONFIG2        (STI5100_SYSTEM_SERV_BASEADDRESS+0X108)
#define STI5100_MODE_CONTROL                (STI5100_SYSTEM_SERV_BASEADDRESS+0X110)
#define STI5100_RESET_STATUS                (STI5100_SYSTEM_SERV_BASEADDRESS+0X140)
#define STI5100_DCO_MODE_CFG                (STI5100_SYSTEM_SERV_BASEADDRESS+0X170)
#define STI5100_CLOCK_SELECT_CFG            (STI5100_SYSTEM_SERV_BASEADDRESS+0X180)
#define STI5100_CLOCK_OBSERVE_CFG           (STI5100_SYSTEM_SERV_BASEADDRESS+0X188)
#define STI5100_REGISTER_LOCK               (STI5100_SYSTEM_SERV_BASEADDRESS+0X300)


#define STI5100_CONFIG_CONTROL_A            (STI5100_CONFIG_CONTROL_BASEADDRESS+0x8000)
#define STI5100_CONFIG_CONTROL_B            (STI5100_CONFIG_CONTROL_BASEADDRESS+0x8004)
#define STI5100_CONFIG_CONTROL_C            (STI5100_CONFIG_CONTROL_BASEADDRESS+0x0)
#define STI5100_CONFIG_CONTROL_D            (STI5100_CONFIG_CONTROL_BASEADDRESS+0X4)  
#define STI5100_CONFIG_CONTROL_E            (STI5100_CONFIG_CONTROL_BASEADDRESS+0x8)
#define STI5100_CONFIG_CONTROL_F            (STI5100_CONFIG_CONTROL_BASEADDRESS+0XC)  
#define STI5100_CONFIG_CONTROL_G            (STI5100_CONFIG_CONTROL_BASEADDRESS+0X10)
#define STI5100_CONFIG_CONTROL_H            (STI5100_CONFIG_CONTROL_BASEADDRESS+0X14)
#define STI5100_NHS2_INIT_0_PRIORITY        (STI5100_CONFIG_CONTROL_BASEADDRESS+0x9000)
#define STI5100_NHS2_INIT_1_PRIORITY        (STI5100_CONFIG_CONTROL_BASEADDRESS+0x9004)
#define STI5100_NHS3_INIT_0_PRIORITY        (STI5100_CONFIG_CONTROL_BASEADDRESS+0xFE000)
#define STI5100_NHS3_INIT_1_PRIORITY        (STI5100_CONFIG_CONTROL_BASEADDRESS+0xFE004)
#define STI5100_NHS3_INIT_2_PRIORITY        (STI5100_CONFIG_CONTROL_BASEADDRESS+0xFE008)
#define STI5100_NHS3_INIT_3_PRIORITY        (STI5100_CONFIG_CONTROL_BASEADDRESS+0xFE00C)
#define STI5100_NHS3_INIT_4_PRIORITY        (STI5100_CONFIG_CONTROL_BASEADDRESS+0xFE010)
#define STI5100_NHS3_INIT_0_LIMIT           (STI5100_CONFIG_CONTROL_BASEADDRESS+0xFE03C)
#define STI5100_NHS3_INIT_1_LIMIT           (STI5100_CONFIG_CONTROL_BASEADDRESS+0xFE040)
#define STI5100_NHS3_INIT_2_LIMIT           (STI5100_CONFIG_CONTROL_BASEADDRESS+0xFE044)
#define STI5100_NHS3_INIT_3_LIMIT           (STI5100_CONFIG_CONTROL_BASEADDRESS+0xFE048)
#define STI5100_NHS3_INIT_4_LIMIT           (STI5100_CONFIG_CONTROL_BASEADDRESS+0xFE04C)
#define STI5100_NHS4_INIT_0_PRIORITY        (STI5100_CONFIG_CONTROL_BASEADDRESS+0xFF000)
#define STI5100_NHS4_INIT_1_PRIORITY        (STI5100_CONFIG_CONTROL_BASEADDRESS+0xFF004)
#define STI5100_NHS4_INIT_2_PRIORITY        (STI5100_CONFIG_CONTROL_BASEADDRESS+0xFF008)
#define STI5100_NHS4_INIT_3_PRIORITY        (STI5100_CONFIG_CONTROL_BASEADDRESS+0xFF00C)
#define STI5100_NHS4_INIT_0_LIMIT           (STI5100_CONFIG_CONTROL_BASEADDRESS+0xFF030)
#define STI5100_NHS4_INIT_1_LIMIT           (STI5100_CONFIG_CONTROL_BASEADDRESS+0xFF034)
#define STI5100_NHS4_INIT_2_LIMIT           (STI5100_CONFIG_CONTROL_BASEADDRESS+0xFF038)
#define STI5100_NHS4_INIT_3_LIMIT           (STI5100_CONFIG_CONTROL_BASEADDRESS+0xFF03C)
#define STI5100_NHD1_INIT_0_PRIORITY        (STI5100_CONFIG_CONTROL_BASEADDRESS+0x2000)
#define STI5100_NHD1_INIT_1_PRIORITY        (STI5100_CONFIG_CONTROL_BASEADDRESS+0x2004)
#define STI5100_NHD1_INIT_2_PRIORITY        (STI5100_CONFIG_CONTROL_BASEADDRESS+0x2008)
#define STI5100_NHD1_INIT_3_PRIORITY        (STI5100_CONFIG_CONTROL_BASEADDRESS+0x200C)
#define STI5100_NHD1_INIT_4_PRIORITY        (STI5100_CONFIG_CONTROL_BASEADDRESS+0x2010)
#define STI5100_NHD1_INIT_5_PRIORITY        (STI5100_CONFIG_CONTROL_BASEADDRESS+0x2014)
#define STI5100_NHD1_INIT_6_PRIORITY        (STI5100_CONFIG_CONTROL_BASEADDRESS+0x2018)
#define STI5100_NHD1_INIT_7_PRIORITY        (STI5100_CONFIG_CONTROL_BASEADDRESS+0x201C)
#define STI5100_NHD1_INIT_0_LIMIT           (STI5100_CONFIG_CONTROL_BASEADDRESS+0x2060)
#define STI5100_NHD1_INIT_1_LIMIT           (STI5100_CONFIG_CONTROL_BASEADDRESS+0x2064)
#define STI5100_NHD1_INIT_2_LIMIT           (STI5100_CONFIG_CONTROL_BASEADDRESS+0x2068)
#define STI5100_NHD1_INIT_3_LIMIT           (STI5100_CONFIG_CONTROL_BASEADDRESS+0x206C)
#define STI5100_NHD1_INIT_4_LIMIT           (STI5100_CONFIG_CONTROL_BASEADDRESS+0x2070)
#define STI5100_NHD1_INIT_5_LIMIT           (STI5100_CONFIG_CONTROL_BASEADDRESS+0x2074)
#define STI5100_NHD1_INIT_6_LIMIT           (STI5100_CONFIG_CONTROL_BASEADDRESS+0x2078)
#define STI5100_NHD1_INIT_7_LIMIT           (STI5100_CONFIG_CONTROL_BASEADDRESS+0x207C)
#define STI5100_NHD2_INIT_0_PRIORITY        (STI5100_CONFIG_CONTROL_BASEADDRESS+0x1000)
#define STI5100_NHD2_INIT_1_PRIORITY        (STI5100_CONFIG_CONTROL_BASEADDRESS+0x1004)
#define STI5100_NHD2_INIT_2_PRIORITY        (STI5100_CONFIG_CONTROL_BASEADDRESS+0x1008)
#define STI5100_NHD2_INIT_3_PRIORITY        (STI5100_CONFIG_CONTROL_BASEADDRESS+0x100C)
#define STI5100_NHD2_INIT_4_PRIORITY        (STI5100_CONFIG_CONTROL_BASEADDRESS+0x1010)
#define STI5100_NHD2_INIT_0_LIMIT           (STI5100_CONFIG_CONTROL_BASEADDRESS+0x103C)
#define STI5100_NHD2_INIT_1_LIMIT           (STI5100_CONFIG_CONTROL_BASEADDRESS+0x1040)
#define STI5100_NHD2_INIT_2_LIMIT           (STI5100_CONFIG_CONTROL_BASEADDRESS+0x1044)
#define STI5100_NHD2_INIT_3_LIMIT           (STI5100_CONFIG_CONTROL_BASEADDRESS+0x1048)
#define STI5100_NHD2_INIT_4_LIMIT           (STI5100_CONFIG_CONTROL_BASEADDRESS+0x104C)
#define STI5100_CPU_FRAME                   (STI5100_CONFIG_CONTROL_BASEADDRESS+0x6000)
#define STI5100_CPU_LIMIT                   (STI5100_CONFIG_CONTROL_BASEADDRESS+0x6004)

/* Exported Functions -------------------------------------------------- */

#endif  /*__REG_H*/

/* EOF --------------------------------------------------------------------- */
