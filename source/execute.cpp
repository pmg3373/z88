// execute.cpp
// author ddm9373
//
// Contains functions for the execute stage of the pipeline

#include "includes.h"

void exectutionSwitch(int exStage){
    int curopcode = ir.value() && instruction::op;
    
    if(curopcode == instruction::ADD){
        if(exStage == 1){
            instruction::ADD_tick_1();
        }
        else{
            instruction::ADD_tick_2();
            exmem_operation_type = instruction::alu_operation_regtoreg;
        }
    }
    else if(curopcode == instruction::ADDI){
        if(exStage == 1){
            instruction::ADDI_tick_1();
        }
        else{
            instruction::ADDI_tick_2();
            exmem_operation_type = instruction::alu_operation_regimm;
        }
    }
    else if(curopcode == instruction::AND){
        if(exStage == 1){
            instruction::AND_tick_1();
        }
        else{
            instruction::AND_tick_2();
            exmem_operation_type = instruction::alu_operation_regtoreg;
        }
    }
    else if(curopcode == instruction::ANDI){
        if(exStage == 1){
            instruction::ANDI_tick_1();
        }
        else{
            instruction::ANDI_tick_2();
            exmem_operation_type = instruction::alu_operation_regimm;
        }
    }
    else if(curopcode == instruction::BEQ){
        if(exStage == 1){
            instruction::BEQ_tick_1();
        }
        else{
            instruction::BEQ_tick_2();
            exmem_operation_type = instruction::branch_operation;
        }
    }
    else if(curopcode == instruction::BNE){
        if(exStage == 1){
            instruction::BNE_tick_1();
        }
        else{
            instruction::BNE_tick_2();
            exmem_operation_type = instruction::branch_operation;
        }
    }
    else if(curopcode == instruction::BREAK){
        if(exStage == 1){
            instruction::BREAK_tick_1();
        }
        else{
            instruction::BREAK_tick_2();
            exmem_operation_type = instruction::alu_operation_regtoreg; //TODO: What type is this?
        }
    }
    else if(curopcode == instruction::HALT){
        if(exStage == 1){
            instruction::HALT_tick_1();
        }
        else{
            instruction::HALT_tick_2();
            exmem_operation_type = instruction::alu_operation_regtoreg; //TODO: What type is this?
        }
    }
    else if(curopcode == instruction::J){
        if(exStage == 1){
            instruction::J_tick_1();
        }
        else{
            instruction::J_tick_2();
            exmem_operation_type = instruction::branch_operation;
        }
    }
    else if(curopcode == instruction::JAL){
        if(exStage == 1){
            instruction::JAL_tick_1();
        }
        else{
            instruction::JAL_tick_2();
            exmem_operation_type = instruction::branch_operation;
        }
    }
    else if(curopcode == instruction::JALR){
        if(exStage == 1){
            instruction::JALR_tick_1();
        }
        else{
            instruction::JALR_tick_2();
            exmem_operation_type = instruction::branch_operation;
        }
    }
    else if(curopcode == instruction::JR){
        if(exStage == 1){
            instruction::JR_tick_1();
        }
        else{
            instruction::JR_tick_2();
            exmem_operation_type = instruction::branch_operation;
        }
    }
    else if(curopcode == instruction::LUI){
        if(exStage == 1){
            instruction::LUI_tick_1();
        }
        else{
            instruction::LUI_tick_2();
            exmem_operation_type = instruction::alu_operation_regimm;
        }
    }
    else if(curopcode == instruction::LW){
        if(exStage == 1){
            instruction::LW_tick_1();
        }
        else{
            instruction::LW_tick_2();
            exmem_operation_type = instruction::load_operation;
        }
    }
    else if(curopcode == instruction::NOP){
       if(exStage == 1){
            instruction::NOP_tick_1();
        }
        else{
            instruction::NOP_tick_2();
            exmem_operation_type = instruction::alu_operation_regtoreg; //TODO: What type is this?
        }
    }
    else if(curopcode == instruction::OR){
        if(exStage == 1){
            instruction::OR_tick_1();
        }
        else{
            instruction::OR_tick_2();
            exmem_operation_type = instruction::alu_operation_regtoreg;
        }
    }
    else if(curopcode == instruction::ORI){
        if(exStage == 1){
            instruction::ORI_tick_1();
        }
        else{
            instruction::ORI_tick_2();
            exmem_operation_type = instruction::alu_operation_regimm;
        }
    }
    else if(curopcode == instruction::SLL){
        if(exStage == 1){
            instruction::SLL_tick_1();
        }
        else{
            instruction::SLL_tick_2();
            exmem_operation_type = instruction::alu_operation_regtoreg;
        }
    }
    else if(curopcode == instruction::SLLV){
        if(exStage == 1){
            instruction::SLLV_tick_1();
        }
        else{
            instruction::SLLV_tick_2();
            exmem_operation_type = instruction::alu_operation_regtoreg;
        }
    }
    else if(curopcode == instruction::SLT){
        if(exStage == 1){
            instruction::SLT_tick_1();
        }
        else{
            instruction::SLT_tick_2();
            exmem_operation_type = instruction::alu_operation_regtoreg;
        }
    }
    else if(curopcode == instruction::SLTI){
        if(exStage == 1){
            instruction::SLTI_tick_1();
        }
        else{
            instruction::SLTI_tick_2();
            exmem_operation_type = instruction::alu_operation_regimm;
        }
    }
    else if(curopcode == instruction::SLTU){
        if(exStage == 1){
            instruction::SLTU_tick_1();
        }
        else{
            instruction::SLTU_tick_2();
            exmem_operation_type = instruction::alu_operation_regtoreg;
        }
    }
    else if(curopcode == instruction::SRA){
        if(exStage == 1){
            instruction::SRA_tick_1();
        }
        else{
            instruction::SRA_tick_2();
            exmem_operation_type = instruction::alu_operation_regtoreg;
        }
    }
    else if(curopcode == instruction::SRAV){
        if(exStage == 1){
            instruction::SRAV_tick_1();
        }
        else{
            instruction::SRAV_tick_2();
            exmem_operation_type = instruction::alu_operation_regtoreg;
        }
    }
    else if(curopcode == instruction::SRL){
        if(exStage == 1){
            instruction::SRL_tick_1();
        }
        else{
            instruction::SRL_tick_2();
            exmem_operation_type = instruction::alu_operation_regtoreg;
        }
    }
    else if(curopcode == instruction::SRLV){
        if(exStage == 1){
            instruction::SRLV_tick_1();
        }
        else{
            instruction::SRLV_tick_2();
            exmem_operation_type = instruction::alu_operation_regtoreg;
        }
    }
    else if(curopcode == instruction::SUB){
        if(exStage == 1){
            instruction::SUB_tick_1();
        }
        else{
            instruction::SUB_tick_2();
            exmem_operation_type = instruction::alu_operation_regtoreg; 
        }
    }
    else if(curopcode == instruction::SW){
        if(exStage == 1){
            instruction::SW_tick_1();
        }
        else{
            instruction::SW_tick_2();
            exmem_operation_type = instruction::store_operation;
        }
    }
    else if(curopcode == instruction::XOR){
        if(exStage == 1){
            instruction::XOR_tick_1();
        }
        else{
            instruction::XOR_tick_2();
            exmem_operation_type = instruction::alu_operation_regtoreg;
        }
    }
    else if(curopcode == instruction::XORI){
        if(exStage == 1){
            instruction::XORI_tick_1();
        }
        else{
            instruction::XORI_tick_2();
            exmem_operation_type = instruction::alu_operation_regimm;
        }
    }
    else{
        throw ArchLibError("Undefined OpCode");
    }
    
    
}


void ex1() {
    exectutionSwitch(1);
}

void ex2() {
    // Transmit PC
    ex_pc_bus.IN().pullFrom(idex_pc);
    exmem_pc.latchFrom(ex_pc_bus.OUT());

    // EX/MEM.IR <- ID/EX.IR
    ex_ir_bus.IN().pullFrom(idex_ir);
    exmem_ir.latchFrom(ex_ir_bus.OUT());

    // There maybe should be a check on here
    ex_b_bus.IN().pullFrom(idex_b);
    exmem_b.latchFrom(ex_b_bus.OUT());

    exectutionSwitch(2);
}
