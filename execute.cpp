#include "execute.h"
#include <iostream>
using namespace std;

void EXECUTE::executing() {
    insn_out.write(NULL);
    wait();
    while(true) {
        // cout << "time @ " << sc_time_stamp();
        printf("\t\there\n");
        INSTRUCTION* insn = insn_in.read();
        if(insn != NULL) {
            cout << "time @ " << sc_time_stamp() << "  executetttt" << std::endl;
            insn->execute();
        } else {
            printf("execute insn is null\n");
        }
        printf("execute done\n");
        // insn_out.write(insn);
        wait();
    }
}