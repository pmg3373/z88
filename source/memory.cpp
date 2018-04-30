
#include "includes.h"

// memory.cpp
// author ddm9373
//
// Contains functions for the memory stage of the pipeline

void mem1() {
    
    memwb_operation_type_prev = memwb_operation_type;
    memwb_operation_type = exmem_operation_type;
    
    if( (memwb_operation_type == instruction::alu_operation_regtoreg) ||
            (memwb_operation_type == instruction::alu_operation_regimm)){
        
        //ALU Instructions
        memwb_ir.latchFrom(memwb_ir_bus.OUT());
        memwb_ir_bus.IN().pullFrom(exmem_ir);
        
        memwb_ALUOutput.latchFrom(memwb_ALUOutput_bus.OUT());
        memwb_ALUOutput_bus.IN().pullFrom(exmem_ALUOutput);
        
    }
    else if( (memwb_operation_type == instruction::load_operation) ||
            (memwb_operation_type == instruction::store_operation) ){
        
        //Load/Store instructions
        memwb_ir.latchFrom(memwb_ir_bus.OUT());
        memwb_ir_bus.IN().pullFrom(exmem_ir);
        
        dm.MAR().latchFrom(memwb_ALUOutput_bus.OUT());
        memwb_ALUOutput_bus.IN().pullFrom(exmem_ALUOutput);
        
    }
    else if(memwb_operation_type == instruction::branch_operation){
        //Branch Instructions
        //Just Idle, Intentionally Blank
    }
    else{
        //something has gone wrong???
        throw ArchLibError("Undefined operation has continued forward in pipeline!!!");
        return;
    }
}

void mem2() {
    if(memwb_operation_type == instruction::load_operation){
        //Load
        memwb_LMD.latchFrom(dm.READ());
        dm.read();
    }
    else if(memwb_operation_type == instruction::store_operation){
        //Store
        dm.WRITE().pullFrom(exmem_b);
        dm.write();
    }
}
