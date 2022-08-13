#ifndef RAM_H
#define RAM_H

#include <iostream>
#include <vector>

class ram {
public:
    ram(const std::string& file_name);

    ~ram();

public:
    void init_memory(const std::string& file_name);

    uint32_t read(uint32_t addr, uint32_t byte_num);

    void write(uint32_t addr, uint32_t byte_num, uint32_t value);

private:
    std::string ram_file_name;
    std::vector<uint8_t> mem;
};

#endif