#include <fstream>
#include <sstream>
#include "rom.h"

using namespace std;

ROM::ROM(sc_module_name name, const string& file_name):
    rom_file_name(file_name) {
    ifstream read_file(rom_file_name, ios::in | ios::binary);

    if(!read_file) {
        cout << "ERROR: file " << rom_file_name << " doesn't exist" << endl;
        return;
    }
    
    int insn_cnt = 0;
    while(!read_file.eof()) {
        char insn[40];
        read_file.getline((char*)&insn, 40);
        uint32_t insn_bits;
        std::stringstream ss;
        ss << insn;
        ss >> std::hex >> insn_bits;
        mem.push_back(insn_bits);
        // printf("insn: %#010x\n", mem[insn_cnt]);
        insn_cnt++;
    }

    SC_METHOD(read);
    sensitive << rd_addr;
}

void ROM::read() {
    uint32_t addr = rd_addr.read();

    if(addr >= mem.size()) {
        std::cout << "ERROR: addr out of range" << std::endl;
    } else {
        rd_data.write(mem[addr]);
    }

}

ROM::~ROM() {

}