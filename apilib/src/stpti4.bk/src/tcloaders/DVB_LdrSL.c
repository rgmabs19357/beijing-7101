/************************************************************************
COPYRIGHT (C) ST Microelectronics (R&D) 2007
All rights reserved.

Author :           Automatically generated file

Contains the transport controller code packed as a word array

************************************************************************/

#define TC_ID 5
#define TC_DVB 1
#define TC_PTI4_SECURELITE 1
#define TC_WATCH_AND_RECORD_CLEAR_PAYLOAD 1
#define TC_HARDWARE_START_CODE_DETECTION 1
#define TC_CAROUSEL_SUPPORT 1
#define TC_WATCH_AND_RECORD_SUPPORT 1
#define TC_AES_DESCRAMBLE_SUPPORT 1
#define TC_MULTI2_DESCRAMBLE_SUPPORT 1
#define TC_TSDEBUG_SUPPORT 1
#define TC_PROFILING 1

#define TRANSPORT_CONTROLLER_CODE_SIZE      2442

static char const VERSION[] = "\nTC Version STPTI_DVBTCLoaderSL \n\tRel: 1648. File: DVBTC4 Version: 0\n \n\tRel: 1648. File: TCINIT Version: 0\n \n\tRel: 1648. File: TS_HEADER Version: 0\n \n\tRel: 1648. File: SETUPDMA Version: 0\n \n\tRel: 1648. File: AF_ALTOUT Version: 0\n \n\tRel: 1648. File: AF_PROC Version: 0\n \n\tRel: 1648. File: CC_PROC Version: 0\n \n\tRel: 1648. File: SLT_SWIT Version: 0\n \n\tRel: 1648. File: ECMEMM Version: 0\n \n\tRel: 1648. File: RAW_PROC Version: 0\n \n\tRel: 1648. File: PES_PROC Version: 0\n \n\tRel: 1648. File: CAR_PROC Version: 0\n \n\tRel: 1648. File: RAMCAM_PROC Version: 0\n \n\tRel: 1648. File: DMA_UNLD Version: 0\n \n\tRel: 1648. File: SIG_DEC Version: 0\n \n\tRel: 1648. File: STAT_BLK Version: 0\n \n\tRel: 1648. File: STREAMID Version: 0\n \n\tRel: 1648. File: ERR_PROC Version: 0\n \n\tRel: 1648. File: COMMON Version: 0\n \n\tRel: 1648. File: TCDMA Version: 0\n \n\tRel: 1648. File: SET_SCRAM Version: 0\n";


#define TRANSPORT_CONTROLLER_VERSION    2


