// run_simulation.cpp
// Author ddm9373
//
// Runs the simulation by repeatedly grabbing and then executing an instruction

#include "includes.h"

bool stall_check() {
    //ID/EX opcode = LOAD
    if (loadp(idex_ir.value())) {
        //IF/ID opcode = R-R ALU
        if (rralu_instruction(ifid_ir.value())) {
            return (RT(idex_ir.value()) == RS(idex_ir.value())) ||
                   (RT(idex_ir.value()) == RT(idex_ir.value()));
        }
        //IF/ID opcode = ALU imm., load, store, branch
        if (    immralu_instruction(ifid_ir.value()) ||
                loadp(ifid_ir.value()) ||
                storep(ifid_ir.value()) ||
                branchp(ifid_ir.value())) {

            return RT(idex_ir.value()) == RS(ifid_ir.value());
        }

    }
    //EX/MEM
    if (loadp(exmem_ir.value())) {
        //IF/ID opcode = BEQ or BNE
        if (branchp(ifid_ir.value())) {
            return RT(ifid_ir.value()) == RT(exmem_ir.value());
        }
    }
    return false;
}

// run until done
void run_simulation(char *objfile) {
    im.load(objfile);
    dm.load(objfile);

    pc.latchFrom(im.READ());
    Clock::tick();

    while(!done) {
        if (!(stalled & IFSTALL))  if1();
        if (!(stalled & IDSTALL))  id1();
        if (!(stalled & EXSTALL))  ex1();
        if (!(stalled & MEMSTALL)) mem1();
        if (!(stalled & WBSTALL))  wb1();

        Clock::tick();

        if (!(stalled & IFSTALL))  if2();
        if (!(stalled & IDSTALL))  id2();
        if (!(stalled & EXSTALL))  ex2();
        if (!(stalled & MEMSTALL)) mem2();
        if (!(stalled & WBSTALL))  wb2();

        Clock::tick();

        stalled = stalled >> 1;

        // Check for new stalls
        if (stall_check()) {
            cout << "STALLING" << endl;
            stalled = stalled | IFSTALL | IDSTALL;
        }
    }
}
