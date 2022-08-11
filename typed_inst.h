#ifndef TYPED_INST_H
#define TYPED_INST_H

#include "base_inst.h"
#include <string>

class rtype_inst: public base_inst {
public:
    rtype_inst(uint32_t pc, uint32_t insn_bits, const std::string& name);
};

template<typename imm_type>
class imm_inst: public base_inst {
protected:
    imm_type imm;
};


class mem_inst: public base_inst {

};

class load_inst: public mem_inst {

};

class store_inst: public mem_inst {

};

#endif