static const unsigned int transport_controller_code[] = {
	0x2c000040, 0x40003f80, 0x40009f00, 0x2faaee04, 0x2c8001c0, 0x4020a888, 
	0x2c800000, 0x40002108, 0x40003888, 0x4020ab88, 0x4000a100, 0x4000a188, 
	0x2d003fc0, 0x40002d10, 0x40002c88, 0x2d200000, 0x40002010, 0x2d001800, 
	0x40002090, 0x2c000000, 0x4000cb00, 0x4000c100, 0x50003880, 0x50802100, 
	0x5100c100, 0x20400040, 0x20400080, 0x88001600, 0x2f001e04, 0xc0082a00, 
	0x2c000000, 0x4000cb00, 0x2c000040, 0x4000c100, 0x40008600, 0x40008680, 
	0x2c000000, 0x4020aa00, 0x4020ab00, 0x40046100, 0x4000cf00, 0x2e20b100, 
	0xe0000100, 0x44400500, 0x120001a0, 0xe0000240, 0x44400500, 0x4020a500, 
	0x4020a580, 0x4000c900, 0x40206f00, 0x2ca06a00, 0xe0000280, 0x44400440, 
	0x50a0a700, 0x10800048, 0x4020a708, 0x2c800000, 0x10800048, 0x08800008, 
	0x5000c100, 0x24400000, 0x88003a00, 0x5020ab80, 0x00800048, 0x88004600, 
	0x10000040, 0x00800400, 0x98004d00, 0x2c0003c0, 0x30000040, 0x102ae300, 
	0x50c00000, 0x10800048, 0x08800008, 0x40400008, 0x2c000000, 0x4020ab80, 
	0x51a0b004, 0x25c000db, 0x80006100, 0x2f005304, 0xc0085200, 0x51a0b080, 
	0x2f005604, 0xc007b100, 0xe04000c0, 0x2fc00180, 0x2f005a04, 0xc0089400, 
	0x51808200, 0x52808280, 0x484010da, 0x484014ea, 0x484020da, 0x484024ea, 
	0xc0001c00, 0x2c000080, 0x4000cb00, 0x2c203800, 0x4000cc00, 0x40206980, 
	0x2caa9304, 0x50aa9680, 0x2483ffc8, 0x00002008, 0x80008400, 0x51a0af00, 
	0x24004018, 0x80068700, 0x25003fd8, 0x2caa9304, 0x58c01c42, 0x2403ffc8, 
	0x28400080, 0x80008400, 0x2caaa504, 0x58c01c42, 0x2403ffc8, 0x28400080, 
	0x80008400, 0x2caab704, 0x58c01c42, 0x2403ffc8, 0x28400080, 0x80008400, 
	0x2caac904, 0x58c01c42, 0x2403ffc8, 0x28400080, 0x80008400, 0xc0068700, 
	0x2d800040, 0x2f008704, 0xc007b100, 0x2d400180, 0x4020a990, 0x2e002e80, 
	0x5ac01842, 0x26800428, 0x88008e00, 0x2e002040, 0x58406c42, 0x24400000, 
	0x80009b00, 0x50a0af00, 0x25804008, 0x80009700, 0x24803fc8, 0x01c00050, 
	0x80009b00, 0x26c00168, 0x80009b00, 0x298011d0, 0x88001c00, 0x10c00100, 
	0x40001008, 0x11800040, 0x2f00a004, 0xc007b100, 0xe0400000, 0x2d400180, 
	0x31000210, 0x21400190, 0x4020a310, 0x4020aa90, 0x58400042, 0x10000040, 
	0x48400042, 0x26800428, 0x8800ac00, 0xc0001c00, 0x2c380000, 0x2487ffd0, 
	0x2f00b004, 0xc0074700, 0x5120a300, 0x24200010, 0x8806b700, 0x51a0a600, 
	0x258003d8, 0x01800058, 0x8800bd00, 0x2d801100, 0x40003798, 0x2d800040, 
	0x40003898, 0x2d800000, 0x40003898, 0x2d800040, 0x2f00c004, 0xc007b100, 
	0x24100010, 0x8000c500, 0x5020b180, 0x20008000, 0x4020b180, 0x5220a580, 
	0x24000220, 0x8800cf00, 0x5020a600, 0x24004000, 0x8000d400, 0x22000220, 
	0x4020a5a0, 0x26000060, 0x8800d400, 0x2d400180, 0x5120a680, 0x293c0010, 
	0x8003ea00, 0xc000d600, 0x2c400180, 0x4020a380, 0x2d800000, 0x4020ab18, 
	0x40046018, 0x5020a600, 0x258003c0, 0x25000c00, 0x8800df00, 0x25c000d8, 
	0x80011600, 0x25801000, 0x88010800, 0x5020a380, 0x25002000, 0x80010800, 
	0x24afffc8, 0x51a0b280, 0x21800118, 0x24001000, 0x8800ee00, 0x25000048, 
	0x8000f500, 0x25bfff98, 0x24bfff88, 0xc000f200, 0x25000048, 0x8800f500, 
	0x21800058, 0x20800048, 0x5120b180, 0x21010010, 0x4020b190, 0x4020b298, 
	0x25000108, 0x8800fd00, 0x20800108, 0x51a0b180, 0x21810018, 0x4020b198, 
	0x20800088, 0x59400c02, 0x29bc0010, 0x8808c600, 0x51a0a600, 0x258003d8, 
	0x018000d8, 0x80011600, 0x51a0a380, 0x25800418, 0x80011600, 0xc006e800, 
	0x25900008, 0x88010e00, 0x25800108, 0x80011600, 0x25800088, 0x80011600, 
	0x24afffc8, 0x24bffe08, 0x51a0b280, 0x25bffed8, 0x4020b298, 0x51a0b180, 
	0x21810018, 0x4020b198, 0x5120a580, 0x26800210, 0x88011c00, 0x5120a600, 
	0x268003d0, 0x80012800, 0x51a0a680, 0x4020b498, 0x293c0018, 0x80012800, 
	0x594010c0, 0x4020b810, 0x594014c0, 0x4020b890, 0x2f012604, 0xc0085200, 
	0x2f012804, 0xc0086100, 0x5120a580, 0x25800210, 0x80012d00, 0x25800050, 
	0x8003ea00, 0x51a0a600, 0x25800c18, 0x88013300, 0x2d000000, 0x4000c910, 
	0xc0014000, 0x2d0000c0, 0x4000c910, 0x2d000400, 0x4000c810, 0x2d0011c0, 
	0x4000ca10, 0x2d000000, 0x4000c810, 0x5120a300, 0x31000610, 0x4000ca10, 
	0x5120a300, 0x4000ca10, 0x5220a380, 0x25002020, 0x80016e00, 0x59400c02, 
	0x2abc0010, 0x80015d00, 0x51400080, 0x26801020, 0x88014c00, 0x26800050, 
	0x80015d00, 0xc0014e00, 0x25000090, 0x80015d00, 0x5120a600, 0x26800810, 
	0x80015600, 0x253fcfe0, 0x4000ca10, 0x2c000040, 0x4000c900, 0xc0017500, 
	0x258003d0, 0x018000d8, 0x88016e00, 0x25001010, 0x88016e00, 0x253fcfe0, 
	0xc0017500, 0x25c000d8, 0x80016800, 0x5120a380, 0x4000ca10, 0x2d000040, 
	0x4000c910, 0x5120a600, 0x258003d0, 0x018000d8, 0x80016e00, 0xc006ee00, 
	0x5120a600, 0x258003d0, 0x80016e00, 0x018000d8, 0x80016e00, 0xc0016e00, 
	0x5120a380, 0x51a0a600, 0x25800c18, 0x80017500, 0x4000ca10, 0x2c000040, 
	0x4000c900, 0x24000c10, 0x80070400, 0x5020a580, 0x24000040, 0x80018500, 
	0x5220af00, 0x25804020, 0x80017f00, 0x25803fe0, 0xc0018000, 0x2d8011c0, 
	0x2fc000c0, 0x5220a300, 0x33800620, 0x2fc00100, 0x2fc00080, 0x25000810, 
	0x88018a00, 0x24400000, 0x8801ef00, 0xc001c800, 0x2d800040, 0x2f018d04, 
	0xc007b100, 0x2dc00180, 0x24000040, 0x80019100, 0x2fc000c0, 0x52a0a380, 
	0x26800428, 0x88019600, 0x2d802dc0, 0xc0019d00, 0x02802dd8, 0x90070400, 
	0x26c000d8, 0x88019d00, 0x24000040, 0x8001c800, 0xc001ef00, 0x2f019f04, 
	0xc007b100, 0x2d400180, 0x24000040, 0x8001a300, 0x2fc00080, 0x01800058, 
	0x52a0b180, 0x26bfc028, 0x22c000a8, 0x4020b1a8, 0x26800410, 0x8001be00, 
	0x02800198, 0x9801be00, 0x32800230, 0x22c001a8, 0x4020b528, 0x31000230, 
	0x21400190, 0x4020b590, 0x32000230, 0x224001a0, 0x4020b620, 0x24000040, 
	0x8001bd00, 0x33800628, 0x2fc00140, 0x33800610, 0x2fc00080, 0x33800620, 
	0x2fc00100, 0x01800198, 0x24000040, 0x8001c300, 0xe04000c0, 0x2fc00180, 
	0xc001ef00, 0xe04000c0, 0x2c400180, 0x5220a380, 0x26000420, 0x8001ef00, 
	0x51a0a600, 0x25820018, 0x8801ef00, 0x51a0a380, 0x25800418, 0x8001ef00, 
	0x5120b180, 0x26820008, 0x8801d400, 0x25008010, 0x8801e900, 0xc0073800, 
	0x24002010, 0x8001d800, 0x25000410, 0x8001e900, 0x5020a380, 0x260003c0, 
	0x26803c08, 0x32800728, 0x28400160, 0x8801e400, 0x25000208, 0x8801e200, 
	0x20800208, 0xc005bc00, 0x24bffdc8, 0xc006e500, 0x24bffdc8, 0x12800068, 
	0x268003e8, 0x28400160, 0x8806e500, 0x5020a380, 0x260003c0, 0x32000120, 
	0x24bfc3c8, 0x20c00108, 0x20820008, 0x51a0a680, 0x29bc0018, 0x8006e800, 
	0x5020a600, 0x258003c0, 0x25000c00, 0x8801f800, 0x25c000d8, 0x8005bc00, 
	0x5120a600, 0x25000c10, 0x8001fd00, 0x2e000040, 0x4000c920, 0x50001000, 
	0x51a0a600, 0x258003d8, 0x88020700, 0x21880000, 0x2f020404, 0xc007b100, 
	0xe0400000, 0x2dc00180, 0xc005bc00, 0x010000d8, 0x80026a00, 0x24400000, 
	0x80055000, 0x01000098, 0x80027a00, 0x01000058, 0x80043c00, 0xc005bc00, 
	0x29002e00, 0x88070400, 0x25810008, 0x8005bc00, 0x5a401806, 0x2b3c0025, 
	0x8005bc00, 0x5020b180, 0x24008000, 0x88021d00, 0x25c00127, 0x88025200, 
	0xc005bc00, 0x25c00127, 0x80022400, 0x51a0a680, 0x50000400, 0x40000200, 
	0x50000480, 0x40000280, 0x2d900100, 0x2f022704, 0xc007b100, 0x2c400180, 
	0x2c400180, 0x31800234, 0x21c0019d, 0x2583ffd9, 0x8005bc00, 0x2b3c0025, 
	0x8005bc00, 0x5a401c06, 0x26400021, 0x5ac00c06, 0x2a400129, 0x26003fe0, 
	0x8805bc00, 0x2e8011c0, 0x26000040, 0x88023b00, 0x25800088, 0x80023e00, 
	0xc0024400, 0x25800048, 0x80024100, 0xc0024400, 0x20800088, 0x24bfff88, 
	0xc0024300, 0x20800048, 0x24bfff48, 0x2e801d00, 0x2d900040, 0x2f024704, 
	0xc007b100, 0x32000230, 0x20400100, 0x2a8011e8, 0x8005bc00, 0xe0000300, 
	0x2f800000, 0x2fc00000, 0x33800619, 0x2fc000c2, 0x33800600, 0x0180005d, 
	0x2583ffdd, 0x51801000, 0x21900018, 0x2f025704, 0xc007b100, 0x01900018, 
	0x2d4000c2, 0x004000da, 0x90025d00, 0x2d4000c0, 0x2c000000, 0xe0400080, 
	0x2fc00180, 0xe0400000, 0x2f400184, 0x01c000dd, 0x90026400, 0x2d800004, 
	0x4840181b, 0x21c000df, 0x88055000, 0x2f800000, 0xc0027400, 0xc005bc00, 
	0x2f026c04, 0xc007d300, 0x51a0ab00, 0x21c000c0, 0x2f027004, 0xc007b100, 
	0xe0400000, 0x2fc00180, 0x2f027404, 0xc007f200, 0x2d800040, 0x4020a518, 
	0x51a0a580, 0x25800218, 0x8803ea00, 0xc0055000, 0x2f027c04, 0xc007d300, 
	0x51008204, 0x250000d5, 0x268000c0, 0x114000ae, 0x250000d5, 0x52a0b180, 
	0x25003c08, 0x32000710, 0x30000200, 0x22400020, 0x25008028, 0x80028900, 
	0x22001020, 0x25002028, 0x80028c00, 0x22002020, 0x24008028, 0x8002b500, 
	0x25018008, 0x01818010, 0x80029a00, 0x01810010, 0x9802c200, 0x51a0b100, 
	0x21802018, 0x4020b118, 0x24be7fc8, 0x2f029904, 0xc008ab00, 0xc002c200, 
	0x51a0a800, 0x26800098, 0x8002c200, 0x25800218, 0x8802a600, 0x52a0a680, 
	0x59c02140, 0x59402540, 0x2fc000c0, 0x33800618, 0x2fc00080, 0x33800610, 
	0x2d800040, 0x4020a518, 0x2f02aa04, 0xc0089400, 0x25800098, 0x8806fc00, 
	0x51008200, 0x50008280, 0x4020a410, 0x4020a480, 0x48402150, 0x48402540, 
	0x40008210, 0x40008280, 0xc002c200, 0x24018008, 0x8005bc00, 0x5120a800, 
	0x25000110, 0x8002bc00, 0x2fc00100, 0x33800620, 0x2e800000, 0x01018000, 
	0x80037b00, 0x01010000, 0x80037b00, 0xc0034c00, 0x52801000, 0x01000268, 
	0x9002c900, 0x2dc00140, 0x2f02c804, 0xc007b100, 0xc006f300, 0x5120a800, 
	0x25000110, 0x8002ce00, 0x2fc00100, 0x33800620, 0x258001c8, 0x25800098, 
	0x8802d400, 0x2e800240, 0x2c400140, 0xc002d600, 0x5020ab00, 0x20400140, 
	0x2dc00000, 0x2f02d904, 0xc007b100, 0x028000a8, 0x30000230, 0x20400180, 
	0x8806f300, 0x02800068, 0x2c400180, 0x00000040, 0x8806f300, 0x2f800000, 
	0x2f800000, 0x2f800040, 0x02800068, 0x2c400180, 0x48402002, 0x2fc00000, 
	0x59c01802, 0x25004018, 0x8002ee00, 0x25803fd8, 0x29c00018, 0x8806f300, 
	0x028000a8, 0x31000230, 0x21400190, 0x48401c12, 0x25400090, 0x8002f800, 
	0x9802f800, 0x51801000, 0x01c000d0, 0x9806f300, 0x33800610, 0x2fc00080, 
	0x29802f00, 0x80030a00, 0x29802fc0, 0x80030a00, 0x29803c00, 0x80030a00, 
	0x29803c40, 0x80030a00, 0x29803fc0, 0x80030a00, 0x29803c80, 0x80030a00, 
	0x29803e00, 0x80030a00, 0x29802f80, 0x88031600, 0xe0400140, 0x2fc00180, 
	0x2e800000, 0x253e7fc8, 0x20818010, 0x59c01c02, 0x01800298, 0x48401c1a, 
	0x50001000, 0x24400000, 0x8003c600, 0xc0039c00, 0x2c400180, 0x02800068, 
	0x25800800, 0x80033600, 0x51a0a600, 0x25801018, 0x88033600, 0x25800108, 
	0x88032700, 0x20800108, 0x24bfff48, 0x51a0b180, 0x21810018, 0x4020b198, 
	0x51a0b280, 0x21800118, 0x4020b298, 0x5a400c02, 0x29bc0020, 0x8006ee00, 
	0x25800400, 0x88033100, 0x52400100, 0x26004020, 0x8006ee00, 0x24bfff88, 
	0xc0033e00, 0x52400100, 0x26008020, 0x8006ee00, 0x20800048, 0xc0033e00, 
	0x25800108, 0x80033e00, 0x25800088, 0x88033e00, 0x24bffe08, 0x51a0b180, 
	0x21810018, 0x4020b198, 0x2fc00000, 0x028000a8, 0x2fc00180, 0x2c400180, 
	0x2fc00000, 0x48402002, 0x24400000, 0x80036e00, 0x59401c02, 0x25400090, 
	0x80034b00, 0x01400010, 0x48401c12, 0x20808008, 0x58402002, 0x51001000, 
	0x25400090, 0x8003cc00, 0x01c00010, 0x90035300, 0x2c400080, 0x26000088, 
	0x80035d00, 0x26c00168, 0x88036300, 0x2ec00080, 0x2dc00080, 0x21880018, 
	0x2f035c04, 0xc007b100, 0xc0036300, 0x26c00168, 0x8806f300, 0x2ec00000, 
	0x2dc00000, 0x2f036304, 0xc007b100, 0x59402002, 0x01400010, 0x48402012, 
	0xe0400000, 0x2fc00180, 0x02c00028, 0x25400090, 0x80036e00, 0x26c00168, 
	0x8806f300, 0xc003cc00, 0x58401c02, 0x24400000, 0x80037600, 0x000000c0, 
	0x48401c02, 0x253e7fc8, 0x20810010, 0xc0037800, 0x253e7fc8, 0x20818010, 
	0x51001000, 0x25400090, 0x8003cc00, 0x240001c8, 0x25000100, 0x80039800, 
	0x25000080, 0x88039800, 0x59c00c02, 0x293c0018, 0x8006e800, 0x25000040, 
	0x80038a00, 0x514000c0, 0x25008010, 0x8006ee00, 0x12000318, 0xc0038e00, 
	0x514000c0, 0x25008010, 0x8006ee00, 0x12000118, 0x55400500, 0x54400500, 
	0x40044410, 0x40044480, 0x55400500, 0x54400500, 0x40044510, 0x40044580, 
	0x2c080000, 0x4020ab00, 0x50001000, 0x59c01c02, 0x00400018, 0x48401c02, 
	0x26c00168, 0x8803a300, 0x51a0ab00, 0x52801000, 0x21c00158, 0x2f03a304, 
	0xc007b100, 0x25400097, 0x8803aa00, 0xe0400140, 0x2fc00180, 0x2e800000, 
	0xc003c600, 0x2d400144, 0x01c000aa, 0x9803a900, 0xe04000c0, 0x2fc00180, 
	0x2f03b004, 0xc0089400, 0x25800098, 0x8806fc00, 0x52808200, 0x51808280, 
	0x40008228, 0x40008298, 0x298000d1, 0x8803c300, 0x01000095, 0x2fc00180, 
	0x2fc00180, 0x2f03bd04, 0xc0089400, 0x25800098, 0x8806fc00, 0x52808200, 
	0x51808280, 0x40008228, 0x40008298, 0x2e800000, 0xe0400082, 0x2fc00180, 
	0x24018008, 0x00018000, 0x8003cc00, 0x58401c02, 0x24400000, 0x8003d500, 
	0x51a0a800, 0x25800218, 0x8803d600, 0x5020a800, 0x24000100, 0x8803d600, 
	0x2f03d404, 0xc007f200, 0xc0055000, 0x24be7fc8, 0x2f03d804, 0xc007f200, 
	0x51a0a500, 0x11800058, 0x4020a518, 0x5020a800, 0x24000080, 0x8003e800, 
	0x51a0a680, 0x5120a800, 0x25000210, 0x8803e800, 0x594020c0, 0x59c024c0, 
	0x2fc00080, 0x33800610, 0x2fc000c0, 0x33800618, 0x2c000040, 0xc0055100, 
	0x2c000040, 0x40207380, 0x50207200, 0x25000400, 0x8803ed00, 0x25000040, 
	0x8803f500, 0x5120a580, 0x25000050, 0x88055000, 0xc0043900, 0x25000080, 
	0x80040700, 0x2ea07280, 0x55c00540, 0x51000c00, 0x300007d8, 0x251fffd0, 
	0x02400010, 0x98043500, 0x2a400010, 0x88040700, 0x54400540, 0x51000c80, 
	0x300007c0, 0x318003d8, 0x204000c0, 0x01400010, 0x98043500, 0x50207200, 
	0x30000600, 0x2d802f00, 0x01c00018, 0x5220a680, 0x2a3c0020, 0x80041600, 
	0x2e3fffc0, 0x2ea07400, 0x54400540, 0x2fc00000, 0x33800600, 0x01800098, 
	0x88041000, 0xc0042900, 0x2e000000, 0x2ea07400, 0x2d0000c0, 0x4000c910, 
	0x2d000400, 0x4000c810, 0x54400540, 0x4000ca00, 0x2d000000, 0x4000c810, 
	0x30000600, 0x4000ca00, 0x01800098, 0x54400540, 0x4000ca00, 0x30000600, 
	0x4000ca00, 0x01800098, 0x88042300, 0x2c000000, 0x40207200, 0x40207380, 
	0x5020b100, 0x20010000, 0x4020b100, 0x263fffe0, 0x8005bc00, 0x51a0a500, 
	0x11800058, 0x4020a518, 0xc0055000, 0x5120a580, 0x25000050, 0x88055000, 
	0xc0043900, 0x2d000000, 0x40207390, 0xc0001c00, 0x59401802, 0x29bc0010, 
	0x8006e800, 0x51a0ab00, 0x21c000c0, 0x2f044304, 0xc007b100, 0x59c05880, 
	0x30000618, 0x200f0200, 0x40003800, 0x2c000400, 0x2a140018, 0x88044c00, 
	0x20010000, 0xc0044e00, 0x2c000800, 0x2000c000, 0x40004100, 0x2c000000, 
	0x40004180, 0x2c000040, 0x40004000, 0x40004080, 0x52a0a684, 0x58402142, 
	0x5a402542, 0x4020a400, 0x4020a4a0, 0x2c000000, 0x40001080, 0x2c3fffc0, 
	0x40003600, 0x2c000000, 0x40003c80, 0x40003d80, 0x40004600, 0x40004880, 
	0x5ac05880, 0x28140028, 0x80048500, 0x59c04042, 0x58400080, 0x244000c0, 
	0x40003c00, 0x40003d00, 0x59c04442, 0x58400480, 0x244000c0, 0x40003c80, 
	0x40003d80, 0x59c04842, 0x58400880, 0x25c000c0, 0x28100028, 0x88048200, 
	0x40003d18, 0x59c04c42, 0x58400c80, 0x244000c0, 0x40003d80, 0x59c05042, 
	0x58401080, 0x244000c0, 0x40004600, 0x59c05842, 0x58401880, 0x244000c0, 
	0x40004880, 0xc004a700, 0x40004618, 0x40004898, 0xc004a700, 0x59c04042, 
	0x5a400080, 0x264000e0, 0x240003e0, 0x2683c020, 0x32800728, 0x20400140, 
	0x59c04442, 0x5a400480, 0x264000e0, 0x268003e0, 0x32800228, 0x20400140, 
	0x2683c020, 0x32800128, 0x20400140, 0x40003c00, 0x59c04842, 0x5a400880, 
	0x264000e0, 0x240003e0, 0x2683c020, 0x32800728, 0x20400140, 0x59c04c42, 
	0x5a400c80, 0x264000e0, 0x268003e0, 0x32800228, 0x20400140, 0x2683c020, 
	0x32800128, 0x20400140, 0x40003d00, 0x24008008, 0x8004d000, 0x5020b180, 
	0x24008000, 0x8004bc00, 0x2c400180, 0x59c04480, 0x018000d8, 0x9004b300, 
	0x11c000c0, 0x9804b600, 0xc004bc00, 0x59c05080, 0x2a4000c0, 0x8004bc00, 
	0x24bf7fc8, 0x51a0a400, 0x5220a480, 0x40008218, 0x400082a0, 0xc004d400, 
	0x12800410, 0x2d800240, 0x2e003000, 0x54400540, 0x44400500, 0x01800058, 
	0x8804bf00, 0x2d8000c0, 0x2e003480, 0x54400540, 0x44400500, 0x01800058, 
	0x8804c500, 0x2d800080, 0x2e003700, 0x54400540, 0x44400500, 0x01800058, 
	0x8804cb00, 0xc004e300, 0x5020b180, 0x24008000, 0x80070400, 0x2c400180, 
	0x51801000, 0x01c00018, 0x98070400, 0xe0400000, 0x2ec00180, 0x25c000d8, 
	0x8005bc00, 0x2c000000, 0x40003880, 0x40003700, 0x40003480, 0x40003780, 
	0x2c3fffc0, 0x40003500, 0x40003580, 0x2f04e504, 0xc0083600, 0x2c000040, 
	0x40003880, 0x2f04e904, 0xc0083d00, 0x24200020, 0x8805bc00, 0x24001020, 
	0x80052b00, 0x24000060, 0x80051b00, 0x240000a0, 0x80051b00, 0x58401842, 
	0x24000080, 0x8804f700, 0x50001080, 0x40003600, 0xc0051e00, 0x5020b100, 
	0x20000080, 0x4020b100, 0x5020a880, 0x243ffec0, 0x4020a880, 0x5020ac00, 
	0x24000080, 0x8804fd00, 0x2c000040, 0x40008600, 0x40008680, 0x50008600, 
	0x29800040, 0x80050300, 0x5120a880, 0x21000110, 0x4020a890, 0x24000080, 
	0x8806fc00, 0x50003600, 0x11000040, 0x88051100, 0x5020a400, 0x51a0a480, 
	0xc0051800, 0x2d800000, 0x5ac01142, 0x59401542, 0x10400140, 0x19c00098, 
	0x2f051804, 0xc008b800, 0x40008200, 0x40008298, 0xc0052b00, 0x50003600, 
	0x11000040, 0x80052b00, 0x50003600, 0x2d800000, 0x5ac01142, 0x59401542, 
	0x10400140, 0x19c00098, 0x2f052604, 0xc008b800, 0x4020a400, 0x4020a498, 
	0x5020a500, 0x10000040, 0x4020a500, 0x24000220, 0x80053300, 0x50001000, 
	0xe0400000, 0x2d400180, 0x2c000040, 0x24bf7fc8, 0xc0055100, 0x24000120, 
	0x8004db00, 0x51003480, 0x010000d0, 0x98053b00, 0x50003700, 0x24400000, 
	0x80053000, 0x20808008, 0x5ac01802, 0x12800428, 0x2e003000, 0x2c000240, 
	0x55400500, 0x44400550, 0x00000040, 0x88054000, 0x2e003480, 0x2c0000c0, 
	0x55400500, 0x44400550, 0x00000040, 0x88054600, 0x2e003700, 0x2c000080, 
	0x55400500, 0x44400550, 0x00000040, 0x88054c00, 0x2c000000, 0x2f055304, 
	0xc0089400, 0x52a0a680, 0x51808204, 0x52008280, 0x48401159, 0x48401560, 
	0x5120a600, 0x25018010, 0x80055f00, 0x52008304, 0x52808384, 0x48401961, 
	0x48401d69, 0x25800098, 0x8806fc00, 0x24400000, 0x80056500, 0x4020a419, 
	0x4020a4a0, 0x5020a600, 0x24018000, 0x80057000, 0x2e008200, 0x30000700, 
	0x12c00020, 0x54400500, 0x55400500, 0x243ffc00, 0x44400540, 0x44400550, 
	0x52a0a500, 0x26c00168, 0x8005bc00, 0x51a0a680, 0x5a4028c0, 0x59402cc0, 
	0x10400160, 0x19000010, 0x484028c0, 0x48402cd0, 0x4020b700, 0x4020b790, 
	0x5220a600, 0x260003e0, 0x29000060, 0x80058400, 0x290000a0, 0x80058400, 
	0x2e808200, 0xc0058500, 0x2ea0a400, 0x56400540, 0x55400540, 0x484020e0, 
	0x484024d0, 0x5a4038c0, 0x26400120, 0x8005b300, 0x5a4008c0, 0x32000620, 
	0x5ac00cc0, 0x32800228, 0x12c00128, 0x402adf28, 0x5a4000c0, 0x32000620, 
	0x5ac004c0, 0x32800228, 0x12c00128, 0x402adfa8, 0x5a4020c0, 0x32000620, 
	0x5ac024c0, 0x32800228, 0x12c00128, 0x402ae028, 0x5a4018c0, 0x32000620, 
	0x5ac01cc0, 0x32800228, 0x12c00128, 0x402ae0a8, 0x522adf00, 0x52aadf80, 
	0x02c00160, 0x402ae128, 0x522ae000, 0x52aae080, 0x02c00160, 0x26200028, 
	0x8005af00, 0x522ae100, 0x12c00160, 0x5a4038c0, 0x02400128, 0x9805bc00, 
	0xc005b600, 0x5a4034c0, 0x01c00100, 0x9805bc00, 0x5020a800, 0x24000040, 
	0x8805bc00, 0x5020b100, 0x20001000, 0x4020b100, 0x51801000, 0x51207100, 
	0x01c00098, 0xe04000c0, 0x2c400180, 0x51801000, 0x2f05c404, 0xc007b100, 
	0xe04000c0, 0x2c400180, 0x2f05c804, 0xc0089400, 0x25800098, 0x88070200, 
	0x59401002, 0x253fc010, 0x29bfc010, 0x88063100, 0x5120b100, 0x59c03842, 
	0x21880018, 0x25c00098, 0x4020b118, 0x5120b180, 0x59c01402, 0x26c000d0, 
	0x5a403c42, 0x258000a0, 0x8805dc00, 0x52a0b180, 0x26900028, 0xc005ec00, 
	0x51a0a600, 0x258003d8, 0x298000d8, 0x8805ec00, 0x51a0a580, 0x25800118, 
	0x8805ec00, 0x25800060, 0x8005ec00, 0x22820028, 0x5120b280, 0x25000110, 
	0x8005ea00, 0x22810028, 0x263fffa0, 0x48403c62, 0x5a406042, 0x4020b320, 
	0x5a406442, 0x4020b3a0, 0x5a406842, 0x4020b420, 0x5120b100, 0x4020b1a8, 
	0x22c000a8, 0x80062900, 0x2daa8f00, 0x2f05f904, 0xc0085200, 0x52a0a580, 
	0x26800128, 0x8005ff00, 0x52a0b180, 0x2683bfe8, 0x4020b1a8, 0x2ea0b100, 
	0x2d800d00, 0x56400540, 0x27803fe0, 0x33800620, 0x01800098, 0x88060100, 
	0x26080010, 0x80061600, 0x51a0a984, 0x24000040, 0x01c0001d, 0x2d800040, 
	0x4000cb18, 0x4000cc19, 0x2d801e00, 0x11c00018, 0x4000c018, 0x40001018, 
	0xe0400000, 0x2f400184, 0xe0001e00, 0x2fc00180, 0x2f061804, 0xc0089400, 
	0x25800098, 0x80061f00, 0x2f061c04, 0xc0087000, 0x2d800080, 0x40005018, 
	0xc0062f00, 0x51808200, 0x51008280, 0x402a9118, 0x402a9190, 0x51aa9100, 
	0x512a9200, 0x29c00098, 0x80062900, 0x2d800040, 0x40005018, 0x51a0a580, 
	0x25800218, 0x88001c00, 0x51a0a600, 0x25804018, 0x88001c00, 0x4840000a, 
	0xc0001c00, 0x40206f80, 0x58402402, 0x24004000, 0x8005ce00, 0x31800750, 
	0x11a29e18, 0x2e4000c4, 0x2f063a04, 0xc0085200, 0x59401102, 0x4020b810, 
	0x59401502, 0x4020b890, 0x2d800040, 0x4000cb18, 0x2da03800, 0x4000cc18, 
	0x2d206a00, 0x50400080, 0x2d803180, 0x4000c018, 0x40001018, 0x2e3fffc0, 
	0x51a0a600, 0x258003d8, 0x2a800198, 0x80064f00, 0x52a0b100, 0x26880028, 
	0x80065400, 0x5ac02002, 0x26c00168, 0x80065400, 0x3180062c, 0x26003fe8, 
	0x25800040, 0x11c000c0, 0x2e800000, 0x02400020, 0x8c065d00, 0x12400020, 
	0x02c00100, 0x2c400100, 0x2e000000, 0xe0400000, 0x2fc00180, 0xe0400140, 
	0x2f400184, 0xe0400140, 0x2fc000c2, 0x25800040, 0x80066600, 0x2dc00180, 
	0x5c400480, 0x24400000, 0x88065400, 0x51801000, 0xe04000c0, 0x2c400180, 
	0x2f066e04, 0xc0089400, 0x50008200, 0x51008280, 0x48401102, 0x48401512, 
	0x48402102, 0x48402512, 0x58402902, 0x59402d02, 0x10000040, 0x19000010, 
	0x48402902, 0x48402d12, 0x4020b900, 0x4020b990, 0x59403502, 0x00400080, 
	0x9805ce00, 0x58403102, 0x24000040, 0x8805ce00, 0x5020b180, 0x20100000, 
	0x4020b180, 0x50206f80, 0xc005ce00, 0x2d800040, 0x2f068a04, 0xc007b100, 
	0x2d400180, 0x2c000000, 0x4000cb00, 0x2c000180, 0x4000c000, 0x2c400180, 
	0x31800780, 0x258000c4, 0x3180021d, 0x22c0019d, 0x32000234, 0x224001a5, 
	0x31800234, 0x21c0019d, 0x2caa9304, 0x58c01c42, 0x2403ffc8, 0x284000c0, 
	0x8006ad00, 0x2caaa504, 0x58c01c42, 0x2403ffc8, 0x284000c0, 0x8006ad00, 
	0x2caab704, 0x58c01c42, 0x2403ffc8, 0x284000c0, 0x8006ad00, 0x2caac904, 
	0x58c01c42, 0x2403ffc8, 0x284000c0, 0x8006ad00, 0xc0001c00, 0x24200008, 
	0x8006b200, 0x4840606b, 0x48406463, 0x4840685b, 0x2e000080, 0x4000cb20, 
	0x52206980, 0x4000cc20, 0xc0008800, 0x2c000100, 0x40005000, 0x58403042, 
	0x25800c00, 0x80001c00, 0x2c000400, 0x4000c800, 0x2c0000c0, 0x4000c900, 
	0x2c0011c0, 0x4000ca00, 0x2c000000, 0x4000c800, 0x5020a300, 0x31000600, 
	0x4000ca10, 0x4000ca00, 0x2c000040, 0x4000c900, 0x2c002e40, 0x59401842, 
	0x25000410, 0x8806cf00, 0x2c002000, 0x4000c000, 0xe0400000, 0x2c400180, 
	0xc0001c00, 0x51a0a600, 0x25802018, 0x8006e500, 0x51a0a680, 0x2a3c0018, 
	0x8006e500, 0x5ac030c0, 0x268003a8, 0x2a800028, 0x8806e500, 0x2f06df04, 
	0xc0085200, 0x2f802d00, 0x2f800000, 0x2f800000, 0x2f800040, 0x2f802d00, 
	0xc0070800, 0x24bdffc8, 0x2e800400, 0xc0070500, 0x2e900000, 0xc0070500, 
	0x2e800080, 0xc0070500, 0x2e800100, 0xc0070500, 0x59400c02, 0x2abc0010, 
	0x8006e800, 0x2e800100, 0xc0070500, 0x2e802000, 0xc0070500, 0x2a000128, 
	0x80070400, 0x2a000328, 0x80070400, 0x2a000228, 0x80070400, 0xc005bc00, 
	0x51a0b100, 0x21a00018, 0x4020b118, 0x51a0b180, 0x25bfbfd8, 0x4020b198, 
	0x2f070804, 0xc0087000, 0x2e800200, 0x51a0b100, 0x21c00158, 0x4020b118, 
	0x2f070a04, 0xc0089400, 0x25800098, 0x80071f00, 0x51a0b100, 0x21a00018, 
	0x4020b118, 0x51a0a600, 0x25818018, 0x80071d00, 0x2e008200, 0x31800718, 
	0x12c000e0, 0x55c00540, 0x55400540, 0x5220a680, 0x12000220, 0x44400518, 
	0x44400510, 0x44400518, 0x44400510, 0x2f071f04, 0xc0087000, 0x5020a600, 
	0x240003c0, 0x01800040, 0x80072c00, 0x01800080, 0x80073700, 0x59c01802, 
	0x293c0018, 0x80073800, 0x594054c0, 0x253fdfd0, 0x484054d0, 0xc0073800, 
	0x50008700, 0x2d800040, 0x40009718, 0x40009798, 0x51809700, 0x25800058, 
	0x88073000, 0x40008700, 0x40008780, 0x24bf7fc8, 0xc0073800, 0x24be7fc8, 
	0x2f073a04, 0xc008ab00, 0x5120b180, 0x25008010, 0x8005bc00, 0x5120b100, 
	0x29000410, 0x8805bc00, 0x51001000, 0x25400090, 0x8005bc00, 0x58401842, 
	0x24000400, 0x8801e900, 0xc005bc00, 0x512a9680, 0x2503ffd0, 0x29002010, 
	0x80074e00, 0x59401c42, 0x25200010, 0x88075500, 0x52005200, 0x51005280, 
	0x52805300, 0x26a07fe8, 0x48406062, 0x48406452, 0x4840686a, 0x5120ac80, 
	0x25000090, 0x80075a00, 0x2c3fffc0, 0x2cbfffc0, 0x59401042, 0x40002010, 
	0x59401442, 0x40002090, 0x40002188, 0x2d000040, 0x40002110, 0x51002100, 
	0x25400090, 0x88076100, 0x51002200, 0x24a00010, 0x88079200, 0x58401046, 
	0x00200005, 0x300007c5, 0x10400085, 0x30800201, 0x4020b208, 0x30800101, 
	0x30000085, 0x10400045, 0x1020be05, 0x58c00402, 0x10800048, 0x4840040a, 
	0x2e3c0000, 0x58c01002, 0x24803fc8, 0x2a803fc8, 0x80077b00, 0x32000148, 
	0x12229e20, 0x4020a6a0, 0x58c03100, 0x4020a808, 0x58c00802, 0x4020a608, 
	0x2e000000, 0x248003c8, 0x288000c8, 0x88078b00, 0x5220a300, 0x5ac01c02, 
	0x26400020, 0x22400160, 0x4020a320, 0x2e000040, 0x4020a5a0, 0x58c00002, 
	0x58402402, 0x24004000, 0x88079100, 0x2c000000, 0x4000cb00, 0xc0400182, 
	0x2c800000, 0x4000cb08, 0x2cbfffc0, 0x4020b208, 0x5120ae00, 0x50a0ae80, 
	0x2c3fffc0, 0x00afbbc8, 0x80076700, 0x58c03042, 0x24000c0c, 0x8806bc00, 
	0x2400400c, 0x80001c00, 0x52a07200, 0x24800068, 0x80001c00, 0x2e000200, 
	0x4020a5a0, 0x24800328, 0x30800788, 0x2caa9304, 0xe0400040, 0x1080120d, 
	0x58c03442, 0x4020a688, 0x58c03040, 0x4020a808, 0x2c800000, 0x4020a608, 
	0xc0400182, 0x40207008, 0x2483ffd8, 0x8007d100, 0x50a0a580, 0x24804008, 
	0x8807d100, 0x40207090, 0x51206f00, 0x10800090, 0x40206f08, 0x10a06a10, 
	0x25080018, 0x8007c300, 0x59402402, 0x25008010, 0x8007c300, 0x2d0000c0, 
	0x4000cb10, 0x4000c018, 0x2503ffd8, 0x40400050, 0x50801000, 0x00c00088, 
	0x40207108, 0x24800050, 0x8007cc00, 0x11000050, 0x50a06980, 0x11400050, 
	0x40206990, 0x4000cc10, 0x51207080, 0x50a07000, 0xc0400182, 0x59401402, 
	0x25004010, 0x80400182, 0x59c02406, 0x25803fdd, 0x11a5ff1d, 0x2d20ba84, 
	0x40002c11, 0x59400cc2, 0x40002c90, 0x594008c2, 0x40002e10, 0x2d000000, 
	0x40002d90, 0x5220b180, 0x26008020, 0x8807ec00, 0x5a4000c6, 0x263fff21, 
	0x8007ed00, 0x2a003fa5, 0x52001000, 0x12400125, 0x404000a3, 0x2d000040, 
	0x2e000004, 0x2d20b104, 0x40002d10, 0x48402c92, 0x40002ea1, 0xc0400182, 
	0x5a401402, 0x26004020, 0x80082700, 0x59c02406, 0x25803fdd, 0x11a5ff1d, 
	0x51002e80, 0x484000d2, 0x51002d00, 0x25400090, 0x80082700, 0x020001d0, 
	0x90081a00, 0x2d20ba84, 0x01800050, 0x31800058, 0x114000d5, 0x52c00082, 
	0x263fc028, 0x80080f00, 0x01824020, 0x88081a00, 0x59c008c2, 0x25a00018, 
	0x80081a00, 0x02800068, 0x404000aa, 0x8c081a00, 0xc0081500, 0x59c008c2, 
	0x25a00018, 0x88081a00, 0x028000a8, 0x404000aa, 0x8c081a00, 0x26803fe8, 
	0x22c00128, 0x484000ea, 0x01000050, 0x80082700, 0x2d20b104, 0x48402c92, 
	0x51a0a680, 0x5a4028c0, 0x59402cc0, 0x2e800040, 0x12400160, 0x19000010, 
	0x484030a2, 0x48403492, 0x59400482, 0x21004010, 0x48400492, 0x2d003fc0, 
	0x40002d10, 0xc0400182, 0x2d003fc0, 0x40002d10, 0xc0400182, 0x56c00504, 
	0x4440052b, 0x56c00504, 0x4440052b, 0x56c00504, 0x4440052b, 0x56c00504, 
	0x4440052b, 0xc0400182, 0x5220ac00, 0x26000060, 0x88083600, 0x5220a880, 
	0x263fffa0, 0x4020a8a0, 0xc0400182, 0x5220af80, 0x52003884, 0x26000065, 
	0x80084d00, 0x02000060, 0x88083e00, 0x52004c04, 0x402d7fa1, 0x2e000004, 
	0x400038a1, 0x5220a904, 0x12000065, 0x0a000025, 0x4020a921, 0x52200000, 
	0xc0084e00, 0x52003780, 0x5220a884, 0x22000065, 0x4020a8a1, 0xc0400182, 
	0x2e008000, 0x2e800200, 0x554004c4, 0x44400511, 0x02800068, 0x88085400, 
	0x2d800000, 0x52008000, 0x52808300, 0x2a400160, 0x88085e00, 0x2d800040, 
	0x40008418, 0x40008498, 0xc0400182, 0x5020a600, 0x24018000, 0x80086f00, 
	0x2e008300, 0x30000700, 0x12c00020, 0x55c00540, 0x54400540, 0x44400518, 
	0x44400500, 0x52a0a680, 0x12800328, 0x44400558, 0x44400540, 0xc0400182, 
	0x2d800380, 0x40008718, 0x40008798, 0x5120ad00, 0x51a0ad80, 0x40008210, 
	0x40008298, 0x40008098, 0x40008398, 0x2d800000, 0x40008118, 0x40008198, 
	0x51a0a880, 0x25bffed8, 0x4020a898, 0x51a0ac00, 0x25800098, 0x88087f00, 
	0x2d8001c0, 0x40008618, 0x40008698, 0x2d8003c0, 0x40008718, 0x40008798, 
	0x51808600, 0x25000058, 0x88088800, 0x5120a880, 0x21000110, 0x4020a890, 
	0x2d000100, 0x40008610, 0x40008690, 0x25800098, 0x88087000, 0xc0400182, 
	0x51a0a880, 0x25bffed8, 0x4020a898, 0x51a0ac00, 0x25800098, 0x88089700, 
	0x2d8001c0, 0x40008618, 0x40008698, 0x2e3fffc0, 0x02000060, 0x8008a400, 
	0x51808600, 0x29000058, 0x253ffed0, 0x80089e00, 0x5220a880, 0x22000120, 
	0x4020a8a0, 0x2e000100, 0x40008620, 0x400086a0, 0xc0400182, 0x51a0a680, 
	0x293c0018, 0x8008b700, 0x5120a600, 0x25018010, 0x8808b700, 0x594020c0, 
	0x584024c0, 0x484010d0, 0x40008210, 0x484014c0, 0x40008280, 0xc0400182, 
	0x5ac00942, 0x59400d42, 0x26bffc28, 0x12800428, 0x19000010, 0x02c00140, 
	0x09400098, 0x9808c500, 0x58400142, 0x59c00542, 0x10400140, 0x19c00098, 
	0xc008b800, 0xc0400182, 0x51a0a380, 0x25800c18, 0x29800818, 0x80098900, 
	0x51c00080, 0x25c000d8, 0x8006ec00, 0x263c0018, 0x32000520, 0x25801c18, 
	0x28001818, 0x8808d300, 0x2d800400, 0x318007d8, 0x21c000e0, 0x40044018, 
	0x59c00480, 0x24000058, 0x40046080, 0x24000198, 0x300007c0, 0x40046400, 
	0x2c400100, 0x2a000120, 0x8808e900, 0x2e203000, 0x2e044c04, 0x2f08e304, 
	0xc0082d00, 0x2f08e504, 0xc0082d00, 0x2f08e704, 0xc0082d00, 0x2f08e904, 
	0xc0082d00, 0x26800048, 0x8008f000, 0x51c00080, 0x25800098, 0x8006ee00, 
	0x12000310, 0xc008f400, 0x51c00080, 0x25800058, 0x8006ee00, 0x12000110, 
	0x2a0000c4, 0x80090500, 0x2a000144, 0x80090500, 0x2e044404, 0x2f08fb04, 
	0xc0082d00, 0x52040204, 0x26000065, 0x80090000, 0x40040221, 0xc006ee00, 
	0x12000220, 0x2e044a04, 0x2f090404, 0xc0082d00, 0xc0091b00, 0x2e044e04, 
	0x2f090804, 0xc0082d00, 0x26c00168, 0x88090c00, 0x12000220, 0xc0090d00, 
	0x12000620, 0x2e045004, 0x2f091004, 0xc0082d00, 0x52040204, 0x26000065, 
	0x80091500, 0x40040221, 0xc006ee00, 0x2e044a04, 0x2f091804, 0xc0082d00, 
	0x2e044c04, 0x2f091b04, 0xc0082d00, 0x2c080000, 0x4020ab00, 0x50046100, 
	0x243f83c0, 0x51c00080, 0x25802018, 0x80092300, 0x20001800, 0x59c00480, 
	0x25801c18, 0x204000c0, 0x40046100, 0x58401842, 0x24000400, 0x88092e00, 
	0x2e002080, 0x2e800080, 0x40046028, 0xc0094a00, 0x2e002f00, 0x5020a380, 
	0x24000800, 0x80094100, 0x2d800040, 0x2f093504, 0xc007b100, 0x2ec00080, 
	0x2d400180, 0x11800150, 0x50400140, 0x24000100, 0x80093e00, 0x118004d8, 
	0x25bffc18, 0x01800118, 0x40046018, 0x2e800140, 0xc0094a00, 0x50400080, 
	0x24000100, 0x80094800, 0x2e800300, 0x40046028, 0x2e800100, 0xc0094a00, 
	0x2e800100, 0x40046028, 0x2c000000, 0x40206f00, 0x2e206a04, 0xe0000100, 
	0x44400502, 0x2c203800, 0x4000cc00, 0x40206980, 0x50046100, 0x243ffdc0, 
	0x40046100, 0x400461a0, 0x2c000c00, 0x4000cf00, 0x2c000040, 0x4000cd00, 
	0x21880028, 0x2f095d04, 0xc007b100, 0x2e050004, 0x000020a0, 0x80096400, 
	0x5020a980, 0x20400102, 0x4000ce00, 0x2e000004, 0x51a0aa80, 0x30000618, 
	0x20400102, 0x4000ce00, 0x24003fd8, 0x4000ce00, 0x01c00160, 0x000020a0, 
	0x80097300, 0x5020a380, 0x4000ce00, 0x24000800, 0x80097300, 0x4000ce10, 
	0x02800068, 0xe0000780, 0x24400000, 0x2c001a00, 0x4000cf00, 0x2c000000, 
	0x4000cd00, 0x40001018, 0x21880018, 0x2f097d04, 0xc007b100, 0x40001020, 
	0xe0400140, 0x2c400180, 0x5020a580, 0x20004000, 0x4020a580, 0x58402402, 
	0x24008000, 0x80098900, 0x40206a20, 0x2c000000, 0x40206a80, 0xc0011600 };

