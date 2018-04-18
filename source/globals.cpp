// globals.cpp
// author ddm9373
//
// initializing processor components

// Useful global variables
bool done = false;


// Standard register set
// Counter regs[32];
Counter pc("PC", DATA_BITS);
StorageObject ir("IR", DATA_BITS);
StorageObject iar("IAR", DATA_BITS);
StorageObject temp("TEMP", DATA_BITS);

StorageObject a("A", DATA_BITS);
StorageObject b("B", DATA_BITS);
StorageObject c("C", DATA_BITS);


// ALUs
BusALU mainALU("mainALU", DATA_BITS);
BusALU ifALU("ifALU", DATA_BITS);


// Memory
//Memory dm("Data Memory", ADDR_BITS, DATA_BITS, ;
//Memory im;


// Additional registers for pipelining (If we need extra)


// IF/ID


// ID/EX


// EX/MEM


// MEM/WB


// Constants


// The Krapf's yard
// Defined busses
Bus op1("OP1", DATA_BITS);
Bus op2("OP2", DATA_BITS);
Bus out("OUT", DATA_BITS);


// Misc busses


