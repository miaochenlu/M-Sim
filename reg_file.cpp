#include "reg_file.h"

reg_file& reg_file::get_instance() {
    static reg_file rf;
    return rf;
}

reg_file::reg_file() {
    for(int i = 0; i < 32; i++) {
        regs[i] = 0;
    }
}

reg_file::~reg_file() {

}

uint32_t reg_file::read(uint32_t index) const {
    if(index == 0) return 0;
    return regs[index];
}

void reg_file::write(uint32_t index, uint32_t val) {
    if(index != 0) {
        regs[index] = val;
    }
}