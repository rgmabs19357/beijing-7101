/*******************************************************************************

File name   : blt_tab.c

Description : Contains conversion tables

COPYRIGHT (C) STMicroelectronics 2000.

Date               Modification                                     Name
----               ------------                                     ----
Mar 2001           Created                                          TM
*******************************************************************************/

/* Private preliminary definitions (internal use only) ---------------------- */


/* Includes ----------------------------------------------------------------- */

#include "stddefs.h"


/* Private Types ------------------------------------------------------------ */


/* Private Constants -------------------------------------------------------- */


/* Private Variables (static)------------------------------------------------ */


/* Global Variables --------------------------------------------------------- */

const U16 stblit_TableROP[28][28]  =
{
 { 0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x202 ,0x202 ,0x202 ,0x202 ,0x202 ,0x202 ,0x21  ,0x8000,0x8000,0x31  ,0x8000,0x8000,0x29  ,0x8000,0x8000,0x39  ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x202 ,0x202 ,0x202 ,0x202 ,0x202 ,0x202 ,0x21  ,0x8000,0x8000,0x31  ,0x8000,0x8000,0x29  ,0x8000,0x8000,0x39  ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x202 ,0x202 ,0x202 ,0x202 ,0x202 ,0x202 ,0x21  ,0x8000,0x8000,0x31  ,0x8000,0x8000,0x29  ,0x8000,0x8000,0x39  ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x202 ,0x202 ,0x202 ,0x202 ,0x202 ,0x202 ,0x21  ,0x8000,0x8000,0x31  ,0x8000,0x8000,0x29  ,0x8000,0x8000,0x39  ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x202 ,0x202 ,0x202 ,0x202 ,0x202 ,0x202 ,0x21  ,0x8000,0x8000,0x31  ,0x8000,0x8000,0x29  ,0x8000,0x8000,0x39  ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x202 ,0x202 ,0x202 ,0x202 ,0x202 ,0x202 ,0x21  ,0x8000,0x8000,0x31  ,0x8000,0x8000,0x29  ,0x8000,0x8000,0x39  ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x0   ,0x4000,0x4000,0x4000,0x4000,0x4000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x4000,0x0   ,0x4000,0x4000,0x4000,0x4000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x4000,0x4000,0x0   ,0x4000,0x4000,0x4000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x4000,0x4000,0x4000,0x0   ,0x4000,0x4000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x8000,0x8000,0x0   ,0x8000,0x0   ,0x4000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x8000,0x8000,0x8000,0x0   ,0x8000,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x1   ,0x1   ,0x1   ,0x1   ,0x1   ,0x1   ,0x203 ,0x203 ,0x203 ,0x203 ,0x203 ,0x203 ,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x1   ,0x1   ,0x1   ,0x1   ,0x1   ,0x1   ,0x203 ,0x203 ,0x203 ,0x203 ,0x203 ,0x203 ,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x11  ,0x11  ,0x11  ,0x11  ,0x11  ,0x11  ,0x213 ,0x213 ,0x213 ,0x213 ,0x213 ,0x213 ,0x8000,0x8000,0x8000,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x11  ,0x11  ,0x11  ,0x11  ,0x11  ,0x11  ,0x213 ,0x213 ,0x213 ,0x213 ,0x213 ,0x213 ,0x8000,0x8000,0x8000,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x9   ,0x9   ,0x9   ,0x9   ,0x9   ,0x9   ,0x20B ,0x20B ,0x20B ,0x20B ,0x20B ,0x20B ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x9   ,0x9   ,0x9   ,0x9   ,0x9   ,0x9   ,0x20B ,0x20B ,0x20B ,0x20B ,0x20B ,0x20B ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x19  ,0x19  ,0x19  ,0x19  ,0x19  ,0x19  ,0x21B ,0x21B ,0x21B ,0x21B ,0x21B ,0x21B ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x19  ,0x19  ,0x19  ,0x19  ,0x19  ,0x19  ,0x21B ,0x21B ,0x21B ,0x21B ,0x21B ,0x21B ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 }
};

