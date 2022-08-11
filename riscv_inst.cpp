#include "riscv_inst.h"

add::add(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : rtype_inst(pc, insn_bits, name) {
    src_regs.resize(2);
    src_regs[0] = rs1(); src_regs[1] = rs2();
    dst_regs.resize(1); dst_regs[0] = rd();
}

void add::execute() {
    printf("add inst\n");
    printf("src size: %d reg list: %d %d \t dest size: %d dest list: %d\n", 
        src_regs.size(), src_regs[0], src_regs[1], dst_regs.size(), dst_regs[0]);
}