#include "rom.h"
#include "reg_pc.h"
#include "tb/reg_pc_tb.h"
#include "decode.h"
#include "execute.h"

int sc_main(int, char*[]) {
    sc_core::sc_report_handler::set_actions( "/IEEE_Std_1666/deprecated",
                                           sc_core::SC_DO_NOTHING );

    sc_clock clk("Clock", 1, SC_SEC, 0.5, 0.0, SC_NS);

    sc_signal< bool >         rst;
    sc_signal< bool >         enable;
    sc_signal< sc_uint<32> >  pc_in;
    sc_signal< sc_uint<32> >  pc_out;

    sc_fifo< INSTRUCTION* >* fetch_fifo = new sc_fifo<INSTRUCTION*>(1);
    sc_fifo< INSTRUCTION* >* decode_fifo = new sc_fifo<INSTRUCTION*>(1);
    sc_fifo< INSTRUCTION* >* execute_fifo = new sc_fifo<INSTRUCTION*>(1);
    
    REG_PC pc("pc");
    pc.clk(clk);
    pc.rst(rst);
    pc.enable(enable);
    pc.pc_in(pc_in);
    pc.pc_out(pc_out);
    
    ROM rom("rom", "rom.hex");
    rom.rd_addr(pc_out);
    rom.insn_out(*fetch_fifo);
    rom.clk(clk);

    DECODE decode("decode");
    decode.clk(clk);
    decode.insn_in(*fetch_fifo);
    decode.insn_out(*decode_fifo);

    EXECUTE execute("execute");
    execute.clk(clk);
    execute.insn_in(*decode_fifo);
    execute.insn_out(*execute_fifo);

    sc_start(20, SC_SEC);

    delete fetch_fifo;
    delete decode_fifo;
    delete execute_fifo;
    return 0;
}