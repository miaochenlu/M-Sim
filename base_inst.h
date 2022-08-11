#ifndef BASE_INST_H
#define BASE_INST_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>

class base_inst {
public:
    base_inst(uint32_t pc, uint32_t insn_bits, const std::string& name);

public:
    virtual void execute();

protected:
    /******reg related*******/

    int num_src_regs;
    int num_dst_reg;
    std::vector<uint32_t> src_regs;
    std::vector<uint32_t> dst_regs; 

    uint32_t x(int lo, int len) { return (insn_bits >> lo) & ((uint32_t(1) << len) - 1); }


    /****** insn related*****/
    uint32_t insn_pc;
    uint32_t insn_bits;
    std::string insn_name;

public: 
    uint32_t rs1() { return x(15, 5); }
    uint32_t rs2() { return x(20, 5); }
    uint32_t rd()  { return x( 7, 5); }
    
    int32_t i_imm() { return int32_t(insn_bits) >> 20; }
    
    uint32_t get_insn_bits() const { return insn_bits; }
    const std::string get_insn_name() const { return insn_name; }

    virtual std::string disassembly() { return std::string("test"); }
};

typedef std::shared_ptr<base_inst> base_inst_ptr;
#endif