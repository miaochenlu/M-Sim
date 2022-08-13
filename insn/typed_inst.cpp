#include "typed_inst.h"
using namespace std;

rtype_inst::rtype_inst(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : base_inst(pc, insn_bits, name) {
    src_regs.resize(2); src_regs[0] = rs1(); src_regs[1] = rs2();
    dst_regs.resize(1); dst_regs[0] = rd();
}

string rtype_inst::disassembly() {
    return insn_name + " x" + to_string(dst_regs[0]) + ", x" + to_string(src_regs[0]) + ", x" + to_string(src_regs[1]); 
}

mem_inst::mem_inst(uint32_t pc, uint32_t insn_bits, const std::string& name, uint32_t imm)
    : base_inst(pc, insn_bits, name), imm(imm)  {

}

load_inst::load_inst(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : mem_inst(pc, insn_bits, name, 0){
    src_regs.resize(1); src_regs[0] = rs1();
    dst_regs.resize(1); dst_regs[0] = rd();
    imm = i_imm();
}

string load_inst::disassembly() {
    return insn_name + " x" + to_string(dst_regs[0]) + ", " + to_string(imm) + "(x" + to_string(src_regs[0]) + ")";
}

store_inst::store_inst(uint32_t pc, uint32_t insn_bits, const std::string& name)
    : mem_inst(pc, insn_bits, name, 0){
    src_regs.resize(2); src_regs[0] = rs1(); src_regs[1] = rs2();
    imm = s_imm();
}

string store_inst::disassembly() {
    return insn_name + " x" + to_string(src_regs[1]) + ", " + to_string(imm) + "(x" + to_string(src_regs[0]) + ")";
}