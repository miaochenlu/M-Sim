#ifndef DECODE_H
#define DECODE_H

#include <systemc.h>
#include "instruction.h"

class DECODE: public sc_module {
public:
    sc_in_clk clk;
    sc_fifo_in< INSTRUCTION* > insn_in;
    sc_fifo_out< INSTRUCTION* > insn_out;

public:
    SC_CTOR(DECODE) {
        SC_CTHREAD(decoding, clk.pos());
    }

private:
    void decoding();
};

#endif