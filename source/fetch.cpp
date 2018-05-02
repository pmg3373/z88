
#include "includes.h"

// fetch.cpp
// author ddm9373
//
// Contains functions for the fetch stage of the pipeline

/**
 * Step one of instruction fetch
 * RTL: MEM[MAR] <- PC
 */
void if1() {
    // Transmit PC
    ifpcbus.IN().pullFrom(pc);
    ifid_pc.latchFrom(ifpcbus.OUT());

    ifbus.IN().pullFrom(pc);
    im.MAR().latchFrom(ifbus.OUT());

    pc.perform(Counter::incr4);

    ifalu.OP1().pullFrom(ifid_ir);
    ifalu.OP2().pullFrom(imm_sign_bit_stor);
    ifalu.perform(BusALU::op_extendSign);
    iftemp.latchFrom(ifalu.OUT());
}

/**
 * Step two of instruction fetch
 * RTL: IFID_IR  <- MEM[MAR];
 *      IFID_NPC,PC <- ( (IFIDIR & OPCODE == BRANCH) && (IFIDIR & RS op 0) ) ?
 *              IFIDNPC + (IFIDIR && IMM ) << 2 (sign extended) :
 *              PC + 4;
 */
void if2() {
    if( (((ifid_ir.value() & instruction::op) == instruction::BEQ)
            && (REGS(RS(ifid_ir.value())).value() == 0))
            ||
            (((ifid_ir.value() & instruction::op) == instruction::BNE)
            && (REGS(RS(ifid_ir.value())).value() != 0))) {
       
        ifalu.OP1().pullFrom(iftemp);
        ifalu.OP2().pullFrom(ifid_npc);
        ifalu.perform(BusALU::op_add);
        pc.latchFrom(ifalu.OUT());
        ifid_npc.latchFrom(ifalu.OUT());
    }
    else {
        ifid_npc.perform(Counter::incr4);
    }
    
    im.read();
    ifid_ir.latchFrom(im.READ());
}
