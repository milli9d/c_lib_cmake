#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <fstream>

#include "common_defines.hpp"

namespace mips
{

    /* =============================================================================== Data Memory */

    class DataMem
    {
    public:
        std::bitset<32> readdata;

        /**
         * @brief Default Constructor
         *
         * Open DMEM file and read contents
         */
        DataMem()
        {
            DMem.resize(MemSize);
            std::ifstream dmem;
            std::string line;
            int i = 0;
            dmem.open("dmem.txt");
            if (dmem.is_open())
            {
                while (getline(dmem, line))
                {
                    DMem[i] = std::bitset<8>(line);
                    i++;
                }
            }
            else
            {
                throw std::runtime_error("DMEM Unable to open file.");
            }
            dmem.close();
        }

        std::bitset<32> MemoryAccess(std::bitset<32> Address, std::bitset<32> WriteData, std::bitset<1> readmem, std::bitset<1> writemem)
        {
            bool readMem = readmem.to_ulong() == 1u;
            bool writeMem =  writemem.to_ulong() == 1u;

            /* sanity check */
            if (readMem && writeMem) {
                throw std::runtime_error("Both R/W bits set");
            }

            if (readMem)
            {
                /* Read the byte at the Address and the following three byte */
                for (uint8_t i = 0u; i < 4u; i++)
                {
                    /* build out std::bitset, byte by byte, MSB first */
                    std::bitset<8> &_byte = DMem[Address.to_ulong() + i];
                    readdata = (readdata.to_ulong() << 8u) | _byte.to_ulong();
                }
            }
            else if (writeMem)
            {
                /* Write the byte at the Address and the following three byte */
                for (uint8_t i = 0u; i < 4u; i++)
                {
                    DMem[Address.to_ulong() + i] = WriteData.to_ulong() >> (8u * (3u - i));
               
                    /* build out std::bitset, byte by byte, MSB first */
                    std::bitset<8> &_byte = DMem[Address.to_ulong() + i];
                    readdata = (readdata.to_ulong() << 8u) | _byte.to_ulong();
                }
            }

            std::cout<< "Address:" << Address << " \nR" << readMem << " W"  << writeMem << " Data:" << readdata << std::endl;

            return readdata;
        }

        void OutputDataMem() // write dmem results to file
        {
            std::ofstream dmemout;
            dmemout.open("dmemresult.txt");
            if (dmemout.is_open())
            {
                for (int j = 0; j < 1000; j++)
                {
                    dmemout << DMem[j] << std::endl;
                }
            }
            else
            {
                throw std::runtime_error("OUT Unable to open file.");
            }
            dmemout.close();
        }

    private:
        std::vector<std::bitset<8>> DMem{};
    };

}