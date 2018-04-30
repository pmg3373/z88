// globals.cpp
// author ddm9373
//
// initializing processor components

#include "includes.h"

// Useful global variables
bool done = false;
StorageObject zero_const_stor("zero", DATA_BITS, 0);
StorageObject six("six", DATA_BITS, 6);
StorageObject sixteen_const_stor("sixteen", DATA_BITS, 16);


// Masks
Constant imm_sign_bit_const("SignExtendConstant", DATA_BITS, 0xFFFF);
StorageObject imm_sign_bit("SignExtendRegister", DATA_BITS);


// Standard register set
Counter *regs;
Counter pc("PC", DATA_BITS);
StorageObject ir("IR", DATA_BITS);
StorageObject iar("IAR", DATA_BITS);
StorageObject temp("TEMP", DATA_BITS);
StorageObject extemp("EXTEMP", DATA_BITS);

StorageObject a("A", DATA_BITS);
StorageObject b("B", DATA_BITS);
StorageObject c("C", DATA_BITS);


// ALUs
BusALU mainALU("mainALU", DATA_BITS);
BusALU ifALU("ifALU", DATA_BITS);

BusALU exALU("exALU", DATA_BITS);


// Memory
Memory dm("Data Memory", ADDR_BITS, DATA_BITS);
Memory im("Instr Memory", ADDR_BITS, DATA_BITS);


// Additional registers for pipelining (If we need extra)


// IF/ID
Clearable ifid_v("IfId_V", 1);
StorageObject ifid_ir("IfId_IR", DATA_BITS);
Counter ifid_npc("IfId_NPC", DATA_BITS);


// ID/EX
StorageObject idex_a("IdEx_A", DATA_BITS);
StorageObject idex_b("IdEx_B", DATA_BITS);
StorageObject idex_ir("IdEx_IR", DATA_BITS);
StorageObject idex_imm("IdEx_IMM", DATA_BITS);


// EX/MEM
StorageObject exmem_ir("ExMem_IR", DATA_BITS);
StorageObject exmem_aluoutput("ExMem_ALUOutput", DATA_BITS);
StorageObject exmem_b("ExMem_B", DATA_BITS);
StorageObject exmem_cond("ExMem_COND", DATA_BITS);
StorageObject exmem_cpc("ExMem_CPC", DATA_BITS);


// MEM/WB
StorageObject memwb_ir("MemWb_IR", DATA_BITS);
StorageObject memwb_aluoutput("MemWb_ALUOutput", DATA_BITS);
StorageObject memwb_lmd("MemWb_LMD", DATA_BITS);
StorageObject memwb_cpc("MemWb_CPC", DATA_BITS);


// Constants


// The Krapf's yard
// Defined busses
Bus op1("OP1", DATA_BITS);
Bus op2("OP2", DATA_BITS);
Bus out("OUT", DATA_BITS);
Bus exbus("Ex Bus", DATA_BITS);


// Misc busses
// Fetch
Bus ifbus("IfBus", DATA_BITS);
BusALU ifalu("IfALU", DATA_BITS);
StorageObject iftemp("IfTemp", DATA_BITS);

// Decode
Bus id_a_bus("IdABus", DATA_BITS);
Bus id_b_bus("IdBBus", DATA_BITS);
Bus id_ir_bus("IdIRBus", DATA_BITS);
BusALU id_imm_alu("IdImmALU", DATA_BITS);

// Execute
Bus ex_ir_bus("EXIRBUS", DATA_BITS);

// Memory
Bus mem_ir_bus("MEMIRBUS", DATA_BITS);
Bus mem_alu_bus("MEMALUBUS", DATA_BITS);

// WB
Bus wb_ALUOutput_bus("WBALUBUS", DATA_BITS);
Bus wb_LMD_bus("WBLMDBUS", DATA_BITS);



