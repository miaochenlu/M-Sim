#include "decoder.h"
#include "base_inst.h"
#include "riscv_inst.h"
#include "rom.h"
#include "ram.h"
#include "processor.h"
#include <iostream>

using namespace std;

int main() {
    processor m_proc;
    m_proc.run();
}