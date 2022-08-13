#include "riscv_inst.h"
#include "../processor.h"

using namespace std;

add_insn::add_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : rtype_inst(pc, insn_bits, name) {

}

void add_insn::execute(processor& p) {
    printf("+++src size: %ld reg list: %d %d \n\tdstsize: %ld dst list: %d\n", 
        src_regs.size(), src_regs[0], src_regs[1], dst_regs.size(), dst_regs[0]);

    arch_state* state = p.get_state();
    state->gprs.write(
        dst_regs[0], state->gprs.read(src_regs[0]) + state->gprs.read(src_regs[1])
    );

    state->npc = state->pc + 4;
    printf("---result dst val: %#x\n", state->gprs.read(dst_regs[0]));
}

// std::string add_insn::disassembly() {
//     return insn_name + " x" + to_string(dst_regs[0]) + ", x" + to_string(src_regs[0]) + ", x" + to_string(src_regs[1]); 
// }


sub_insn::sub_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : rtype_inst(pc, insn_bits, name) {

}

void sub_insn::execute(processor& p) {
    printf("+++src size: %ld reg list: %d %d \n\tdstsize: %ld dst list: %d\n", 
        src_regs.size(), src_regs[0], src_regs[1], dst_regs.size(), dst_regs[0]);

    arch_state* state = p.get_state();
    state->gprs.write(
        dst_regs[0], state->gprs.read(src_regs[0]) - state->gprs.read(src_regs[1])
    );

    state->npc = state->pc + 4;
    printf("---result dst val: %#x\n", state->gprs.read(dst_regs[0]));
}

sll_insn::sll_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : rtype_inst(pc, insn_bits, name) {

}

void sll_insn::execute(processor& p) {
    printf("src size: %ld reg list: %d %d \n\tdstsize: %ld dst list: %d\n", 
        src_regs.size(), src_regs[0], src_regs[1], dst_regs.size(), dst_regs[0]);

    arch_state* state = p.get_state();
    state->gprs.write(
        dst_regs[0], (state->gprs.read(src_regs[0]) << state->gprs.read(src_regs[1]))
    );

    state->npc = state->pc + 4;
    printf("result dst val: %#x\n", state->gprs.read(dst_regs[0]));
}

slt_insn::slt_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : rtype_inst(pc, insn_bits, name) {

}

void slt_insn::execute(processor& p) {
    printf("src size: %ld reg list: %d %d \n\tdstsize: %ld dst list: %d\n", 
        src_regs.size(), src_regs[0], src_regs[1], dst_regs.size(), dst_regs[0]);

    arch_state* state = p.get_state();
    state->gprs.write(
        dst_regs[0], int32_t(state->gprs.read(src_regs[0])) < int32_t(state->gprs.read(src_regs[1]))
    );

    state->npc = state->pc + 4;
    printf("result dst val: %#x\n", state->gprs.read(dst_regs[0]));
}

sltu_insn::sltu_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : rtype_inst(pc, insn_bits, name) {

}

void sltu_insn::execute(processor& p) {
    printf("src size: %ld reg list: %d %d \n\tdstsize: %ld dst list: %d\n", 
        src_regs.size(), src_regs[0], src_regs[1], dst_regs.size(), dst_regs[0]);

    arch_state* state = p.get_state();
    state->gprs.write(
        dst_regs[0], uint32_t(state->gprs.read(src_regs[0])) < uint32_t(state->gprs.read(src_regs[1]))
    );

    state->npc = state->pc + 4;
    printf("result dst val: %#x\n", state->gprs.read(dst_regs[0]));
}

xor_insn::xor_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : rtype_inst(pc, insn_bits, name) {

}

void xor_insn::execute(processor& p) {
    printf("+++src size: %ld reg list: %d %d \n\tdstsize: %ld dst list: %d\n", 
        src_regs.size(), src_regs[0], src_regs[1], dst_regs.size(), dst_regs[0]);

    arch_state* state = p.get_state();
    state->gprs.write(
        dst_regs[0], state->gprs.read(src_regs[0]) ^ state->gprs.read(src_regs[1])
    );

    state->npc = state->pc + 4;
    printf("---result dst val: %#x\n", state->gprs.read(dst_regs[0]));
}


srl_insn::srl_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : rtype_inst(pc, insn_bits, name) {

}

