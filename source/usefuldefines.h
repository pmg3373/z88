#ifndef _USEFULDEFINES_H
#define _USEFULDEFINES_H

#define RS(val) (((val) & 0x3E00000) >> 21)
#define RT(val) (((val) & 0x1F0000) >> 16)
#define RD(val) (((val) & 0xF800) >> 11)

#define OP(val) (((val) & 0xFC000000) >> 26)
#define FUN(val) (((val) & 0x3F))

#define REGS(val) (*registerfile[val])

#define IFSTALL 0x10
#define IDSTALL 0x8
#define EXSTALL 0x4
#define MEMSTALL 0x2
#define WBSTALL 0x1

#endif
