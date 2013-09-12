/************************************************************************
COPYRIGHT (C) ST Microelectronics (R&D) 2008
All rights reserved.

Author :           Automatically generated file

Contains the transport controller code packed as a word array

************************************************************************/

#define TC_ID 23
#define TC_DVB 1
#define TC_PTI4_SECURELITE 2
#define TC_TSGDMA 1
#define TC_BSL_SUPPORT 1

#define TRANSPORT_CONTROLLER_CODE_SIZE      1710

static char const VERSION[] = "\nTC Version STPTI_DVBTCLoaderBSLSL2 \n\tRel: 427216. File: DVBTC4 Version: 0\n \n\tRel: 427216. File: TCINIT Version: 0\n \n\tRel: 427216. File: TS_HEADER Version: 0\n \n\tRel: 427216. File: SETUPDMA Version: 0\n \n\tRel: 427216. File: AF_ALTOUT Version: 0\n \n\tRel: 427216. File: AF_PROC Version: 0\n \n\tRel: 427216. File: CC_PROC Version: 0\n \n\tRel: 427216. File: SLT_SWIT Version: 0\n \n\tRel: 427216. File: RAMCAM_PROC Version: 0\n \n\tRel: 427216. File: DMA_UNLD Version: 0\n \n\tRel: 427216. File: SIG_DEC Version: 0\n \n\tRel: 427216. File: STAT_BLK Version: 0\n \n\tRel: 427216. File: STREAMID Version: 0\n \n\tRel: 427216. File: ERR_PROC Version: 0\n \n\tRel: 427216. File: COMMON Version: 0\n \n\tRel: 427216. File: TCDMA Version: 0\n \n\tRel: 427216. File: SET_SCRAM Version: 0\n";


#define TRANSPORT_CONTROLLER_VERSION    2


