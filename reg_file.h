#ifndef REG_FILE_H
#define REG_FILE_H

#include <systemc.h>
#include <cstdlib>

class REG_FILE: public sc_module {
public:
    sc_in_clk           clk;
    sc_in<bool>         rst;
    sc_in<bool>         wr_en;
    sc_in<sc_uint<5>>   raddr_A;
    sc_in<sc_uint<5>>   raddr_B;
    sc_out<signed>      rval_A;
    sc_out<signed>      rval_B;
    sc_in<sc_uint<5>>   waddr;
    sc_in<signed>       wdata;
    
public:
    void read();
    void write();

    SC_CTOR(REG_FILE) {
        for(int i = 0; i < 32; i++) {
            reg[i] = 0;
        }

        SC_METHOD(read);
        sensitive << raddr_A << raddr_B;

        SC_CTHREAD(write, clk.neg());
        reset_signal_is(rst, true);
    }

private:
    int32_t reg[32];

};

#endif