// globals.cpp
// author ddm9373
//
// initializing processor components

#include "includes.h"

// Useful global variables
bool done = false;
bool jumping = false;
bool branching = false;
int stalled = 0xF;
int regmod = 0;
StorageObject zero_const_stor("zero", DATA_BITS, 0);
StorageObject four_const_stor("six", DATA_BITS, 6);
StorageObject six_const_stor("six", DATA_BITS, 6);
StorageObject sixteen_const_stor("sixteen", DATA_BITS, 16);

//Masks
StorageObject imm_mask_stor("imm mask", DATA_BITS, instruction::imm);
StorageObject sh_mask_stor("sh mask", DATA_BITS, instruction::sh);
StorageObject sh_shift_stor("sh shift", DATA_BITS, instruction::sh_shift);
StorageObject target_mask_stor("target mask", DATA_BITS, instruction::target);
StorageObject low_five_bits_stor("low five bits", DATA_BITS, instruction::low_5_bits);
StorageObject imm_sign_bit_stor("imm sign bit", DATA_BITS, instruction::imm_sign_bit);
StorageObject target_sign_bit_stor("target sign bit", DATA_BITS, instruction::target_sign_bit);
StorageObject jump_mask_stor("jump mask", DATA_BITS, instruction::target);

// Standard register set
Counter r0("R0", DATA_BITS);
Counter r1("R1", DATA_BITS);
Counter r2("R2", DATA_BITS);
Counter r3("R3", DATA_BITS);
Counter r4("R4", DATA_BITS);
Counter r5("R5", DATA_BITS);
Counter r6("R6", DATA_BITS);
Counter r7("R7", DATA_BITS);
Counter r8("R8", DATA_BITS);
Counter r9("R9", DATA_BITS);

Counter r10("R10", DATA_BITS);
Counter r11("R11", DATA_BITS);
Counter r12("R12", DATA_BITS);
Counter r13("R13", DATA_BITS);
Counter r14("R14", DATA_BITS);
Counter r15("R15", DATA_BITS);
Counter r16("R16", DATA_BITS);
Counter r17("R17", DATA_BITS);
Counter r18("R18", DATA_BITS);
Counter r19("R19", DATA_BITS);

Counter r20("R20", DATA_BITS);
Counter r21("R21", DATA_BITS);
Counter r22("R22", DATA_BITS);
Counter r23("R23", DATA_BITS);
Counter r24("R24", DATA_BITS);
Counter r25("R25", DATA_BITS);
Counter r26("R26", DATA_BITS);
Counter r27("R27", DATA_BITS);
Counter r28("R28", DATA_BITS);
Counter r29("R29", DATA_BITS);

Counter r30("R30", DATA_BITS);
Counter r31("R31", DATA_BITS);

Counter* registerfile[32] = {
    &r0,
    &r1,
    &r2,
    &r3,
    &r4,
    &r5,
    &r6,
    &r7,
    &r8,
    &r9,
    &r10,
    &r11,
    &r12,
    &r13,
    &r14,
    &r15,
    &r16,
    &r17,
    &r18,
    &r19,
    &r20,
    &r21,
    &r22,
    &r23,
    &r24,
    &r25,
    &r26,
    &r27,
    &r28,
    &r29,
    &r30,
    &r31,
};

Counter pc("PC", DATA_BITS);
StorageObject ir("IR", DATA_BITS);
StorageObject iar("IAR", DATA_BITS);
StorageObject temp("TEMP", DATA_BITS);
StorageObject extemp("EXTEMP", DATA_BITS);

StorageObject a("A", DATA_BITS);
StorageObject b("B", DATA_BITS);
StorageObject c("C", DATA_BITS);

// Memory
Memory dm("DMemory", ADDR_BITS, 8, 0xffff, 4);
Memory im("IMemory", ADDR_BITS, 8, 0xffff, 4);

// Additional registers for pipelining (If we need extra)

// IF/ID
Clearable ifid_v("IfId_V", 1);
StorageObject ifid_ir("IfId_IR", DATA_BITS);
Counter ifid_npc("IfId_NPC", DATA_BITS);

StorageObject ifid_pc("IfId_PC", DATA_BITS);

// ID/EX
StorageObject idex_a("IdEx_A", DATA_BITS);
StorageObject idex_b("IdEx_B", DATA_BITS);
StorageObject idex_ir("IdEx_IR", DATA_BITS);
StorageObject idex_imm("IdEx_IMM", DATA_BITS);
StorageObject idex_sh("IdEx_SH", DATA_BITS);
StorageObject idex_temp_sh("IdEx_TEMP_SH", DATA_BITS);

StorageObject idex_pc("IfEx_PC", DATA_BITS);

// EX/MEM
StorageObject exmem_ir("ExMem_IR", DATA_BITS);
StorageObject exmem_aluoutput("ExMem_ALUOutput", DATA_BITS);
StorageObject exmem_b("ExMem_B", DATA_BITS);
StorageObject exmem_temp("ExMem_temp", DATA_BITS);
StorageObject exmem_cond("ExMem_COND", DATA_BITS);
int exmem_operation_type = 0;

StorageObject exmem_pc("ExMem_PC", DATA_BITS);

BusALU exALU("exALU", DATA_BITS);
Bus exmem_ir_bus("ExMem_IR_BUS", DATA_BITS);
Bus exmem_ALUOutput_bus("ExMem_ALUOUTPUT_BUS", DATA_BITS);
Bus exmem_b_bus("ExMem_B_BUS", DATA_BITS);
Bus exmem_cond_bus("ExMem_COND_BUS", DATA_BITS);


// MEM/WB
StorageObject memwb_ir("MemWb_IR", DATA_BITS);
StorageObject memwb_aluoutput("MemWb_ALUOutput", DATA_BITS);
StorageObject memwb_lmd("MemWb_LMD", DATA_BITS);

StorageObject memwb_pc("MemWb_PC", DATA_BITS);

// The Krapf's yard
// Defined busses
Bus exbus("Ex Bus", DATA_BITS);


// Misc busses
// Fetch
Bus ifbus("IfBus", DATA_BITS);
BusALU ifalu("IfALU", DATA_BITS);
StorageObject iftemp("IfTemp", DATA_BITS);

Bus ifpcbus("IfPcBus", DATA_BITS);

// Decode
Bus id_a_bus("IdABus", DATA_BITS);
Bus id_b_bus("IdBBus", DATA_BITS);
Bus id_ir_bus("IdIRBus", DATA_BITS);
Bus id_pc_bus("IdPcBus", DATA_BITS);
BusALU id_imm_alu("IdImmALU", DATA_BITS);
BusALU id_sh_alu("IdShALU", DATA_BITS);
BusALU id_j_alu("IdjALU", DATA_BITS);

StorageObject id_temp_sh("IdTemp", DATA_BITS);
StorageObject id_temp_br("IdTempBr", DATA_BITS);

// Execute
Bus ex_ir_bus("EXIRBUS", DATA_BITS);
Bus ex_b_bus("EXBBUS", DATA_BITS);
Bus ex_pc_bus("EXPCBUS", DATA_BITS);

// Memory
Bus mem_ir_bus("MEMIRBUS", DATA_BITS);
Bus mem_alu_bus("MEMALUBUS", DATA_BITS);
Bus mem_pc_bus("MEMPCBUS", DATA_BITS);

// WB
Bus wb_ALUOutput_bus("WBALUBUS", DATA_BITS);
Bus wb_LMD_bus("WBLMDBUS", DATA_BITS);
int wb_operation_type = 0;

