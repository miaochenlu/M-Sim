#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "reg_file.h"
#include "rom.h"
#include "ram.h"
#include "decoder.h"

class processor {
public:
    processor();
    ~processor();
public:
    void run();
    arch_state* get_state();
    ram* get_ram();
private:
    arch_state m_arch_state;
    rom m_rom;
    ram m_ram;
    decoder& m_decoder;
};

#endif