void srl_insn::execute(processor& p) {
    printf("+++src size: %ld reg list: %d %d \n\tdstsize: %ld dst list: %d\n", 
        src_regs.size(), src_regs[0], src_regs[1], dst_regs.size(), dst_regs[0]);

    arch_state* state = p.get_state();
    state->gprs.write(
        dst_regs[0], (state->gprs.read(src_regs[0]) >> state->gprs.read(src_regs[1]))
    );

    state->npc = state->pc + 4;
    printf("---result dst val: %#x\n", state->gprs.read(dst_regs[0]));
}

sra_insn::sra_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : rtype_inst(pc, insn_bits, name) {

}

void sra_insn::execute(processor& p) {
    printf("+++src size: %ld reg list: %d %d \n\tdstsize: %ld dst list: %d\n", 
        src_regs.size(), src_regs[0], src_regs[1], dst_regs.size(), dst_regs[0]);
    arch_state* state = p.get_state();
    printf("reg[0]: %#010x\t reg[1]: %#010x\n", state->gprs.read(src_regs[0]), state->gprs.read(src_regs[1]));

    // uint32_t sign_bit = (state->gprs.read(src_regs[0]) >> 31);
    // uint32_t num = 0;
    // if(sign_bit) {
    //     num = ((1 << (state->gprs.read(src_regs[1]) + 1)) - 1) << (32 - state->gprs.read(src_regs[1]));
    // }
    // printf("sign bit: %d num: %#010x\n", sign_bit, int32_t(num));

    // state->gprs.write(
    //     dst_regs[0], int32_t(state->gprs.read(src_regs[0]) >> state->gprs.read(src_regs[1]))
    // );

    state->gprs.write(
        dst_regs[0], int32_t(state->gprs.read(src_regs[0])) >> state->gprs.read(src_regs[1])
    );

    state->npc = state->pc + 4;
    printf("---result dst val: %#010x\n", (int32_t)(state->gprs.read(dst_regs[0])));
}

or_insn::or_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : rtype_inst(pc, insn_bits, name) {

}

void or_insn::execute(processor& p) {
    printf("+++src size: %ld reg list: %d %d \n\tdstsize: %ld dst list: %d\n", 
        src_regs.size(), src_regs[0], src_regs[1], dst_regs.size(), dst_regs[0]);

    arch_state* state = p.get_state();
    state->gprs.write(
        dst_regs[0], state->gprs.read(src_regs[0]) | state->gprs.read(src_regs[1])
    );

    state->npc = state->pc + 4;
    printf("---result dst val: %#x\n", state->gprs.read(dst_regs[0]));
}

and_insn::and_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : rtype_inst(pc, insn_bits, name) {

}

void and_insn::execute(processor& p) {
    printf("+++src size: %ld reg list: %d %d \n\tdstsize: %ld dst list: %d\n", 
        src_regs.size(), src_regs[0], src_regs[1], dst_regs.size(), dst_regs[0]);

    arch_state* state = p.get_state();
    state->gprs.write(
        dst_regs[0], state->gprs.read(src_regs[0]) & state->gprs.read(src_regs[1])
    );

    state->npc = state->pc + 4;
    printf("---result dst val: %#x\n", state->gprs.read(dst_regs[0]));
}

lb_insn::lb_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : load_inst(pc, insn_bits, name) {

}

void lb_insn::execute(processor& p) {
    arch_state* state = p.get_state();
    
    uint32_t addr = state->gprs.read(src_regs[0]) + imm;
    uint32_t value = p.get_ram()->read(addr, 1);
    uint32_t sign_bit = (value >> 7) & 0x1;

    if(sign_bit) value = value | 0xFFFFFF00;
    
    state->gprs.write(dst_regs[0], value);
    state->npc = state->pc + 4;
    printf("result dst val: %#x\n", state->gprs.read(dst_regs[0]));
}

lh_insn::lh_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : load_inst(pc, insn_bits, name) {

}

void lh_insn::execute(processor& p) {
    arch_state* state = p.get_state();
    
    uint32_t addr = state->gprs.read(src_regs[0]) + imm;
    uint32_t value = p.get_ram()->read(addr, 2);
    uint32_t sign_bit = (value >> 15) & 0x1;

    if(sign_bit) value = value | 0xFFFF0000;
    
    state->gprs.write(dst_regs[0], value);
    state->npc = state->pc + 4;
    printf("result dst val: %#x\n", state->gprs.read(dst_regs[0]));
}

