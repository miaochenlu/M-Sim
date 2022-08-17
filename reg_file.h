#ifndef REG_FILE_H
#define REG_FILE_H

#include <stdint.h>
#include <unordered_map>
#include "csr.h"

class gpr_regfile {
public:
    gpr_regfile(); 
    ~gpr_regfile();

public:
    uint32_t read(uint32_t index) const;

    void write(uint32_t index, uint32_t val);

private:
    uint32_t regs[32];
};

class arch_state {
public:
    uint32_t priv;
    uint32_t pc;
    uint32_t npc;
    gpr_regfile gprs;

    std::unordered_map<uint32_t, base_csr> csr_map;

public:
    arch_state();
    ~arch_state();
    void reset();
};
#endif