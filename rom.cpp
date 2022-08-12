#include "rom.h"
#include <fstream>
#include <sstream>

using namespace std;

rom::rom(const string& file_name): rom_file_name(file_name) {
    init_memory(rom_file_name);
}

void rom::init_memory(const std::string& file_name) {
    
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
}

uint32_t rom::read(uint32_t pc) {
    if((pc >> 2) >= mem.size()) {
        std::cout << "ERROR: addr out of range" << std::endl;
        return 0;
    } else {
        return mem[pc >> 2];
    }
}

rom::~rom() {

}