static const unsigned int transport_controller_code[] = {
	0x2c000040, 0x40003f80, 0x40009f00, 0x2fab4104, 0x2c8001c0, 0x40206f88, 
	0x2c800000, 0x40002108, 0x40003888, 0x40207288, 0x2d000fc0, 0x40002d10, 
	0x2d200000, 0x40002010, 0x2d001800, 0x40002090, 0x2c000000, 0x4000cb00, 
	0x4000c100, 0x50003880, 0x50802100, 0x5100c100, 0x20400040, 0x20400080, 
	0x88001300, 0x2c000040, 0x4000a100, 0x4000a180, 0x2c000000, 0x4000cb00, 
	0x2c000040, 0x4000c100, 0x40008600, 0x40008680, 0x2c000000, 0x40207100, 
	0x40207200, 0x40206d00, 0x40046100, 0x4000cf00, 0x2e207c00, 0xe0000100, 
	0x44400500, 0x120001a0, 0xe0000240, 0x44400500, 0x40206c00, 0x40206c80, 
	0x4000c900, 0x40206700, 0x2ca06200, 0xe0000280, 0x44400440, 0x2c800000, 
	0x10800048, 0x08800008, 0x5000c100, 0x24400000, 0x88003600, 0x50a06e00, 
	0x50206e80, 0x10800048, 0x18000000, 0x40206e08, 0x40206e80, 0x2c203000, 
	0x40206180, 0x2caad204, 0x50aad580, 0x2483ffc8, 0x00002008, 0x80005600, 
	0x51a07700, 0x24004018, 0x80041200, 0x25003fd8, 0x2d800140, 0x2caad204, 
	0x58c01c42, 0x2403ffc8, 0x28400080, 0x80005600, 0x1080140d, 0x01800058, 
	0x88004e00, 0xc0041200, 0x2d800040, 0x2f005904, 0xc0052000, 0x2d400180, 
	0x40207090, 0x2e002e80, 0x5ac01842, 0x26800428, 0x88006000, 0x2e002040, 
	0x58406c42, 0x24400000, 0x80006d00, 0x50a07700, 0x25804008, 0x80006900, 
	0x24803fc8, 0x01c00050, 0x80006d00, 0x26c00168, 0x80006d00, 0x298011d0, 
	0x88001900, 0x10c00100, 0x40001008, 0x11800040, 0x2f007204, 0xc0052000, 
	0xe0400000, 0x2d400180, 0x31000210, 0x21400190, 0x40206a10, 0x40207190, 
	0x58400042, 0x10000040, 0x48400042, 0x26800428, 0x88007e00, 0xc0001900, 
	0x2c380000, 0x2487ffd0, 0x2f008204, 0xc004c600, 0x51206a00, 0x24200010, 
	0x88043600, 0x51a06d00, 0x258003d8, 0x01800058, 0x88008f00, 0x2d801100, 
	0x40003798, 0x2d800040, 0x40003898, 0x2d800000, 0x40003898, 0x2d800040, 
	0x2f009204, 0xc0052000, 0x24100010, 0x80009700, 0x50207c80, 0x20008000, 
	0x40207c80, 0x2c400180, 0x40206a80, 0x2d800000, 0x40207218, 0x40046018, 
	0x50206d00, 0x258003c0, 0x25000c00, 0x8800a200, 0x25c000d8, 0x8000d900, 
	0x25801000, 0x8800cb00, 0x50206a80, 0x25002000, 0x8000cb00, 0x24afffc8, 
	0x51a07d80, 0x21800118, 0x24001000, 0x8800b100, 0x25000048, 0x8000b800, 
	0x25bfff98, 0x24bfff88, 0xc000b500, 0x25000048, 0x8800b800, 0x21800058, 
	0x20800048, 0x51207c80, 0x21010010, 0x40207c90, 0x40207d98, 0x25000108, 
	0x8800c000, 0x20800108, 0x51a07c80, 0x21810018, 0x40207c98, 0x20800088, 
	0x59400c02, 0x29bc0010, 0x88060600, 0x51a06d00, 0x258003d8, 0x018000d8, 
	0x8000d900, 0x51a06a80, 0x25800418, 0x8000d900, 0xc0046700, 0x25900008, 
	0x8800d100, 0x25800108, 0x8000d900, 0x25800088, 0x8000d900, 0x24afffc8, 
	0x24bffe08, 0x51a07d80, 0x25bffed8, 0x40207d98, 0x51a07c80, 0x21810018, 
	0x40207c98, 0x51206d00, 0x268003d0, 0x8000e800, 0x51a06d80, 0x40207f98, 
	0x293c0018, 0x8000e800, 0x594010c0, 0x40208310, 0x594014c0, 0x40208390, 
	0x2f00e604, 0xc0058f00, 0x2f00e804, 0xc0059e00, 0x51a06d00, 0x25800c18, 
	0x8800ee00, 0x2d000000, 0x4000c910, 0xc000fb00, 0x2d0000c0, 0x4000c910, 
	0x2d000400, 0x4000c810, 0x2d0011c0, 0x4000ca10, 0x2d000000, 0x4000c810, 
	0x51206a00, 0x31000610, 0x4000ca10, 0x51206a00, 0x4000ca10, 0x52206a80, 
	0x25002020, 0x80012900, 0x59400c02, 0x2abc0010, 0x80011800, 0x51400080, 
	0x26801020, 0x88010700, 0x26800050, 0x80011800, 0xc0010900, 0x25000090, 
	0x80011800, 0x51206d00, 0x26800810, 0x80011100, 0x253fcfe0, 0x4000ca10, 
	0x2c000040, 0x4000c900, 0xc0013000, 0x258003d0, 0x018000d8, 0x88012900, 
	0x25001010, 0x88012900, 0x253fcfe0, 0xc0013000, 0x25c000d8, 0x80012300, 
	0x51206a80, 0x4000ca10, 0x2d000040, 0x4000c910, 0x51206d00, 0x258003d0, 
	0x018000d8, 0x80012900, 0xc0046d00, 0x51206d00, 0x258003d0, 0x80012900, 
	0x018000d8, 0x80012900, 0xc0012900, 0x51206a80, 0x51a06d00, 0x25800c18, 
	0x80013000, 0x4000ca10, 0x2c000040, 0x4000c900, 0x24000c10, 0x80048300, 
	0x50206c80, 0x24000040, 0x80014500, 0x5a401802, 0x26000060, 0x80013a00, 
	0x2f013a04, 0xc0055100, 0x52207700, 0x25804020, 0x80013f00, 0x25803fe0, 
	0xc0014000, 0x2d8011c0, 0x2fc000c0, 0x52206a00, 0x33800620, 0x2fc00100, 
	0x2fc00080, 0x25000810, 0x88014a00, 0x24400000, 0x8801af00, 0xc0018800, 
	0x2d800040, 0x2f014d04, 0xc0052000, 0x2dc00180, 0x24000040, 0x80015100, 
	0x2fc000c0, 0x52a06a80, 0x26800428, 0x88015600, 0x2d802dc0, 0xc0015d00, 
	0x02802dd8, 0x90048300, 0x26c000d8, 0x88015d00, 0x24000040, 0x80018800, 
	0xc001af00, 0x2f015f04, 0xc0052000, 0x2d400180, 0x24000040, 0x80016300, 
	0x2fc00080, 0x01800058, 0x52a07c80, 0x26bfc028, 0x22c000a8, 0x40207ca8, 
	0x26800410, 0x80017e00, 0x02800198, 0x98017e00, 0x32800230, 0x22c001a8, 
	0x40208028, 0x31000230, 0x21400190, 0x40208090, 0x32000230, 0x224001a0, 
	0x40208120, 0x24000040, 0x80017d00, 0x33800628, 0x2fc00140, 0x33800610, 
	0x2fc00080, 0x33800620, 0x2fc00100, 0x01800198, 0x24000040, 0x80018300, 
	0xe04000c0, 0x2fc00180, 0xc001af00, 0xe04000c0, 0x2c400180, 0x52206a80, 
	0x26000420, 0x8001af00, 0x51a06d00, 0x25820018, 0x8801af00, 0x51a06a80, 
	0x25800418, 0x8001af00, 0x51207c80, 0x26820008, 0x88019400, 0x25008010, 
	0x8801a900, 0xc004b700, 0x24002010, 0x80019800, 0x25000410, 0x8001a900, 
	0x50206a80, 0x260003c0, 0x26803c08, 0x32800728, 0x28400160, 0x8801a400, 
	0x25000208, 0x8801a200, 0x20800208, 0xc0039400, 0x24bffdc8, 0xc0046400, 
	0x24bffdc8, 0x12800068, 0x268003e8, 0x28400160, 0x88046400, 0x50206a80, 
	0x260003c0, 0x32000120, 0x24bfc3c8, 0x20c00108, 0x20820008, 0x51a06d80, 
	0x29bc0018, 0x8801bd00, 0x51a07300, 0x29bc0018, 0x80046700, 0x50001000, 
	0x51a07200, 0x21c000c0, 0x2f01ba04, 0xc0052000, 0xe0400000, 0x2dc00180, 
	0xc0039400, 0x50206d00, 0x258003c0, 0x25000c00, 0x8801c300, 0x25c000d8, 
	0x80039400, 0x51206d00, 0x25000c10, 0x8001c800, 0x2e000040, 0x4000c920, 
	0x50001000, 0x51a06d00, 0x258003d8, 0x8801d200, 0x21880000, 0x2f01cf04, 
	0xc0052000, 0xe0400000, 0x2dc00180, 0xc0039400, 0x24400000, 0x80031f00, 
	0x01000058, 0x8001d700, 0xc0039400, 0x59401802, 0x29bc0010, 0x80046700, 
	0x51a07200, 0x21c000c0, 0x2f01de04, 0xc0052000, 0x59c05880, 0x30000618, 
	0x200f0200, 0x52207180, 0x2603ffe0, 0x2a000520, 0x8801e600, 0x20004000, 
	0x40003800, 0x2c000600, 0x2a140018, 0x8801ec00, 0x20010000, 0xc001ee00, 
	0x2c000a00, 0x2000c000, 0x40004100, 0x2c000000, 0x40004180, 0x2c000040, 
	0x40004000, 0x40004080, 0x52a06d84, 0x58402142, 0x5a402542, 0x40206b00, 
	0x40206ba0, 0x2c000000, 0x40001080, 0x2c3fffc0, 0x40003600, 0x2c000000, 
	0x40003c80, 0x40003d80, 0x40004600, 0x40004880, 0x40004800, 0x40004900, 
	0x5ac05880, 0x28140028, 0x80023400, 0x59c04042, 0x58400080, 0x244000c0, 
	0x40003c00, 0x40003d00, 0x59c04442, 0x58400480, 0x244000c0, 0x40003c80, 
	0x40003d80, 0x59c04842, 0x58400880, 0x25c000c0, 0x28100028, 0x88022c00, 
	0x40003d18, 0x59c04c42, 0x58400c80, 0x244000c0, 0x40003d80, 0x59c05042, 
	0x58401080, 0x244000c0, 0x40004600, 0x59c05842, 0x58401880, 0x244000c0, 
	0x40004880, 0x59c05442, 0x58401480, 0x244000c0, 0x40004800, 0x59c05c42, 
	0x58401c80, 0x244000c0, 0x40004900, 0xc0024200, 0x40004618, 0x40004898, 
	0x59c04c42, 0x58400c80, 0x25c000c0, 0x40004818, 0x40004918, 0xc0024200, 
	0x1180080d, 0x12000014, 0x2f023804, 0xc0025700, 0x40003c00, 0x2f023b04, 
	0xc0025700, 0x40003d00, 0x2f023e04, 0xc0025700, 0x40003c80, 0x2f024104, 
	0xc0025700, 0x40003d80, 0x24008008, 0x80027c00, 0x50207c80, 0x24008000, 
	0x80026800, 0x2c400180, 0x59c04480, 0x018000d8, 0x90024e00, 0x11c000c0, 
	0x98025100, 0xc0026800, 0x59c05080, 0x2a4000c0, 0x80026800, 0x24bf7fc8, 
	0x51a06b00, 0x52206b80, 0x40008218, 0x400082a0, 0xc0028000, 0x55c004c2, 
	0x56400502, 0x264000e0, 0x55c004c2, 0x56c00502, 0x26c000e8, 0x240003e0, 
	0x2583c020, 0x31800718, 0x204000c0, 0x258003e8, 0x31800218, 0x204000c0, 
	0x2583c028, 0x31800118, 0x204000c0, 0xc0400182, 0x12800410, 0x2d800240, 
	0x2e003000, 0x54400540, 0x44400500, 0x01800058, 0x88026b00, 0x2d8000c0, 
	0x2e003480, 0x54400540, 0x44400500, 0x01800058, 0x88027100, 0x2d800080, 
	0x2e003700, 0x54400540, 0x44400500, 0x01800058, 0x88027700, 0xc0028f00, 
	0x50207c80, 0x24008000, 0x80048300, 0x2c400180, 0x51801000, 0x01c00018, 
	0x98048300, 0xe0400000, 0x2ec00180, 0x25c000d8, 0x80039400, 0x2c000000, 
	0x40003880, 0x40003700, 0x40003480, 0x40003780, 0x2c3fffc0, 0x40003500, 
	0x40003580, 0x2f029104, 0xc0057300, 0x2c000040, 0x40003880, 0x2f029504, 
	0xc0057a00, 0x24200020, 0x88039400, 0x24001020, 0x8002fa00, 0x24000060, 
	0x8002ea00, 0x240000a0, 0x8002ea00, 0x50003800, 0x24004000, 0x8002c000, 
	0x50003000, 0x25a00000, 0x8802c000, 0x25803fc0, 0x29801cd8, 0x8802c300, 
	0x2f02a804, 0xc005d100, 0x50008200, 0x51808000, 0x004000c0, 0x8802b500, 
	0x50008280, 0x51808080, 0x004000c0, 0x8802b500, 0x50008100, 0x51808180, 
	0x40008200, 0x40008298, 0xc002bd00, 0x50008200, 0x51808280, 0x24400000, 
	0x8802ba00, 0x01800058, 0x00000040, 0x40008200, 0x40008298, 0x2f803fc0, 
	0x2f02c004, 0xc005d100, 0x58401842, 0x24000080, 0x8802c600, 0x50001080, 
	0x40003600, 0xc002ed00, 0x50207c00, 0x20000080, 0x40207c00, 0x50206f80, 
	0x243ffec0, 0x40206f80, 0x50207400, 0x24000080, 0x8802cc00, 0x2c000040, 
	0x40008600, 0x40008680, 0x50008600, 0x29800040, 0x8002d200, 0x51206f80, 
	0x21000110, 0x40206f90, 0x24000080, 0x88047b00, 0x50003600, 0x11000040, 
	0x8802e000, 0x50206b00, 0x51a06b80, 0xc002e700, 0x2d800000, 0x5ac01142, 
	0x59401542, 0x10400140, 0x19c00098, 0x2f02e704, 0xc005f800, 0x40008200, 
	0x40008298, 0xc002fa00, 0x50003600, 0x11000040, 0x8002fa00, 0x50003600, 
	0x2d800000, 0x5ac01142, 0x59401542, 0x10400140, 0x19c00098, 0x2f02f504, 
	0xc005f800, 0x40206b00, 0x40206b98, 0x50206c00, 0x10000040, 0x40206c00, 
	0x24000220, 0x80030200, 0x50001000, 0xe0400000, 0x2d400180, 0x2c000040, 
	0x24bf7fc8, 0xc0032000, 0x24000120, 0x80028700, 0x51003480, 0x010000d0, 
	0x98030a00, 0x50003700, 0x24400000, 0x8002ff00, 0x20808008, 0x5ac01802, 
	0x12800428, 0x2e003000, 0x2c000240, 0x55400500, 0x44400550, 0x00000040, 
	0x88030f00, 0x2e003480, 0x2c0000c0, 0x55400500, 0x44400550, 0x00000040, 
	0x88031500, 0x2e003700, 0x2c000080, 0x55400500, 0x44400550, 0x00000040, 
	0x88031b00, 0x2c000000, 0x2f032204, 0xc005d100, 0x52a06d80, 0x51206d00, 
	0x25018010, 0x80032a00, 0x52008304, 0x52808384, 0x48401961, 0x48401d69, 
	0x25800098, 0x88047b00, 0x51808204, 0x52008280, 0x48401159, 0x48401560, 
	0x24400000, 0x80033400, 0x40206b19, 0x40206ba0, 0x50206d00, 0x24018000, 
	0x80033f00, 0x2e008200, 0x30000700, 0x12c00020, 0x54400500, 0x55400500, 
	0x243ffc00, 0x44400540, 0x44400550, 0x52a06c00, 0x51a06d80, 0x5a4028c0, 
	0x59402cc0, 0x10400160, 0x19000010, 0x40208200, 0x40208290, 0x26c00168, 
	0x80039400, 0x484028c0, 0x48402cd0, 0x52206d00, 0x260003e0, 0x29000060, 
	0x80035300, 0x290000a0, 0x80035300, 0x2e808200, 0xc0035400, 0x2ea06b00, 
	0x56400540, 0x55400540, 0x484020e0, 0x484024d0, 0x5a4038c0, 0x26400120, 
	0x80038200, 0x5a4008c0, 0x32000620, 0x5ac00cc0, 0x32800228, 0x12c00128, 
	0x402b3a28, 0x5a4000c0, 0x32000620, 0x5ac004c0, 0x32800228, 0x12c00128, 
	0x402b3aa8, 0x5a4020c0, 0x32000620, 0x5ac024c0, 0x32800228, 0x12c00128, 
	0x402b3b28, 0x5a4018c0, 0x32000620, 0x5ac01cc0, 0x32800228, 0x12c00128, 
	0x402b3ba8, 0x522b3a00, 0x52ab3a80, 0x02c00160, 0x402b3c28, 0x522b3b00, 
	0x52ab3b80, 0x02c00160, 0x26200028, 0x80037e00, 0x522b3c00, 0x12c00160, 
	0x5a4038c0, 0x02400128, 0x98039400, 0xc0038c00, 0x5a4034c0, 0x02c00100, 
	0x98039400, 0x52a06d00, 0x268003e8, 0x2a8000e8, 0x88038c00, 0x12000120, 
	0x02c00100, 0x90039400, 0x584030c0, 0x26800040, 0x88039400, 0x26800200, 
	0x88039400, 0x50207c00, 0x20001000, 0x40207c00, 0x51801000, 0x51206900, 
	0x01c00098, 0xe04000c0, 0x2c400180, 0x51801000, 0x2f039c04, 0xc0052000, 
	0xe04000c0, 0x2c400180, 0x2f03a004, 0xc005d100, 0x25800098, 0x88048100, 
	0x51207c00, 0x59c03842, 0x21880018, 0x25c00098, 0x40207c18, 0x25336fd0, 
	0x293fffd0, 0x59c03842, 0x25c00098, 0x4840385a, 0x51207c80, 0x59c01402, 
	0x21900018, 0x26c000d0, 0x5a403c42, 0x258000a0, 0x8803b600, 0x52a07c80, 
	0x26900028, 0xc003ca00, 0x51a06d00, 0x258003d8, 0x298000d8, 0x8803c700, 
	0x51a06c80, 0x25800118, 0x8803ca00, 0x25800060, 0x8003ca00, 0x22820028, 
	0x51207d80, 0x25000110, 0x8003c400, 0x22810028, 0x263fffa0, 0x48403c62, 
	0xc003ca00, 0x51a07300, 0x293c0018, 0x8803ba00, 0x59406042, 0x40207e10, 
	0x59c06442, 0x40207e98, 0x5a406842, 0x40207f20, 0x51207c00, 0x40207ca8, 
	0x22c000a8, 0x80040a00, 0x2daace00, 0x2f03d704, 0xc0058f00, 0x52a06c80, 
	0x26800128, 0x8003dd00, 0x52a07c80, 0x26a3bfe8, 0x40207ca8, 0x2c000000, 
	0x4000a100, 0x4000a180, 0x2ea07c00, 0x2d800d00, 0x56400540, 0x27803fe0, 
	0x33800620, 0x01800098, 0x8803e200, 0x26080010, 0x8003f700, 0x51a07084, 
	0x24000040, 0x01c0001d, 0x2d800040, 0x4000cb18, 0x4000cc19, 0x2d801e00, 
	0x11c00018, 0x4000c018, 0x40001018, 0xe0400000, 0x2f400184, 0xe0001e00, 
	0x2fc00180, 0x2f03f904, 0xc005d100, 0x25800098, 0x80040000, 0x2f03fd04, 
	0xc005ad00, 0x2d800080, 0x40005018, 0xc0041000, 0x51808200, 0x51008280, 
	0x402ad018, 0x402ad090, 0x51aad000, 0x512ad100, 0x29c00098, 0x80040a00, 
	0x2d800040, 0x40005018, 0x51a06c80, 0x25800218, 0x88001900, 0x51a06d00, 
	0x25804018, 0x88001900, 0x4840000a, 0xc0001900, 0x2c000000, 0x4000cb00, 
	0x2c000200, 0x4000c000, 0x2dc00184, 0x30000230, 0x21c0001d, 0x2e400184, 
	0x30000230, 0x22400025, 0x2ec00184, 0x30000230, 0x22c0002d, 0x2dc00180, 
	0x30000230, 0x21c00018, 0x2e000140, 0x2caad204, 0x58c01c42, 0x2403ffc8, 
	0x284000c0, 0x80042c00, 0x1080140d, 0x02000060, 0x88042400, 0xc0001900, 
	0x24200008, 0x80043100, 0x4840606b, 0x48406463, 0x4840685b, 0x2d800040, 
	0x2f043404, 0xc0052000, 0x2d400180, 0xc0005a00, 0x2c000100, 0x40005000, 
	0x58403042, 0x25800c00, 0x80001900, 0x2c000400, 0x4000c800, 0x2c0000c0, 
	0x4000c900, 0x2c0011c0, 0x4000ca00, 0x2c000000, 0x4000c800, 0x50206a00, 
	0x31000600, 0x4000ca10, 0x4000ca00, 0x2c000040, 0x4000c900, 0x2c002e40, 
	0x59401842, 0x25000410, 0x88044e00, 0x2c002000, 0x4000c000, 0xe0400000, 
	0x2c400180, 0xc0001900, 0x51a06d00, 0x25802018, 0x80046400, 0x51a06d80, 
	0x2a3c0018, 0x80046400, 0x5ac030c0, 0x268003a8, 0x2a800028, 0x88046400, 
	0x2f045e04, 0xc0058f00, 0x2f802d00, 0x2f800000, 0x2f800000, 0x2f800040, 
	0x2f802d00, 0xc0048700, 0x24bdffc8, 0x2e800400, 0xc0048400, 0x2e900000, 
	0xc0048400, 0x2e800080, 0xc0048400, 0x2e800100, 0xc0048400, 0x59400c02, 
	0x2abc0010, 0x80046700, 0x2e800100, 0xc0048400, 0x2e802000, 0xc0048400, 
	0x2a000128, 0x80048300, 0x2a000328, 0x80048300, 0x2a000228, 0x80048300, 
	0xc0039400, 0x51a07c00, 0x21a00018, 0x40207c18, 0x51a07c80, 0x25bfbfd8, 
	0x40207c98, 0x2f048704, 0xc005ad00, 0x2e800200, 0x51a07c00, 0x21c00158, 
	0x40207c18, 0x2f048904, 0xc005d100, 0x25800098, 0x80049e00, 0x51a07c00, 
	0x21a00018, 0x40207c18, 0x51a06d00, 0x25818018, 0x80049c00, 0x2e008200, 
	0x31800718, 0x12c000e0, 0x55c00540, 0x55400540, 0x52206d80, 0x12000220, 
	0x44400518, 0x44400510, 0x44400518, 0x44400510, 0x2f049e04, 0xc005ad00, 
	0x50206d00, 0x240003c0, 0x01800040, 0x8004ab00, 0x01800080, 0x8004b600, 
	0x59c01802, 0x293c0018, 0x8004b700, 0x594054c0, 0x253fdfd0, 0x484054d0, 
	0xc004b700, 0x50008700, 0x2d800040, 0x40009718, 0x40009798, 0x51809700, 
	0x25800058, 0x8804af00, 0x40008700, 0x40008780, 0x24bf7fc8, 0xc004b700, 
	0x24be7fc8, 0x2f04b904, 0xc005e800, 0x51207c80, 0x25008010, 0x80039400, 
	0x51207c00, 0x29000410, 0x88039400, 0x51001000, 0x25400090, 0x80039400, 
	0x58401842, 0x24000400, 0x8801a900, 0xc0039400, 0x2e3c0000, 0x40206da0, 
	0x40207320, 0x512ad580, 0x2503ffd0, 0x29002010, 0x8004d000, 0x59401c42, 
	0x25200010, 0x8804d700, 0x52005200, 0x51005280, 0x52805300, 0x26a07fe8, 
	0x48406062, 0x48406452, 0x4840686a, 0x59402442, 0x25000090, 0x8004dc00, 
	0x2c3fffc0, 0x2cbfffc0, 0x59401042, 0x40002010, 0x59401442, 0x40002090, 
	0x40002188, 0x2d000040, 0x40002110, 0x51002100, 0x25400090, 0x8804e300, 
	0x51002200, 0x24a00010, 0x88051400, 0x58401046, 0x00200005, 0x300007c5, 
	0x10400085, 0x30800201, 0x40207d08, 0x30800101, 0x30000085, 0x10400045, 
	0x10208905, 0x58c00402, 0x10800048, 0x4840040a, 0x5ac01002, 0x24bfc028, 
	0x2a3fc008, 0x8004fd00, 0x32000748, 0x12226920, 0x40207320, 0x24803fe8, 
	0x2a003fc8, 0x80050300, 0x32000148, 0x12226920, 0x40206da0, 0x58c03100, 
	0x40206f08, 0x58c00802, 0x40206d08, 0x2e000000, 0x248003c8, 0x288000c8, 
	0x88051200, 0x52206a00, 0x5ac01c02, 0x26400020, 0x22400160, 0x40206a20, 
	0x2e000040, 0x40206ca0, 0x58c00002, 0xc0400182, 0x2cbfffc0, 0x40207d08, 
	0x51207600, 0x50a07680, 0x2c3fffc0, 0x00afbbc8, 0x8004e900, 0x58c03042, 
	0x24000c0c, 0x88043b00, 0xc0001900, 0xc0400182, 0x40206808, 0x2483ffd8, 
	0x80054600, 0x50a06c80, 0x24804008, 0x88054600, 0x40206798, 0x40206890, 
	0x2c800080, 0x4000cb08, 0x25080018, 0x88053400, 0x59401842, 0x25000410, 
	0x80053400, 0x51206d00, 0x250003d0, 0x29000050, 0x80053400, 0x21900018, 
	0x51206700, 0x10800090, 0x40206708, 0x10a06210, 0x51206180, 0x4000cc10, 
	0x4000c018, 0x40400058, 0x2583ffd8, 0x50801000, 0x00c000c8, 0x40206908, 
	0x24800058, 0x11c00058, 0x114000d0, 0x40206190, 0x51206880, 0x51a06780, 
	0x50a06800, 0xc0400182, 0x56c00504, 0x4440052b, 0x56c00504, 0x4440052b, 
	0x56c00504, 0x4440052b, 0x56c00504, 0x4440052b, 0xc0400182, 0x5a406846, 
	0x320005e5, 0x5ac06446, 0x328001e9, 0x22400165, 0x328005ed, 0x5ac06042, 
	0x328001e8, 0x22c0016d, 0x2e804b00, 0x2d000004, 0x2d800004, 0x26000068, 
	0x80056100, 0x11400117, 0x19c0015f, 0x3280006d, 0x26200021, 0x80056500, 
	0x2280006d, 0x32000065, 0x328007e8, 0x88055d00, 0x5a406842, 0x26007fe0, 
	0x11400115, 0x1980001d, 0x32000619, 0x2fc00100, 0x2fc000c2, 0x32000611, 
	0x2fc00100, 0x2fc00082, 0xc0400182, 0x52207400, 0x26000060, 0x88057300, 
	0x52206f80, 0x263fffa0, 0x40206fa0, 0xc0400182, 0x52207780, 0x52003884, 
	0x26000065, 0x80058a00, 0x02000060, 0x88057b00, 0x52004c04, 0x402d7fa1, 
	0x2e000004, 0x400038a1, 0x52207004, 0x12000065, 0x0a000025, 0x40207021, 
	0x52200000, 0xc0058b00, 0x52003780, 0x52206f84, 0x22000065, 0x40206fa1, 
	0xc0400182, 0x2e008000, 0x2e800200, 0x554004c4, 0x44400511, 0x02800068, 
	0x88059100, 0x2d800000, 0x52008000, 0x52808300, 0x2a400160, 0x88059b00, 
	0x2d800040, 0x40008418, 0x40008498, 0xc0400182, 0x50206d00, 0x24018000, 
	0x8005ac00, 0x2e008300, 0x30000700, 0x12c00020, 0x55c00540, 0x54400540, 
	0x44400518, 0x44400500, 0x52a06d80, 0x12800328, 0x44400558, 0x44400540, 
	0xc0400182, 0x2d800380, 0x40008718, 0x40008798, 0x51207500, 0x51a07580, 
	0x40008210, 0x40008298, 0x40008098, 0x40008398, 0x2d800000, 0x40008118, 
	0x40008198, 0x51a06f80, 0x25bffed8, 0x40206f98, 0x51a07400, 0x25800098, 
	0x8805bc00, 0x2d8001c0, 0x40008618, 0x40008698, 0x2d8003c0, 0x40008718, 
	0x40008798, 0x51808600, 0x25000058, 0x8805c500, 0x51206f80, 0x21000110, 
	0x40206f90, 0x2d000100, 0x40008610, 0x40008690, 0x25800098, 0x8805ad00, 
	0xc0400182, 0x51a06f80, 0x25bffed8, 0x40206f98, 0x51a07400, 0x25800098, 
	0x8805d400, 0x2d8001c0, 0x40008618, 0x40008698, 0x2e3fffc0, 0x02000060, 
	0x8005e100, 0x51808600, 0x29000058, 0x253ffed0, 0x8005db00, 0x52206f80, 
	0x22000120, 0x40206fa0, 0x2e000100, 0x40008620, 0x400086a0, 0xc0400182, 
	0x51a06f00, 0x25800818, 0x8005f700, 0x51a06d80, 0x293c0018, 0x8005f700, 
	0x51206d00, 0x25018010, 0x8805f700, 0x594020c0, 0x584024c0, 0x484010d0, 
	0x40008210, 0x484014c0, 0x40008280, 0xc0400182, 0x5ac00942, 0x59400d42, 
	0x26bffc28, 0x12800428, 0x19000010, 0x02c00140, 0x09400098, 0x98060500, 
	0x58400142, 0x59c00542, 0x10400140, 0x19c00098, 0xc005f800, 0xc0400182, 
	0x51a06a80, 0x25800c18, 0x29800818, 0x8006ad00, 0x51c00080, 0x25c000d8, 
	0x80046b00, 0x263c0018, 0x32000520, 0x25801c18, 0x28001818, 0x88061300, 
	0x2d800400, 0x318007d8, 0x21c000e0, 0x40044018, 0x59c00480, 0x24000058, 
	0x40046080, 0x24000198, 0x300007c0, 0x40046400, 0x2c400100, 0x2a000120, 
	0x88062900, 0x2e203000, 0x2e044c04, 0x2f062304, 0xc0054800, 0x2f062504, 
	0xc0054800, 0x2f062704, 0xc0054800, 0x2f062904, 0xc0054800, 0x26800048, 
	0x80063000, 0x51c00080, 0x25800098, 0x80046d00, 0x12000310, 0xc0063400, 
	0x51c00080, 0x25800058, 0x80046d00, 0x12000110, 0x2e044404, 0x2f063704, 
	0xc0054800, 0x52040204, 0x26000065, 0x80063c00, 0x40040221, 0xc0046d00, 
	0x12000220, 0x2e044a04, 0x2f064004, 0xc0054800, 0x2c080000, 0x40207200, 
	0x50046100, 0x243f83c0, 0x51c00080, 0x25802018, 0x80064800, 0x20001800, 
	0x59c00480, 0x25801c18, 0x204000c0, 0x40046100, 0x58401842, 0x24000400, 
	0x88065300, 0x2e002080, 0x2e800080, 0x40046028, 0xc0066f00, 0x2e002f00, 
	0x50206a80, 0x24000800, 0x80066600, 0x2d800040, 0x2f065a04, 0xc0052000, 
	0x2ec00080, 0x2d400180, 0x11800150, 0x50400140, 0x24000100, 0x80066300, 
	0x118004d8, 0x25bffc18, 0x01800118, 0x40046018, 0x2e800140, 0xc0066f00, 
	0x50400080, 0x24000100, 0x80066d00, 0x2e800300, 0x40046028, 0x2e800100, 
	0xc0066f00, 0x2e800100, 0x40046028, 0x2c000000, 0x40206700, 0x2e206204, 
	0xe0000100, 0x44400502, 0x2c203000, 0x40206180, 0x50046100, 0x243ffdc0, 
	0x40046100, 0x400461a0, 0x2c000c00, 0x4000cf00, 0x2c000040, 0x4000cd00, 
	0x21880028, 0x2f068104, 0xc0052000, 0x2e050004, 0x000020a0, 0x80068800, 
	0x50207080, 0x20400102, 0x4000ce00, 0x2e000004, 0x51a07180, 0x30000618, 
	0x20400102, 0x4000ce00, 0x24003fd8, 0x4000ce00, 0x01c00160, 0x000020a0, 
	0x80069700, 0x50206a80, 0x4000ce00, 0x24000800, 0x80069700, 0x4000ce10, 
	0x02800068, 0xe0000780, 0x24400000, 0x2c001a00, 0x4000cf00, 0x2c000000, 
	0x4000cd00, 0x40001018, 0x21880018, 0x2f06a104, 0xc0052000, 0x40001020, 
	0xe0400140, 0x2c400180, 0x50206c80, 0x20004000, 0x40206c80, 0x58402402, 
	0x24008000, 0x8006ad00, 0x40206220, 0x2c000000, 0x40206280, 0xc000d900 };

