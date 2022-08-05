#include "reg.h"

void REG::read() {
    rval_A.write(reg[raddr_A.read()]);
    rval_B.write(reg[raddr_B.read()]);
}

void REG::write() {
    // Reset code
    wait();
    while(true) {
        if(waddr.read() != 0)
            reg[waddr.read()] = wdata.read();
        wait();
    }
}