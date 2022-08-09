#ifndef REG_PC_H
#define REG_PC_H

#include <systemc.h>

class REG_PC: public sc_module {
public:
    sc_in_clk clk;
    sc_in < bool > rst;
    sc_in < bool > enable;
    sc_in < sc_uint<32> > pc_in;
    sc_out< sc_uint<32> > pc_out;

    SC_CTOR(REG_PC) {
        reg_val = 0;
        SC_CTHREAD(access_reg, clk.pos());
        reset_signal_is(rst, true);
    }
private:
    void access_reg();


private:
    uint32_t reg_val;
};

#endif