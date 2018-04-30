// writeback.cpp
// author ddm9373
//
// Contains functions for the writeback stage of the pipeline

#include "includes.h"

void wb1() {
    // ALL THIS SHIT MIGHT BE SUPPOSED TO HAPPEN ON TICK 2
    if(alu_instruction(memwb_ir.value())){
        //ALU
        if(rralu_instruction(memwb_ir.value())){
            //Register to Register ALU
            // reg[MEM/WB.IR[rd]] <- MEM/WB.ALUOutput
            wb_ALUOutput_bus.IN().pullFrom(memwb_aluoutput);
            regs[RD(memwb_ir.value())].latchFrom(wb_ALUOutput_bus.OUT());
        }
        else{
            //Immediate to Register ALU
            // reg[MEM/WB.IR[rt]] <- MEM/WB.ALUOutput
            wb_ALUOutput_bus.IN().pullFrom(memwb_aluoutput);
            regs[RT(memwb_ir.value())].latchFrom(wb_ALUOutput_bus.OUT());
        }
    }
    else if(loadp(memwb_ir.value())){
        //Load
        // reg[MEM/WB.IR[rt]] <- MEM/WB.LMD
        wb_LMD_bus.IN().pullFrom(memwb_lmd);
        regs[RT(memwb_ir.value())].latchFrom(wb_LMD_bus.OUT());
    }
}

void wb2() {}
