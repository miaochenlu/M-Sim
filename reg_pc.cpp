#include "reg_pc.h"

void REG_PC::access_reg() {
    pc_out.write(0);
    wait();

    while(true) {
        if(enable.read()) {
            reg_val = pc_in.read();
        }
        pc_out.write(reg_val);
        wait();
    }
}