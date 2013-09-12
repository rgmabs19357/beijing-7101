/************************************************************************
COPYRIGHT (C) ST Microelectronics (R&D) 2008
All rights reserved.

Author :           Automatically generated file

Contains the transport controller code packed as a word array

************************************************************************/

#define TC_ID 0
#define TC_DVB 1
#define TC_CAROUSEL_SUPPORT 1
#define TC_TSDEBUG_SUPPORT 1
#define TC_PROFILING 1

#define TRANSPORT_CONTROLLER_CODE_SIZE      1920

static char const VERSION[] = "\nTC Version STPTI_DVBTCLoader \n\tRel: 427216. File: DVBTC4 Version: 0\n \n\tRel: 427216. File: TCINIT Version: 0\n \n\tRel: 427216. File: TS_HEADER Version: 0\n \n\tRel: 427216. File: SETUPDMA Version: 0\n \n\tRel: 427216. File: AF_ALTOUT Version: 0\n \n\tRel: 427216. File: AF_PROC Version: 0\n \n\tRel: 427216. File: CC_PROC Version: 0\n \n\tRel: 427216. File: SLT_SWIT Version: 0\n \n\tRel: 427216. File: RAW_PROC Version: 0\n \n\tRel: 427216. File: PES_PROC Version: 0\n \n\tRel: 427216. File: CAR_PROC Version: 0\n \n\tRel: 427216. File: STDCAM_PROC Version: 0\n \n\tRel: 427216. File: DMA_UNLD Version: 0\n \n\tRel: 427216. File: SIG_DEC Version: 0\n \n\tRel: 427216. File: STAT_BLK Version: 0\n \n\tRel: 427216. File: STREAMID Version: 0\n \n\tRel: 427216. File: ERR_PROC Version: 0\n \n\tRel: 427216. File: COMMON Version: 0\n \n\tRel: 427216. File: TCDMA Version: 0\n \n\tRel: 427216. File: SET_SCRAM Version: 0\n";


#define TRANSPORT_CONTROLLER_VERSION    2