#ifdef ST_OSLINUX

#ifndef __KERNEL__
#  define __KERNEL__
#endif
#ifndef MODULE
#  define MODULE
#endif
#include <linux/module.h>

#endif  /* ST_OSLINUX */

#include "stddefs.h"
#include "../stpti/pti4/tcdefs.h"
#include "../stpti/stptiint.h"

#if !defined( ST_OSLINUX )
#include "stsys.h"
#endif  /* ST_OSLINUX */


#if ((0XAD04-0X8000) > 0X3800)
#error TCCODE data ram overflow
#endif

#if (TRANSPORT_CONTROLLER_CODE_SIZE > 0X1000)
#error TCCODE instruction ram overflow
#endif


ST_ErrorCode_t STPTI_DVBTCLoaderBSLSL2(STPTI_DevicePtr_t CodeStart, void * Params_p)
{
    U32 PTI4_Base = (U32)((U32)CodeStart - 0XC000); 

    STPTI_TCParameters_t * TC_Params_p = Params_p;

    /* Check that the user is using the correct loader for the correct architecture */
    #if defined( TC_PTI4_SECURELITE ) 
        #if !defined( STPTI_ARCHITECTURE_PTI4_SECURE_LITE )
            return( STPTI_ERROR_INVALID_LOADER_OPTIONS );
        #endif

    #elif defined( TC_PTI4_LITE ) 
        #if !defined( STPTI_ARCHITECTURE_PTI4_LITE )
            return( STPTI_ERROR_INVALID_LOADER_OPTIONS );
        #endif

    #else  /* PTI4 */
        #if !defined( STPTI_ARCHITECTURE_PTI4 )
            return( STPTI_ERROR_INVALID_LOADER_OPTIONS );
        #endif
    #endif

    TC_Params_p->TC_CodeStart                  = (STPTI_DevicePtr_t)VERSION;
    TC_Params_p->TC_CodeStart                  = CodeStart;
    TC_Params_p->TC_CodeSize                   = TRANSPORT_CONTROLLER_CODE_SIZE * sizeof(U32);
    TC_Params_p->TC_DataStart                  = (U32*)(((U32)PTI4_Base) + 0X8000);

    TC_Params_p->TC_LookupTableStart           = (U32*)(((U32)PTI4_Base) + 0X8000);
    TC_Params_p->TC_SystemKeyStart             = (U32*)(((U32)PTI4_Base) + 0X80C0);
    TC_Params_p->TC_GlobalDataStart            = (U32*)(((U32)PTI4_Base) + 0X81A8);
    TC_Params_p->TC_StatusBlockStart           = (U32*)(((U32)PTI4_Base) + 0X81F0);
    TC_Params_p->TC_MainInfoStart              = (U32*)(((U32)PTI4_Base) + 0X8224);
    TC_Params_p->TC_DMAConfigStart             = (U32*)(((U32)PTI4_Base) + 0X89A4);
    TC_Params_p->TC_DescramblerKeysStart       = (U32*)(((U32)PTI4_Base) + 0X9084);
    TC_Params_p->TC_TransportFilterStart       = (U32*)(((U32)PTI4_Base) + 0X9278);
    TC_Params_p->TC_SCDFilterTableStart        = (U32*)(((U32)PTI4_Base) + 0X9278);
    TC_Params_p->TC_PESFilterStart             = (U32*)(((U32)PTI4_Base) + 0X9338);
    TC_Params_p->TC_SubstituteDataStart        = (U32*)(((U32)PTI4_Base) + 0X81A8);
    TC_Params_p->TC_SFStatusStart              = (U32*)(((U32)PTI4_Base) + 0X9338);
    TC_Params_p->TC_InterruptDMAConfigStart    = (U32*)(((U32)PTI4_Base) + 0XAB38);
    TC_Params_p->TC_SessionDataStart           = (U32*)(((U32)PTI4_Base) + 0XAB48);
    TC_Params_p->TC_EMMStart                   = (U32*)(((U32)PTI4_Base) + 0XACD8);
    TC_Params_p->TC_ECMStart                   = (U32*)(((U32)PTI4_Base) + 0XACD8);
    TC_Params_p->TC_VersionID                  = (U32*)(((U32)PTI4_Base) + 0XACF8);

    TC_Params_p->TC_NumberCarousels            = 0X0000;
    TC_Params_p->TC_NumberSystemKeys           = 0X0000;
    TC_Params_p->TC_NumberDMAs                 = 0X0037;
    TC_Params_p->TC_NumberDescramblerKeys      = 0X0019;
    TC_Params_p->TC_SizeOfDescramblerKeys      = 0X0014;
    TC_Params_p->TC_NumberPesFilters           = 0X0000;
    TC_Params_p->TC_NumberSectionFilters       = 0X0080;
    TC_Params_p->TC_NumberSlots                = 0X0060;
    TC_Params_p->TC_NumberOfSessions           = 0X0005;
    TC_Params_p->TC_NumberIndexs               = 0X0060;
    TC_Params_p->TC_NumberTransportFilters     = 0X0000;
    TC_Params_p->TC_NumberSCDFilters           = 0X0018;

    TC_Params_p->TC_SignalEveryTransportPacket = 0X0001;
    TC_Params_p->TC_NumberEMMFilters           = 0X0000;
    TC_Params_p->TC_NumberECMFilters           = 0X0060;
    TC_Params_p->TC_AutomaticSectionFiltering  = FALSE;


    {
        U32 i;
        STPTI_DevicePtr_t DataStart = (U32*)(((U32)CodeStart&0xffff0000) | 0X8000);

        for(i = 0; i < (0X3800/4); ++i)
        {
            STSYS_WriteRegDev32LE( (U32)&DataStart[i], 0x00 );
        }

        for(i = 0; i < 0X1000; ++i)
        {
            STSYS_WriteRegDev32LE( (U32)&CodeStart[i], 0x00 );
        }

        for(i = 0; i < TRANSPORT_CONTROLLER_CODE_SIZE; ++i)
        {
            STSYS_WriteRegDev32LE( (U32)&CodeStart[i], transport_controller_code[i] );
        }
        
        STSYS_WriteRegDev32LE( (U32)&(TC_Params_p->TC_VersionID[0]), 0X5354 | (0X5054<<16) );
        STSYS_WriteRegDev32LE( (U32)&(TC_Params_p->TC_VersionID[1]), 0X4934 | (0X0017<<16) );
        STSYS_WriteRegDev32LE( (U32)&(TC_Params_p->TC_VersionID[2]), 0X84D0 | (0X0000<<16) );
    }

    return ST_NO_ERROR;

}
