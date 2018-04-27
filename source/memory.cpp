// memory.cpp
// author ddm9373
//
// Contains functions for the memory stage of the pipeline

void mem1() {
    if (BRANCH_INSTRUCTION) {
        return;
    }

    // MEM/WB.IR <- EX/MEM.IR
    // TODO
    SOMEBUS.pullFrom(*EXMEM.IR);
    MEMWB.IR->latchFrom(SOMEBUS);

    if (ALU_INSTRUCTION) {
        // MEM/WB.ALUOutput <- EX/MEM.ALUOutput;
        // TODO
        SOMEBUS.pullFrom(*EXMEM.ALUOutput);
        MEMWB.ALUOutput->latchFrom(SOMEBUS);
    } else if (L/S INSTRUCTION) {
        SOMEBUS.pullFrom(*EXMEM.ALUOutput);
        dm.MAR().latchFrom(SOMEBUS);
    }
}

void mem2() {
    // MEM/WB.LMD <- Mem[EX/MEM.ALUOutput
    if (LOAD INSTRUCTION) {
        m.read();
        MEMWB.LMD->latchFrom(m.READ());
    }
    // Mem[EX/MEM.ALUOutput] <- EX/MEM.B
    else if (STORE INSTRUCTION) {
        m.WRITE().pullFrom(*EXMEM.B);
        m.write();
    }
}
