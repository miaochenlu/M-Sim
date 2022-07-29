#include "rom.h"

int sc_main(int, char*[]) {
    sc_clock clk("Clock", 1, SC_SEC, 0.5, 0.0, SC_NS);

    sc_signal<unsigned> rom_rd_addr("ROM_RD_ADDR");
    sc_signal<unsigned> rom_rd_data("ROM_RD_DATA");

    ROM rom("rom", "rom.hex");

    rom.rd_addr(rom_rd_addr);
    rom.rd_data(rom_rd_data);
    rom.clk(clk);

    sc_start(7, SC_SEC);
    return 0;
}