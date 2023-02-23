#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <fstream>

#include "common_defines.hpp"

namespace mips
{

    /* =============================================================================== ALU */
    class ALU
    {
    public:
        std::bitset<32> ALUresult;

        std::bitset<32> ALUOperation(std::bitset<3> ALUOP, std::bitset<32> oprand1, std::bitset<32> oprand2)
        {
            /* reset the ALU result */
            ALUresult.reset();
            
            /* parse ALU op */
            funct_t alu_op = static_cast<funct_t>(ALUOP.to_ulong());
            std::cout << "AluOp = " << alu_op << std::endl;
            bool check = false;

            /* perform ALU operation */
            switch (alu_op)
            {
            case ADDU:
                std::cout << "ADDU INSTRUCTION" << std::endl;
                ALUresult = oprand1.to_ulong() + oprand2.to_ulong();
                break;
            case SUBU:
                std::cout << "SUBU INSTRUCTION" << std::endl;

                ALUresult = oprand1.to_ulong() - oprand2.to_ulong();
                break;
            case AND:
                std::cout << "AND INSTRUCTION" << std::endl;
                ALUresult = oprand1.to_ulong() & oprand2.to_ulong();
                break;
            case OR:
                std::cout << "OR INSTRUCTION" << std::endl;
                ALUresult = oprand1.to_ulong() | oprand2.to_ulong();
                break;
            case NOR:
                std::cout << "NOR INSTRUCTION" << std::endl;
                ALUresult = ~(oprand1.to_ulong() | oprand2.to_ulong());
                break;
            default:
                break;
            }

            std::cout << "ALU Result : " << ALUresult << std::endl;

            return ALUresult;
        }
    };
}