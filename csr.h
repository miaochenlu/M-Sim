#ifndef CSR_H
#define CSR_H

#include <stdint.h>

// example (0x1100 & 0x1100) / 4
#define get_field(reg, mask) (((reg) & (decltype(reg))(mask)) / ((mask) & ~((mask) << 1)))
#define set_field(reg, mask, val) (((reg) & ~(decltype(reg))(mask)) | (((decltype(reg))(val) * ((mask) & ~((mask) << 1))) & (decltype(reg))(mask)))

class base_csr {
public:
    base_csr(const uint32_t reg_addr);
    virtual ~base_csr();

    uint32_t reg_addr;

public:
    virtual uint32_t read() const;
    virtual void write(const uint32_t val);

protected:
    const bool csr_readonly; // read only ? read write?
    const unsigned csr_priv;
};


class mstatus_csr: public base_csr {
public:
    mstatus_csr(const uint32_t reg_addr);
    virtual ~mstatus_csr();

public:
    virtual uint32_t read() const;
    virtual void write(const uint32_t val);
private:
    uint32_t mstatus_init();
private:
    uint32_t value;
};

class epc_csr: public base_csr {
public:
    epc_csr(const uint32_t reg_addr);
    virtual ~epc_csr();

public:
    virtual uint32_t read() const;
    virtual void write(const uint32_t val);
private:
    uint32_t value;
};

class tvec_csr: public base_csr {
public:
    tvec_csr(const uint32_t reg_addr);
    virtual ~tvec_csr();

public:
    virtual uint32_t read() const;
    virtual void write(const uint32_t val);
private:
    uint32_t value;
};

class cause_csr: public base_csr {
public:
    cause_csr(const uint32_t reg_addr);
    virtual ~cause_csr();

public:
    virtual uint32_t read() const;
    virtual void write(const uint32_t val);
private:
    uint32_t value;
};
#endif