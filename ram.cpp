#include "ram.h"
#include <fstream>
#include <sstream>

using namespace std;

ram::ram(const string& file_name): ram_file_name(file_name) {
    init_memory(ram_file_name);
}

void ram::init_memory(const std::string& file_name) {
    
    ifstream read_file(ram_file_name, ios::in | ios::binary);

    if(!read_file) {
        cout << "ERROR: file "   << ram_file_name 
             << " doesn't exist" << endl;
        return;
    }
    
    mem.clear();
    string byte;
    int number;
    while(!read_file.eof()) {
        getline(read_file, byte);
        if(sscanf(byte.c_str(), "%x", &number) == 1) {
            mem.push_back(uint8_t(number));
        }
    }
}

uint32_t ram::read(uint32_t addr, uint32_t byte_num) const {
    if(addr + byte_num >= mem.size()) {
        std::cout << "ERROR: addr out of range" << std::endl;
        return 0;
    } else {
        uint32_t result = 0;
        while(byte_num >= 1)  {
            result = (result << 8) + mem[addr + (byte_num - 1)];
            byte_num--;
        }
        return result;
    }
}

void ram::write(uint32_t addr, uint32_t byte_num, uint32_t value) {
    if(addr + byte_num >= mem.size()) {
        std::cout << "ERROR: addr out of range" << std::endl;
    } else {
        uint32_t result = 0;
        for(int index = 0; index < byte_num; index++)  {
            mem[addr + index] = ((1 << 9) - 1) & value;
            value = (value >> 8);
        }
    }
}

ram::~ram() {

}