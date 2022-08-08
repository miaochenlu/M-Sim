#ifndef TB_REG_FILE_TB_H
#define TB_REG_FILE_TB_H

#include <systemc.h>
#include <cstdlib>

class REG_FILE_TB: public sc_module {
public:
    sc_in_clk           clk;
    sc_out<bool>        rst;
    sc_out<bool>        wr_en;
    sc_out<sc_uint<5>>  raddr_A;
    sc_out<sc_uint<5>>  raddr_B;
    sc_out<sc_uint<5>>  waddr;
    sc_in<signed>       rval_A;
    sc_in<signed>       rval_B;
    sc_out<signed>      wdata;
    
public:
    void source();
    void sink();

    SC_CTOR(REG_FILE_TB) {
        SC_CTHREAD(source, clk.pos());
        SC_CTHREAD(sink, clk.pos());
    }

};

#endif