
#include "includes.h"

// fetch.cpp
// author ddm9373
//
// Contains functions for the fetch stage of the pipeline

/**
 * Step one of instruction fetch
 * RTL: MEM[MAR] <- PC
 * @param PC: Pointer to Program Counter from register file
 * @param programMemory: Pointer to the memory unit that contain the program memory
 * @param bus: Pointer to a Bus
 */
void if1(StorageObject* PC, Memory* programMemory, Bus* bus) {
    bus->IN().pullFrom(PC);
    programMemory->MAR().latchFrom(bus->OUT());
}

/**
 * Step two of instruction fetch
 * RTL: IFIDIR <- MEM[MAR];
 *      IFIDNPC <- ( (IFIDIR & OPCODE == BRANCH) && (IFIDIR & RS op 0) ) ?
 *              IFIDNPC + (IFIDIR && IMM ) << 2 (sign extended) :
 *              PC + 4;
 *      PC <- ( (IFIDIR & OPCODE == BRANCH) && (IFIDIR & RS op 0) ) ?
 *              IFIDNPC + (IFIDIR && IMM ) << 2 (sign extended) :
 *              PC + 4;
 * @param IFIDIR
 * @param PC
 * @param IMM_MASK
 * @param IFIDNPC
 * @param programMemory
 * @param ALU
 */
//void if2(StorageObject* IFIDIR, Counter* PC, StorageObject* IMM_MASK, 
//        StorageObject* IFIDNPC, Memory* programMemory, BusALU* ALU) {
void if2() {
    // If this is a branch instruction
    if(((IFID.ir->value() & BRANCH_INSTR) == BRANCH_INSTR) &&
        // And the condition is met
        //TODO
        (DECODEREGISTER(IFID.ir->value()) OP 0)) {
        
        // Add some numbers together for both the PC and NPC
        // TODO
        SOMEALU.op1()->latchFrom(*IFID.npc);

        // This decode immediate instruction might need to be a sign extend in
        // the previous clock tick
        SOMEALU.op2()->latchFrom(*DECODEIMM(IFID.ir->value()));
        SOMEALU.perform(BusALU::op_add);

        pc.latchFrom(SOMEALU.OUT());
        IFID.npc->latchFrom(SOMEALU.OUT());
    }
    else{
        pc.perform(Counter::incr4);
        IFID.npc->perform(Counter::incr4);
    }
    
    programMemory->read();
    IFIDIR->latchFrom(programMemory->READ());
}
