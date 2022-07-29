#ifndef ROM_H
#define ROM_H

#include <iostream>
#include <vector>
#include <systemc>

using namespace sc_core;

class ROM: public sc_module {
public:
    sc_in<unsigned> rd_addr;
    sc_out<unsigned> rd_data;
    sc_in_clk clk;

public:
    ROM(sc_module_name name, const std::string& file_name);
    ~ROM();
    SC_HAS_PROCESS(ROM);

    void read();

private:
    std::string rom_file_name;
    std::vector<uint32_t> mem;
};

#endif