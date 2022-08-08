#include "decode.h"

void DECODE::decoding() {
    insn_out.write(NULL);
    // wait();
    while(true) {
        INSTRUCTION* insn = insn_in.read();
        if(insn != NULL) {
            insn->decode();
            std::cout << insn->get_insn_name() << std::endl;
        }
        insn_out.write(insn);
        // wait();
    }
}