const U16 stblit_TableBlend[28][28]  =
{
 { 0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x21  ,0x8000,0x8000,0x31  ,0x8000,0x8000,0x29  ,0x8000,0x8000,0x39  ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x21  ,0x8000,0x8000,0x31  ,0x8000,0x8000,0x29  ,0x8000,0x8000,0x39  ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x21  ,0x8000,0x8000,0x31  ,0x8000,0x8000,0x29  ,0x8000,0x8000,0x39  ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x21  ,0x8000,0x8000,0x31  ,0x8000,0x8000,0x29  ,0x8000,0x8000,0x39  ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x21  ,0x8000,0x8000,0x31  ,0x8000,0x8000,0x29  ,0x8000,0x8000,0x39  ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x21  ,0x8000,0x8000,0x31  ,0x8000,0x8000,0x29  ,0x8000,0x8000,0x39  ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x1   ,0x1   ,0x1   ,0x1   ,0x1   ,0x1   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x1   ,0x1   ,0x1   ,0x1   ,0x1   ,0x1   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x11  ,0x11  ,0x11  ,0x11  ,0x11  ,0x11  ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x11  ,0x11  ,0x11  ,0x11  ,0x11  ,0x11  ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x9   ,0x9   ,0x9   ,0x9   ,0x9   ,0x9   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x9   ,0x9   ,0x9   ,0x9   ,0x9   ,0x9   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x19  ,0x19  ,0x19  ,0x19  ,0x19  ,0x19  ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x19  ,0x19  ,0x19  ,0x19  ,0x19  ,0x19  ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 }
 };


