// decode.cpp
// author ddm9373
//
// Contains functions for the decode stage of the pipeline

#include "includes.h"

void jumparound() {
    id_j_alu.OP1().pullFrom(ifid_ir);
    id_j_alu.OP2().pullFrom(jump_mask_stor);
    id_j_alu.perform(BusALU::op_and);
    pc.latchFrom(id_j_alu.OUT());
}

void testjumps() {
    if ((ifid_ir.value() & instruction::op) == instruction::J) {
        jumparound();
        return;
    }
    if ((ifid_ir.value() & instruction::op) == instruction::BEQ) {
        if(REGS(RS(ifid_ir.value())).value() == REGS(RT(ifid_ir.value())).value())
            jumparound();
    }
    if ((ifid_ir.value() & instruction::op) == instruction::BNE) {
        if(REGS(RS(ifid_ir.value())).value() != REGS(RT(ifid_ir.value())).value())
            jumparound();
    }
}

void id1() {
    // Transmit PC
    id_pc_bus.IN().pullFrom(ifid_pc);
    idex_pc.latchFrom(id_pc_bus.OUT());

    id_sh_alu.OP1().pullFrom(ifid_ir);
    id_sh_alu.OP2().pullFrom(sh_mask_stor);
    id_sh_alu.perform(BusALU::op_and);
    id_temp_sh.latchFrom(id_sh_alu.OUT());
}

void id2() {
    // ID/EX.A <- reg[IF/ID.IR[rs]]
    id_a_bus.IN().pullFrom(REGS(RS(ifid_ir.value())));
    idex_a.latchFrom(id_a_bus.OUT());

    // ID/EX.B <- reg[IF/ID.IR[rt]]
    id_b_bus.IN().pullFrom(REGS(RT(ifid_ir.value())));
    idex_b.latchFrom(id_b_bus.OUT());

    // ID/EX.IR <- IF/ID.IR
    id_ir_bus.IN().pullFrom(ifid_ir);
    idex_ir.latchFrom(id_ir_bus.OUT());

    // ID/EX.Imm <- sign-extend(IF/ID.IR[imm])
    id_imm_alu.OP1().pullFrom(ifid_ir);
    id_imm_alu.OP2().pullFrom(imm_sign_bit_stor);
    id_imm_alu.perform(BusALU::op_extendSign);
    idex_imm.latchFrom(id_imm_alu.OUT());

    id_sh_alu.OP1().pullFrom(id_temp_sh);
    id_sh_alu.OP2().pullFrom(sh_shift_stor);
    id_sh_alu.perform(BusALU::op_rshift);
    idex_sh.latchFrom(id_sh_alu.OUT());

    testjumps();
}

