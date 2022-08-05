#include "fetch.h"

using namespace std;

FETCH::FETCH(sc_module_name name) {
    SC_CTHREAD(fetch, clk.pos());
}

FETCH::~FETCH() {

}

void FETCH::fetch() {
    while(true) {
        rd_addr = rd_addr + 1;
        printf("insn: %#010x\n", rd_data.read());
        wait();
    }
}