#include "instruction.h"
#include "insn_decode.h"

using namespace std;

INSTRUCTION::INSTRUCTION(uint32_t pc, uint32_t insn_bits)
    : insn_pc(pc), insn_bits(insn_bits),
      insn_name("NULL") {
    
}

void INSTRUCTION::decode() {
    INSN_DECODE& insn_list = INSN_DECODE::get_instance();
    vector<insn_decode_info*> insn_info_list = insn_list.insn_info_list;
    for(int i = 0; i < insn_info_list.size(); i++) {
        if((insn_bits & (insn_info_list[i]->mask)) == insn_info_list[i]->match) {
            insn_name = insn_info_list[i]->name;
            break;
        }
    }
}