// run_simulation.cpp
// Author ddm9373
//
// Runs the simulation by repeatedly grabbing and then executing an instruction

#include "includes.h"

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
    }
}
