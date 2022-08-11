#include "decoder.h"
#include "base_inst.h"
#include "riscv_inst.h"


int main() {
    decoder& m_decoder = decoder::get_instance();
    base_inst* inst = m_decoder.build_inst(0, 0x004100b3);
    inst->execute();
    delete inst;
}