lbu_insn::lbu_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : load_inst(pc, insn_bits, name) {

}

void lbu_insn::execute(processor& p) {
    arch_state* state = p.get_state();
    
    uint32_t addr = state->gprs.read(src_regs[0]) + imm;
    state->gprs.write(dst_regs[0], int32_t(p.get_ram()->read(addr, 1)));
    state->npc = state->pc + 4;
    printf("result dst val: %#x\n", state->gprs.read(dst_regs[0]));
}

lhu_insn::lhu_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : load_inst(pc, insn_bits, name) {

}

void lhu_insn::execute(processor& p) {
    arch_state* state = p.get_state();
    
    uint32_t addr = state->gprs.read(src_regs[0]) + imm;
    state->gprs.write(dst_regs[0], int32_t(p.get_ram()->read(addr, 2)));
    state->npc = state->pc + 4;
    printf("result dst val: %#x\n", state->gprs.read(dst_regs[0]));
}

lw_insn::lw_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : load_inst(pc, insn_bits, name) {

}

void lw_insn::execute(processor& p) {
    arch_state* state = p.get_state();
    
    uint32_t addr = state->gprs.read(src_regs[0]) + imm;
    state->gprs.write(dst_regs[0], int32_t(p.get_ram()->read(addr, 4)));
    state->npc = state->pc + 4;
    printf("result dst val: %#x\n", state->gprs.read(dst_regs[0]));
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
    printf("result dst val: %#x\n", state->gprs.read(dst_regs[0]));
}


std::string addi_insn::disassembly() {
    return insn_name + " x" + to_string(dst_regs[0]) 
            + ", x" + to_string(src_regs[0]) 
            + ", " + to_string(imm); 
}

slti_insn::slti_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : imm_inst(pc, insn_bits, name, 0) {
    src_regs.resize(1); src_regs[0] = rs1();
    dst_regs.resize(1); dst_regs[0] = rd();
    imm = i_imm();
}

void slti_insn::execute(processor& p) {
    printf("src size: %ld reg list: %d\n\tdstsize: %ld dst list: %d\n", 
        src_regs.size(), src_regs[0], dst_regs.size(), dst_regs[0]);
    arch_state* state = p.get_state();
    state->gprs.write(
        dst_regs[0], int32_t(state->gprs.read(src_regs[0])) < int32_t(imm)
    );
    state->npc = state->pc + 4;
    printf("result dst val: %#x\n", state->gprs.read(dst_regs[0]));
}

std::string slti_insn::disassembly() {
    return insn_name + " x" + to_string(dst_regs[0]) 
            + ", x" + to_string(src_regs[0]) 
            + ", " + to_string(imm); 
}

sltiu_insn::sltiu_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : imm_inst(pc, insn_bits, name, 0) {
    src_regs.resize(1); src_regs[0] = rs1();
    dst_regs.resize(1); dst_regs[0] = rd();
    imm = i_imm();
}

void sltiu_insn::execute(processor& p) {
    printf("src size: %ld reg list: %d\n\tdstsize: %ld dst list: %d\n", 
        src_regs.size(), src_regs[0], dst_regs.size(), dst_regs[0]);
    arch_state* state = p.get_state();
    state->gprs.write(
        dst_regs[0], uint32_t(state->gprs.read(src_regs[0])) < uint32_t(imm)
    );
    state->npc = state->pc + 4;
    printf("result dst val: %#x\n", state->gprs.read(dst_regs[0]));
}

std::string sltiu_insn::disassembly() {
    return insn_name + " x" + to_string(dst_regs[0]) 
            + ", x" + to_string(src_regs[0]) 
            + ", " + to_string(imm); 
}

xori_insn::xori_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : imm_inst(pc, insn_bits, name, 0) {
    src_regs.resize(1); src_regs[0] = rs1();
    dst_regs.resize(1); dst_regs[0] = rd();
    imm = i_imm();
}

