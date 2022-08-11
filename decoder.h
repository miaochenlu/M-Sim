#ifndef DECODER_H
#define DECODER_H

#include <stdint.h>
#include <string>
#include <vector>
#include "base_inst.h"

struct insn_decode_info {
public:
    std::string name;
    uint32_t match;
    uint32_t mask;
    insn_decode_info(std::string name, uint32_t match, uint32_t mask): 
        name(name), match(match), mask(mask) {}
};

class decoder {
public:
    static decoder& get_instance();
    ~decoder();

    base_inst* build_inst(uint32_t pc, uint32_t insn_bits);
private:
    decoder();
    decoder(const decoder&) = delete;
    decoder& operator=(const decoder&) = delete;

public:
    std::vector<insn_decode_info*> insn_info_list;
};

#endif