// writeback.cpp
// author ddm9373
//
// Contains functions for the writeback stage of the pipeline

void wb1() {
    // reg[MEM/WB.IR[rd]] <- MEM/WB.ALUOutput
    if (INSTRUCTIONALU) {
        SOMEBUS.pullFrom(MEMWB.ALUOutput);
        if (SOMETHING I'M NOT USRE OF YET) {
            reg[RD(MEMWB.IR->value())].latchFrom(SOMEBUS);
        } else {
            reg[RT(MEMWB.IR->value())].latchFrom(SOMEBUS);
        }
    }

    // reg[MEM/WB.IR[rt]] <- MEM/WB.LMD
    if (INSTRUCTIONLOAD) {
        SOMEBUS.pullFrom(*MEMWB.LMD);
        reg[RT(MEMWB.IR->value())].latchFrom(SOMEBUS);
    }
}

void wb2() {}
