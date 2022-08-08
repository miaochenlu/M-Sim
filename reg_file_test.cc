#include "reg_file.h"
#include "tb/reg_file_tb.h"

int sc_main(int, char* []) {
    REG_FILE reg("reg");
    REG_FILE_TB reg_tb("reg_tb");

    sc_clock                clk("clk", 10, SC_SEC, 0.5, 10, SC_SEC, false);
    sc_signal<bool>         rst;
    sc_signal<bool>         wr_en;
    sc_signal<sc_uint<5>>   raddr_A;
    sc_signal<sc_uint<5>>   raddr_B;
    sc_signal<sc_uint<5>>   waddr;
    sc_signal<signed>       rval_A, rval_B, wdata;

    reg.clk(clk);
    reg.rst(rst);
    reg.wr_en(wr_en);
    reg.raddr_A(raddr_A);
    reg.raddr_B(raddr_B);
    reg.rval_A(rval_A);
    reg.rval_B(rval_B);
    reg.waddr(waddr);
    reg.wdata(wdata);

    reg_tb.clk(clk);
    reg_tb.rst(rst);
    reg_tb.wr_en(wr_en);
    reg_tb.raddr_A(raddr_A);
    reg_tb.raddr_B(raddr_B);
    reg_tb.rval_A(rval_A);
    reg_tb.rval_B(rval_B);
    reg_tb.waddr(waddr);
    reg_tb.wdata(wdata);

    sc_start();
    return 0;
}