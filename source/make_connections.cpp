#include "includes.h"

void make_connections(){
    // Register file
    for(int i = 0; i < 32; i++) {
        REGS(i).connectsTo(id_a_bus.IN());
        REGS(i).connectsTo(id_b_bus.IN());

        REGS(i).connectsTo(wb_ALUOutput_bus.OUT());
        REGS(i).connectsTo(wb_LMD_bus.OUT());
    }

    // FETCH CONNECTIONS
    pc.connectsTo(ifbus.IN());
    pc.connectsTo(ifpcbus.IN());
    pc.connectsTo(ifalu.OUT());
    pc.connectsTo(im.READ());

    ifid_pc.connectsTo(ifpcbus.OUT());

    im.MAR().connectsTo(ifbus.OUT());

    ifid_ir.connectsTo(ifalu.OP1());
    ifid_ir.connectsTo(im.READ());

    imm_sign_bit_stor.connectsTo(ifalu.OP2());

    iftemp.connectsTo(ifalu.OUT());
    iftemp.connectsTo(ifalu.OP1());

    ifid_npc.connectsTo(ifalu.OP2());
    ifid_npc.connectsTo(ifalu.OUT());

    // DECODE CONNECTIONS
    pc.connectsTo(id_j_alu.OUT());
    pc.connectsTo(id_j_alu.OP2());

    ifid_pc.connectsTo(id_pc_bus.IN());
    idex_pc.connectsTo(id_pc_bus.OUT());

    ifid_ir.connectsTo(id_sh_alu.OP1());
    ifid_ir.connectsTo(id_ir_bus.IN());
    ifid_ir.connectsTo(id_imm_alu.OP1());
    ifid_ir.connectsTo(id_j_alu.OP1());

    sh_mask_stor.connectsTo(id_sh_alu.OP2());

    imm_sign_bit_stor.connectsTo(id_imm_alu.OP2());

    sh_shift_stor.connectsTo(id_sh_alu.OP2());

    jump_mask_stor.connectsTo(id_j_alu.OP2());

    id_temp_sh.connectsTo(id_sh_alu.OUT());
    id_temp_sh.connectsTo(id_sh_alu.OP1());

    id_temp_br.connectsTo(id_imm_alu.OUT());
    id_temp_br.connectsTo(id_j_alu.OP1());

    idex_a.connectsTo(id_a_bus.OUT());
    idex_b.connectsTo(id_b_bus.OUT());
    idex_ir.connectsTo(id_ir_bus.OUT());
    idex_imm.connectsTo(id_imm_alu.OUT());
    idex_sh.connectsTo(id_sh_alu.OUT());


    // EXECUTE CONNECTIONS
    idex_pc.connectsTo(ex_pc_bus.IN());
    exmem_pc.connectsTo(ex_pc_bus.OUT());

    idex_ir.connectsTo(ex_ir_bus.IN());
    exmem_ir.connectsTo(ex_ir_bus.OUT());

    idex_b.connectsTo(ex_b_bus.IN());
    exmem_b.connectsTo(ex_b_bus.OUT());
    
    idex_ir.connectsTo(exALU.OP1());
    idex_a.connectsTo(exALU.OP1());
    idex_a.connectsTo(exALU.OP2());
    idex_b.connectsTo(exALU.OP1());
    idex_b.connectsTo(exALU.OP2());
    idex_imm.connectsTo(exALU.OP1());
    idex_imm.connectsTo(exALU.OP2());
    idex_pc.connectsTo(exALU.OP1());
    idex_pc.connectsTo(exALU.OP2());
    idex_sh.connectsTo(exALU.OP1());
    idex_sh.connectsTo(exALU.OP2());
    sixteen_const_stor.connectsTo(exALU.OP1());
    sixteen_const_stor.connectsTo(exALU.OP2());
    low_five_bits_stor.connectsTo(exALU.OP1());
    low_five_bits_stor.connectsTo(exALU.OP2());
    extemp.connectsTo(exALU.OP1());
    extemp.connectsTo(exALU.OP2());
    
    extemp.connectsTo(exALU.OUT());
    exmem_aluoutput.connectsTo(exALU.OUT());
    
    exmem_b.connectsTo(exALU.IN1());


    // MEMORY CONNECTIONS
    exmem_pc.connectsTo(mem_pc_bus.IN());
    memwb_pc.connectsTo(mem_pc_bus.OUT());

    exmem_aluoutput.connectsTo(mem_alu_bus.IN());
    dm.MAR().connectsTo(mem_alu_bus.OUT());

    exmem_ir.connectsTo(mem_ir_bus.IN());
    memwb_ir.connectsTo(mem_ir_bus.OUT());

    exmem_aluoutput.connectsTo(mem_alu_bus.IN());
    memwb_aluoutput.connectsTo(mem_alu_bus.OUT());

    memwb_lmd.connectsTo(dm.READ());
    exmem_b.connectsTo(dm.WRITE());
    // WRITEBACK CONNECTIONS
    memwb_aluoutput.connectsTo(wb_ALUOutput_bus.IN());
    memwb_lmd.connectsTo(wb_LMD_bus.IN());

}
