#include "reg_pc.h"
#include "tb/reg_pc_tb.h"

int sc_main(int, char* []) {
    REG_PC reg_pc("reg_pc");
    REG_PC_TB reg_pc_tb("reg_pc_tb");

    sc_clock                clk("clk", 10, SC_SEC, 0.5, 10, SC_SEC, false);
    sc_signal<bool>         rst;
    sc_signal<bool>         enable;
    sc_signal<sc_uint<32>>  pc_in;
    sc_signal<sc_uint<32>>  pc_out;

    reg_pc.clk(clk);
    reg_pc.rst(rst);
    reg_pc.enable(enable);
    reg_pc.pc_in(pc_in);
    reg_pc.pc_out(pc_out);

    reg_pc_tb.clk(clk);
    reg_pc_tb.rst(rst);
    reg_pc_tb.enable(enable);
    reg_pc_tb.pc_in(pc_in);
    reg_pc_tb.pc_out(pc_out);

    sc_start();
    return 0;
}