mod bus;
mod cpu;
mod dram;
mod param;
mod exception;
mod csr;
mod clint;
mod plic;

use std::env;
use std::fs::File;
use std::io;
use std::io::prelude::*;
use crate::cpu::*;

fn main() -> io::Result<()>{

    let args: Vec<String> = env::args().collect();

    if (args.len() != 2) && (args.len() != 3) {
        panic!("Usage: rvemu-for-book <filename> <(option) image>");
    }

    let mut file = File::open(&args[1])?;
    let mut binary = Vec::new();
    file.read_to_end(&mut binary)?;

    let mut cpu = Cpu::new(binary);

    loop {
        let inst = match cpu.fetch() {
            Ok(inst) => inst,
            Err(e) => {
                cpu.handle_exception(e);
                if e.is_fatal() {
                    println!("{}", e);
                    break;
                }
                continue;
            }
        };

        match cpu.execute(inst) {
            Ok(new_pc) => cpu.pc = new_pc,
            Err(e) => {
                println!("{}", e);
                break;
            }
        }
    }
    cpu.dump_registers();
    cpu.dump_csrs();
    cpu.dump_pc();

    Ok(())

}