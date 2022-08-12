#include "riscv_inst.h"
#include "reg_file.h"
#include "processor.h"

using namespace std;

add::add(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : rtype_inst(pc, insn_bits, name) {
    src_regs.resize(2);
    src_regs[0] = rs1(); src_regs[1] = rs2();
    dst_regs.resize(1); dst_regs[0] = rd();
}

void add::execute(processor& p) {
    printf("src size: %ld reg list: %d %d \ndst size: %ld dst list: %d\n", 
        src_regs.size(), src_regs[0], src_regs[1], dst_regs.size(), dst_regs[0]);

    arch_state* state = p.get_state();
    state->gprs.write(
        dst_regs[0], state->gprs.read(src_regs[0]) + state->gprs.read(src_regs[1])
    );

    state->npc = state->pc + 4;
    printf("result dst val: %d\n", state->gprs.read(dst_regs[0]));
}

std::string add::disassembly() {
    return insn_name + " x" + to_string(dst_regs[0]) + ", x" + to_string(src_regs[0]) + ", x" + to_string(src_regs[1]); 
}


addi::addi(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : imm_inst(pc, insn_bits, name, 0) {
    src_regs.resize(1); src_regs[0] = rs1();
    dst_regs.resize(1); dst_regs[0] = rd();
    imm = i_imm();
}

void addi::execute(processor& p) {
    printf("src size: %ld reg list: %d\ndst size: %ld dst list: %d\n", 
        src_regs.size(), src_regs[0], dst_regs.size(), dst_regs[0]);
    arch_state* state = p.get_state();
    state->gprs.write(
        dst_regs[0], state->gprs.read(src_regs[0]) + imm
    );
    state->npc = state->pc + 4;
    printf("result dst val: %d\n", state->gprs.read(dst_regs[0]));
}


std::string addi::disassembly() {
    return insn_name + " x" + to_string(dst_regs[0]) 
            + ", x" + to_string(src_regs[0]) 
            + ", " + to_string(imm); 
}


beq::beq(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : imm_inst(pc, insn_bits, name, 0) {
    src_regs.resize(2); src_regs[0] = rs1(); src_regs[1] = rs2();
    imm = sb_imm();
}

void beq::execute(processor& p) {
    arch_state* state = p.get_state();
    
    if(state->gprs.read(src_regs[0]) == state->gprs.read(src_regs[1])) {
        state->npc = state->pc + imm;
        printf("beq jump\n");
    } else {
        state->npc = state->pc + 4;
        printf("beq not jump\n");
    }
}


std::string beq::disassembly() {
    return insn_name + " x" + to_string(src_regs[0]) 
            + ", x" + to_string(src_regs[1]) + ", " + to_string(imm); 
}