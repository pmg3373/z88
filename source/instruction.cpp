/* 
 * File:   instruction.h
 * Author: Pat
 *
 * Created on April 18, 2018, 10:39 PM
 */

#include "includes.h"

void instruction::BRANCH_tick_1(){
    exALU.OP1().pullFrom(idex_ir);
    exALU.OP2().pullFrom(sixteen_const_stor);
    exALU.perform(BusALU::op_lshift);
    extemp.latchFrom(exALU.OUT());
}
void instruction::BRANCH_tick_2(){
    exALU.OP1().pullFrom(idex_pc);
    exALU.OP2().pullFrom(extemp);
    exALU.perform(BusALU::op_add);
    exmem_aluoutput.latchFrom(exALU.OUT());
}

void instruction::NOP_tick_1(){}
void instruction::NOP_tick_2(){}

void instruction::J_tick_1(){
}
void instruction::J_tick_2(){
}

void instruction::JAL_tick_1(){
}
void instruction::JAL_tick_2(){
}

void instruction::BEQ_tick_1(){
    if(a.value() == b.value())
        BRANCH_tick_1();
}
void instruction::BEQ_tick_2(){
    if(a.value() == b.value())
        BRANCH_tick_2();
}

void instruction::BNE_tick_1(){
    if(a.value() != b.value())
        BRANCH_tick_1();
}
void instruction::BNE_tick_2(){
    if(a.value() != b.value())
        BRANCH_tick_2();
}

void instruction::ADDI_tick_1(){
}
void instruction::ADDI_tick_2(){
    exALU.OP1().pullFrom(idex_imm);
    exALU.OP2().pullFrom(idex_a);
    exmem_aluoutput.latchFrom(exALU.OUT());
    exALU.perform(BusALU::op_add);
}

void instruction::SLTI_tick_1(){
}
void instruction::SLTI_tick_2(){
    if( idex_a.value() < idex_imm.value()){
        exmem_aluoutput.latchFrom(exALU.OUT());
        exALU.perform(BusALU::op_one);
    }
    else{
        exmem_aluoutput.latchFrom(exALU.OUT());
        exALU.perform(BusALU::op_zero);
    }
}

void instruction::ANDI_tick_1(){
}
void instruction::ANDI_tick_2(){
    exALU.OP1().pullFrom(idex_imm);
    exALU.OP2().pullFrom(idex_a);
    exmem_aluoutput.latchFrom(exALU.OUT());
    exALU.perform(BusALU::op_and);
}

void instruction::ORI_tick_1(){
}
void instruction::ORI_tick_2(){
    exALU.OP1().pullFrom(idex_imm);
    exALU.OP2().pullFrom(idex_a);
    exmem_aluoutput.latchFrom(exALU.OUT());
    exALU.perform(BusALU::op_or);
}

void instruction::XORI_tick_1(){
}
void instruction::XORI_tick_2(){
    exALU.OP1().pullFrom(idex_imm);
    exALU.OP2().pullFrom(idex_a);
    exmem_aluoutput.latchFrom(exALU.OUT());
    exALU.perform(BusALU::op_xor);
}

void instruction::LUI_tick_1(){
}
void instruction::LUI_tick_2(){
    exALU.OP1().pullFrom(idex_imm);
    exALU.OP2().pullFrom(sixteen_const_stor);
    exmem_aluoutput.latchFrom(exALU.OUT());
    exALU.perform(BusALU::op_xor);
}

void instruction::LW_tick_1(){
}
void instruction::LW_tick_2(){
    exALU.OP1().pullFrom(idex_imm);
    exALU.OP2().pullFrom(idex_a);
    exmem_aluoutput.latchFrom(exALU.OUT());
    exALU.perform(BusALU::op_add);
}

void instruction::SW_tick_1(){
}
void instruction::SW_tick_2(){
    exALU.OP1().pullFrom(idex_imm);
    exALU.OP2().pullFrom(idex_a);
    exmem_aluoutput.latchFrom(exALU.OUT());
    exALU.perform(BusALU::op_add);
}

void instruction::HALT_tick_1(){}
void instruction::HALT_tick_2(){}


