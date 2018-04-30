// run_simulation.cpp
// Author ddm9373
//
// Runs the simulation by repeatedly grabbing and then executing an instruction

#include "includes.h"

// run until done
void run_simulation(char *objfile) {
    //m.load(objfile);

    //r7.latchFrom(m.READ());
    //Clock::tick();

    // Initialize Constants
    imm_sign_bit.latchFrom(imm_sign_bit_const.OUT());

    while(!done) {
        if1();
        id1();
        ex1();
        mem1();
        wb1();

        Clock::tick();

        if2();
        id2();
        ex2();
        mem2();
        wb2();

        Clock::tick();
    }
}
