#ifndef _USEFULDEFINES_H
#define _USEFULDEFINES_H

#define RS(val) (((val) & 0x3E00000) >> 21)
#define RT(val) (((val) & 0x1F0000) >> 16)
#define RD(val) (((val) & 0xF800) >> 11)

#endif