void xori_insn::execute(processor& p) {
    printf("src size: %ld reg list: %d\n\tdstsize: %ld dst list: %d\n", 
        src_regs.size(), src_regs[0], dst_regs.size(), dst_regs[0]);
    arch_state* state = p.get_state();
    state->gprs.write(
        dst_regs[0], state->gprs.read(src_regs[0]) ^ imm
    );
    state->npc = state->pc + 4;
    printf("result dst val: %#x\n", state->gprs.read(dst_regs[0]));
}

std::string xori_insn::disassembly() {
    return insn_name + " x" + to_string(dst_regs[0]) 
            + ", x" + to_string(src_regs[0]) 
            + ", " + to_string(imm); 
}

ori_insn::ori_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : imm_inst(pc, insn_bits, name, 0) {
    src_regs.resize(1); src_regs[0] = rs1();
    dst_regs.resize(1); dst_regs[0] = rd();
    imm = i_imm();
}

void ori_insn::execute(processor& p) {
    printf("src size: %ld reg list: %d\n\tdstsize: %ld dst list: %d\n", 
        src_regs.size(), src_regs[0], dst_regs.size(), dst_regs[0]);
    arch_state* state = p.get_state();
    state->gprs.write(
        dst_regs[0], state->gprs.read(src_regs[0]) | imm
    );
    state->npc = state->pc + 4;
    printf("result dst val: %#x\n", state->gprs.read(dst_regs[0]));
}

std::string ori_insn::disassembly() {
    return insn_name + " x" + to_string(dst_regs[0]) 
            + ", x" + to_string(src_regs[0]) 
            + ", " + to_string(imm); 
}

andi_insn::andi_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : imm_inst(pc, insn_bits, name, 0) {
    src_regs.resize(1); src_regs[0] = rs1();
    dst_regs.resize(1); dst_regs[0] = rd();
    imm = i_imm();
}

void andi_insn::execute(processor& p) {
    printf("src size: %ld reg list: %d\n\tdstsize: %ld dst list: %d\n", 
        src_regs.size(), src_regs[0], dst_regs.size(), dst_regs[0]);
    arch_state* state = p.get_state();
    state->gprs.write(
        dst_regs[0], state->gprs.read(src_regs[0]) & imm
    );
    state->npc = state->pc + 4;
    printf("result dst val: %#x\n", state->gprs.read(dst_regs[0]));
}

std::string andi_insn::disassembly() {
    return insn_name + " x" + to_string(dst_regs[0]) 
            + ", x" + to_string(src_regs[0]) 
            + ", " + to_string(imm); 
}

slli_insn::slli_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : imm_inst(pc, insn_bits, name, 0) {
    src_regs.resize(1); src_regs[0] = rs1();
    dst_regs.resize(1); dst_regs[0] = rd();
    imm = shamt();
}

void slli_insn::execute(processor& p) {
    printf("src size: %ld reg list: %d\n\tdstsize: %ld dst list: %d\n", 
        src_regs.size(), src_regs[0], dst_regs.size(), dst_regs[0]);
    arch_state* state = p.get_state();
    state->gprs.write(
        dst_regs[0], state->gprs.read(src_regs[0]) << imm
    );
    state->npc = state->pc + 4;
    printf("result dst val: %#x\n", state->gprs.read(dst_regs[0]));
}

std::string slli_insn::disassembly() {
    return insn_name + " x" + to_string(dst_regs[0]) 
            + ", x" + to_string(src_regs[0]) 
            + ", " + to_string(imm); 
}

srli_insn::srli_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : imm_inst(pc, insn_bits, name, 0) {
    src_regs.resize(1); src_regs[0] = rs1();
    dst_regs.resize(1); dst_regs[0] = rd();
    imm = shamt();
}

void srli_insn::execute(processor& p) {
    printf("src size: %ld reg list: %d\n\tdstsize: %ld dst list: %d\n", 
        src_regs.size(), src_regs[0], dst_regs.size(), dst_regs[0]);
    arch_state* state = p.get_state();
    state->gprs.write(
        dst_regs[0], state->gprs.read(src_regs[0]) >> imm
    );
    state->npc = state->pc + 4;
    printf("result dst val: %#x\n", state->gprs.read(dst_regs[0]));
}

std::string srli_insn::disassembly() {
    return insn_name + " x" + to_string(dst_regs[0]) 
            + ", x" + to_string(src_regs[0]) 
            + ", " + to_string(imm); 
}

