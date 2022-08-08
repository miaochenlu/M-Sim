#include "insn_decode.h"
#include <iostream>

using namespace std;

INSN_DECODE& INSN_DECODE::get_instance() {
    static INSN_DECODE insn_decode;
    return insn_decode;
}

INSN_DECODE::INSN_DECODE() {
    #define DECLARE_INSN(name, match_val, mask_val) \
        insn_info_list.push_back(new insn_decode_info(#name, match_val, mask_val));

    #include "insn_encoding.h"
    #undef DECLARE_INSN
}

INSN_DECODE::~INSN_DECODE() {
    for(int i = 0; i < insn_info_list.size(); i++) {
        if(insn_info_list[i] != NULL) {
            delete insn_info_list[i];
            insn_info_list[i] = NULL;
        }
    }
}