// globals.h
// author ddm9373
//
// Header file for all global components.  They're initialized in the
// corresponding cpp.

#ifndef _GLOBALS_H
#define _GLOBALS_H

#include "includes.h"

#define ADDR_BITS 32
#define DATA_BITS 32

// Useful global variables
extern bool done;


// Standard register set
extern Counter regs[32];
extern Counter pc;
extern StorageObject iar;
extern StorageObject temp;


// ALUs
extern BusALU mainALU;
extern BusALU ifALU;


// Memory
extern Memory dm;
extern Memory im;


// Additional registers for pipelining (If we need extra)


// IF/ID
typedef struct if_id_register_struct {
    Clearable *v;
    StorageObject *ir;
    StorageObject *npc;
} if_id_reg;


// ID/EX
typedef struct id_ex_register_struct {
    StorageObject *a;
    StorageObject *b;
    StorageObject *ir;
    StorageObject *imm;
} id_ex_reg;


// EX/MEM
typedef struct ex_mem_register_struct {
    StorageObject *ir;
    StorageObject *ALUOutput;
    StorageObject *b;
    StorageObject *cond;
} ex_mem_reg;


// MEM/WB
typedef struct mem_wb_register_struct {
    StorageObject *ir;
    StorageObject *ALUOutput;
    StorageObject *LMD
} mem_wb_reg;


// Constants


// The Krapf's yard
// Defined busses
extern Bus op1;
extern Bus op2;
extern Bus out;


// Misc busses


#endif
