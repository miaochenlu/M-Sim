#include "riscv_inst.h"
#include "reg_file.h"
#include "processor.h"

using namespace std;

add_insn::add_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : rtype_inst(pc, insn_bits, name) {
    src_regs.resize(2);
    src_regs[0] = rs1(); src_regs[1] = rs2();
    dst_regs.resize(1); dst_regs[0] = rd();
}

void add_insn::execute(processor& p) {
    printf("+++src size: %ld reg list: %d %d \n\tdstsize: %ld dst list: %d\n", 
        src_regs.size(), src_regs[0], src_regs[1], dst_regs.size(), dst_regs[0]);

    arch_state* state = p.get_state();
    state->gprs.write(
        dst_regs[0], state->gprs.read(src_regs[0]) + state->gprs.read(src_regs[1])
    );

    state->npc = state->pc + 4;
    printf("---result dst val: %d\n", state->gprs.read(dst_regs[0]));
}

// std::string add_insn::disassembly() {
//     return insn_name + " x" + to_string(dst_regs[0]) + ", x" + to_string(src_regs[0]) + ", x" + to_string(src_regs[1]); 
// }


sub_insn::sub_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : rtype_inst(pc, insn_bits, name) {
    src_regs.resize(2);
    src_regs[0] = rs1(); src_regs[1] = rs2();
    dst_regs.resize(1); dst_regs[0] = rd();
}

void sub_insn::execute(processor& p) {
    printf("+++src size: %ld reg list: %d %d \n\tdstsize: %ld dst list: %d\n", 
        src_regs.size(), src_regs[0], src_regs[1], dst_regs.size(), dst_regs[0]);

    arch_state* state = p.get_state();
    state->gprs.write(
        dst_regs[0], state->gprs.read(src_regs[0]) - state->gprs.read(src_regs[1])
    );

    state->npc = state->pc + 4;
    printf("---result dst val: %d\n", state->gprs.read(dst_regs[0]));
}

sll_insn::sll_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : rtype_inst(pc, insn_bits, name) {
    src_regs.resize(2);
    src_regs[0] = rs1(); src_regs[1] = rs2();
    dst_regs.resize(1); dst_regs[0] = rd();
}

void sll_insn::execute(processor& p) {
    printf("src size: %ld reg list: %d %d \n\tdstsize: %ld dst list: %d\n", 
        src_regs.size(), src_regs[0], src_regs[1], dst_regs.size(), dst_regs[0]);

    arch_state* state = p.get_state();
    state->gprs.write(
        dst_regs[0], (state->gprs.read(src_regs[0]) << state->gprs.read(src_regs[1]))
    );

    state->npc = state->pc + 4;
    printf("result dst val: %d\n", state->gprs.read(dst_regs[0]));
}

slt_insn::slt_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : rtype_inst(pc, insn_bits, name) {
    src_regs.resize(2);
    src_regs[0] = rs1(); src_regs[1] = rs2();
    dst_regs.resize(1); dst_regs[0] = rd();
}

void slt_insn::execute(processor& p) {
    printf("src size: %ld reg list: %d %d \n\tdstsize: %ld dst list: %d\n", 
        src_regs.size(), src_regs[0], src_regs[1], dst_regs.size(), dst_regs[0]);

    arch_state* state = p.get_state();
    state->gprs.write(
        dst_regs[0], int32_t(state->gprs.read(src_regs[0])) < int32_t(state->gprs.read(src_regs[1]))
    );

    state->npc = state->pc + 4;
    printf("result dst val: %d\n", state->gprs.read(dst_regs[0]));
}

sltu_insn::sltu_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : rtype_inst(pc, insn_bits, name) {
    src_regs.resize(2);
    src_regs[0] = rs1(); src_regs[1] = rs2();
    dst_regs.resize(1); dst_regs[0] = rd();
}

void sltu_insn::execute(processor& p) {
    printf("src size: %ld reg list: %d %d \n\tdstsize: %ld dst list: %d\n", 
        src_regs.size(), src_regs[0], src_regs[1], dst_regs.size(), dst_regs[0]);

    arch_state* state = p.get_state();
    state->gprs.write(
        dst_regs[0], uint32_t(state->gprs.read(src_regs[0])) < uint32_t(state->gprs.read(src_regs[1]))
    );

    state->npc = state->pc + 4;
    printf("result dst val: %d\n", state->gprs.read(dst_regs[0]));
}

xor_insn::xor_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : rtype_inst(pc, insn_bits, name) {
    src_regs.resize(2);
    src_regs[0] = rs1(); src_regs[1] = rs2();
    dst_regs.resize(1); dst_regs[0] = rd();
}

void xor_insn::execute(processor& p) {
    printf("+++src size: %ld reg list: %d %d \n\tdstsize: %ld dst list: %d\n", 
        src_regs.size(), src_regs[0], src_regs[1], dst_regs.size(), dst_regs[0]);

    arch_state* state = p.get_state();
    state->gprs.write(
        dst_regs[0], state->gprs.read(src_regs[0]) ^ state->gprs.read(src_regs[1])
    );

    state->npc = state->pc + 4;
    printf("---result dst val: %d\n", state->gprs.read(dst_regs[0]));
}


