#include "decoder.h"
#include "riscv_inst.h"
#include "insn_encoding.h"

decoder::decoder() {
}

decoder& decoder::get_instance() {
    static decoder insn_decoder;
    return insn_decoder;
}

base_inst* decoder::build_inst(uint32_t pc, uint32_t insn_bits) {
    if((insn_bits & MASK_ADD) == MATCH_ADD) {
        return new add_insn(pc, insn_bits, "add");
    } else if((insn_bits & MASK_SUB) == MATCH_SUB) {
        return new sub_insn(pc, insn_bits, "sub");
    } else if((insn_bits & MASK_SLL) == MATCH_SLL) {
        return new sll_insn(pc, insn_bits, "sll");
    } else if((insn_bits & MASK_SLT) == MATCH_SLT) {
        return new slt_insn(pc, insn_bits, "slt");
    } else if((insn_bits & MASK_SLTU) == MATCH_SLTU) {
        return new sltu_insn(pc, insn_bits, "sltu");
    } else if((insn_bits & MASK_XOR) == MATCH_XOR) {
        return new xor_insn(pc, insn_bits, "xor");
    } else if((insn_bits & MASK_SRL) == MATCH_SRL) {
        return new srl_insn(pc, insn_bits, "srl");
    } else if((insn_bits & MASK_SRA) == MATCH_SRA) {
        return new sra_insn(pc, insn_bits, "sra");
    } else if((insn_bits & MASK_OR) == MATCH_OR) {
        return new or_insn(pc, insn_bits, "or");
    } else if((insn_bits & MASK_AND) == MATCH_AND) {
        return new and_insn(pc, insn_bits, "and");
    } else if((insn_bits & MASK_LB) == MATCH_LB) {
        return new lb_insn(pc, insn_bits, "lb");
    } else if((insn_bits & MASK_LH) == MATCH_LH) {
        return new lh_insn(pc, insn_bits, "lh");
    } else if((insn_bits & MASK_LBU) == MATCH_LBU) {
        return new lbu_insn(pc, insn_bits, "lbu");
    } else if((insn_bits & MASK_LHU) == MATCH_LHU) {
        return new lhu_insn(pc, insn_bits, "lhu");
    } else if((insn_bits & MASK_LW) == MATCH_LW) {
        return new lw_insn(pc, insn_bits, "lw");
    } else if((insn_bits & MASK_ADDI) == MATCH_ADDI) {
        return new addi_insn(pc, insn_bits, "addi");
    } else if((insn_bits & MASK_SLTI) == MATCH_SLTI) {
        return new slti_insn(pc, insn_bits, "slti");
    } else if((insn_bits & MASK_SLTIU) == MATCH_SLTIU) {
        return new sltiu_insn(pc, insn_bits, "sltiu");
    } else if((insn_bits & MASK_XORI) == MATCH_XORI) {
        return new xori_insn(pc, insn_bits, "xori");
    } else if((insn_bits & MASK_ORI) == MATCH_ORI) {
        return new ori_insn(pc, insn_bits, "ori");
    } else if((insn_bits & MASK_ANDI) == MATCH_ANDI) {
        return new andi_insn(pc, insn_bits, "andi");
    } else if((insn_bits & MASK_SLLI) == MATCH_SLLI) {
        return new slli_insn(pc, insn_bits, "slli");
    } else if((insn_bits & MASK_SRLI) == MATCH_SRLI) {
        return new srli_insn(pc, insn_bits, "srli");
    } else if((insn_bits & MASK_SRAI) == MATCH_SRAI) {
        return new srai_insn(pc, insn_bits, "srai");
    } else if((insn_bits & MASK_JALR) == MATCH_JALR) {
        return new jalr_insn(pc, insn_bits, "jalr");
    } else if((insn_bits & MASK_LUI) == MATCH_LUI) {
        return new lui_insn(pc, insn_bits, "lui");
    } else if((insn_bits & MASK_AUIPC) == MATCH_AUIPC) {
        return new auipc_insn(pc, insn_bits, "auipc");
    } else if((insn_bits & MASK_SB) == MATCH_SB) {
        return new sb_insn(pc, insn_bits, "sb");
    } else if((insn_bits & MASK_SH) == MATCH_SH) {
        return new sh_insn(pc, insn_bits, "sh");
    } else if((insn_bits & MASK_SW) == MATCH_SW) {
        return new sw_insn(pc, insn_bits, "sw");
    } else if((insn_bits & MASK_BEQ) == MATCH_BEQ) {
        return new beq_insn(pc, insn_bits, "beq");
    } else if((insn_bits & MASK_BNE) == MATCH_BNE) {
        return new bne_insn(pc, insn_bits, "bne");
    } else if((insn_bits & MASK_BLT) == MATCH_BLT) {
        return new blt_insn(pc, insn_bits, "blt");
    } else if((insn_bits & MASK_BGE) == MATCH_BGE) {
        return new bge_insn(pc, insn_bits, "bge");
    } else if((insn_bits & MASK_BLT) == MATCH_BLT) {
        return new blt_insn(pc, insn_bits, "blt");
    } else if((insn_bits & MASK_BGEU) == MATCH_BGEU) {
        return new bgeu_insn(pc, insn_bits, "bgeu");
    } else if((insn_bits & MASK_BLTU) == MATCH_BLTU) {
        return new bltu_insn(pc, insn_bits, "bltu");
    } else if((insn_bits & MASK_JAL) == MATCH_JAL) {
        return new jal_insn(pc, insn_bits, "jal");
    }
    return NULL;
}

decoder::~decoder() {
    
}