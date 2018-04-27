/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "includes.h"


    static void BRANCH_tick_1(){
        exALU.OP1().pullFrom(exmem_ir);
        exALU.OP2().pullFrom(sixteen_const_stor);
        exALU.perform(BusALU::op_lshift);
        extemp.latchFrom(exALU.OUT());
    }
    static void BRANCH_tick_2(){
        exALU.OP1().pullFrom(exmem_pc);
        exALU.OP2().pullFrom(extemp);
        exALU.perform(BusALU::op_add);
        exmem_ALUOutput.latchFrom(exALU.OUT());
    }
    
    static void NOP_tick_1(){}
    static void NOP_tick_2(){}
    
    static void J_tick_1(){
        
    }
    static void J_tick_2(){
        exALU.OP1().pullFrom(ir);
        exALU.OP2().pullFrom(six_const_stor);
        exALU.perform(BusALU::op_lshift);
        pc.latchFrom(exALU.OUT());
    }
    
    static void JAL_tick_1(){
        exbus.IN().pullFrom(pc);
        c.latchFrom(exbus.OUT());
    }
    static void JAL_tick_2(){
        exALU.OP1().pullFrom(ir);
        exALU.OP2().pullFrom(six_const_stor);
        exALU.perform(BusALU::op_lshift);
        pc.latchFrom(exALU.OUT());
        
        exbus.IN().pullFrom(c);
        regs[31].latchFrom(exbus.OUT());
    }
    
    static void BEQ_tick_1(){
        if(a.value() == b.value())
            BRANCH_tick_1();
    }
    static void BEQ_tick_2(){
        if(a.value() == b.value())
            BRANCH_tick_2();
    }
    
    static void BNE_tick_1(){
        if(a.value() != b.value())
            BRANCH_tick_1();
    }
    static void BNE_tick_2(){
        if(a.value() != b.value())
            BRANCH_tick_2();
    }
    
    static void ADDI_tick_1(){
        exALU.OP1().pullFrom(idex_imm);
        exALU.OP2().pullFrom(idex_a);
    }
    static void ADDI_tick_2(){
        
    }
    
    static void SLTI_tick_1(){}
    static void SLTI_tick_2(){}
    
    static void ANDI_tick_1(){}
    static void ANDI_tick_2(){}
    
    static void ORI_tick_1(){}
    static void ORI_tick_2(){}
    
    static void XORI_tick_1(){}
    static void XORI_tick_2(){}
    
    static void LUI_tick_1(){}
    static void LUI_tick_2(){}
    
    static void LW_tick_1(){}
    static void LW_tick_2(){}
    
    static void SW_tick_1(){}
    static void SW_tick_2(){}
    
    static void HALT_tick_1(){}
    static void HALT_tick_2(){}
    
    
    static void JR_tick_1(){
    }
    static void JR_tick_2(){
        exbus.IN().pullFrom(a);
        pc.latchFrom(exbus.OUT());
    }
    
    static void JALR_tick_1(){
        exbus.IN().pullFrom(pc);
        c.latchFrom(exbus.OUT());
    }
    static void JALR_tick_2(){
        exALU.OP1().pullFrom(a);
        exALU.perform(BusALU::op_rop1);
        pc.latchFrom(exALU.OUT());
        
        exbus.IN().pullFrom(c);
        regs[(ir.value() & instruction::rd) >> instruction::rd_shift].latchFrom(exbus.OUT());
    }
    
    static void BREAK_tick_1(){}
    static void BREAK_tick_2(){}
    static void ADD_tick_1(){}
    static void ADD_tick_2(){}
    static void SUB_tick_1(){}
    static void SUB_tick_2(){}
    static void AND_tick_1(){}
    static void AND_tick_2(){}
    static void OR_tick_1(){}
    static void OR_tick_2(){}
    static void XOR_tick_1(){}
    static void XOR_tick_2(){}
    static void SLT_tick_1(){}
    static void SLT_tick_2(){}
    static void SLTU_tick_1(){}
    static void SLTU_tick_2(){}
    static void SLL_tick_1(){}
    static void SLL_tick_2(){}
    static void SRL_tick_1(){}
    static void SRL_tick_2(){}
    static void SRA_tick_1(){}
    static void SRA_tick_2(){}
    static void SLLV_tick_1(){}
    static void SLLV_tick_2(){}
    static void SRLV_tick_1(){}
    static void SRLV_tick_2(){}
    static void SRAV_tick_1(){}
    static void SRAV_tick_2(){}