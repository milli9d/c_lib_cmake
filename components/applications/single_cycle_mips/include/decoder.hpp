#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <fstream>

#include "common_defines.hpp"

namespace mips
{

    /* =============================================================================== Decoder */
    class Decoder
    {
    public:
        /**
         * @brief Get current OP type
         */
        op_mode_t get_opmode(void)
        {
            return _mode;
        }

        unified_t &get_ops(void)
        {
            return _ops;
        }

    
        /**
         * @brief Perform logical sign extension of the immediate [I-Type]
         * @param  
         * @return 
         */
        std::bitset<32> SignExtImm(void)
        {
            /* sanity checks */
            if(_mode != I_TYPE) {
                throw std::runtime_error("Wrong Op-Mode");
            }

            /* determine sign of the MSB */
            std::bitset<16>& imm = _ops.it.imm;
            std::bitset<1> sign = imm.to_ulong() >> 15u;

            /* Generate 32 bits mask */
            std::bitset<32> out;
            sign.to_ulong() == 1u ? out.set() : out.reset();

            /* Push imm to mask */
            out = (out.to_ulong() << 16u) | imm.to_ulong();
            std::cout << "Sign = " << sign << "\nSignExtImm = " << out << std::endl;
            return out;
        }

        void decode(std::bitset<32> instruction)
        {
            /* parse opcode */
            _opcode = (instruction.to_ulong() >> 26u);
            std::cout << "Opcode:" << _opcode;

            switch ((op_t)_opcode.to_ulong())
            {
            case R_TYP: // R-Type Instruction
                _mode = R_TYPE;
                _ops.rt.opcode = _opcode.to_ulong();
                _ops.rt.rs = (instruction.to_ulong() >> 21u);
                _ops.rt.rt = (instruction.to_ulong() >> 16u);
                _ops.rt.rd = (instruction.to_ulong() >> 11u);
                _ops.rt.shamt = (instruction.to_ulong() >> 6u);
                _ops.rt.funct = (instruction.to_ulong() >> 0u);
                std::cout << " Rs: " << _ops.rt.rs << " Rt: " << _ops.rt.rs << " Rd: " << _ops.rt.rd << " Shamt: " << _ops.rt.shamt << " Funct: " << _ops.rt.funct << std::endl;
                break;
            case J_TYP: // J-Type Instruction
                _mode = J_TYPE;
                _ops.jt.opcode = _opcode.to_ulong();
                _ops.jt.addr = (instruction.to_ulong() >> 0u);
                std::cout << " addr: " << _ops.jt.addr << std::endl;
                break;
            case HALT: // HALT
                std::cout << std::endl;
                throw std::out_of_range("[HALT] End of instruction memory.");
                break;
            /* I Type instructions */
            default:
                _mode = I_TYPE;
                _ops.it.opcode = _opcode.to_ulong();
                _ops.it.rs = (instruction.to_ulong() >> 21u);
                _ops.it.rt = (instruction.to_ulong() >> 16u);
                _ops.it.imm = (instruction.to_ulong() >> 0u);
                std::cout << " Rs: " << _ops.it.rs << " Rt: " << _ops.it.rt << " Imm: " << _ops.it.imm << std::endl;
                break;
            }
        }

        /**
         * @brief Default Constructor
         *
         * This will decode the given instruction and store it in the unified data type
         */
        Decoder(std::bitset<32> instruction)
        {
            decode(instruction);
        }

        Decoder(){};

    private:
        std::bitset<6> _opcode{};
        unified_t _ops{};
        op_mode_t _mode = OP_NONE;
    };

}