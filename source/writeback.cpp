// writeback.cpp
// author ddm9373
//
// Contains functions for the writeback stage of the pipeline

#include "includes.h"

void wb1() {
    wb_operation_type = memwb_operation_type_prev;
    
    if(wb_operation_type == instruction::alu_operation_regtoreg){
        //Register to Register ALU
        regs[(memwb_ir.value() & instruction::rd) >> instruction::rd_shift].latchFrom(wb_ALUOutput_bus.OUT());
        wb_ALUOutput_bus.IN().pullFrom(memwb_ALUOutput);
    }
    else if(wb_operation_type == instruction::alu_operation_regimm){
        //Immediate to Register ALU
        regs[(memwb_ir.value() & instruction::rt) >> instruction::rt_shift].latchFrom(wb_ALUOutput_bus.OUT());
        wb_ALUOutput_bus.IN().pullFrom(memwb_ALUOutput);
    }
    else if(wb_operation_type == instruction::load_operation){
        //Load
        regs[(memwb_ir.value() & instruction::rt) >> instruction::rt_shift].latchFrom(wb_LMD_bus.OUT());
        wb_LMD_bus.IN().pullFrom(memwb_LMD);
    }
}

void wb2() {
    
}
