#ifndef RISCV_INST_H
#define RISCV_INST_H

#include "typed_inst.h"

class processor;

class add_insn: public rtype_inst {
public:
    add_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);
};

class sub_insn: public rtype_inst {
public:
    sub_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);
};

class sll_insn: public rtype_inst {
public:
    sll_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);
};

class slt_insn: public rtype_inst {
public:
    slt_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);
};

class sltu_insn: public rtype_inst {
public:
    sltu_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);

};

class xor_insn: public rtype_inst {
public:
    xor_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);
};

class srl_insn: public rtype_inst {
public:
    srl_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);
};

class sra_insn: public rtype_inst {
public:
    sra_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);
};

class or_insn: public rtype_inst {
public:
    or_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);
};

class and_insn: public rtype_inst {
public:
    and_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);
};

class lb_insn: public load_inst {
public:
    lb_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);
};

class lh_insn: public load_inst {
public:
    lh_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);
};

class lbu_insn: public load_inst {
public:
    lbu_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);
};

class lhu_insn: public load_inst {
public:
    lhu_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);
};

class lw_insn: public load_inst {
public:
    lw_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);
};

class addi_insn: public imm_inst<int32_t> {
public:
    addi_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);

    std::string disassembly();
};

class slti_insn: public imm_inst<int32_t> {
public:
    slti_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);

    std::string disassembly();
};

class sltiu_insn: public imm_inst<int32_t> {
public:
    sltiu_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);

    std::string disassembly();
};

class xori_insn: public imm_inst<int32_t> {
public:
    xori_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);

    std::string disassembly();
};

class ori_insn: public imm_inst<int32_t> {
public:
    ori_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);

    std::string disassembly();
};

class andi_insn: public imm_inst<int32_t> {
public:
    andi_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);

    std::string disassembly();
};

class slli_insn: public imm_inst<int32_t> {
public:
    slli_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);

    std::string disassembly();
};

class srli_insn: public imm_inst<int32_t> {
public:
    srli_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);

    std::string disassembly();
};

class srai_insn: public imm_inst<int32_t> {
public:
    srai_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);

    std::string disassembly();
};

class jalr_insn: public imm_inst<int32_t> {
public:
    jalr_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);

    std::string disassembly();
};

class lui_insn: public imm_inst<int32_t> {
public:
    lui_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);

    std::string disassembly();
};

class auipc_insn: public imm_inst<int32_t> {
public:
    auipc_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);

    std::string disassembly();
};

class sb_insn: public store_inst {
public:
    sb_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);
};

class sh_insn: public store_inst {
public:
    sh_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);
};

class sw_insn: public store_inst {
public:
    sw_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);
};

class beq_insn: public imm_inst<int32_t> {
public:
    beq_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);

    std::string disassembly();
};

class bne_insn: public imm_inst<int32_t> {
public:
    bne_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);

    std::string disassembly();
};

class blt_insn: public imm_inst<int32_t> {
public:
    blt_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);

    std::string disassembly();
};

class bge_insn: public imm_inst<int32_t> {
public:
    bge_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);

    std::string disassembly();
};

class bltu_insn: public imm_inst<int32_t> {
public:
    bltu_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);

    std::string disassembly();
};

class bgeu_insn: public imm_inst<int32_t> {
public:
    bgeu_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);

    std::string disassembly();
};

class jal_insn: public imm_inst<int32_t> {
public:
    jal_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);

    std::string disassembly();
};

#endif