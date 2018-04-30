// decode.cpp
// author ddm9373
//
// Contains functions for the decode stage of the pipeline

#include "includes.h"

void id1() {
    idex_a.latchFrom(idex_a_bus.OUT());
    idex_a_bus.IN().pullFrom(regs[(ifid_ir.value() & instruction::rs) >> instruction::rs_shift]);
    
    idex_b.latchFrom(idex_b_bus.OUT());
    idex_b_bus.IN().pullFrom(regs[(ifid_ir.value() & instruction::rt) >> instruction::rt_shift]);
    
    idex_ir.latchFrom(idex_ir_bus.OUT());
    idex_ir_bus.IN().pullFrom(ifid_ir);
    
    idex_temp_imm.latchFrom(idex_imm_alu.OUT());
    idex_imm_alu.OP1().pullFrom(ifid_ir);
    idex_imm_alu.OP2().pullFrom(imm_mask_stor);
    idex_imm_alu.perform(BusALU::op_and);
    
    idex_temp_sh.latchFrom(idex_sh_alu.OUT());
    idex_sh_alu.OP1().pullFrom(ifid_ir);
    idex_sh_alu.OP2().pullFrom(sh_mask_stor);
    idex_sh_alu.perform(BusALU::op_and);
}

void id2() {
    idex_imm.latchFrom(idex_imm_alu.OUT());
    idex_imm_alu.OP1().pullFrom(idex_temp_imm);
    idex_imm_alu.OP2().pullFrom(imm_sign_bit);
    idex_imm_alu.perform(BusALU::op_extendSign);
    
    idex_sh.latchFrom(idex_sh_alu.OUT());
    idex_sh_alu.OP1().pullFrom(idex_temp_sh);
    idex_sh_alu.OP2().pullFrom(instruction::sh_shift);
    idex_sh_alu.perform(BusALU::op_rshift);
}
