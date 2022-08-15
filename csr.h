#ifndef CSR_H
#define CSR_H

#include <stdint.h>

enum priv_mode {
    PRV_U = 0,
    PRV_S = 1,
    PRV_M = 3
};

class base_csr {
public:
    base_csr(const uint32_t reg_addr);
    virtual ~base_csr();

    uint32_t reg_addr;

public:
    virtual uint32_t read() const;
    virtual void write(const uint32_t val);

protected:
    uint32_t value;
    const bool csr_rw; // read only ? read write?
    const unsigned csr_priv;
};


class status_csr: public base_csr {

};

class epc_csr: public base_csr {
public:
    epc_csr(const uint32_t reg_addr);
    virtual ~epc_csr();

public:
    virtual uint32_t read() const;
    virtual void write(const uint32_t val);
};

#endif