// prototypes.h
// author ddm9373
//
// contains prototypes for all functions

#ifndef _PROTOTYPES_H
#define _PROTOTYPES_H

void make_connections(void);

void run_simulation(char*);

bool alu_instruction(int);
bool loadp(int);
bool storep(int);
bool loadstorep(int);
bool rralu_instruction(int);

void if1(void);
void if2(void);

void id1(void);
void id2(void);

void ex1(void);
void ex2(void);

void mem1(void);
void mem2(void);

void wb1(void);
void wb2(void);

void forwarding(void);

#endif
