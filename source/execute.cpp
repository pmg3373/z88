// execute.cpp
// author ddm9373
//
// Contains functions for the execute stage of the pipeline

#include "includes.h"
#include "instruction.h"

void ex1() {}
void ex1alu() {
}

void ex1loadstore() {

}

void ex1branch() {

}

void ex2() {}
void ex2alu() {
    // EX/MEM.IR <- ID/EX.IR
    // TODO
    SOMEBUS.pullFrom(*IDEX.IR);
    EXMEM.IR->latchFrom(SOMEBUS);

    //EX/MEM.ALUOutput <- ID/EX.A func ID/EX.{B,Imm}
    SOMEALU.OP1().pullFrom(*IDEX.A);
    if (R-R) SOMEALU.OP2().pullFrom(*IDEX.B);
    else     SOMEALU.OP2().pullFrom(*IDEX.Imm);
    switch (OPERATION(IDEX.IR->value())) {
        case OP_ADD:
            SOMEALU.perform(BusALU::op_add);
            break;
        default:
            SOMEALU.perform(BusALU::op_add);
            break;
    }
    EXMEM.ALUOutput.latchFrom(SOMEALU); 
}

void ex2loadstore() {
    // EX/MEM.IR <- ID/EX.IR
    // TODO
    SOMEBUS.pullFrom(*IDEX.IR);
    EXMEM.IR->latchFrom(SOMEBUS);

    // EX/MEM.ALUOutput <- ID/EX.A + ID/EX.Imm
    SOMEALU.OP1().pullFrom(*IDEX.A);
    SOMEALU.OP1().pullFrom(*IDEX.Imm);
    SOMEALU.perform(BusALU::op_add);
    EXMEM.ALUOutput->latchFrom(SOMEALU.OUT());

    // EX/MEM.B <- ID/EX.B
    SOMEBUS.pullFrom(*IDEX.B);
    EXMEM.B->latchFrom(SOMEBUS);
}

void ex2branch() {

}

void exectutionSwitch(StorageObject* registerFile[], int exStage){
    int curopcode = ir.value() && instruction.op;
    
    if(curopcode == instruction.ADD){
        
    }
    else if(curopcode == instruction.ADDI){
        
    }
    else if(curopcode == instruction.AND){
        
    }
    else if(curopcode == instruction.ANDI){
        
    }
    else if(curopcode == instruction.BEQ){
        
    }
    else if(curopcode == instruction.BNE){
        
    }
    else if(curopcode == instruction.BREAK){
        
    }
    else if(curopcode == instruction.HALT){
        
    }
    else if(curopcode == instruction.J){
        
    }
    else if(curopcode == instruction.JAL){
        
    }
    else if(curopcode == instruction.JALR){
        
    }
    else if(curopcode == instruction.JR){
        
    }
    else if(curopcode == instruction.LUI){
        
    }
    else if(curopcode == instruction.LW){
        
    }
    else if(curopcode == instruction.NOP){
        
    }
    else if(curopcode == instruction.OR){
        
    }
    else if(curopcode == instruction.ORI){
        
    }
    else if(curopcode == instruction.SLL){
        
    }
    else if(curopcode == instruction.SLLV){
        
    }
    else if(curopcode == instruction.SLT){
        
    }
    else if(curopcode == instruction.SLTI){
        
    }
    else if(curopcode == instruction.SLTU){
        
    }
    else if(curopcode == instruction.SRA){
        
    }
    else if(curopcode == instruction.SRAV){
        
    }
    else if(curopcode == instruction.SRL){
        
    }
    else if(curopcode == instruction.SRLV){
        
    }
    else if(curopcode == instruction.SUB){
        
    }
    else if(curopcode == instruction.SW){
        
    }
    else if(curopcode == instruction.XOR){
        
    }
    else if(curopcode == instruction.XORI){
        
    }
    else{
        throw ArchLibError();
    }
    
    
}
