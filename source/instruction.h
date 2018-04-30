/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   instruction.h
 * Author: Pat
 *
 * Created on April 18, 2018, 10:39 PM
 */

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

class instruction{
public:
enum opcodes {
    NOP = 0b00000100000000000000000000000000,
    J  = 0b00001000000000000000000000000000,
    JAL = 0b00001100000000000000000000000000,
    BEQ = 0b11110000000000000000000000000000,
    BNE  = 0b11110100000000000000000000000000,
    ADDI = 0b01000000000000000000000000000000,
    SLTI = 0b01100000000000000000000000000000,
    ANDI = 0b01000000000000000000000000000000,
    ORI = 0b01010100000000000000000000000000,
    XORI = 0b01011000000000000000000000000000,
    LUI = 0b10011100000000000000000000000000,
    LW = 0b10001100000000000000000000000000,
    SW = 0b10101100000000000000000000000000,
    HALT = 0b00000000000000000000000000000000,
    JR = 0b00000000000000000000000000000010,
    JALR = 0b00000000000000000000000000000011,
    BREAK = 0b00000000000000000000000000000111,
    ADD = 0b00000000000000000000000000010000,
    SUB = 0b00000000000000000000000000010010,
    AND = 0b00000000000000000000000000010100,
    OR = 0b00000000000000000000000000010101,
    XOR = 0b00000000000000000000000000010110,
    SLT = 0b00000000000000000000000000011000,
    SLTU = 0b00000000000000000000000000011001,
    SLL = 0b00000000000000000000000000100101,
    SRL = 0b00000000000000000000000000100110,
    SRA = 0b00000000000000000000000000100111,
    SLLV = 0b00000000000000000000000000101101,
    SRLV = 0b00000000000000000000000000101110,
    SRAV = 0b00000000000000000000000000101111
};

enum    instructionFormat {
    op = 0b11111100000000000000000000000000,
    rs = 0b00000011111000000000000000000000,
    rt = 0b00000000000111110000000000000000,
    rd = 0b00000000000000001111100000000000,
    sh = 0b00000000000000000000011111000000,
    func = 0b00000000000000000000000000111111,
    imm = 0b00000000000000001111111111111111,
    imm_sign_bit = 0b00000000000000001000000000000000,
    target = 0b00000011111111111111111111111111,
    target_sign_bit = 0b00000010000000000000000000000000,
    low_5_bits = 0b11111
};

enum    operation_types{
    alu_operation_regtoreg = 1,
    alu_operation_regimm = 2,
    load_operation = 3,
    store_operation = 4,
    branch_operation = 5
};

enum    instructionShifts {
    op_shift = 26,
    rs_shift = 21,
    rt_shift = 16,
    rd_shift = 11,
    sh_shift = 6
    
};

    static void NOP_tick_1();
    static void NOP_tick_2();
    
    static void J_tick_1();
    static void J_tick_2();
    
    static void JAL_tick_1();
    static void JAL_tick_2();
    
    static void BEQ_tick_1();
    static void BEQ_tick_2();
    
    static void BNE_tick_1();
    static void BNE_tick_2();
    
    static void ADDI_tick_1();
    static void ADDI_tick_2();
    
    static void SLTI_tick_1();
    static void SLTI_tick_2();
    
    static void ANDI_tick_1();
    static void ANDI_tick_2();
    
    static void ORI_tick_1();
    static void ORI_tick_2();
    
    static void XORI_tick_1();
    static void XORI_tick_2();
    
    static void LUI_tick_1();
    static void LUI_tick_2();
    
    static void LW_tick_1();
    static void LW_tick_2();
    
    static void SW_tick_1();
    static void SW_tick_2();
    
    static void HALT_tick_1();
    static void HALT_tick_2();
    
    static void JR_tick_1();
    static void JR_tick_2();
    
    static void JALR_tick_1();
    static void JALR_tick_2();
    
    static void BREAK_tick_1();
    static void BREAK_tick_2();
    
    static void ADD_tick_1();
    static void ADD_tick_2();
    
    static void SUB_tick_1();
    static void SUB_tick_2();
    
    static void AND_tick_1();
    static void AND_tick_2();
    
    static void OR_tick_1();
    static void OR_tick_2();
    
    static void XOR_tick_1();
    static void XOR_tick_2();
    
    static void SLT_tick_1();
    static void SLT_tick_2();
    
    static void SLTU_tick_1();
    static void SLTU_tick_2();
    
    static void SLL_tick_1();
    static void SLL_tick_2();
    
    static void SRL_tick_1();
    static void SRL_tick_2();
    
    static void SRA_tick_1();
    static void SRA_tick_2();
    
    static void SLLV_tick_1();
    static void SLLV_tick_2();
    
    static void SRLV_tick_1();
    static void SRLV_tick_2();
    
    static void SRAV_tick_1();
    static void SRAV_tick_2();
    
    
private:
    static void BRANCH_tick_1();
    static void BRANCH_tick_2();
};


#endif /* INSTRUCTION_H */

