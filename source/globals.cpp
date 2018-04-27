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


// Standard register set
Counter* registerfile[32];
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
//Memory dm("Data Memory", ADDR_BITS, DATA_BITS, ;
//Memory im;


// Additional registers for pipelining (If we need extra)


// IF/ID
Clearable ifid_v("IfId_V", 1);
StorageObject ifid_ir("IfId_IR", DATA_BITS);
StorageObject ifid_npc("IfId_NPC", DATA_BITS);
//See globals.h
//if_id_reg IFID =
//    {&ifid_v, &ifid_ir, &ifid_npc};


// ID/EX
StorageObject idex_a("IdEx_A", DATA_BITS);
StorageObject idex_b("IdEx_B", DATA_BITS);
StorageObject idex_ir("IdEx_IR", DATA_BITS);
StorageObject idex_imm("IdEx_IMM", DATA_BITS);
//see globals.h
//id_ex_reg IDEX =
//    {&idex_a, &idex_b, &idex_ir, &idex_imm};


// EX/MEM
StorageObject exmem_ir("ExMem_IR", DATA_BITS);
StorageObject exmem_aluoutput("ExMem_ALUOutput", DATA_BITS);
StorageObject exmem_b("ExMem_B", DATA_BITS);
StorageObject exmem_cond("ExMem_COND", DATA_BITS);
StorageObject exmem_cpc("ExMem_CPC", DATA_BITS);
ex_mem_reg EXMEM =
    {&exmem_ir, &exmem_aluoutput, &exmem_b, &exmem_cond, &exmem_cpc};


// MEM/WB
StorageObject memwb_ir("MemWb_IR", DATA_BITS);
StorageObject memwb_aluoutput("MemWb_ALUOutput", DATA_BITS);
StorageObject memwb_lmd("MemWb_LMD", DATA_BITS);
StorageObject memwb_cpc("MemWb_CPC", DATA_BITS);
mem_wb_reg =
    {&memwb_ir, &memwb_aluoutput, &memwb_lmd, &memwb_cpc};


// Constants


// The Krapf's yard
// Defined busses
Bus op1("OP1", DATA_BITS);
Bus op2("OP2", DATA_BITS);
Bus out("OUT", DATA_BITS);
Bus ifbus("If Bus", DATA_BITS);
Bus exbus("Ex Bus", DATA_BITS);


// Misc busses
// Fetch
Bus fPC("fPC", DATA_BITS);


// Decode

// Execute

// Memory

// WB