srai_insn::srai_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : imm_inst(pc, insn_bits, name, 0) {
    src_regs.resize(1); src_regs[0] = rs1();
    dst_regs.resize(1); dst_regs[0] = rd();
    imm = shamt();
}

void srai_insn::execute(processor& p) {
    printf("src size: %ld reg list: %d\n\tdstsize: %ld dst list: %d\n", 
        src_regs.size(), src_regs[0], dst_regs.size(), dst_regs[0]);
    arch_state* state = p.get_state();
    state->gprs.write(
        dst_regs[0], (int32_t)state->gprs.read(src_regs[0]) >> imm
    );
    state->npc = state->pc + 4;
    printf("result dst val: %#x\n", state->gprs.read(dst_regs[0]));
}

std::string srai_insn::disassembly() {
    return insn_name + " x" + to_string(dst_regs[0]) 
            + ", x" + to_string(src_regs[0]) 
            + ", " + to_string(imm); 
}

jalr_insn::jalr_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : imm_inst(pc, insn_bits, name, 0) {
    src_regs.resize(1); src_regs[0] = rs1();
    dst_regs.resize(1); dst_regs[0] = rd();
    imm = i_imm();
}

void jalr_insn::execute(processor& p) {
    printf("src size: %ld reg list: %d\n\tdstsize: %ld dst list: %d\n", 
        src_regs.size(), src_regs[0], dst_regs.size(), dst_regs[0]);
    arch_state* state = p.get_state();
    state->gprs.write(
        dst_regs[0], state->pc + 4
    );
    state->npc = state->gprs.read(src_regs[0]) + imm;
    printf("result dst val: %#x\n", state->gprs.read(dst_regs[0]));
}

std::string jalr_insn::disassembly() {
    return insn_name + " x" + to_string(dst_regs[0]) 
            + ", x" + to_string(src_regs[0]) 
            + ", " + to_string(imm); 
}

sb_insn::sb_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : store_inst(pc, insn_bits, name) {
}

void sb_insn::execute(processor& p) {
    arch_state* state = p.get_state();
    
    uint32_t addr = state->gprs.read(src_regs[0]) + imm;
    p.get_ram()->write(addr, 1, state->gprs.read(src_regs[1]));
    state->npc = state->pc + 4;
}

sh_insn::sh_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : store_inst(pc, insn_bits, name) {
}

void sh_insn::execute(processor& p) {
    arch_state* state = p.get_state();
    
    uint32_t addr = state->gprs.read(src_regs[0]) + imm;
    p.get_ram()->write(addr, 2, state->gprs.read(src_regs[1]));
    state->npc = state->pc + 4;
}

sw_insn::sw_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : store_inst(pc, insn_bits, name) {
}

void sw_insn::execute(processor& p) {
    arch_state* state = p.get_state();
    
    uint32_t addr = state->gprs.read(src_regs[0]) + imm;
    p.get_ram()->write(addr, 4, state->gprs.read(src_regs[1]));
    state->npc = state->pc + 4;
}

lui_insn::lui_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : imm_inst(pc, insn_bits, name, 0) {
    dst_regs.resize(1); dst_regs[0] = rd();
    imm = u_imm();
}

void lui_insn::execute(processor& p) {
    arch_state* state = p.get_state();
    state->gprs.write(
        dst_regs[0], imm
    );
    state->npc = state->pc + 4;
    printf("result dst val: %#x\n", state->gprs.read(dst_regs[0]));
}

std::string lui_insn::disassembly() {
    return insn_name + " x" + to_string(dst_regs[0]) 
            + ", " + to_string(imm); 
}

auipc_insn::auipc_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : imm_inst(pc, insn_bits, name, 0) {
    dst_regs.resize(1); dst_regs[0] = rd();
    imm = u_imm();
}

void auipc_insn::execute(processor& p) {
    arch_state* state = p.get_state();
    state->gprs.write(
        dst_regs[0], state->pc + imm
    );
    state->npc = state->pc + 4;
    printf("result dst val: %#x\n", state->gprs.read(dst_regs[0]));
}

