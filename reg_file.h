#ifndef REG_FILE_H
#define REG_FILE_H

#include <stdint.h>

class reg_file {
public:
    static reg_file& get_instance();
    ~reg_file();

private:
    reg_file();

public:
    uint32_t read(uint32_t index) const;

    void write(uint32_t index, uint32_t val);

private:
    uint32_t regs[32];
};

#endif