// writeback.cpp
// author ddm9373
//
// Contains functions for the writeback stage of the pipeline

#include "includes.h"

void wb1() {
    if(1){
        //ALU
        if(1){
            //Register to Register ALU
            regs[(memwb_ir.value() & instruction::rd) >> instruction::rd_shift].latchFrom(wb_ALUOutput_bus.OUT());
            wb_ALUOutput_bus.IN().pullFrom(memwb_ALUOutput);
        }
        else{
            //Immediate to Register ALU
            regs[(memwb_ir.value() & instruction::rt) >> instruction::rt_shift].latchFrom(wb_ALUOutput_bus.OUT());
            wb_ALUOutput_bus.IN().pullFrom(memwb_ALUOutput);
        }
    }
    else if(2){
        //Load/Store
        if(1){
            //Load
            regs[(memwb_ir.value() & instruction::rt) >> instruction::rt_shift].latchFrom(wb_LMD_bus.OUT());
            wb_LMD_bus.IN().pullFrom(memwb_LMD);
        }
    }
    else{
        //Branch
        //Just Idle, Intentionally Blank
    }
}

void wb2() {}
