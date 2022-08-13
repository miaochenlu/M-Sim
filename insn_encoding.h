#ifndef INSN_ENCODING_H
#define INSN_ENCODING_H

#ifndef RISCV_ENCODING
#define RISCV_ENCODING

/***************R type****************/
#define MATCH_ADD 0x33
#define MASK_ADD 0xfe00707f

#define MATCH_SUB 0x40000033
#define MASK_SUB 0xfe00707f

#define MATCH_SLL 0x1033
#define MASK_SLL 0xfe00707f

#define MATCH_SLT 0x2033
#define MASK_SLT 0xfe00707f

#define MATCH_SLTU 0x3033
#define MASK_SLTU 0xfe00707f

#define MATCH_XOR 0x4033
#define MASK_XOR 0xfe00707f

#define MATCH_SRL 0x5033
#define MASK_SRL 0xfe00707f

#define MATCH_SRA 0x40005033
#define MASK_SRA 0xfe00707f

#define MATCH_OR 0x6033
#define MASK_OR 0xfe00707f

#define MATCH_AND 0x7033
#define MASK_AND 0xfe00707f

/***************I type****************/
#define MATCH_LB 0x3
#define MASK_LB 0x707f

#define MATCH_LH 0x1003
#define MASK_LH 0x707f

#define MATCH_LBU 0x4003
#define MASK_LBU 0x707f

#define MATCH_LHU 0x5003
#define MASK_LHU 0x707f

#define MATCH_LW 0x2003
#define MASK_LW 0x707f

#define MATCH_ADDI 0x13
#define MASK_ADDI 0x707f

#define MATCH_SLTI 0x2013
#define MASK_SLTI 0x707f

#define MATCH_SLTIU 0x3013
#define MASK_SLTIU 0x707f

#define MATCH_XORI 0x4013
#define MASK_XORI 0x707f

#define MATCH_ORI 0x6013
#define MASK_ORI 0x707f

#define MATCH_ANDI 0x7013
#define MASK_ANDI 0x707f

#define MATCH_SLLI 0x1013
#define MASK_SLLI 0xfc00707f

#define MATCH_SRLI 0x5013
#define MASK_SRLI 0xfc00707f

#define MATCH_SRAI 0x40005013
#define MASK_SRAI 0xfc00707f

#define MATCH_JALR 0x67
#define MASK_JALR 0x707f

/***************S type****************/
#define MATCH_SB 0x23
#define MASK_SB 0x707f

#define MATCH_SH 0x1023
#define MASK_SH 0x707f

#define MATCH_SW 0x2023
#define MASK_SW 0x707f

/***************U type****************/
#define MATCH_LUI 0x37
#define MASK_LUI 0x7f

#define MATCH_AUIPC 0x17
#define MASK_AUIPC 0x7f

/***************B type****************/
#define MATCH_BEQ 0x63
#define MASK_BEQ 0x707f

#define MATCH_BNE 0x1063
#define MASK_BNE 0x707f

#define MATCH_BLT 0x4063
#define MASK_BLT 0x707f

#define MATCH_BLTU 0x6063
#define MASK_BLTU 0x707f

#define MATCH_BGE 0x5063
#define MASK_BGE 0x707f

#define MATCH_BGEU 0x7063
#define MASK_BGEU 0x707f

/***************UJ type****************/
#define MATCH_JAL 0x6f
#define MASK_JAL 0x7f

#endif

#endif