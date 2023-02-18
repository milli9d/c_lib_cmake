#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <fstream>

#include "common_defines.hpp"

namespace mips
{

    /* =============================================================================== Register File */
    class RF
    {
    public:
        /* output data */
        std::bitset<32> ReadData1, ReadData2;

        /**
         * @brief Default constructor
         */
        RF()
        {
            Registers.resize(32);
            Registers[0] = std::bitset<32>(0);

            for(int i = 0 ; i < 32 ; i++) 
            {
                Registers[i] = std::bitset<32>(i*4);
            }
        }

        /**
         * @brief Read Write Register File
         *
         * If WrtEnable then write data to wrtReg
         * else, read data from RdReg1 and RdReg2 into ReadData1,2
         *
         */
        void ReadWrite(std::bitset<5> RdReg1, std::bitset<5> RdReg2, std::bitset<5> WrtReg, std::bitset<32> WrtData, std::bitset<1> WrtEnable)
        {
            if (WrtEnable == 1u)
            {
                /* write data to the register file */
                Registers[(size_t)WrtReg.to_ulong()] = WrtData;
            }
            else
            {
                /* read data from the register file */
                ReadData1 = Registers[RdReg1.to_ulong()];
                ReadData2 = Registers[RdReg2.to_ulong()];
            }
        }

        void OutputRF() // write RF results to file
        {
            std::ofstream rfout;
            rfout.open("RFresult.txt", std::ios_base::app);

            if (rfout.is_open())
            {

                rfout << "A state of RF:" << std::endl;
                for (int j = 0; j < 32; j++)
                {
                    rfout << Registers[j] << std::endl;
                }
            }
            else
            {
                throw std::runtime_error("RF Unable to open file.");
            }

            rfout.close();
        }

    private:
        /* register file data memory */
        std::vector<std::bitset<32>> Registers{};
    };

}