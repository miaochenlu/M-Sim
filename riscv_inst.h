#ifndef RISCV_INST_H
#define RISCV_INST_H

#include "typed_inst.h"

class add: public rtype_inst {

public:
    add(uint32_t pc, uint32_t insn_bits, const std::string& name);

    void execute();

};

#endif