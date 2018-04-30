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
extern StorageObject sh_mask_stor;
extern StorageObject target_mask_stor;
extern StorageObject low_five_bits_stor;
extern StorageObject imm_sign_bit_stor;
extern StorageObject target_sign_bit_stor;

// Standard register set
extern Counter* regs;
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
extern Counter ifid_npc;
extern Bus ifid_bus;
extern BusALU ifid_alu;
extern Bus ifbus;

//ID-EX Stage Components
extern StorageObject idex_a;
extern StorageObject idex_b;
extern StorageObject idex_ir;
extern StorageObject idex_imm;
extern StorageObject idex_sh;
extern StorageObject idex_temp_imm;
extern StorageObject idex_temp_sh;

extern Bus idex_a_bus;
extern Bus idex_b_bus;
extern Bus idex_ir_bus;
extern BusALU idex_imm_alu;
extern BusALU idex_sh_alu;

// EX/MEM
extern StorageObject exmem_ir;
extern StorageObject exmem_pc;
extern StorageObject exmem_aluoutput;
extern StorageObject exmem_b;
extern StorageObject exmem_temp;
extern StorageObject exmem_cond;
extern int exmem_operation_type;

extern Bus exmem_ALUOutput_bus;
extern Bus exmem_b_bus;
extern Bus exmem_cond_bus;
extern BusALU exALU;
extern Bus exbus;

// MEM/WB
extern StorageObject memwb_ir;
extern StorageObject memwb_ALUOutput;
extern StorageObject memwb_LMD;
extern int memwb_operation_type;
extern int memwb_operation_type_prev;

extern Bus memwb_ir_bus;
extern Bus memwb_ALUOutput_bus;
extern Bus memwb_LMD_bus;
extern Bus memwb_bus;

//WB
extern Bus wb_ALUOutput_bus;
extern Bus wb_LMD_bus;
extern int wb_operation_type;

// The Krapf's yard
// Defined busses
extern Bus op1;
extern Bus op2;
extern Bus out;
extern Bus exbus;


// Misc busses
// Fetch
extern Bus ifbus;
extern BusALU ifalu;
extern StorageObject iftemp;

// Decode
extern Bus id_a_bus;
extern Bus id_b_bus;
extern Bus id_ir_bus;
extern BusALU id_imm_alu;

// Execute
extern Bus ex_ir_bus;

// Memory
extern Bus mem_ir_bus;
extern Bus mem_alu_bus;

// WB
extern Bus wb_ALUOutput_bus;
extern Bus wb_LMD_bus;

#endif
