#include "base_inst.h"
#include "processor.h"

base_inst::base_inst(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : insn_pc(pc), insn_bits(insn_bits), insn_name(name) {

}

void base_inst::execute(processor& p) {
    printf("base inst execute\n");
}