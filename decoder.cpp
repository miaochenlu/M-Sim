#include "decoder.h"
#include "riscv_inst.h"

decoder::decoder() {
    #define DECLARE_INSN(name, match_val, mask_val) \
        insn_info_list.push_back(new insn_decode_info(#name, match_val, mask_val));

    #include "insn_encoding.h"
    #undef DECLARE_INSN
}

decoder& decoder::get_instance() {
    static decoder insn_decoder;
    return insn_decoder;
}

base_inst* decoder::build_inst(uint32_t pc, uint32_t insn_bits) {
    printf("build inst\n");
    if((insn_bits & MASK_ADD) == MATCH_ADD) {
        printf("add instruction\n");
        return new add(pc, insn_bits, "add");
    } else if((insn_bits & MASK_ADDI) == MATCH_ADDI) {
        printf("addi instruction\n");
        return new addi(pc, insn_bits, "addi");
    }
    return NULL;
}

decoder::~decoder() {
    
}