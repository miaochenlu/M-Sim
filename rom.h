#ifndef ROM_H
#define ROM_H

#include <iostream>
#include <vector>
#include <systemc.h>
#include "instruction.h"

class ROM: public sc_module {
public:
    sc_in< sc_uint<32> > rd_addr;
    sc_fifo_out< INSTRUCTION* > insn_out;
    sc_in_clk clk;

public:
    ROM(sc_module_name name, const std::string& file_name);

    ~ROM();

    SC_HAS_PROCESS(ROM);

public:
    void init_memory(const std::string& file_name);

    void read();

private:
    std::string rom_file_name;
    std::vector<uint32_t> mem;
};

#endif