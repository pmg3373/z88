// writeback.cpp
// author ddm9373
//
// Contains functions for the writeback stage of the pipeline

#include "includes.h"

void dumpregs() {
    cout << right << setfill('0');
    int numprinted = 0;
    for(int i = 0; i < 32; i++) {
        if(REGS(i).value()) {
            if(!(numprinted % 4))
                cout << endl << "   ";
            cout << "  " << REGS(i);
            numprinted++;
        }
    }
}

void wb1() {
    // ALL THIS SHIT MIGHT BE SUPPOSED TO HAPPEN ON TICK 2
    if(alu_instruction(memwb_ir.value())){
        //ALU
        if(rralu_instruction(memwb_ir.value())){
            regmod = RD(memwb_ir.value());
            //if(!regmod) return;
            //Register to Register ALU
            // reg[MEM/WB.IR[rd]] <- MEM/WB.ALUOutput
            wb_ALUOutput_bus.IN().pullFrom(memwb_aluoutput);
            REGS(regmod).latchFrom(wb_ALUOutput_bus.OUT());

        }
        else{
            regmod = RT(memwb_ir.value());
            //if(!regmod) return;
            //Immediate to Register ALU
            // reg[MEM/WB.IR[rt]] <- MEM/WB.ALUOutput
            wb_ALUOutput_bus.IN().pullFrom(memwb_aluoutput);
            REGS(regmod).latchFrom(wb_ALUOutput_bus.OUT());
        }
    }
    else if(loadp(memwb_ir.value())){
        regmod = RT(memwb_ir.value());
        //This check doesn't make sense since 0 is a register that can be modified
        //if(!regmod) return;
        //Load
        // reg[MEM/WB.IR[rt]] <- MEM/WB.LMD
        wb_LMD_bus.IN().pullFrom(memwb_lmd);
        REGS(regmod).latchFrom(wb_LMD_bus.OUT());
    }
}

void wb2() {
    //This should probably be called something other than ir since we already have
    //a storage object in our globals file called ir
    int ir = memwb_ir.value();
    int opcode = OP(ir);
    int funct = FUN(ir);
    int switcher = opcode ? ir & instruction::op : ir & instruction::func;

    cout << std::hex << setw(8) << memwb_pc.value()
         << ":  " << setw(2) << opcode << " ";
    if (opcode) cout << "   ";
    else        cout << setw(2) << funct << " ";

    
    cout << setw(7) << left << setfill(' ');
    switch (switcher) {
        case instruction::NOP:
          cout << "NOP";
          break;
        case instruction::J:
          cout << "J";
          break;
        case instruction::JAL:
          cout << "JAL";
          break;
        case instruction::BEQ:
          cout << "BEQ";
          break;
        case instruction::BNE:
          cout << "BNE";
          break;
        case instruction::ADDI:
          cout << "ADDI";
          break;
        case instruction::SLTI:
          cout << "SLTI";
          break;
        case instruction::ANDI:
          cout << "ANDI";
          break;
        case instruction::ORI:
          cout << "ORI";
          break;
        case instruction::XORI:
          cout << "XORI";
          break;
        case instruction::LUI:
          cout << "LUI";
          break;
        case instruction::LW:
          cout << "LW";
          break;
        case instruction::SW:
          cout << "SW";
          break;
        case instruction::HALT:
          cout << "HALT";
          cout << endl << "Machine Halted - HALT instruction executed";
          done = true;
          break;
        case instruction::JR:
          cout << "JR";
          break;
        case instruction::JALR:
          cout << "JALR";
          break;
        case instruction::BREAK:
          cout << "BREAK";
          dumpregs();
          break;
        case instruction::ADD:
          cout << "ADD";
          break;
        case instruction::SUB:
          cout << "SUB";
          break;
        case instruction::AND:
          cout << "AND";
          break;
        case instruction::OR:
          cout << "OR";
          break;
        case instruction::XOR:
          cout << "XOR";
          break;
        case instruction::SLT:
          cout << "SLT";
          break;
        case instruction::SLTU:
          cout << "SLTU";
          break;
        case instruction::SLL:
          cout << "SLL";
          break;
        case instruction::SRL:
          cout << "SRL";
          break;
        case instruction::SRA:
          cout << "SRA";
          break;
        case instruction::SLLV:
          cout << "SLLV";
          break;
        case instruction::SRLV:
          cout << "SRLV";
          break;
        case instruction::SRAV:
          cout << "SRAV";
          break;
        default:
          cout << "????";
          break;
    }
    cout << right << setfill('0');

    //if (regmod != -1) cout << " " << REGS(regmod);
    //regmod = -1;
    if (regmod) cout << " " << REGS(regmod);
    regmod = 0;

    cout << endl;
}
