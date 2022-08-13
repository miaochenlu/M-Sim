#ifndef RISCV_INST_H
#define RISCV_INST_H

#include "typed_inst.h"

class processor;

class add_insn: public rtype_inst {
public:
    add_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);

    // std::string disassembly();
};

class sub_insn: public rtype_inst {
public:
    sub_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);

    // std::string disassembly();
};

class sll_insn: public rtype_inst {
public:
    sll_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);

    // std::string disassembly();
};

class slt_insn: public rtype_inst {
public:
    slt_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);

    // std::string disassembly();
};

class sltu_insn: public rtype_inst {
public:
    sltu_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);

    // std::string disassembly();
};

class xor_insn: public rtype_inst {
public:
    xor_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);

    // std::string disassembly();
};

class srl_insn: public rtype_inst {
public:
    srl_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);

    // std::string disassembly();
};

class sra_insn: public rtype_inst {
public:
    sra_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);

    // std::string disassembly();
};

class or_insn: public rtype_inst {
public:
    or_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);

    // std::string disassembly();
};

class and_insn: public rtype_inst {
public:
    and_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);

    // std::string disassembly();
};




class addi_insn: public imm_inst<int32_t> {

public:
    addi_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);

    std::string disassembly();
};


class beq_insn: public imm_inst<int32_t> {

public:
    beq_insn(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute(processor& p);

    std::string disassembly();
};

#endif