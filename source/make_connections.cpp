#include "includes.h"

const char * reg_names[32] = {
"REG0",
"REG1",
"REG2",
"REG3",
"REG4",
"REG5",
"REG6",
"REG7",
"REG8",
"REG9",
"REG10",
"REG11",
"REG12",
"REG13",
"REG14",
"REG15",
"REG16",
"REG17",
"REG18",
"REG19",
"REG20",
"REG21",
"REG22",
"REG23",
"REG24",
"REG25",
"REG26",
"REG27",
"REG28",
"REG29",
"REG30",
"REG31"
};

void make_connections(){
    // Initialize registers
    regs = (Counter*) malloc (32 * sizeof(Counter));
    for(int i = 0; i < 32; i++) {
        Counter reg(reg_names[i],  DATA_BITS);
        std::memcpy(regs + i, &reg, sizeof(Counter));
    }
}