#ifdef ST_OSLINUX

#ifndef __KERNEL__
#  define __KERNEL__
#endif
#ifndef MODULE
#  define MODULE
#endif
#include <linux/config.h>
#include <linux/module.h>
#include <linux/kernel.h>   /* printk() */
#include "compat.h"

#endif  /* ST_OSLINUX */

#include "stddefs.h"
#include "../stpti/pti4/tcdefs.h"
#include "../stpti/stptiint.h"

#if !defined( ST_OSLINUX )
#include "stsys.h"
#endif  /* ST_OSLINUX */


#if ((0XABB8-0X8000) > 0X3800)
#error TCCODE data ram overflow
#endif

#if (TRANSPORT_CONTROLLER_CODE_SIZE > 0X0D00)
#error TCCODE instruction ram overflow
#endif


ST_ErrorCode_t STPTI_DVBTCLoaderSL(STPTI_DevicePtr_t CodeStart, void * Params_p)
{
    U32 PTI4_Base = (U32)((U32)CodeStart - 0XC000); 

    STPTI_TCParameters_t * TC_Params_p = Params_p;

#ifdef ST_OSLINUX
    printk(KERN_ALERT "pticore: LoaderFunction called\n");
#endif

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

    TC_Params_p->TC_CodeStart                  = CodeStart;
    TC_Params_p->TC_CodeSize                   = TRANSPORT_CONTROLLER_CODE_SIZE * sizeof(U32);
    TC_Params_p->TC_DataStart                  = (U32*)(((U32)PTI4_Base) + 0X8000);

    TC_Params_p->TC_LookupTableStart           = (U32*)(((U32)PTI4_Base) + 0X8000);
    TC_Params_p->TC_SystemKeyStart             = (U32*)(((U32)PTI4_Base) + 0X80C0);
    TC_Params_p->TC_GlobalDataStart            = (U32*)(((U32)PTI4_Base) + 0X828C);
    TC_Params_p->TC_StatusBlockStart           = (U32*)(((U32)PTI4_Base) + 0X82C4);
    TC_Params_p->TC_MainInfoStart              = (U32*)(((U32)PTI4_Base) + 0X82F8);
    TC_Params_p->TC_DMAConfigStart             = (U32*)(((U32)PTI4_Base) + 0X8A78);
    TC_Params_p->TC_DescramblerKeysStart       = (U32*)(((U32)PTI4_Base) + 0X9158);
    TC_Params_p->TC_TransportFilterStart       = (U32*)(((U32)PTI4_Base) + 0X97FC);
    TC_Params_p->TC_SCDFilterTableStart        = (U32*)(((U32)PTI4_Base) + 0X97FC);
    TC_Params_p->TC_PESFilterStart             = (U32*)(((U32)PTI4_Base) + 0X983C);
    TC_Params_p->TC_SubstituteDataStart        = (U32*)(((U32)PTI4_Base) + 0X81C8);
    TC_Params_p->TC_SFStatusStart              = (U32*)(((U32)PTI4_Base) + 0X983C);
    TC_Params_p->TC_InterruptDMAConfigStart    = (U32*)(((U32)PTI4_Base) + 0XAA3C);
    TC_Params_p->TC_SessionDataStart           = (U32*)(((U32)PTI4_Base) + 0XAA4C);
    TC_Params_p->TC_EMMStart                   = (U32*)(((U32)PTI4_Base) + 0XAB6C);
    TC_Params_p->TC_ECMStart                   = (U32*)(((U32)PTI4_Base) + 0XAB6C);
    TC_Params_p->TC_VersionID                  = (U32*)(((U32)PTI4_Base) + 0XABAC);

    TC_Params_p->TC_NumberCarousels            = 0X0001;
    TC_Params_p->TC_NumberSystemKeys           = 0X0001;
    TC_Params_p->TC_NumberDMAs                 = 0X0037;
    TC_Params_p->TC_NumberDescramblerKeys      = 0X0019;
    TC_Params_p->TC_SizeOfDescramblerKeys      = 0X0044;
    TC_Params_p->TC_NumberPesFilters           = 0X0000;
    TC_Params_p->TC_NumberSectionFilters       = 0X0060;
    TC_Params_p->TC_NumberSlots                = 0X0060;
    TC_Params_p->TC_NumberOfSessions           = 0X0004;
    TC_Params_p->TC_NumberIndexs               = 0X0060;
    TC_Params_p->TC_NumberTransportFilters     = 0X0000;
    TC_Params_p->TC_NumberSCDFilters           = 0X0008;

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

        for(i = 0; i < 0X0D00; ++i)
        {
            STSYS_WriteRegDev32LE( (U32)&CodeStart[i], 0x00 );
        }

        for(i = 0; i < TRANSPORT_CONTROLLER_CODE_SIZE; ++i)
        {
            STSYS_WriteRegDev32LE( (U32)&CodeStart[i], transport_controller_code[i] );
        }
        
        STSYS_WriteRegDev32LE( (U32)&(TC_Params_p->TC_VersionID[0]), 0X5354 | (0X5054<<16) );
        STSYS_WriteRegDev32LE( (U32)&(TC_Params_p->TC_VersionID[1]), 0X4934 | (0X0005<<16) );
        STSYS_WriteRegDev32LE( (U32)&(TC_Params_p->TC_VersionID[2]), 0X0670 | (0X0000<<16) );
    }

#ifdef ST_OSLINUX
    printk(KERN_ALERT "pticore:TC code loaded\n");
#endif

    return ST_NO_ERROR;

}
