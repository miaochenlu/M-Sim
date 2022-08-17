#include "csr.h"

base_csr::base_csr(const uint32_t reg_addr)
    : reg_addr(reg_addr),
     csr_priv(get_field(reg_addr, 0x300)),
     csr_readonly(get_field(reg_addr, 0xC00) == 3) {

}

mstatus_csr::mstatus_csr(const uint32_t reg_addr)
    : base_csr(reg_addr), value(mstatus_init()) {

}

uint32_t mstatus_csr::mstatus_init() {
    return 0;
}

uint32_t mstatus_csr::read() const {
    return value; // should check alignment
}

void mstatus_csr::write(const uint32_t val) {
    value = val & ~(uint32_t)1;
}

epc_csr::epc_csr(const uint32_t reg_addr)
    : value(0), base_csr(reg_addr) {

}

uint32_t epc_csr::read() const {
    return value; // should check alignment
}

void epc_csr::write(const uint32_t val) {
    value = val & ~(uint32_t)1;
}

tvec_csr::tvec_csr(const uint32_t reg_addr)
    : value(0), base_csr(reg_addr) {

}

uint32_t tvec_csr::read() const {
    return value; // should check alignment
}

void tvec_csr::write(const uint32_t val) {
    value = val & ~(uint32_t)2;
}

cause_csr::cause_csr(const uint32_t reg_addr)
    : value(0), base_csr(reg_addr) {

}

uint32_t cause_csr::read() const {
    return value; // should check alignment
}

void cause_csr::write(const uint32_t val) {
    value = val;
}