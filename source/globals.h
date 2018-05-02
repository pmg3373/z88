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
extern bool jumping;
extern bool branching;
extern int stalled;
extern int regmod;
extern StorageObject zero_const_stor;
extern StorageObject four_const_stor;
extern StorageObject six_const_stor;
extern StorageObject sixteen_const_stor;

//Masks
extern StorageObject imm_mask_stor;
extern StorageObject sh_mask_stor; //
extern StorageObject sh_shift_stor; //
extern StorageObject target_mask_stor;
extern StorageObject low_five_bits_stor;
extern StorageObject imm_sign_bit_stor; //
extern StorageObject target_sign_bit_stor;
extern StorageObject jump_mask_stor;

// Standard register set
extern Counter* registerfile[32];
extern Counter pc; //
extern StorageObject ir;
extern StorageObject iar;
extern StorageObject temp;
extern StorageObject extemp;

extern StorageObject a;
extern StorageObject b;
extern StorageObject c;

// Memory
extern Memory dm; //
extern Memory im; //

// Additional registers for pipelining (If we need extra)

//IF-ID Stage Components
extern Clearable ifid_v;
extern StorageObject ifid_ir; //
extern Counter ifid_npc; //

extern StorageObject ifid_pc;

//ID-EX Stage Components
extern StorageObject idex_a; //
extern StorageObject idex_b; //
extern StorageObject idex_ir; //
extern StorageObject idex_imm; //
extern StorageObject idex_sh; //
extern StorageObject idex_temp_sh;

extern StorageObject idex_pc;

// EX/MEM
extern StorageObject exmem_ir; //
extern StorageObject exmem_aluoutput; //
extern StorageObject exmem_b; //
extern StorageObject exmem_temp;
extern StorageObject exmem_cond;
extern int exmem_operation_type;

extern StorageObject exmem_pc;

extern Bus exmem_ALUOutput_bus;
extern Bus exmem_b_bus;
extern Bus exmem_cond_bus;
extern BusALU exALU;
extern Bus exbus;

// MEM/WB
extern StorageObject memwb_ir; //
extern StorageObject memwb_aluoutput; //
extern StorageObject memwb_lmd; //
//extern int memwb_operation_type;
//extern int memwb_operation_type_prev;

extern StorageObject memwb_pc;



// The Krapf's yard
// Defined busses
extern Bus exbus;


// Fetch
extern Bus ifbus; //
extern BusALU ifalu; //
extern StorageObject iftemp; //
extern Bus ifpcbus;

// Decode
extern Bus id_a_bus; //
extern Bus id_b_bus; //
extern Bus id_ir_bus; //
extern Bus id_pc_bus;
extern BusALU id_imm_alu; //
extern BusALU id_sh_alu; //
extern BusALU id_j_alu;

extern StorageObject id_temp_sh; //
extern StorageObject id_temp_br;

// Execute
extern Bus ex_ir_bus;
extern Bus ex_b_bus;
extern Bus ex_pc_bus;

// Memory
extern Bus mem_ir_bus; //
extern Bus mem_alu_bus; //
extern Bus mem_pc_bus;

// WB
extern Bus wb_ALUOutput_bus;
extern Bus wb_LMD_bus;

#endif