void instruction::JR_tick_1(){
}
void instruction::JR_tick_2(){
    exbus.IN().pullFrom(a);
    pc.latchFrom(exbus.OUT());
}

void instruction::JALR_tick_1(){
    exbus.IN().pullFrom(pc);
    c.latchFrom(exbus.OUT());
}
void instruction::JALR_tick_2(){
    //TODO:Is this correct?
    exALU.OP1().pullFrom(a);
    exALU.perform(BusALU::op_rop1);
    pc.latchFrom(exALU.OUT());
    
    exbus.IN().pullFrom(c);
    REGS(RD(ir.value())).latchFrom(exbus.OUT());
}

void instruction::BREAK_tick_1(){}
void instruction::BREAK_tick_2(){}

void instruction::ADD_tick_1(){
}
void instruction::ADD_tick_2(){
    exALU.OP1().pullFrom(idex_b);
    exALU.OP2().pullFrom(idex_a);
    exmem_aluoutput.latchFrom(exALU.OUT());
    exALU.perform(BusALU::op_add);
}

void instruction::SUB_tick_1(){
}
void instruction::SUB_tick_2(){
    exALU.OP1().pullFrom(idex_b);
    exALU.OP2().pullFrom(idex_a);
    exmem_aluoutput.latchFrom(exALU.OUT());
    exALU.perform(BusALU::op_add);
}

void instruction::AND_tick_1(){
}
void instruction::AND_tick_2(){
    exALU.OP1().pullFrom(idex_b);
    exALU.OP2().pullFrom(idex_a);
    exmem_aluoutput.latchFrom(exALU.OUT());
    exALU.perform(BusALU::op_add);
}

void instruction::OR_tick_1(){
}
void instruction::OR_tick_2(){
    exALU.OP1().pullFrom(idex_b);
    exALU.OP2().pullFrom(idex_a);
    exmem_aluoutput.latchFrom(exALU.OUT());
    exALU.perform(BusALU::op_add);
}

void instruction::XOR_tick_1(){
}
void instruction::XOR_tick_2(){
    exALU.OP1().pullFrom(idex_b);
    exALU.OP2().pullFrom(idex_a);
    exmem_aluoutput.latchFrom(exALU.OUT());
    exALU.perform(BusALU::op_add);
}

void instruction::SLT_tick_1(){
}
void instruction::SLT_tick_2(){
    if( idex_a.value() < idex_b.value()){
        exmem_aluoutput.latchFrom(exALU.OUT());
        exALU.perform(BusALU::op_one);
    }
    else{
        exmem_aluoutput.latchFrom(exALU.OUT());
        exALU.perform(BusALU::op_zero);
    }
}

void instruction::SLTU_tick_1(){
}
void instruction::SLTU_tick_2(){
    if( idex_a.uvalue() < idex_b.uvalue()){
        exmem_aluoutput.latchFrom(exALU.OUT());
        exALU.perform(BusALU::op_one);
    }
    else{
        exmem_aluoutput.latchFrom(exALU.OUT());
        exALU.perform(BusALU::op_zero);
    }
}

void instruction::SLL_tick_1(){
}
void instruction::SLL_tick_2(){
    exALU.OP1().pullFrom(idex_b);
    exALU.OP2().pullFrom(idex_sh);
    exmem_aluoutput.latchFrom(exALU.OUT());
    exALU.perform(BusALU::op_lshift);
}


void instruction::SRL_tick_1(){
}
void instruction::SRL_tick_2(){
    exALU.OP1().pullFrom(idex_b);
    exALU.OP2().pullFrom(idex_sh);
    exmem_aluoutput.latchFrom(exALU.OUT());
    exALU.perform(BusALU::op_rshift);
}

void instruction::SRA_tick_1(){
}
void instruction::SRA_tick_2(){
    exALU.OP1().pullFrom(idex_b);
    exALU.OP2().pullFrom(idex_sh);
    exmem_aluoutput.latchFrom(exALU.OUT());
    exALU.perform(BusALU::op_rashift);
}

