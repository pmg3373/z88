
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
void if2(StorageObject* IFIDIR, Counter* PC, StorageObject* IMM_MASK, 
        StorageObject* IFIDNPC, Memory* programMemory, BusALU* ALU) {
    
    if( (IFIDIR->value() & instruction.op == instruction.branch) && ( 1/*reg[IF/ID.IR[rs] op 0*/) ){ //TODO: Discuss with Carithers what this means
        //TODO: I have no idea how to do this in one tick
        //The result of IFIDIR & IMM_MASK needs to be sign extended shifted right twice
        //and then PC and IFIDPC both need the result
    }
    else{
        PC->perform(Counter::incr4);
        //TODO:This may have some issues depending on timing could push incr back to step 1
        IFIDNPC->latchFrom(ALU->OUT());
        ALU->OP1().pullFrom(PC);
        
    }
    
    programMemory->read();
    IFIDIR->latchFrom(programMemory->READ());
}