std::string auipc_insn::disassembly() {
    return insn_name + " x" + to_string(dst_regs[0]) 
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

bne_insn::bne_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : imm_inst(pc, insn_bits, name, 0) {
    src_regs.resize(2); src_regs[0] = rs1(); src_regs[1] = rs2();
    imm = sb_imm();
}

void bne_insn::execute(processor& p) {
    arch_state* state = p.get_state();
    
    if(state->gprs.read(src_regs[0]) != state->gprs.read(src_regs[1])) {
        state->npc = state->pc + imm;
        printf("bne jump\n");
    } else {
        state->npc = state->pc + 4;
        printf("bne not jump\n");
    }
}

std::string bne_insn::disassembly() {
    return insn_name + " x" + to_string(src_regs[0]) 
            + ", x" + to_string(src_regs[1]) + ", " + to_string(imm); 
}

blt_insn::blt_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : imm_inst(pc, insn_bits, name, 0) {
    src_regs.resize(2); src_regs[0] = rs1(); src_regs[1] = rs2();
    imm = sb_imm();
}

void blt_insn::execute(processor& p) {
    arch_state* state = p.get_state();
    
    if(int32_t(state->gprs.read(src_regs[0])) < int32_t(state->gprs.read(src_regs[1]))) {
        state->npc = state->pc + imm;
        printf("blt jump\n");
    } else {
        state->npc = state->pc + 4;
        printf("blt not jump\n");
    }
}

std::string blt_insn::disassembly() {
    return insn_name + " x" + to_string(src_regs[0]) 
            + ", x" + to_string(src_regs[1]) + ", " + to_string(imm); 
}

bge_insn::bge_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : imm_inst(pc, insn_bits, name, 0) {
    src_regs.resize(2); src_regs[0] = rs1(); src_regs[1] = rs2();
    imm = sb_imm();
}

void bge_insn::execute(processor& p) {
    arch_state* state = p.get_state();
    
    if(int32_t(state->gprs.read(src_regs[0])) >= int32_t(state->gprs.read(src_regs[1]))) {
        state->npc = state->pc + imm;
        printf("bge jump\n");
    } else {
        state->npc = state->pc + 4;
        printf("bge not jump\n");
    }
}

std::string bge_insn::disassembly() {
    return insn_name + " x" + to_string(src_regs[0]) 
            + ", x" + to_string(src_regs[1]) + ", " + to_string(imm); 
}

bltu_insn::bltu_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : imm_inst(pc, insn_bits, name, 0) {
    src_regs.resize(2); src_regs[0] = rs1(); src_regs[1] = rs2();
    imm = sb_imm();
}

void bltu_insn::execute(processor& p) {
    arch_state* state = p.get_state();
    
    if(uint32_t(state->gprs.read(src_regs[0])) >= uint32_t(state->gprs.read(src_regs[1]))) {
        state->npc = state->pc + imm;
        printf("bltu jump\n");
    } else {
        state->npc = state->pc + 4;
        printf("bltu not jump\n");
    }
}

std::string bltu_insn::disassembly() {
    return insn_name + " x" + to_string(src_regs[0]) 
            + ", x" + to_string(src_regs[1]) + ", " + to_string(imm); 
}

bgeu_insn::bgeu_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : imm_inst(pc, insn_bits, name, 0) {
    src_regs.resize(2); src_regs[0] = rs1(); src_regs[1] = rs2();
    imm = sb_imm();
}

void bgeu_insn::execute(processor& p) {
    arch_state* state = p.get_state();
    
    if(uint32_t(state->gprs.read(src_regs[0])) >= uint32_t(state->gprs.read(src_regs[1]))) {
        state->npc = state->pc + imm;
        printf("bgeu jump\n");
    } else {
        state->npc = state->pc + 4;
        printf("bgeu not jump\n");
    }
}

std::string bgeu_insn::disassembly() {
    return insn_name + " x" + to_string(src_regs[0]) 
            + ", x" + to_string(src_regs[1]) + ", " + to_string(imm); 
}

jal_insn::jal_insn(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : imm_inst(pc, insn_bits, name, 0) {
    dst_regs.resize(1); dst_regs[0] = rd();
    imm = uj_imm();
}

void jal_insn::execute(processor& p) {
    arch_state* state = p.get_state();
    state->gprs.write(
        dst_regs[0], state->pc + 4
    );
    state->npc = state->pc + imm;
    printf("result dst val: %#x\n", state->gprs.read(dst_regs[0]));
}

std::string jal_insn::disassembly() {
    return insn_name + " x" + to_string(dst_regs[0]) 
            + ", " + to_string(imm);  
}