
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
    ifbus.IN().pullFrom(pc);
    im.MAR().latchFrom(ifbus.OUT());
    ifid_alu.IN1().pullFrom(pc);
    ifid_alu.IN2().pullFrom(four_const_stor);
    
}

/**
 * Step two of instruction fetch
 * RTL: IFIDIR <- MEM[MAR];
 *      IFIDNPC <- ( (IFIDIR & OPCODE == BRANCH) && (IFIDIR & RS op 0) ) ?
 *              IFIDNPC + (IFIDIR && IMM ) << 2 (sign extended) :
 *              PC + 4;
 *      PC <- ( (IFIDIR & OPCODE == BRANCH) && (IFIDIR & RS op 0) ) ?
 *              IFIDNPC + (IFIDIR && IMM ) << 2 (sign extended) :
 *              PC + 4;
 */
void if2() {
    
    if( (((ifid_ir.value() & instruction::op) == instruction::BEQ) && (regs[(ifid_ir.value() & instruction::rs) >> instruction::rs_shift].value() == 0)) ||
            (((ifid_ir.value() & instruction::op) == instruction::BNE) && (regs[(ifid_ir.value() & instruction::rs) >> instruction::rs_shift].value() != 0))){
        //TODO: I have no idea how to do this in one tick
        //The result of IFIDIR & IMM_MASK needs to be sign extended shifted right twice
        //and then PC and IFIDPC both need the result
        
    }
    else{
        ifid_bus.IN().pullFrom(pc);
        ifid_npc.latchFrom(ifid_bus.OUT());
    }
    
    im.read();
    ifid_ir.latchFrom(im.READ());
}
