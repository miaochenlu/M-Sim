use crate::param::*;
use crate::exception::*;
use crate::dram::*;
use crate::plic::Plic;
use crate::clint::Clint;

pub struct Bus {
    dram: Dram,
    plic: Plic,
    clint: Clint,
}


impl Bus {
    pub fn new(code: Vec<u8>) -> Self {
        Self { 
            dram: Dram::new(code),
            clint: Clint::new(),
            plic: Plic::new(),
        }
    }

    pub fn load(&mut self, addr: u64, size: u64) -> Result<u64, Exception> {
        match addr {
            CLINT_BASE..=CLINT_END => self.clint.load(addr, size),
            PLIC_BASE..=PLIC_END => self.plic.load(addr, size),
            DRAM_BASE..=DRAM_END => self.dram.load(addr, size),
            _ => Err(Exception::LoadAccessFault(addr)),
        }
    }

    pub fn store(&mut self, addr: u64, size: u64, value: u64) -> Result<(), Exception> {
        match addr {
            CLINT_BASE..=CLINT_END => self.clint.store(addr, size, value),
            PLIC_BASE..=PLIC_END => self.plic.store(addr, size, value),
            DRAM_BASE..=DRAM_END => self.dram.store(addr, size, value),
            _ => Err(Exception::StoreAMOAccessFault(addr)),
        }
    }
}