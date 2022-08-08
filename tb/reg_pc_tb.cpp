#include "reg_pc_tb.h"
#include <iostream>

using namespace std;

void REG_PC_TB::source() {
    // Reset
    rst.write(1);
    enable.write(0);
    pc_in.write(0);
    wait();

    rst.write(0);
    enable.write(1);
    wait();

    pc_in.write(4);
    wait();

    pc_in.write(8);
    wait();

    pc_in.write(24);
    wait();

    pc_in.write(28);
    wait();

    enable.write(0);
    pc_in.write(12);
    wait();

    wait();
}

void REG_PC_TB::sink() {
    for(int i = 0; i < 10; i++) {
        wait();
        cout << "pc val: " << pc_out.read() << endl;
    }
    sc_stop();
}