#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <fstream>

#include "common_defines.hpp"

namespace mips
{
    /* =============================================================================== Instruction Memory */

    class INSMem
    {
    public:
        std::bitset<32> Instruction;
        INSMem() // read instruction memory
        {
            IMem.resize(MemSize);
            std::ifstream imem;
            std::string line;
            int i = 0;
            imem.open("imem.txt");
            if (imem.is_open())
            {
                while (getline(imem, line))
                {
                    IMem[i] = std::bitset<8>(line);
                    i++;
                }
            }
            else
            {
                throw std::runtime_error("IMEM Unable to open file.");
            }
            imem.close();
        }

        /**
         * @brief Read a memory word [4 bytes] from the Instruction memory
         *
         * @param ReadAddress[in]       Byte index of requested read
         */
        std::bitset<32> ReadMemory(std::bitset<32> ReadAddress)
        {
            /* Read the byte at the ReadAddress and the following three byte */
            for (uint8_t i = 0u; i < 4u; i++)
            {
                /* build out std::bitset, byte by byte, MSB first */
                std::bitset<8> &_byte = IMem[ReadAddress.to_ulong() + i];
                Instruction = (Instruction.to_ulong() << 8u) | _byte.to_ulong();
            }

            std::cout << "Instruction: " << Instruction << std::endl;
            return Instruction;
        }

    private:
        std::vector<std::bitset<8>> IMem;
    };
}