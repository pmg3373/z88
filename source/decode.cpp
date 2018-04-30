// decode.cpp
// author ddm9373
//
// Contains functions for the decode stage of the pipeline

#include "includes.h"

void id1() {
<<<<<<< HEAD
}

void id2() {
    // ID/EX.A <- reg[IF/ID.IR[rs]]
    id_a_bus.IN().pullFrom(regs[RS(ifid_ir.value())]);
    idex_a.latchFrom(id_a_bus.OUT());

    // ID/EX.B <- reg[IF/ID.IR[rt]]
    id_b_bus.IN().pullFrom(regs[RT(ifid_ir.value())]);
    idex_b.latchFrom(id_b_bus.OUT());

    // ID/EX.IR <- IF/ID.IR
    id_ir_bus.IN().pullFrom(ifid_ir);
    idex_ir.latchFrom(id_ir_bus.OUT());

    // ID/EX.Imm <- sign-extend(IF/ID.IR[imm])
    id_imm_alu.OP1().pullFrom(ifid_ir);
    id_imm_alu.OP2().pullFrom(imm_sign_bit);
    id_imm_alu.perform(BusALU::op_extendSign);
    idex_imm.latchFrom(id_imm_alu.OUT());
=======
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
>>>>>>> 089f7f4ec1840d3ac6abc85c171149b5d4272cd1
}
