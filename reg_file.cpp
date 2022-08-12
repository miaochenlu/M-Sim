#include "reg_file.h"

gpr_regfile::gpr_regfile() {
    for(int i = 0; i < 32; i++) {
        regs[i] = 0;
    }
}

gpr_regfile::~gpr_regfile() {

}

uint32_t gpr_regfile::read(uint32_t index) const {
    if(index == 0) return 0;
    return regs[index];
}

void gpr_regfile::write(uint32_t index, uint32_t val) {
    if(index != 0) {
        regs[index] = val;
    }
}

arch_state::arch_state()
    :pc(0), npc(0), gprs() {

}

arch_state::~arch_state() {

}