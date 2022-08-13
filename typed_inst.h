#ifndef TYPED_INST_H
#define TYPED_INST_H

#include "base_inst.h"
#include <string>

class rtype_inst: public base_inst {
public:
    rtype_inst(uint32_t pc, uint32_t insn_bits, const std::string& name);
    std::string disassembly();
};

template<typename imm_type>
class imm_inst: public base_inst {
public:
    imm_inst(uint32_t pc, uint32_t insn_bits, const std::string& name, imm_type imm = 0)
        : base_inst(pc, insn_bits, name), imm(imm) {
    }
    
protected:
    imm_type imm;
};

class mem_inst: public base_inst {
public:
    mem_inst(uint32_t pc, uint32_t insn_bits, const std::string& name, uint32_t imm = 0);
protected:
    uint32_t imm;
};

class load_inst: public mem_inst {
public:
    load_inst(uint32_t pc, uint32_t insn_bits, const std::string& name);
    std::string disassembly();
};

class store_inst: public mem_inst {
public:
    store_inst(uint32_t pc, uint32_t insn_bits, const std::string& name);
    std::string disassembly();
};

#endif