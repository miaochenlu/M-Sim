#include "reg_tb.h"
#include <iostream>

using namespace std;

void REG_TB::source() {
    // Reset
    rst.write(1);
    wr_en.write(0);
    raddr_A.write(0);
    raddr_B.write(0);
    wait();

    rst.write(0);
    wait();

    wr_en.write(1);
    waddr.write(1);
    wdata.write(20);
    wait();

    wr_en.write(0);
    raddr_A.write(1);
    wait();

    wr_en.write(1);
    waddr.write(2);
    wdata.write(30);
    wait();

    wr_en.write(0);
    raddr_B.write(2);
    wait();

    wr_en.write(1);
    waddr.write(3);
    wdata.write(40);
    wait();
    
    wr_en.write(0);
    raddr_A.write(3);
    wait();
}

void REG_TB::sink() {
    for(int i = 0; i < 10; i++) {
        wait();
        cout << "A value: " << rval_A.read() << "\t B value: " << rval_B.read() << endl;
    }
    sc_stop();
}