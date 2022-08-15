#include "csr.h"

base_csr::base_csr(const uint32_t reg_addr)
    : value(0), reg_addr(reg_addr),
     csr_priv(),
     csr_rw() {

}

epc_csr::epc_csr(const uint32_t reg_addr)
    : base_csr(reg_addr) {

}

uint32_t epc_csr::read() const {
    return value; // should check alignment
}