const U16 stblit_TableSingleSrc2[28][28]  =
{
 { 0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x202 ,0x202 ,0x202 ,0x202 ,0x202 ,0x202 ,0x4   ,0x4   ,0x8000,0x84  ,0x84  ,0x8000,0x44  ,0x44  ,0x8000,0xC4  ,0xC4  ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x202 ,0x202 ,0x202 ,0x202 ,0x202 ,0x202 ,0x4   ,0x4   ,0x8000,0x84  ,0x84  ,0x8000,0x44  ,0x44  ,0x8000,0xC4  ,0xC4  ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x202 ,0x202 ,0x202 ,0x202 ,0x202 ,0x202 ,0x4   ,0x4   ,0x8000,0x84  ,0x84  ,0x8000,0x44  ,0x44  ,0x8000,0xC4  ,0xC4  ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x202 ,0x202 ,0x202 ,0x202 ,0x202 ,0x202 ,0x4   ,0x4   ,0x8000,0x84  ,0x84  ,0x8000,0x44  ,0x44  ,0x8000,0xC4  ,0xC4  ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x202 ,0x202 ,0x202 ,0x202 ,0x202 ,0x202 ,0x4   ,0x4   ,0x8000,0x84  ,0x84  ,0x8000,0x44  ,0x44  ,0x8000,0xC4  ,0xC4  ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x202 ,0x202 ,0x202 ,0x202 ,0x202 ,0x202 ,0x4   ,0x4   ,0x8000,0x84  ,0x84  ,0x8000,0x44  ,0x44  ,0x8000,0xC4  ,0xC4  ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x0   ,0x4000,0x4000,0x4000,0x4000,0x4000,0x6   ,0x6   ,0x8000,0x86  ,0x86  ,0x8000,0x46  ,0x46  ,0x8000,0xC6  ,0xC6  ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x4000,0x0   ,0x4000,0x4000,0x4000,0x4000,0x6   ,0x6   ,0x8000,0x86  ,0x86  ,0x8000,0x46  ,0x46  ,0x8000,0xC6  ,0xC6  ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x4000,0x4000,0x0   ,0x4000,0x4000,0x4000,0x6   ,0x6   ,0x8000,0x86  ,0x86  ,0x8000,0x46  ,0x46  ,0x8000,0xC6  ,0xC6  ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x4000,0x4000,0x4000,0x0   ,0x4000,0x4000,0x6   ,0x6   ,0x8000,0x86  ,0x86  ,0x8000,0x46  ,0x46  ,0x8000,0xC6  ,0xC6  ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x8000,0x8000,0x0   ,0x8000,0x0   ,0x4000,0x6   ,0x6   ,0x8000,0x86  ,0x86  ,0x8000,0x46  ,0x46  ,0x8000,0xC6  ,0xC6  ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x2   ,0x8000,0x8000,0x8000,0x0   ,0x8000,0x0   ,0x6   ,0x6   ,0x8000,0x86  ,0x86  ,0x8000,0x46  ,0x46  ,0x8000,0xC6  ,0xC6  ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x1   ,0x1   ,0x1   ,0x1   ,0x1   ,0x1   ,0x203 ,0x203 ,0x203 ,0x203 ,0x203 ,0x203 ,0x0   ,0x0   ,0x8000,0x85  ,0x85  ,0x8000,0x45  ,0x45  ,0x8000,0xC5  ,0xC5  ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x1   ,0x1   ,0x1   ,0x1   ,0x1   ,0x1   ,0x203 ,0x203 ,0x203 ,0x203 ,0x203 ,0x203 ,0x0   ,0x0   ,0x8000,0x85  ,0x85  ,0x8000,0x45  ,0x45  ,0x8000,0xC5  ,0xC5  ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x11  ,0x11  ,0x11  ,0x11  ,0x11  ,0x11  ,0x213 ,0x213 ,0x213 ,0x213 ,0x213 ,0x213 ,0x15  ,0x15  ,0x8000,0x0   ,0x0   ,0x8000,0x55  ,0x55  ,0x8000,0xD5  ,0xD5  ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x11  ,0x11  ,0x11  ,0x11  ,0x11  ,0x11  ,0x213 ,0x213 ,0x213 ,0x213 ,0x213 ,0x213 ,0x15  ,0x15  ,0x8000,0x0   ,0x0   ,0x8000,0x55  ,0x55  ,0x8000,0xD5  ,0xD5  ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x9   ,0x9   ,0x9   ,0x9   ,0x9   ,0x9   ,0x20B ,0x20B ,0x20B ,0x20B ,0x20B ,0x20B ,0xD   ,0xD   ,0x8000,0x8D  ,0x8D  ,0x8000,0x0   ,0x0   ,0x8000,0xCD  ,0xCD  ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x9   ,0x9   ,0x9   ,0x9   ,0x9   ,0x9   ,0x20B ,0x20B ,0x20B ,0x20B ,0x20B ,0x20B ,0xD   ,0xD   ,0x8000,0x8D  ,0x8D  ,0x8000,0x0   ,0x0   ,0x8000,0xCD  ,0xCD  ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x19  ,0x19  ,0x19  ,0x19  ,0x19  ,0x19  ,0x21B ,0x21B ,0x21B ,0x21B ,0x21B ,0x21B ,0x1D  ,0x1D  ,0x8000,0x9D  ,0x9D  ,0x8000,0x5D  ,0x5D  ,0x8000,0x0   ,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x19  ,0x19  ,0x19  ,0x19  ,0x19  ,0x19  ,0x21B ,0x21B ,0x21B ,0x21B ,0x21B ,0x21B ,0x1D  ,0x1D  ,0x8000,0x9D  ,0x9D  ,0x8000,0x5D  ,0x5D  ,0x8000,0x0   ,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 }
 };

