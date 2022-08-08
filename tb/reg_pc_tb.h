#ifndef TB_REG_PC_TB_H
#define TB_REG_PC_TB_H

#include <systemc.h>
#include <cstdlib>

class REG_PC_TB: public sc_module {
public:
    sc_in_clk                 clk;
    sc_out< bool >            rst;
    sc_out< bool >            enable;
    sc_out< sc_uint<32> >     pc_in;
    sc_in < sc_uint<32> >     pc_out;
    
public:
    void source();
    void sink();

    SC_CTOR(REG_PC_TB) {
        SC_CTHREAD(source, clk.pos());
        SC_CTHREAD(sink, clk.pos());
    }

};

#endif