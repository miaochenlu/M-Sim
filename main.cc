#include "decoder.h"
#include "base_inst.h"
#include "riscv_inst.h"
#include "rom.h"
#include <iostream>

using namespace std;

int main() {
    rom M_rom("rom.hex");
    decoder& m_decoder = decoder::get_instance();
    uint32_t pc = 0;
    for(int i = 0; i < 10; i++) {
        base_inst* inst = m_decoder.build_inst(pc, M_rom.read(pc));
        inst->execute();
        cout << inst->disassembly() << endl;
        delete inst;
        pc += 4;
    }

}