const U16 stblit_TableMB[28][28]  =
{
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x1   ,0x1   ,0x1   ,0x1   ,0x1   ,0x1   ,0x203 ,0x203 ,0x203 ,0x203 ,0x203 ,0x203 ,0x0   ,0x0   ,0x8000,0x85  ,0x85  ,0x8000,0x45  ,0x45  ,0x8000,0xC5  ,0xC5  ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x1   ,0x1   ,0x1   ,0x1   ,0x1   ,0x1   ,0x203 ,0x203 ,0x203 ,0x203 ,0x203 ,0x203 ,0x0   ,0x0   ,0x8000,0x85  ,0x85  ,0x8000,0x45  ,0x45  ,0x8000,0xC5  ,0xC5  ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x11  ,0x11  ,0x11  ,0x11  ,0x11  ,0x11  ,0x213 ,0x213 ,0x213 ,0x213 ,0x213 ,0x213 ,0x15  ,0x15  ,0x8000,0x0   ,0x0   ,0x8000,0x55  ,0x55  ,0x8000,0xD5  ,0xD5  ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x11  ,0x11  ,0x11  ,0x11  ,0x11  ,0x11  ,0x213 ,0x213 ,0x213 ,0x213 ,0x213 ,0x213 ,0x15  ,0x15  ,0x8000,0x0   ,0x0   ,0x8000,0x55  ,0x55  ,0x8000,0xD5  ,0xD5  ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x9   ,0x9   ,0x9   ,0x9   ,0x9   ,0x9   ,0x20B ,0x20B ,0x20B ,0x20B ,0x20B ,0x20B ,0xD   ,0xD   ,0x8000,0x8D  ,0x8D  ,0x8000,0x0   ,0x0   ,0x8000,0xCD  ,0xCD  ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x9   ,0x9   ,0x9   ,0x9   ,0x9   ,0x9   ,0x20B ,0x20B ,0x20B ,0x20B ,0x20B ,0x20B ,0xD   ,0xD   ,0x8000,0x8D  ,0x8D  ,0x8000,0x0   ,0x0   ,0x8000,0xCD  ,0xCD  ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x19  ,0x19  ,0x19  ,0x19  ,0x19  ,0x19  ,0x21B ,0x21B ,0x21B ,0x21B ,0x21B ,0x21B ,0x1D  ,0x1D  ,0x8000,0x9D  ,0x9D  ,0x8000,0x5D  ,0x5D  ,0x8000,0x0   ,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x19  ,0x19  ,0x19  ,0x19  ,0x19  ,0x19  ,0x21B ,0x21B ,0x21B ,0x21B ,0x21B ,0x21B ,0x1D  ,0x1D  ,0x8000,0x9D  ,0x9D  ,0x8000,0x5D  ,0x5D  ,0x8000,0x0   ,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 }
 };

const U16 stblit_TableSingleSrc1[28][28]  =
{
 { 0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x4   ,0x4   ,0x8000,0x84  ,0x84  ,0x8000,0x44  ,0x44  ,0x8000,0xC4  ,0xC4  ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x4   ,0x4   ,0x8000,0x84  ,0x84  ,0x8000,0x44  ,0x44  ,0x8000,0xC4  ,0xC4  ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x4   ,0x4   ,0x8000,0x84  ,0x84  ,0x8000,0x44  ,0x44  ,0x8000,0xC4  ,0xC4  ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x4   ,0x4   ,0x8000,0x84  ,0x84  ,0x8000,0x44  ,0x44  ,0x8000,0xC4  ,0xC4  ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x4   ,0x4   ,0x8000,0x84  ,0x84  ,0x8000,0x44  ,0x44  ,0x8000,0xC4  ,0xC4  ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x4   ,0x4   ,0x8000,0x84  ,0x84  ,0x8000,0x44  ,0x44  ,0x8000,0xC4  ,0xC4  ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x0   ,0x8000,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x0   ,0x8000,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x24  ,0x24  ,0x24  ,0x24  ,0x24  ,0x24  ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x0   ,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0xA4  ,0xA4  ,0xA4  ,0xA4  ,0xA4  ,0xA4  ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x0   ,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x64  ,0x64  ,0x64  ,0x64  ,0x64  ,0x64  ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x0   ,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0xE4  ,0xE4  ,0xE4  ,0xE4  ,0xE4  ,0xE4  ,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x0   ,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x0   ,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 }
 };

/*
 const U16 TableRop[28][28]  =
{
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 },
 { 0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000 }
 };
 */


/* Private Macros ----------------------------------------------------------- */


/* Private Function prototypes ---------------------------------------------- */


/* Functions ---------------------------------------------------------------- */


/*******************************************************************************
Name        :
Description :
Parameters  :
Assumptions :
Limitations :
Returns     :
*******************************************************************************/



/*
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
*/


/* End of blt_tab.c */
