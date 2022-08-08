#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <systemc.h>
#include <string>

class INSTRUCTION {
public:
    INSTRUCTION(uint32_t pc, uint32_t insn_bits);
    ~INSTRUCTION();
public:
    void decode();
    void execute();
    void writeback();

    // uint32_t rs1() { return insn_bits.range(19, 14); }
    // uint32_t rs2() { return insn_bits.range(24, 20); }
    // uint32_t rd() { return insn_bits.range(11, 7); }
    uint32_t get_insn_bits() const { return insn_bits; }
    const std::string get_insn_name() const { return insn_name; }

private:
    uint32_t insn_pc;
    uint32_t insn_bits;
    std::string insn_name;
};

#endif