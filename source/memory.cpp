#include "includes.h"

// memory.cpp
// author ddm9373
//
// Contains functions for the memory stage of the pipeline

bool rralu_instruction(int instr) {
    return alu_instruction(instr);
}

bool alu_instruction(int instr) {
    int opcode = instr & instruction::op;
    int funct = instr & instruction::func;
    return
        opcode == instruction::ADDI ||
        opcode == instruction::ANDI ||
        opcode == instruction::ORI ||
        opcode == instruction::XORI ||
        opcode == instruction::SLTI ||
        opcode == instruction::LUI ||
       (opcode == 0 && (
        funct  == instruction::ADD ||
        funct  == instruction::SUB ||
        funct  == instruction::AND ||
        funct  == instruction::OR ||
        funct  == instruction::XOR ||
        funct  == instruction::SLT ||
        funct  == instruction::SLTU ||
        funct  == instruction::SLL ||
        funct  == instruction::SRL ||
        funct  == instruction::SRA ||
        funct  == instruction::SLLV ||
        funct  == instruction::SRLV ||
        funct  == instruction::SRAV));
}

bool loadp(int instr) {
    return (exmem_ir.value() & instruction::op) == instruction::LW;
}

bool storep(int instr) {
    return (exmem_ir.value() & instruction::op) == instruction::SW;
}

bool loadstorep(int instr) {
    return loadp(instr) || storep(instr);
}

void mem1() {
    if(loadstorep(exmem_ir.value())) {
        //Load/Store instructions
        mem_alu_bus.IN().pullFrom(exmem_aluoutput);
        dm.MAR().latchFrom(mem_alu_bus.OUT());
    }
}

void mem2() {
    if(alu_instruction(exmem_ir.value())) {
        // MEM/WB.IR <- EX/MEM.IR;
        mem_ir_bus.IN().pullFrom(exmem_ir);
        memwb_ir.latchFrom(mem_ir_bus.OUT());

        // MEM/WB.ALUOutput <- EX/MEME.ALUOutput
        mem_alu_bus.IN().pullFrom(exmem_aluoutput);
        memwb_aluoutput.latchFrom(mem_alu_bus.OUT());
    }
    if(loadstorep(exmem_ir.value())) {
        //Load/Store
        //
        // MEM/WB.IR <- EX/MEM.IR
        mem_ir_bus.IN().pullFrom(exmem_ir);
        memwb_ir.latchFrom(mem_ir_bus.OUT());

        if(loadp(exmem_ir.value())){
            // Load
            // MEM/WB.LMD <- Mem[EX/MEM.ALUOutput
            dm.read();
            memwb_lmd.latchFrom(dm.READ());
        }
        else {
            // Store
            // Mem[EX/MEM.ALUOutput] <- EX/MEM.B
            dm.WRITE().pullFrom(exmem_b);
            dm.write();
        }
    }
}
