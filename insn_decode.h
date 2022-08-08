#ifndef INSN_DECODE_H
#define INSN_DECODE_H

#include <string>
#include <vector>

struct insn_decode_info {
public:
    std::string name;
    uint32_t match;
    uint32_t mask;
    insn_decode_info(std::string name, uint32_t match, uint32_t mask): 
        name(name), match(match), mask(mask) {}
};

class INSN_DECODE {
public:
    static INSN_DECODE& get_instance();
    ~INSN_DECODE();
private:
    INSN_DECODE();
    INSN_DECODE(const INSN_DECODE&) = delete;
    INSN_DECODE& operator=(const INSN_DECODE&) = delete;

public:
    std::vector<insn_decode_info*> insn_info_list;
};

#endif