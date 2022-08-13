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
        return new add_insn(pc, insn_bits, "add");
    } else if((insn_bits & MASK_SUB) == MATCH_SUB) {
        printf("sub instruction\n");
        return new sub_insn(pc, insn_bits, "sub");
    } else if((insn_bits & MASK_SLL) == MATCH_SLL) {
        printf("sll instruction\n");
        return new sll_insn(pc, insn_bits, "sll");
    } else if((insn_bits & MASK_SLT) == MATCH_SLT) {
        printf("slt instruction\n");
        return new slt_insn(pc, insn_bits, "slt");
    } else if((insn_bits & MASK_SLTU) == MATCH_SLTU) {
        printf("sltu instruction\n");
        return new sltu_insn(pc, insn_bits, "sltu");
    } else if((insn_bits & MASK_XOR) == MATCH_XOR) {
        printf("xor instruction\n");
        return new xor_insn(pc, insn_bits, "xor");
    } else if((insn_bits & MASK_SRL) == MATCH_SRL) {
        printf("srl instruction\n");
        return new srl_insn(pc, insn_bits, "srl");
    } else if((insn_bits & MASK_SRA) == MATCH_SRA) {
        printf("sra instruction\n");
        return new sra_insn(pc, insn_bits, "sra");
    } else if((insn_bits & MASK_OR) == MATCH_OR) {
        printf("or instruction\n");
        return new or_insn(pc, insn_bits, "or");
    } else if((insn_bits & MASK_AND) == MATCH_AND) {
        printf("and instruction\n");
        return new and_insn(pc, insn_bits, "and");
    } else if((insn_bits & MASK_ADDI) == MATCH_ADDI) {
        printf("addi instruction\n");
        return new addi(pc, insn_bits, "addi");
    } else if((insn_bits & MASK_BEQ) == MATCH_BEQ) {
        printf("beq instruction\n");
        return new beq(pc, insn_bits, "beq");
    } 
    return NULL;
}

decoder::~decoder() {
    
}