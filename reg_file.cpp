#include "reg_file.h"

void REG_FILE::read() {
    if(raddr_A.read() == 0) rval_A.write(0);
    else rval_A.write(reg[raddr_A.read()]);

    if(raddr_B.read() == 0) rval_B.write(0);
    else rval_B.write(reg[raddr_B.read()]);
}

void REG_FILE::write() {
    // Reset code
    for(int i = 0; i < 32; i++) {
        reg[i] = 0;
    }
    wait();

    while(true) {
        if(waddr.read() != 0)
            reg[waddr.read()] = wdata.read();
        wait();
    }
}