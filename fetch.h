#ifndef _FETCH_H
#define _FETCH_H

#include <systemc.h>

class FETCH: public sc_module {
public:
    sc_out<unsigned> rd_addr;
    sc_in<unsigned> rd_data;
    sc_in_clk clk;

public:
    FETCH(sc_module_name name);
    ~FETCH();
    SC_HAS_PROCESS(FETCH);

    void fetch();
};

#endif