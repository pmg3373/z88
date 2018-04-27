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
extern StorageObject zero_const_stor;
extern StorageObject four_const_stor;
extern StorageObject six_const_stor;
extern StorageObject sixteen_const_stor;

//Masks
extern StorageObject imm_mask_stor;
extern StorageObject imm_sign_bit;

// Standard register set
extern Counter regs[32];
extern Counter pc;
extern StorageObject ir;
extern StorageObject iar;
extern StorageObject temp;
extern StorageObject extemp;

extern StorageObject a;
extern StorageObject b;
extern StorageObject c;
// ALUs
extern BusALU mainALU;


extern BusALU exALU;
// Memory
extern Memory dm;
extern Memory im;


// Additional registers for pipelining (If we need extra)

//IF-ID Stage Components
extern Clearable ifid_v;
extern StorageObject ifid_ir;
extern StorageObject ifid_pc;
extern StorageObject ifid_npc;
extern Bus ifid_bus;
extern BusALU ifid_alu;

//ID-EX Stage Components
extern StorageObject idex_a;
extern StorageObject idex_b;
extern StorageObject idex_ir;
extern StorageObject idex_imm;
extern StorageObject idex_temp;

extern Bus idex_a_bus;
extern Bus idex_b_bus;
extern Bus idex_ir_bus;
extern BusALU idex_imm_alu;

// EX/MEM
extern StorageObject exmem_ir;
extern StorageObject exmem_pc;
extern StorageObject exmem_ALUOutput;
extern StorageObject exmem_b;
extern StorageObject exmem_cond;

extern Bus exmem_ir_bus;
extern Bus exmem_ALUOutput_bus;
extern Bus exmem_b_bus;
extern Bus exmem_cond_bus;

// MEM/WB
extern StorageObject memwb_ir;
extern StorageObject memwb_ALUOutput;
extern StorageObject memwb_LMD;

extern Bus memwb_ir_bus;
extern Bus memwb_ALUOutput_bus;
extern Bus memwb_LMD_bus;
extern Bus memwb_bus;

//WB
extern Bus wb_ALUOutput_bus;
extern Bus wb_LMD_bus;

/* We should keep our construction of the registers consistent and stick to
 * just declaring them instead of using structs
// IF/ID
typedef struct if_id_register_struct {
    Clearable *v;
    StorageObject *ir;
    Counter *npc;
    StorageObject *cpc;
} if_id_reg;


// ID/EX
typedef struct id_ex_register_struct {
    StorageObject *a;
    StorageObject *b;
    StorageObject *ir;
    StorageObject *imm;
    StorageObject *cpc;
} id_ex_reg;


// EX/MEM
typedef struct ex_mem_register_struct {
    StorageObject *ir;
    StorageObject *ALUOutput;
    StorageObject *b;
    StorageObject *cond;
    StorageObject *cpc;
} ex_mem_reg;


// MEM/WB
typedef struct mem_wb_register_struct {
    StorageObject *ir;
    StorageObject *ALUOutput;
    StorageObject *LMD;
} mem_wb_reg; 
*/


// Constants


// The Krapf's yard
// Defined busses
extern Bus op1;
extern Bus op2;
extern Bus out;
extern Bus ifbus;
extern Bus exbus;


// Misc busses
// Fetch
extern Bus fPC;

// Decode

// Execute

// Memory

// WB

#endif
