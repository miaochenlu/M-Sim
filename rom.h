#ifndef ROM_H
#define ROM_H

#include <iostream>
#include <vector>

class rom {
public:
    rom(const std::string& file_name);

    ~rom();

public:
    void init_memory(const std::string& file_name);

    uint32_t read(uint32_t pc);

private:
    std::string rom_file_name;
    std::vector<uint32_t> mem;
};

#endif