static const unsigned int transport_controller_code[] = {
	0x2c000040, 0x40003f80, 0x40009f00, 0x2fa67004, 0x2c8001c0, 0x4020a088, 
	0x2c800000, 0x40002108, 0x40003888, 0x4020a388, 0x2d200000, 0x40002010, 
	0x2d001800, 0x40002090, 0x2c000000, 0x4000cb00, 0x4000c100, 0x50003880, 
	0x50802100, 0x5100c100, 0x20400040, 0x20400080, 0x88001100, 0x2c000000, 
	0x4000cb00, 0x2c000040, 0x4000c100, 0x40008600, 0x40008680, 0x2c000000, 
	0x4020a200, 0x4020a300, 0x2e20ad00, 0xe0000100, 0x44400500, 0x120001a0, 
	0xe0000240, 0x44400500, 0x40209d00, 0x40209d80, 0x4000c900, 0x40206700, 
	0x2ca06200, 0xe0000280, 0x44400440, 0x2c800000, 0x10800048, 0x08800008, 
	0x5000c100, 0x24400000, 0x88002e00, 0x5020a380, 0x00800048, 0x88003a00, 
	0x10000040, 0x00800400, 0x98004100, 0x2c0003c0, 0x30000040, 0x10266500, 
	0x50c00000, 0x10800048, 0x08800008, 0x40400008, 0x2c000000, 0x4020a380, 
	0x50a09f00, 0x50209f80, 0x10800048, 0x18000000, 0x40209f08, 0x40209f80, 
	0x51a0a904, 0x25c000db, 0x80006200, 0x2f004d04, 0xc006e500, 0x51a0a980, 
	0x2f005004, 0xc006b300, 0xe04000c0, 0x2fc00180, 0x2f005404, 0xc0072700, 
	0x25800098, 0x80005b00, 0x2f005804, 0xc0070300, 0x2d800000, 0x4020a918, 
	0xc0001700, 0x51808200, 0x52808280, 0x484010da, 0x484014ea, 0x484020da, 
	0x484024ea, 0xc0001700, 0x2c203000, 0x40206180, 0x2ca63504, 0x50a63880, 
	0x2483ffc8, 0x00002008, 0x80007700, 0x51a0a800, 0x24004018, 0x80059900, 
	0x25003fd8, 0x2d8000c0, 0x2ca63504, 0x58c01c42, 0x2403ffc8, 0x28400080, 
	0x80007700, 0x1080100d, 0x01800058, 0x88006f00, 0xc0059900, 0x2d800040, 
	0x2f007a04, 0xc006b300, 0x2d400180, 0x4020a190, 0x2e002e80, 0x5ac01842, 
	0x26800428, 0x88008100, 0x2e002040, 0x58405c42, 0x24400000, 0x80008e00, 
	0x50a0a800, 0x25804008, 0x80008a00, 0x24803fc8, 0x01c00050, 0x80008e00, 
	0x26c00168, 0x80008e00, 0x298011d0, 0x88001700, 0x10c00100, 0x40001008, 
	0x11800040, 0x2f009304, 0xc006b300, 0xe0400000, 0x2d400180, 0x31000210, 
	0x21400190, 0x40209b10, 0x4020a290, 0x58400042, 0x10000040, 0x48400042, 
	0x26800428, 0x88009f00, 0xc0001700, 0x2c380000, 0x2487ffd0, 0x2f00a304, 
	0xc0064a00, 0x51209b00, 0x24200010, 0x8805ba00, 0x51a09e00, 0x258003d8, 
	0x01800058, 0x8800b000, 0x2d801100, 0x40003798, 0x2d800040, 0x40003898, 
	0x2d800000, 0x40003898, 0x2d800040, 0x2f00b304, 0xc006b300, 0x24100010, 
	0x8000b800, 0x5020ad80, 0x20008000, 0x4020ad80, 0x52209d80, 0x24000220, 
	0x8800c200, 0x50209e00, 0x24004000, 0x8000c700, 0x22000220, 0x40209da0, 
	0x26000060, 0x8800c700, 0x2d400180, 0x51209e80, 0x293c0010, 0x80037600, 
	0xc000c900, 0x2c400180, 0x40209b80, 0x2d800000, 0x4020a318, 0x50209e00, 
	0x258003c0, 0x25000c00, 0x8800d100, 0x25c000d8, 0x80010800, 0x25801000, 
	0x8800fa00, 0x50209b80, 0x25002000, 0x8000fa00, 0x24afffc8, 0x51a0ae80, 
	0x21800118, 0x24001000, 0x8800e000, 0x25000048, 0x8000e700, 0x25bfff98, 
	0x24bfff88, 0xc000e400, 0x25000048, 0x8800e700, 0x21800058, 0x20800048, 
	0x5120ad80, 0x21010010, 0x4020ad90, 0x4020ae98, 0x25000108, 0x8800ef00, 
	0x20800108, 0x51a0ad80, 0x21810018, 0x4020ad98, 0x20800088, 0x59400c02, 
	0x29bc0010, 0x88074e00, 0x51a09e00, 0x258003d8, 0x018000d8, 0x80010800, 
	0x51a09b80, 0x25800418, 0x80010800, 0xc005eb00, 0x25900008, 0x88010000, 
	0x25800108, 0x80010800, 0x25800088, 0x80010800, 0x24afffc8, 0x24bffe08, 
	0x51a0ae80, 0x25bffed8, 0x4020ae98, 0x51a0ad80, 0x21810018, 0x4020ad98, 
	0x51209d80, 0x26800210, 0x88010e00, 0x51209e00, 0x268003d0, 0x80011a00, 
	0x51a09e80, 0x4020b098, 0x293c0018, 0x80011a00, 0x594010c0, 0x4020b410, 
	0x594014c0, 0x4020b490, 0x2f011804, 0xc006e500, 0x2f011a04, 0xc006f400, 
	0x51209d80, 0x25800210, 0x80011f00, 0x25800050, 0x80037600, 0x51a09e00, 
	0x25800c18, 0x88012500, 0x2d000000, 0x4000c910, 0xc0013200, 0x2d0000c0, 
	0x4000c910, 0x2d000400, 0x4000c810, 0x2d0011c0, 0x4000ca10, 0x2d000000, 
	0x4000c810, 0x51209b00, 0x31000610, 0x4000ca10, 0x51209b00, 0x4000ca10, 
	0x52209b80, 0x25002020, 0x80016000, 0x59400c02, 0x2abc0010, 0x80014f00, 
	0x51400080, 0x26801020, 0x88013e00, 0x26800050, 0x80014f00, 0xc0014000, 
	0x25000090, 0x80014f00, 0x51209e00, 0x26800810, 0x80014800, 0x253fcfe0, 
	0x4000ca10, 0x2c000040, 0x4000c900, 0xc0016700, 0x258003d0, 0x018000d8, 
	0x88016000, 0x25001010, 0x88016000, 0x253fcfe0, 0xc0016700, 0x25c000d8, 
	0x80015a00, 0x51209b80, 0x4000ca10, 0x2d000040, 0x4000c910, 0x51209e00, 
	0x258003d0, 0x018000d8, 0x80016000, 0xc005f100, 0x51209e00, 0x258003d0, 
	0x80016000, 0x018000d8, 0x80016000, 0xc0016000, 0x51209b80, 0x51a09e00, 
	0x25800c18, 0x80016700, 0x4000ca10, 0x2c000040, 0x4000c900, 0x24000c10, 
	0x80060700, 0x50209d80, 0x24000040, 0x80017c00, 0x5220a800, 0x25804020, 
	0x80017100, 0x25803fe0, 0xc0017200, 0x2d8011c0, 0x2fc000c0, 0x5a401802, 
	0x260000a0, 0x80017800, 0x2f017804, 0xc006d700, 0x52209b00, 0x33800620, 
	0x2fc00100, 0x2fc00080, 0x25000810, 0x88018100, 0x24400000, 0x8801e600, 
	0xc001bf00, 0x2d800040, 0x2f018404, 0xc006b300, 0x2dc00180, 0x24000040, 
	0x80018800, 0x2fc000c0, 0x52a09b80, 0x26800428, 0x88018d00, 0x2d802dc0, 
	0xc0019400, 0x02802dd8, 0x90060700, 0x26c000d8, 0x88019400, 0x24000040, 
	0x8001bf00, 0xc001e600, 0x2f019604, 0xc006b300, 0x2d400180, 0x24000040, 
	0x80019a00, 0x2fc00080, 0x01800058, 0x52a0ad80, 0x26bfc028, 0x22c000a8, 
	0x4020ada8, 0x26800410, 0x8001b500, 0x02800198, 0x9801b500, 0x32800230, 
	0x22c001a8, 0x4020b128, 0x31000230, 0x21400190, 0x4020b190, 0x32000230, 
	0x224001a0, 0x4020b220, 0x24000040, 0x8001b400, 0x33800628, 0x2fc00140, 
	0x33800610, 0x2fc00080, 0x33800620, 0x2fc00100, 0x01800198, 0x24000040, 
	0x8001ba00, 0xe04000c0, 0x2fc00180, 0xc001e600, 0xe04000c0, 0x2c400180, 
	0x52209b80, 0x26000420, 0x8001e600, 0x51a09e00, 0x25820018, 0x8801e600, 
	0x51a09b80, 0x25800418, 0x8001e600, 0x5120ad80, 0x26820008, 0x8801cb00, 
	0x25008010, 0x8801e000, 0xc0063b00, 0x24002010, 0x8001cf00, 0x25000410, 
	0x8001e000, 0x50209b80, 0x260003c0, 0x26803c08, 0x32800728, 0x28400160, 
	0x8801db00, 0x25000208, 0x8801d900, 0x20800208, 0xc0052100, 0x24bffdc8, 
	0xc005e800, 0x24bffdc8, 0x12800068, 0x268003e8, 0x28400160, 0x8805e800, 
	0x50209b80, 0x260003c0, 0x32000120, 0x24bfc3c8, 0x20c00108, 0x20820008, 
	0x51a09e80, 0x29bc0018, 0x8801ed00, 0x51a0a400, 0x29bc0018, 0x8005eb00, 
	0xc0052100, 0x50209e00, 0x258003c0, 0x25000c00, 0x8801f300, 0x25c000d8, 
	0x80052100, 0x51209e00, 0x25000c10, 0x8001f800, 0x2e000040, 0x4000c920, 
	0x50001000, 0x51a09e00, 0x258003d8, 0x88020200, 0x21880000, 0x2f01ff04, 
	0xc006b300, 0xe0400000, 0x2dc00180, 0xc0052100, 0x010000d8, 0x80020b00, 
	0x24400000, 0x8004d600, 0x01000098, 0x80021700, 0x01000058, 0x8003cb00, 
	0xc0052100, 0x51a0a300, 0x21c000c0, 0x2f020f04, 0xc006b300, 0xe0400000, 
	0x2fc00180, 0x2d800040, 0x40209d18, 0x51a09d80, 0x25800218, 0x88037600, 
	0xc004d600, 0x51008204, 0x250000d5, 0x268000c0, 0x114000ae, 0x250000d5, 
	0x52a0ad80, 0x24008028, 0x80024400, 0x25018008, 0x01818010, 0x80022b00, 
	0x01810010, 0x98024f00, 0x51a0ad00, 0x21802018, 0x4020ad18, 0x24be7fc8, 
	0x2f022a04, 0xc0073e00, 0xc0024f00, 0x51a0a000, 0x52a09e80, 0x25000418, 
	0x88023900, 0x59c02140, 0x59402540, 0x2fc000c0, 0x33800618, 0x2fc00080, 
	0x33800610, 0x2f023704, 0xc0072700, 0x25800098, 0x8805ff00, 0x2d800040, 
	0x40209d18, 0x51008200, 0x50008280, 0x40209c10, 0x40209c80, 0x48402150, 
	0x48402540, 0x40008210, 0x40008280, 0xc0024f00, 0x24018008, 0x80052100, 
	0x2e000000, 0x2f024904, 0xc0036b00, 0x2e800000, 0x01018000, 0x80030600, 
	0x01010000, 0x80030600, 0xc002d700, 0x52801000, 0x01000268, 0x90025600, 
	0x2dc00140, 0x2f025504, 0xc006b300, 0xc005f600, 0x2e001000, 0x2f025904, 
	0xc0036b00, 0x258001c8, 0x25800098, 0x88025f00, 0x2e800240, 0x2c400140, 
	0xc0026100, 0x5020a300, 0x20400140, 0x2dc00000, 0x2f026404, 0xc006b300, 
	0x028000a8, 0x30000230, 0x20400180, 0x8805f600, 0x02800068, 0x2c400180, 
	0x00000040, 0x8805f600, 0x2f800000, 0x2f800000, 0x2f800040, 0x02800068, 
	0x2c400180, 0x48402002, 0x2fc00000, 0x59c01802, 0x25004018, 0x80027900, 
	0x25803fd8, 0x29c00018, 0x8805f600, 0x028000a8, 0x31000230, 0x21400190, 
	0x48401c12, 0x25400090, 0x80028300, 0x98028300, 0x51801000, 0x01c000d0, 
	0x9805f600, 0x33800610, 0x2fc00080, 0x29802f00, 0x80029500, 0x29802fc0, 
	0x80029500, 0x29803c00, 0x80029500, 0x29803c40, 0x80029500, 0x29803fc0, 
	0x80029500, 0x29803c80, 0x80029500, 0x29803e00, 0x80029500, 0x29802f80, 
	0x8802a100, 0xe0400140, 0x2fc00180, 0x2e800000, 0x253e7fc8, 0x20818010, 
	0x59c01c02, 0x01800298, 0x48401c1a, 0x50001000, 0x24400000, 0x80035100, 
	0xc0032700, 0x2c400180, 0x02800068, 0x25800800, 0x8002c100, 0x51a09e00, 
	0x25801018, 0x8802c100, 0x25800108, 0x8802b200, 0x20800108, 0x24bfff48, 
	0x51a0ad80, 0x21810018, 0x4020ad98, 0x51a0ae80, 0x21800118, 0x4020ae98, 
	0x5a400c02, 0x29bc0020, 0x8005f100, 0x25800400, 0x8802bc00, 0x52400100, 
	0x26004020, 0x8005f100, 0x24bfff88, 0xc002c900, 0x52400100, 0x26008020, 
	0x8005f100, 0x20800048, 0xc002c900, 0x25800108, 0x8002c900, 0x25800088, 
	0x8802c900, 0x24bffe08, 0x51a0ad80, 0x21810018, 0x4020ad98, 0x2fc00000, 
	0x028000a8, 0x2fc00180, 0x2c400180, 0x2fc00000, 0x48402002, 0x24400000, 
	0x8002f900, 0x59401c02, 0x25400090, 0x8002d600, 0x01400010, 0x48401c12, 
	0x20808008, 0x58402002, 0x51001000, 0x25400090, 0x80035700, 0x01c00010, 
	0x9002de00, 0x2c400080, 0x26000088, 0x8002e800, 0x26c00168, 0x8802ee00, 
	0x2ec00080, 0x2dc00080, 0x21880018, 0x2f02e704, 0xc006b300, 0xc002ee00, 
	0x26c00168, 0x8805f600, 0x2ec00000, 0x2dc00000, 0x2f02ee04, 0xc006b300, 
	0x59402002, 0x01400010, 0x48402012, 0xe0400000, 0x2fc00180, 0x02c00028, 
	0x25400090, 0x8002f900, 0x26c00168, 0x8805f600, 0xc0035700, 0x58401c02, 
	0x24400000, 0x80030100, 0x000000c0, 0x48401c02, 0x253e7fc8, 0x20810010, 
	0xc0030300, 0x253e7fc8, 0x20818010, 0x51001000, 0x25400090, 0x80035700, 
	0x240001c8, 0x25000100, 0x80032300, 0x25000080, 0x88032300, 0x59c00c02, 
	0x293c0018, 0x8005eb00, 0x25000040, 0x80031500, 0x514000c0, 0x25008010, 
	0x8005f100, 0x12000318, 0xc0031900, 0x514000c0, 0x25008010, 0x8005f100, 
	0x12000118, 0x55400500, 0x54400500, 0x4000e410, 0x4000e480, 0x55400500, 
	0x54400500, 0x4000e510, 0x4000e580, 0x2c080000, 0x4020a300, 0x50001000, 
	0x59c01c02, 0x00400018, 0x48401c02, 0x26c00168, 0x88032e00, 0x51a0a300, 
	0x52801000, 0x21c00158, 0x2f032e04, 0xc006b300, 0x25400097, 0x88033500, 
	0xe0400140, 0x2fc00180, 0x2e800000, 0xc0035100, 0x2d400144, 0x01c000aa, 
	0x98033400, 0xe04000c0, 0x2fc00180, 0x2f033b04, 0xc0072700, 0x25800098, 
	0x8805ff00, 0x52808200, 0x51808280, 0x40008228, 0x40008298, 0x298000d1, 
	0x88034e00, 0x01000095, 0x2fc00180, 0x2fc00180, 0x2f034804, 0xc0072700, 
	0x25800098, 0x8805ff00, 0x52808200, 0x51808280, 0x40008228, 0x40008298, 
	0x2e800000, 0xe0400082, 0x2fc00180, 0x24018008, 0x00018000, 0x80035700, 
	0x58401c02, 0x24400000, 0x80035b00, 0x5020a000, 0x24000100, 0x88035c00, 
	0xc004d600, 0x24be7fc8, 0x51a09d00, 0x11800058, 0x40209d18, 0x51a0a000, 
	0x25000418, 0x88036900, 0x51a09e80, 0x594020c0, 0x59c024c0, 0x2fc00080, 
	0x33800610, 0x2fc000c0, 0x33800618, 0x2c000040, 0xc004d700, 0x5120a000, 
	0x25000110, 0x80037500, 0x52a0ad80, 0x26802028, 0x22c00128, 0x26003c08, 
	0x32000720, 0x23c00160, 0x53801000, 0xc0400182, 0x50206a00, 0x25000400, 
	0x88037700, 0x2d000040, 0x40206b90, 0x25000040, 0x88038100, 0x51209d80, 
	0x25000050, 0x8804d600, 0xc003c800, 0x25000080, 0x80039300, 0x2ea06a80, 
	0x55c00540, 0x51000a00, 0x300007d8, 0x251fffd0, 0x02400010, 0x9803c400, 
	0x2a400010, 0x88039300, 0x54400540, 0x51000a80, 0x300007c0, 0x318003d8, 
	0x204000c0, 0x01400010, 0x9803c400, 0x52a06a00, 0x30000628, 0x2d802f00, 
	0x01c00018, 0x52209e80, 0x2a3c0020, 0x8003a300, 0x2e3fffc0, 0x2ea06c00, 
	0x12c00028, 0x54400540, 0x2fc00000, 0x33800600, 0x01800098, 0x88039d00, 
	0xc003b600, 0x2e000000, 0x2ea06c00, 0x2d0000c0, 0x4000c910, 0x2d000400, 
	0x4000c810, 0x54400540, 0x4000ca00, 0x2d000000, 0x4000c810, 0x30000600, 
	0x4000ca00, 0x01800098, 0x54400540, 0x4000ca00, 0x30000600, 0x4000ca00, 
	0x01800098, 0x8803b000, 0x50206a00, 0x24003c00, 0x40206a00, 0x2c000000, 
	0x40206b80, 0x5020ad00, 0x20010000, 0x4020ad00, 0x263fffe0, 0x80052100, 
	0x51a09d00, 0x11800058, 0x40209d18, 0xc004d600, 0x51209d80, 0x25000050, 
	0x8804d600, 0xc003c800, 0x2d000000, 0x40206b90, 0xc0001700, 0x59401802, 
	0x29bc0010, 0x8005eb00, 0x51a0a300, 0x21c000c0, 0x2f03d204, 0xc006b300, 
	0x58401842, 0x243c0000, 0x30000600, 0x20084280, 0x40003800, 0x51a09e80, 
	0x584020c0, 0x5a4024c0, 0x40008f00, 0x40008fa0, 0x40209c00, 0x40209ca0, 
	0x24008008, 0x80040400, 0x5020ad80, 0x24008000, 0x8003f000, 0x2c400180, 
	0x59c02480, 0x018000d8, 0x9803f000, 0x59c03080, 0x2a4000c0, 0x8003f000, 
	0x24bf7fc8, 0x51a09c00, 0x52209c80, 0x40008218, 0x400082a0, 0xc0040800, 
	0x12800210, 0x2d800140, 0x2e003000, 0x54400540, 0x44400500, 0x01800058, 
	0x8803f300, 0x2d8000c0, 0x2e003480, 0x54400540, 0x44400500, 0x01800058, 
	0x8803f900, 0x2d800080, 0x2e003700, 0x54400540, 0x44400500, 0x01800058, 
	0x8803ff00, 0xc0041700, 0x5020ad80, 0x24008000, 0x80060700, 0x2c400180, 
	0x51801000, 0x01c00018, 0x98060700, 0xe0400000, 0x2ec00180, 0x25c000d8, 
	0x80052100, 0x2c000000, 0x40003880, 0x40003700, 0x40003480, 0x40003780, 
	0x2c3fffc0, 0x40003500, 0x40003580, 0x59c04042, 0x58400080, 0x244000c0, 
	0x40003c00, 0x40003d00, 0x59c04442, 0x58400480, 0x244000c0, 0x40003c80, 
	0x40003d80, 0x58401842, 0x243c0000, 0x28100000, 0x88042d00, 0x59c04842, 
	0x58400880, 0x244000c0, 0x40003d00, 0x59c04c42, 0x58400c80, 0x244000c0, 
	0x40003d80, 0x5020a500, 0x24000040, 0x80043100, 0xc0042d00, 0x5020a080, 
	0x243fff80, 0x4020a080, 0x2c000040, 0x40003880, 0x51003780, 0x5020a080, 
	0x20000040, 0x4020a080, 0x2c000100, 0x40008600, 0x40008680, 0x24000410, 
	0x80047100, 0x50003000, 0x24003fc0, 0x28003fc0, 0x80047100, 0x50003a00, 
	0x51803a80, 0x52003800, 0x26001c20, 0x02001c20, 0x98045600, 0x52003b00, 
	0x2a400020, 0x24400020, 0x52003b80, 0x2a4000e0, 0x25c000e0, 0x2fc00000, 
	0x33800600, 0x2fc000c0, 0x33800618, 0xe0000100, 0x2f800000, 0xc0046000, 
	0x2fc00000, 0x33800600, 0x2fc000c0, 0x33800618, 0x50003b00, 0x51803b80, 
	0x2fc00000, 0x33800600, 0x2fc000c0, 0x33800618, 0x24b7ffc8, 0x5a401842, 
	0x260000a0, 0x88046500, 0x20880008, 0x50003700, 0x24400000, 0x8804aa00, 
	0x51803480, 0x2e003000, 0x54400500, 0x2fc00000, 0x01800058, 0x80047100, 
	0x33800600, 0x01800058, 0x88046a00, 0x253ffbd0, 0x24001010, 0x8004aa00, 
	0x24000050, 0x8004aa00, 0x50003000, 0x24200000, 0x80049d00, 0x24000090, 
	0x80049d00, 0x25880008, 0x88049f00, 0x5020ad00, 0x20000080, 0x4020ad00, 
	0x50008600, 0x24000100, 0x88049c00, 0x5020a080, 0x243ffec0, 0x4020a080, 
	0x5020a500, 0x24000080, 0x88048600, 0x2c000040, 0x40008600, 0x40008680, 
	0x50008600, 0x29800040, 0x25bffed8, 0x80048c00, 0x51a0a080, 0x21800118, 
	0x4020a098, 0x2d800100, 0x40008618, 0x24000080, 0x8805ff00, 0x50209c00, 
	0x51a09c80, 0x40008200, 0x40008298, 0xc004b400, 0xc005ff00, 0x2f800000, 
	0xc004a000, 0x2f803fc0, 0x2c000080, 0x40003880, 0x50209d00, 0x10000040, 
	0x40209d00, 0x50008f00, 0x51808f80, 0x40209c00, 0x40209c98, 0xc004b400, 
	0x24000210, 0x8004b400, 0x50001000, 0xe0400000, 0x2d400180, 0x50008600, 
	0x24000100, 0x88049c00, 0x24bf7fc8, 0xc004d600, 0x24000110, 0x80042d00, 
	0x24000410, 0x88042d00, 0x51003480, 0x010000d0, 0x9804be00, 0x51003700, 
	0x25400090, 0x8004af00, 0x20808008, 0x5ac01802, 0x12800228, 0x2e003000, 
	0x2c000140, 0x55400500, 0x44400550, 0x00000040, 0x8804c300, 0x2e003480, 
	0x2c0000c0, 0x55400500, 0x44400550, 0x00000040, 0x8804c900, 0x2e003700, 
	0x2c000080, 0x55400500, 0x44400550, 0x00000040, 0x8804cf00, 0x50008600, 
	0x24000100, 0x88049c00, 0x2c000000, 0x2f04d904, 0xc0072700, 0x52a09e80, 
	0x51209e00, 0x25018010, 0x8004e100, 0x52008304, 0x52808384, 0x48401961, 
	0x48401d69, 0x25800098, 0x8805ff00, 0x51808204, 0x52008280, 0x48401159, 
	0x48401560, 0x24400000, 0x8004eb00, 0x40209c19, 0x40209ca0, 0x50209e00, 
	0x24018000, 0x8004f600, 0x2e008200, 0x30000700, 0x12c00020, 0x54400500, 
	0x55400500, 0x243ffc00, 0x44400540, 0x44400550, 0x52a09d00, 0x51a09e80, 
	0x5a4028c0, 0x59402cc0, 0x10400160, 0x19000010, 0x4020b300, 0x4020b390, 
	0x26c00168, 0x80052100, 0x484028c0, 0x48402cd0, 0x52209e00, 0x260003e0, 
	0x29000060, 0x80050a00, 0x290000a0, 0x80050a00, 0x2e808200, 0xc0050b00, 
	0x2ea09c00, 0x56400540, 0x55400540, 0x484020e0, 0x484024d0, 0x5a4034c0, 
	0x02c00100, 0x98052100, 0x52a09e00, 0x268003e8, 0x2a8000e8, 0x88051900, 
	0x12000120, 0x02c00100, 0x90052100, 0x584030c0, 0x26800040, 0x88052100, 
	0x26800200, 0x88052100, 0x5020ad00, 0x20001000, 0x4020ad00, 0x51801000, 
	0x51206900, 0x01c00098, 0xe04000c0, 0x2c400180, 0x51801000, 0x2f052904, 
	0xc006b300, 0xe04000c0, 0x2c400180, 0x2f052d04, 0xc0072700, 0x25800098, 
	0x88060500, 0x5120ad00, 0x59c03842, 0x21880018, 0x25c00098, 0x4020ad18, 
	0x25336fd0, 0x293fffd0, 0x59c03842, 0x25c00098, 0x4840385a, 0x5120ad80, 
	0x59c01402, 0x21900018, 0x26c000d0, 0x5a403c42, 0x258000a0, 0x88054300, 
	0x52a0ad80, 0x26900028, 0xc0055400, 0x51a09e00, 0x258003d8, 0x298000d8, 
	0x88055400, 0x51a09d80, 0x25800118, 0x88055400, 0x25800060, 0x80055400, 
	0x22820028, 0x5120ae80, 0x25000110, 0x80055100, 0x22810028, 0x263fffa0, 
	0x48403c62, 0xc0055400, 0x59405042, 0x4020af10, 0x59c05442, 0x4020af98, 
	0x5a405842, 0x4020b020, 0x5120ad00, 0x4020ada8, 0x22c000a8, 0x80059100, 
	0x2da63100, 0x2f056104, 0xc006e500, 0x52a09d80, 0x26800128, 0x80056700, 
	0x52a0ad80, 0x26a3bfe8, 0x4020ada8, 0x2ea0ad00, 0x2d800900, 0x56400540, 
	0x27803fe0, 0x33800620, 0x01800098, 0x88056900, 0x26080010, 0x80057e00, 
	0x51a0a184, 0x24000040, 0x01c0001d, 0x2d800040, 0x4000cb18, 0x4000cc19, 
	0x2d801e00, 0x11c00018, 0x4000c018, 0x40001018, 0xe0400000, 0x2f400184, 
	0xe0001e00, 0x2fc00180, 0x2f058004, 0xc0072700, 0x25800098, 0x80058700, 
	0x2f058404, 0xc0070300, 0x2d800080, 0x40005018, 0xc0059700, 0x51808200, 
	0x51008280, 0x40263318, 0x40263390, 0x51a63300, 0x51263400, 0x29c00098, 
	0x80059100, 0x2d800040, 0x40005018, 0x51a09d80, 0x25800218, 0x88001700, 
	0x51a09e00, 0x25804018, 0x88001700, 0x4840000a, 0xc0001700, 0x2d800040, 
	0x2f059c04, 0xc006b300, 0x2d400180, 0x2c000000, 0x4000cb00, 0x2c000180, 
	0x4000c000, 0x2c400180, 0x31800780, 0x258000c4, 0x3180021d, 0x22c0019d, 
	0x32000234, 0x224001a5, 0x31800234, 0x21c0019d, 0x2e0000c0, 0x2ca63504, 
	0x58c01c42, 0x2403ffc8, 0x284000c0, 0x8005b400, 0x1080100d, 0x02000060, 
	0x8805ac00, 0xc0001700, 0x24200008, 0x8005b900, 0x4840506b, 0x48405463, 
	0x4840585b, 0xc0007b00, 0x2c000100, 0x40005000, 0x58403042, 0x25800c00, 
	0x80001700, 0x2c000400, 0x4000c800, 0x2c0000c0, 0x4000c900, 0x2c0011c0, 
	0x4000ca00, 0x2c000000, 0x4000c800, 0x50209b00, 0x31000600, 0x4000ca10, 
	0x4000ca00, 0x2c000040, 0x4000c900, 0x2c002e40, 0x59401842, 0x25000410, 
	0x8805d200, 0x2c002000, 0x4000c000, 0xe0400000, 0x2c400180, 0xc0001700, 
	0x51a09e00, 0x25802018, 0x8005e800, 0x51a09e80, 0x2a3c0018, 0x8005e800, 
	0x5ac030c0, 0x268003a8, 0x2a800028, 0x8805e800, 0x2f05e204, 0xc006e500, 
	0x2f802d00, 0x2f800000, 0x2f800000, 0x2f800040, 0x2f802d00, 0xc0060b00, 
	0x24bdffc8, 0x2e800400, 0xc0060800, 0x2e900000, 0xc0060800, 0x2e800080, 
	0xc0060800, 0x2e800100, 0xc0060800, 0x59400c02, 0x2abc0010, 0x8005eb00, 
	0x2e800100, 0xc0060800, 0x2e802000, 0xc0060800, 0x2a000128, 0x80060700, 
	0x2a000328, 0x80060700, 0x2a000228, 0x80060700, 0xc0052100, 0x51a0ad00, 
	0x21a00018, 0x4020ad18, 0x51a0ad80, 0x25bfbfd8, 0x4020ad98, 0x2f060b04, 
	0xc0070300, 0x2e800200, 0x51a0ad00, 0x21c00158, 0x4020ad18, 0x2f060d04, 
	0xc0072700, 0x25800098, 0x80062200, 0x51a0ad00, 0x21a00018, 0x4020ad18, 
	0x51a09e00, 0x25818018, 0x80062000, 0x2e008200, 0x31800718, 0x12c000e0, 
	0x55c00540, 0x55400540, 0x52209e80, 0x12000220, 0x44400518, 0x44400510, 
	0x44400518, 0x44400510, 0x2f062204, 0xc0070300, 0x50209e00, 0x240003c0, 
	0x01800040, 0x80062f00, 0x01800080, 0x80063a00, 0x59c01802, 0x293c0018, 
	0x80063b00, 0x594034c0, 0x253fdfd0, 0x484034d0, 0xc0063b00, 0x50008700, 
	0x2d800040, 0x40009718, 0x40009798, 0x51809700, 0x25800058, 0x88063300, 
	0x40008700, 0x40008780, 0x24bf7fc8, 0xc0063b00, 0x24be7fc8, 0x2f063d04, 
	0xc0073e00, 0x5120ad80, 0x25008010, 0x80052100, 0x5120ad00, 0x29000410, 
	0x88052100, 0x51001000, 0x25400090, 0x80052100, 0x58401842, 0x24000400, 
	0x8801e000, 0xc0052100, 0x2e3c0000, 0x40209ea0, 0x4020a420, 0x51263880, 
	0x2503ffd0, 0x29002010, 0x80065400, 0x59401c42, 0x25200010, 0x88065b00, 
	0x52005200, 0x51005280, 0x52805300, 0x26a07fe8, 0x48405062, 0x48405452, 
	0x4840586a, 0x59402442, 0x25000090, 0x80066000, 0x2c3fffc0, 0x2cbfffc0, 
	0x59401042, 0x40002010, 0x59401442, 0x40002090, 0x40002188, 0x2d000040, 
	0x40002110, 0x51002100, 0x25400090, 0x88066700, 0x51002200, 0x24a00010, 
	0x88069600, 0x58401046, 0x00200005, 0x300007c5, 0x10400085, 0x30800201, 
	0x4020ae08, 0x30800101, 0x30000085, 0x10400045, 0x1020b605, 0x58c00402, 
	0x10800048, 0x4840040a, 0x5ac01002, 0x24803fe8, 0x2a003fc8, 0x80068500, 
	0x32000088, 0x308000c8, 0x12400060, 0x30800048, 0x12400060, 0x12229620, 
	0x40209ea0, 0x58c03100, 0x4020a008, 0x58c00802, 0x40209e08, 0x2e000000, 
	0x248003c8, 0x288000c8, 0x88069400, 0x52209b00, 0x5ac01c02, 0x26400020, 
	0x22400160, 0x40209b20, 0x2e000040, 0x40209da0, 0x58c00002, 0xc0400182, 
	0x2cbfffc0, 0x4020ae08, 0x5120a700, 0x50a0a780, 0x2c3fffc0, 0x00afbbc8, 
	0x80066d00, 0x58c03042, 0x24000c0c, 0x8805bf00, 0x2400400c, 0x80001700, 
	0x52a06a00, 0x24800068, 0x80001700, 0x2e000200, 0x40209da0, 0x24800328, 
	0x30800788, 0x2ca63504, 0xe0400040, 0x1080100d, 0x58c03442, 0x40209e88, 
	0x58c03040, 0x4020a008, 0x2c800000, 0x40209e08, 0xc0400182, 0x40206808, 
	0x2483ffd8, 0x8006cc00, 0x40206798, 0x40206890, 0x2c800080, 0x4000cb08, 
	0x51206700, 0x10800090, 0x40206708, 0x10a06210, 0x51206180, 0x4000cc10, 
	0x4000c018, 0x40400058, 0x2583ffd8, 0x50801000, 0x00c000c8, 0x40206908, 
	0x24800058, 0x11c00058, 0x114000d0, 0x40206190, 0x51206880, 0x51a06780, 
	0x50a06800, 0xc0400182, 0x56c00504, 0x4440052b, 0x56c00504, 0x4440052b, 
	0x56c00504, 0x4440052b, 0x56c00504, 0x4440052b, 0xc0400182, 0x5a401c42, 
	0x2603ffe0, 0x320000a0, 0x59405046, 0x32800611, 0x23c00160, 0x2fc00082, 
	0x5a405442, 0x33800620, 0x2fc00100, 0x5a405842, 0x33800620, 0x2fc00100, 
	0xc0400182, 0x2e008000, 0x2e800200, 0x554004c4, 0x44400511, 0x02800068, 
	0x8806e700, 0x2d800000, 0x52008000, 0x52808300, 0x2a400160, 0x8806f100, 
	0x2d800040, 0x40008418, 0x40008498, 0xc0400182, 0x50209e00, 0x24018000, 
	0x80070200, 0x2e008300, 0x30000700, 0x12c00020, 0x55c00540, 0x54400540, 
	0x44400518, 0x44400500, 0x52a09e80, 0x12800328, 0x44400558, 0x44400540, 
	0xc0400182, 0x2d800380, 0x40008718, 0x40008798, 0x5120a600, 0x51a0a680, 
	0x40008210, 0x40008298, 0x40008098, 0x40008398, 0x2d800000, 0x40008118, 
	0x40008198, 0x51a0a080, 0x25bffed8, 0x4020a098, 0x51a0a500, 0x25800098, 
	0x88071200, 0x2d8001c0, 0x40008618, 0x40008698, 0x2d8003c0, 0x40008718, 
	0x40008798, 0x51808600, 0x25000058, 0x88071b00, 0x5120a080, 0x21000110, 
	0x4020a090, 0x2d000100, 0x40008610, 0x40008690, 0x25800098, 0x88070300, 
	0xc0400182, 0x51a0a080, 0x25bffed8, 0x4020a098, 0x51a0a500, 0x25800098, 
	0x88072a00, 0x2d8001c0, 0x40008618, 0x40008698, 0x2e3fffc0, 0x02000060, 
	0x80073700, 0x51808600, 0x29000058, 0x253ffed0, 0x80073100, 0x5220a080, 
	0x22000120, 0x4020a0a0, 0x2e000100, 0x40008620, 0x400086a0, 0xc0400182, 
	0x51a0a000, 0x25800818, 0x80074d00, 0x51a09e80, 0x293c0018, 0x80074d00, 
	0x51209e00, 0x25018010, 0x88074d00, 0x594020c0, 0x584024c0, 0x484010d0, 
	0x40008210, 0x484014c0, 0x40008280, 0xc0400182, 0x51a09b80, 0x25800c18, 
	0x29800818, 0x80077f00, 0x51c00080, 0x25c000d8, 0x8005ef00, 0x263c0018, 
	0x32000520, 0x25801c18, 0x28001818, 0x88075b00, 0x2d800400, 0x318007d8, 
	0x21c000e0, 0x4000e018, 0x2c400100, 0x2a000120, 0x88076b00, 0x2e203000, 
	0x2e00ec04, 0x2f076504, 0xc006ce00, 0x2f076704, 0xc006ce00, 0x2f076904, 
	0xc006ce00, 0x2f076b04, 0xc006ce00, 0x26800048, 0x80077200, 0x51c00080, 
	0x25800098, 0x8005f100, 0x12000310, 0xc0077600, 0x51c00080, 0x25800058, 
	0x8005f100, 0x12000110, 0x2e00e404, 0x2f077904, 0xc006ce00, 0x12000220, 
	0x2e00ea04, 0x2f077d04, 0xc006ce00, 0x2c080000, 0x4020a300, 0xc0010800 };

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


