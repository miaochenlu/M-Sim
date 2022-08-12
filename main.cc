#include "decoder.h"
#include "base_inst.h"
#include "riscv_inst.h"
#include "rom.h"
#include <iostream>

using namespace std;

int main() {
    // decoder& m_decoder = decoder::get_instance();
    // base_inst* inst = m_decoder.build_inst(0, 0xfff08093);
    // inst->execute();
    // cout << inst->disassembly() << endl;
    // delete inst;
    // inst = m_decoder.build_inst(0, 0x004100b3);
    // inst->execute();
    // cout << inst->disassembly() << endl;
    // delete inst;

    rom M_rom("rom.hex");
    printf("%#010x\n", M_rom.read(4));
}