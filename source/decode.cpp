// decode.cpp
// author ddm9373
//
// Contains functions for the decode stage of the pipeline

#include "includes.h"


void id1() {
    // ID/EX.A <- reg[IF/ID.IR[rs]];
    // TODO
    BUSA.pullFrom(regs[RS(IFID.ir->value())]);
    IDEX.A->latchFrom(BUSA);
    
    // ID/EX.B <- reg[IF/ID.IR[rt]];
    // TODO
    BUSB.pullFrom(regs[RT(IFID.ir->value())]);
    IDEX.B->latchFrom(BUSB);
    
    // ID/EX.IR <- IF/ID.IR;
    // TODO
    SOMEBUS.pullFrom(*IFID.ir);
    IDEX.ir->latchFrom(SOMEBUS);

    // ID/EX.Imm <- sign-extend(IF/ID.IR[imm]);
    // TODO
    SOMEALU.OP1().pullFrom(*IFID.IR);
    SOMEALU.OP2().pullFrom(CONSTANT);
    SOMEALU.perform(BusALU::op_sign_extend);
    IDEX.Imm->latchFrom(SOMEALU.OUT());
}

void id2() {
    //;sdjf;odasjfosdafi;asfjiasdf;asjcaslidooa
}
