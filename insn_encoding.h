#ifndef INSN_ENCODING_H
#define INSN_ENCODING_H

#ifndef RISCV_ENCODING
#define RISCV_ENCODING

#define MATCH_ADD 0x33
#define MASK_ADD 0xfe00707f
#define MATCH_ADDI 0x13
#define MASK_ADDI 0x707f
#endif

#ifdef DECLARE_INSN
DECLARE_INSN(add, MATCH_ADD, MASK_ADD)
DECLARE_INSN(addi, MATCH_ADDI, MASK_ADDI)
#endif

#endif