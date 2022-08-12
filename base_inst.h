#ifndef BASE_INST_H
#define BASE_INST_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>

class processor;

class base_inst {
public:
    base_inst(uint32_t pc, uint32_t insn_bits, const std::string& name);

public:
    virtual void execute(processor& p);

protected:
    /******reg related*******/

    int num_src_regs;
    int num_dst_reg;
    std::vector<uint32_t> src_regs;
    std::vector<uint32_t> dst_regs; 

    uint32_t x(int lo, int len) { return (insn_bits >> lo) & ((uint32_t(1) << len) - 1); }
    uint32_t xs(int lo, int len) { return int32_t(insn_bits) << (32 - lo - len) >> (32 - len); }
    uint32_t imm_sign() { return xs(31, 1); }
    /****** insn related*****/
    uint32_t insn_pc;
    uint32_t insn_bits;
    std::string insn_name;

public: 
    uint32_t rs1() { return x(15, 5); }
    uint32_t rs2() { return x(20, 5); }
    uint32_t rd()  { return x( 7, 5); }
    
    int32_t i_imm()  { return int32_t(insn_bits) >> 20; }
    int32_t sb_imm() { return (x(8, 4) << 1) + (x(25, 6) << 5) + (x(7, 1) << 11) + (imm_sign() << 12); }
    
    uint32_t get_insn_bits() const { return insn_bits; }
    const std::string get_insn_name() const { return insn_name; }

    virtual std::string disassembly() { return std::string("test"); }
};

typedef std::shared_ptr<base_inst> base_inst_ptr;
#endif