srl_insn::srl_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : rtype_inst(pc, insn_bits, name) {
    src_regs.resize(2);
    src_regs[0] = rs1(); src_regs[1] = rs2();
    dst_regs.resize(1); dst_regs[0] = rd();
}

void srl_insn::execute(processor& p) {
    printf("+++src size: %ld reg list: %d %d \n\tdstsize: %ld dst list: %d\n", 
        src_regs.size(), src_regs[0], src_regs[1], dst_regs.size(), dst_regs[0]);

    arch_state* state = p.get_state();
    state->gprs.write(
        dst_regs[0], (state->gprs.read(src_regs[0]) >> state->gprs.read(src_regs[1]))
    );

    state->npc = state->pc + 4;
    printf("---result dst val: %d\n", state->gprs.read(dst_regs[0]));
}

sra_insn::sra_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : rtype_inst(pc, insn_bits, name) {
    src_regs.resize(2);
    src_regs[0] = rs1(); src_regs[1] = rs2();
    dst_regs.resize(1); dst_regs[0] = rd();
}

void sra_insn::execute(processor& p) {
    printf("+++src size: %ld reg list: %d %d \n\tdstsize: %ld dst list: %d\n", 
        src_regs.size(), src_regs[0], src_regs[1], dst_regs.size(), dst_regs[0]);
    arch_state* state = p.get_state();
    printf("reg[0]: %#010x\t reg[1]: %#010x\n", state->gprs.read(src_regs[0]), state->gprs.read(src_regs[1]));

    uint32_t sign_bit = (state->gprs.read(src_regs[0]) >> 31);
    uint32_t num = 0;
    if(sign_bit) {
        num = ((1 << (state->gprs.read(src_regs[1]) + 1)) - 1) << (32 - state->gprs.read(src_regs[1]));
    }
    printf("sign bit: %d num: %#010x\n", sign_bit, int32_t(num));

    state->gprs.write(
        dst_regs[0], num + (state->gprs.read(src_regs[0]) >> state->gprs.read(src_regs[1]))
    );

    state->npc = state->pc + 4;
    printf("---result dst val: %#010x\n", (int32_t)(state->gprs.read(dst_regs[0])));
}

or_insn::or_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : rtype_inst(pc, insn_bits, name) {
    src_regs.resize(2);
    src_regs[0] = rs1(); src_regs[1] = rs2();
    dst_regs.resize(1); dst_regs[0] = rd();
}

void or_insn::execute(processor& p) {
    printf("+++src size: %ld reg list: %d %d \n\tdstsize: %ld dst list: %d\n", 
        src_regs.size(), src_regs[0], src_regs[1], dst_regs.size(), dst_regs[0]);

    arch_state* state = p.get_state();
    state->gprs.write(
        dst_regs[0], state->gprs.read(src_regs[0]) | state->gprs.read(src_regs[1])
    );

    state->npc = state->pc + 4;
    printf("---result dst val: %d\n", state->gprs.read(dst_regs[0]));
}

and_insn::and_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : rtype_inst(pc, insn_bits, name) {
    src_regs.resize(2);
    src_regs[0] = rs1(); src_regs[1] = rs2();
    dst_regs.resize(1); dst_regs[0] = rd();
}

void and_insn::execute(processor& p) {
    printf("+++src size: %ld reg list: %d %d \n\tdstsize: %ld dst list: %d\n", 
        src_regs.size(), src_regs[0], src_regs[1], dst_regs.size(), dst_regs[0]);

    arch_state* state = p.get_state();
    state->gprs.write(
        dst_regs[0], state->gprs.read(src_regs[0]) & state->gprs.read(src_regs[1])
    );

    state->npc = state->pc + 4;
    printf("---result dst val: %d\n", state->gprs.read(dst_regs[0]));
}

addi_insn::addi_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : imm_inst(pc, insn_bits, name, 0) {
    src_regs.resize(1); src_regs[0] = rs1();
    dst_regs.resize(1); dst_regs[0] = rd();
    imm = i_imm();
}

void addi_insn::execute(processor& p) {
    printf("src size: %ld reg list: %d\n\tdstsize: %ld dst list: %d\n", 
        src_regs.size(), src_regs[0], dst_regs.size(), dst_regs[0]);
    arch_state* state = p.get_state();
    state->gprs.write(
        dst_regs[0], state->gprs.read(src_regs[0]) + imm
    );
    state->npc = state->pc + 4;
    printf("result dst val: %d\n", state->gprs.read(dst_regs[0]));
}


std::string addi_insn::disassembly() {
    return insn_name + " x" + to_string(dst_regs[0]) 
            + ", x" + to_string(src_regs[0]) 
            + ", " + to_string(imm); 
}


beq_insn::beq_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : imm_inst(pc, insn_bits, name, 0) {
    src_regs.resize(2); src_regs[0] = rs1(); src_regs[1] = rs2();
    imm = sb_imm();
}

void beq_insn::execute(processor& p) {
    arch_state* state = p.get_state();
    
    if(state->gprs.read(src_regs[0]) == state->gprs.read(src_regs[1])) {
        state->npc = state->pc + imm;
        printf("beq jump\n");
    } else {
        state->npc = state->pc + 4;
        printf("beq not jump\n");
    }
}


std::string beq_insn::disassembly() {
    return insn_name + " x" + to_string(src_regs[0]) 
            + ", x" + to_string(src_regs[1]) + ", " + to_string(imm); 
}