#if ((0X99C0-0X8000) > 0X1A00)
#error TCCODE data ram overflow
#endif

#if (TRANSPORT_CONTROLLER_CODE_SIZE > 0X0780)
#error TCCODE instruction ram overflow
#endif


ST_ErrorCode_t STPTI_DVBTCLoader(STPTI_DevicePtr_t CodeStart, void * Params_p)
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
    TC_Params_p->TC_GlobalDataStart            = (U32*)(((U32)PTI4_Base) + 0X826C);
    TC_Params_p->TC_StatusBlockStart           = (U32*)(((U32)PTI4_Base) + 0X82B4);
    TC_Params_p->TC_MainInfoStart              = (U32*)(((U32)PTI4_Base) + 0X82D8);
    TC_Params_p->TC_DMAConfigStart             = (U32*)(((U32)PTI4_Base) + 0X8A58);
    TC_Params_p->TC_DescramblerKeysStart       = (U32*)(((U32)PTI4_Base) + 0X905C);
    TC_Params_p->TC_TransportFilterStart       = (U32*)(((U32)PTI4_Base) + 0X91C4);
    TC_Params_p->TC_SCDFilterTableStart        = (U32*)(((U32)PTI4_Base) + 0X91C4);
    TC_Params_p->TC_PESFilterStart             = (U32*)(((U32)PTI4_Base) + 0X91C4);
    TC_Params_p->TC_SubstituteDataStart        = (U32*)(((U32)PTI4_Base) + 0X81A8);
    TC_Params_p->TC_SFStatusStart              = (U32*)(((U32)PTI4_Base) + 0X91C4);
    TC_Params_p->TC_InterruptDMAConfigStart    = (U32*)(((U32)PTI4_Base) + 0X98C4);
    TC_Params_p->TC_SessionDataStart           = (U32*)(((U32)PTI4_Base) + 0X98D4);
    TC_Params_p->TC_EMMStart                   = (U32*)(((U32)PTI4_Base) + 0X9994);
    TC_Params_p->TC_ECMStart                   = (U32*)(((U32)PTI4_Base) + 0X9994);
    TC_Params_p->TC_VersionID                  = (U32*)(((U32)PTI4_Base) + 0X99B4);

    TC_Params_p->TC_NumberCarousels            = 0X0001;
    TC_Params_p->TC_NumberSystemKeys           = 0X0000;
    TC_Params_p->TC_NumberDMAs                 = 0X0037;
    TC_Params_p->TC_NumberDescramblerKeys      = 0X0012;
    TC_Params_p->TC_SizeOfDescramblerKeys      = 0X0014;
    TC_Params_p->TC_NumberPesFilters           = 0X0000;
    TC_Params_p->TC_NumberSectionFilters       = 0X0040;
    TC_Params_p->TC_NumberSlots                = 0X0060;
    TC_Params_p->TC_NumberOfSessions           = 0X0003;
    TC_Params_p->TC_NumberIndexs               = 0X0060;
    TC_Params_p->TC_NumberTransportFilters     = 0X0000;
    TC_Params_p->TC_NumberSCDFilters           = 0X0000;

    TC_Params_p->TC_SignalEveryTransportPacket = 0X0001;
    TC_Params_p->TC_NumberEMMFilters           = 0X0000;
    TC_Params_p->TC_NumberECMFilters           = 0X0060;
    TC_Params_p->TC_AutomaticSectionFiltering  = FALSE;


    {
        U32 i;
        STPTI_DevicePtr_t DataStart = (U32*)(((U32)CodeStart&0xffff0000) | 0X8000);

        for(i = 0; i < (0X1A00/4); ++i)
        {
            STSYS_WriteRegDev32LE( (U32)&DataStart[i], 0x00 );
        }

        for(i = 0; i < 0X0780; ++i)
        {
            STSYS_WriteRegDev32LE( (U32)&CodeStart[i], 0x00 );
        }

        for(i = 0; i < TRANSPORT_CONTROLLER_CODE_SIZE; ++i)
        {
            STSYS_WriteRegDev32LE( (U32)&CodeStart[i], transport_controller_code[i] );
        }
        
        STSYS_WriteRegDev32LE( (U32)&(TC_Params_p->TC_VersionID[0]), 0X5354 | (0X5054<<16) );
        STSYS_WriteRegDev32LE( (U32)&(TC_Params_p->TC_VersionID[1]), 0X4934 | (0X0000<<16) );
        STSYS_WriteRegDev32LE( (U32)&(TC_Params_p->TC_VersionID[2]), 0X84D0 | (0X0000<<16) );
    }

    return ST_NO_ERROR;

}

