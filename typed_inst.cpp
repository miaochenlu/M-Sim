#include "typed_inst.h"
using namespace std;

rtype_inst::rtype_inst(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : base_inst(pc, insn_bits, name) {

}

string rtype_inst::disassembly() {
    return insn_name + " x" + to_string(dst_regs[0]) + ", x" + to_string(src_regs[0]) + ", x" + to_string(src_regs[1]); 
}
