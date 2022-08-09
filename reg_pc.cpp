#include "reg_pc.h"

void REG_PC::access_reg() {
    pc_out.write(0);
    reg_val = 0;
    wait();

    while(true) {
        // if(enable.read()) {
            // reg_val = pc_in.read();
            reg_val += 4;
        // }
        pc_out.write(reg_val);
        std::cout << "time @ " << sc_time_stamp() << " pc: " << pc_out.read() << std::endl;
        wait();
    }
}