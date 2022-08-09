#include <fstream>
#include <sstream>
#include "rom.h"

using namespace std;

ROM::ROM(sc_module_name name, const string& file_name):
    rom_file_name(file_name) {

    init_memory(rom_file_name);

    // SC_METHOD(read);
    // sensitive << rd_addr;
    SC_CTHREAD(read, clk.pos());
}

void ROM::init_memory(const std::string& file_name) {
    
    ifstream read_file(rom_file_name, ios::in | ios::binary);

    if(!read_file) {
        cout << "ERROR: file "   << rom_file_name 
             << " doesn't exist" << endl;
        return;
    }
    
    mem.clear();

    int insn_cnt = 0;
    string insn;
    uint32_t insn_hex = 0;
    while(!read_file.eof()) {
        getline(read_file, insn);
        if(sscanf(insn.c_str(), "%x", &insn_hex) == 1) {
            mem.push_back(insn_hex);
        }
        insn_cnt++;
    }

    // for(int i = 0; i < insn_cnt; i++) {
    //     printf("mem: %#x\n", mem[i]);
    // }
}

void ROM::read() {
    insn_out.write(NULL);
    wait();

    while(true) {
        uint32_t addr = rd_addr.read();
        INSTRUCTION* insn = NULL;
        if((addr >> 2) >= mem.size()) {
            std::cout << "ERROR: addr out of range" << std::endl;
        } else {
            insn = new INSTRUCTION(addr, mem[addr >> 2]);
        }
        insn_out.write(insn);
        cout << "==ROM time @ " << sc_time_stamp();
        printf("  pc: %#x rom read insn: %#x\n", addr, insn->get_insn_bits());
        wait();
    }

}

ROM::~ROM() {

}