void instruction::SLLV_tick_1(){
    exmem_temp.latchFrom(exALU.OUT());
    exALU.IN1().pullFrom(idex_a);
    exALU.IN2().pullFrom(low_five_bits_stor);
    exALU.perform(BusALU::op_and);
}
void instruction::SLLV_tick_2(){
    exmem_aluoutput.latchFrom(exALU.OUT());
    exALU.IN1().pullFrom(exmem_b);
    exALU.IN2().pullFrom(exmem_temp);
    exALU.perform(BusALU::op_lshift);
}

void instruction::SRLV_tick_1(){
    exmem_temp.latchFrom(exALU.OUT());
    exALU.IN1().pullFrom(idex_a);
    exALU.IN2().pullFrom(low_five_bits_stor);
    exALU.perform(BusALU::op_and);
}
void instruction::SRLV_tick_2(){
    exmem_aluoutput.latchFrom(exALU.OUT());
    exALU.IN1().pullFrom(exmem_b);
    exALU.IN2().pullFrom(exmem_temp);
    exALU.perform(BusALU::op_rshift);
}

void instruction::SRAV_tick_1(){
    exmem_temp.latchFrom(exALU.OUT());
    exALU.IN1().pullFrom(idex_a);
    exALU.IN2().pullFrom(low_five_bits_stor);
    exALU.perform(BusALU::op_and);
}
void instruction::SRAV_tick_2(){
    exmem_aluoutput.latchFrom(exALU.OUT());
    exALU.IN1().pullFrom(exmem_b);
    exALU.IN2().pullFrom(exmem_temp);
    exALU.perform(BusALU::op_rashift);
}

/*
void instruction::NOP_tick_1(){}
void instruction::NOP_tick_2(){}

void instruction::J_tick_1(){}
void instruction::J_tick_2(){}

void instruction::JAL_tick_1(){}
void instruction::JAL_tick_2(){}

void instruction::BEQ_tick_1(){}
void instruction::BEQ_tick_2(){}

void instruction::BNE_tick_1(){}
void instruction::BNE_tick_2(){}

void instruction::ADDI_tick_1(){}
void instruction::ADDI_tick_2(){}

void instruction::SLTI_tick_1(){}
void instruction::SLTI_tick_2(){}

void instruction::ANDI_tick_1(){}
void instruction::ANDI_tick_2(){}

void instruction::ORI_tick_1(){}
void instruction::ORI_tick_2(){}

void instruction::XORI_tick_1(){}
void instruction::XORI_tick_2(){}

void instruction::LUI_tick_1(){}
void instruction::LUI_tick_2(){}

void instruction::LW_tick_1(){}
void instruction::LW_tick_2(){}

void instruction::SW_tick_1(){}
void instruction::SW_tick_2(){}

void instruction::HALT_tick_1(){}
void instruction::HALT_tick_2(){}

void instruction::JR_tick_1(){}
void instruction::JR_tick_2(){}

void instruction::JALR_tick_1(){}
void instruction::JALR_tick_2(){}

void instruction::BREAK_tick_1(){}
void instruction::BREAK_tick_2(){}

void instruction::ADD_tick_1(){}
void instruction::ADD_tick_2(){}

void instruction::SUB_tick_1(){}
void instruction::SUB_tick_2(){}

void instruction::AND_tick_1(){}
void instruction::AND_tick_2(){}

void instruction::OR_tick_1(){}
void instruction::OR_tick_2(){}

void instruction::XOR_tick_1(){}
void instruction::XOR_tick_2(){}

void instruction::SLT_tick_1(){}
void instruction::SLT_tick_2(){}

void instruction::SLTU_tick_1(){}
void instruction::SLTU_tick_2(){}

void instruction::SLL_tick_1(){}
void instruction::SLL_tick_2(){}

void instruction::SRL_tick_1(){}
void instruction::SRL_tick_2(){}

void instruction::SRA_tick_1(){}
void instruction::SRA_tick_2(){}

void instruction::SLLV_tick_1(){}
void instruction::SLLV_tick_2(){}

void instruction::SRLV_tick_1(){}
void instruction::SRLV_tick_2(){}

void instruction::SRAV_tick_1(){}
void instruction::SRAV_tick_2(){}

void instruction::BRANCH_tick_1(){}
void instruction::BRANCH_tick_2(){}
*/
