#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "reg_file.h"
#include "decoder.h"
#include "rom.h"
#include "decoder.h"

class processor {
public:
    processor();
    ~processor();
public:
    void run();
    arch_state* get_state();
private:
    arch_state m_arch_state;
    rom m_rom;
    decoder& m_decoder;
};

#endif