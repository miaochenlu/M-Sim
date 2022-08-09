#ifndef EXECUTE_H
#define EXECUTE_H

#include <systemc.h>
#include "instruction.h"

class EXECUTE: public sc_module {
public:
    sc_in_clk clk;
    sc_fifo_in< INSTRUCTION* > insn_in;
    sc_fifo_out< INSTRUCTION* > insn_out;

public:
    SC_CTOR(EXECUTE) {
        SC_CTHREAD(executing, clk.pos());
    }

private:
    void executing();
};

#endif
