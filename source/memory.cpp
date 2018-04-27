
#include "includes.h"

// memory.cpp
// author ddm9373
//
// Contains functions for the memory stage of the pipeline

void mem1() {
    if(1){
        //ALU Instructions
        memwb_ir.latchFrom(memwb_ir_bus.OUT());
        memwb_ir_bus.IN().pullFrom(exmem_ir);
        
        memwb_ALUOutput.latchFrom(memwb_ALUOutput_bus.OUT());
        memwb_ALUOutput_bus.IN().pullFrom(exmem_ALUOutput);
    }
    else if(2){
        //Load/Store instructions
        memwb_ir.latchFrom(memwb_ir_bus.OUT());
        memwb_ir_bus.IN().pullFrom(exmem_ir);
        
        dm.MAR().latchFrom(memwb_ALUOutput_bus.OUT());
        memwb_ALUOutput_bus.IN().pullFrom(exmem_ALUOutput);
    }
    else{
        //Branch Instructions
        //Just Idle, Intentionally Blank
    }
}

void mem2() {
    if(2){
        //Load/Store
        if(1){
            //Load
            memwb_LMD.latchFrom(dm.READ());
            dm.read();
        }
        else{
            //Store
            dm.WRITE().pullFrom(exmem_b);
            dm.write();
        }
    }
}
