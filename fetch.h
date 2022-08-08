// #ifndef _FETCH_H
// #define _FETCH_H

// #include <systemc.h>
// #include "instruction.h"

// class FETCH: public sc_module {
// public:
//     sc_in< sc_uint<32> > pc_in;
//     sc_in< sc_uint<32> > inst;
//     sc_out<
//     sc_out< INSTRUCTION* > insn_out;
//     sc_in_clk clk;

// public:
//     FETCH::FETCH(sc_module_name name) {
//         SC_METHOD(fetch);
//         sensitive << clk.pos();
//     }
//     ~FETCH();

//     void fetch();
// };

// #endif