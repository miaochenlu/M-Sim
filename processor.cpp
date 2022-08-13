#include "processor.h"
#include <iostream>
using namespace std;

processor::processor()
    : m_rom("rom.hex"), m_decoder(decoder::get_instance()), 
     m_arch_state() {
}

processor::~processor() {

}

arch_state* processor::get_state() {
    return &m_arch_state;
}

void processor::run() {
    for(int i = 0; i < 10; i++) {
        base_inst* inst = m_decoder.build_inst(m_arch_state.pc, m_rom.read(m_arch_state.pc));
        printf("\n%#010x: ", m_arch_state.pc);
        cout << inst->disassembly() << endl;
        inst->execute(*this);
        delete inst;
        m_arch_state.pc = m_arch_state.npc;
    }
}