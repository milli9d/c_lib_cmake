#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <fstream>

#include "include/common_defines.hpp"
#include "include/register_file.hpp"
#include "include/alu.hpp"
#include "include/decoder.hpp"
#include "include/imem.hpp"
#include "include/dmem.hpp"

namespace mips
{
    class mips_cu
    {
    private:
        mips::RF myRF;
        mips::ALU myALU;
        mips::INSMem myInsMem;
        mips::DataMem myDataMem;
        mips::Decoder decoder;

        uint32_t myPC = 0u;
        uint32_t iteration = 0u;

        mips::op_mode_t _curr_mode{};

    public:
        /**
         * @brief Read RF Stage
         * @param ops
         */
        void stageRF(void)
        {
            /* read RF */
            mips::unified_t &ops = decoder.get_ops();

            switch (_curr_mode)
            {
            case mips::R_TYPE:
                myRF.ReadWrite(ops.rt.rs, ops.rt.rt, 0u, 0u, 0u);
                std::cout << "R-TYPE\n";
                std::cout << "RdData1: " << myRF.ReadData1 << "\nRdData2: " << myRF.ReadData2 << std::endl;
                break;
            case mips::I_TYPE:
                myRF.ReadWrite(ops.it.rs, ops.it.rt, 0u, 0u, 0u);
                std::cout << "I-TYPE\n";
                break;
            case mips::J_TYPE:
                std::cout << "J-TYPE\n";
                break;
            default:
                break;
            }
        }

        /**
         * @brief EXECUTE Stage
         * @param ops
         * @param decode
         */
        void stageEX(void)
        {
            /* Execute */
            mips::unified_t &ops = decoder.get_ops();

            switch (_curr_mode)
            {
            case mips::R_TYPE:
                myALU.ALUOperation(ops.rt.funct.to_ulong(), myRF.ReadData1, myRF.ReadData2);
                break;
            case mips::I_TYPE:
                /* I type instructions add R[rs] and SignExtImm */
                myALU.ALUOperation(mips::funct_t::ADDU, myRF.ReadData1, decoder.SignExtImm());

                /* decode I-Type */
                switch (ops.it.opcode.to_ullong())
                {
                case (itype_ops_t::LW):
                    std::cout << "LW INSTRUCTION" << std::endl;
                    break;
                case (itype_ops_t::SW):
                    std::cout << "SW INSTRUCTION" << std::endl;
                    break;
                case (itype_ops_t::ADDIU):
                    std::cout << "ADDIU INSTRUCTION" << std::endl;
                    break;
                case (itype_ops_t::BEQ):
                    /* branch if R[rs] == R[rt] */
                    std::cout << "BEQ INSTRUCTION" << std::endl;
                    myPC = (myRF.ReadData1 == myRF.ReadData2) ? (myPC + WORD_LEN + (decoder.SignExtImm().to_ulong() & 0b00)) : (myPC + WORD_LEN);
                    break;
                default:
                    std::cout << "DEFAULT " << ops.it.opcode << "NUM = " << ops.it.opcode.to_ulong() << std::endl;
                    break;
                }

                break;
            case mips::J_TYPE:
                break;
            default:
                break;
            }
        }

        void stageDMEM(void)
        {
            /* Read/Write Mem */
            mips::unified_t &ops = decoder.get_ops();

            switch (_curr_mode)
            {
            case mips::R_TYPE:
                break;
            case mips::J_TYPE:
                break;
            case mips::I_TYPE:
                /* decode I-Type */
                switch (ops.it.opcode.to_ullong())
                {
                case (itype_ops_t::LW):
                    /* R[rt] <- Mem[{signExtImm} + R[rs]] */
                    myDataMem.MemoryAccess(myALU.ALUresult, 0u, 1u, 0u);
                    break;
                case (itype_ops_t::SW):
                    /* Mem[{signExtImm} + R[rs]] <- R[rt] */
                    myDataMem.MemoryAccess(myALU.ALUresult, myRF.ReadData2, 0u, 1u);
                    break;
                case (itype_ops_t::ADDIU):
                    myALU.ALUOperation(mips::funct_t::ADDU, myRF.ReadData1, decoder.SignExtImm());
                    break;
                case (itype_ops_t::BEQ):
                    break;
                default:
                    std::cout << "DEFAULT " << ops.it.opcode << "NUM = " << ops.it.opcode.to_ulong() << std::endl;
                    break;
                }
                break;
            default:
                break;
            }
        }

        void stageWB(void)
        {
            /* Write back to RF */
            mips::unified_t &ops = decoder.get_ops();

            switch (_curr_mode)
            {
            case mips::I_TYPE:
                /* decode I-Type */
                switch (ops.it.opcode.to_ullong())
                {
                case (itype_ops_t::LW):
                    /* R[rt] <- Mem[{signExtImm} + R[rs]] */
                    myRF.ReadWrite(0u, 0u, ops.it.rt, myDataMem.readdata, 1u);
                    break;
                case (itype_ops_t::SW):
                    /* Mem[{signExtImm} + R[rs]] <- R[rt] */
                    break;
                case (itype_ops_t::ADDIU):
                    myRF.ReadWrite(0u, 0u, ops.it.rt, myALU.ALUresult, 1u);
                    break;
                case (itype_ops_t::BEQ):
                    break;
                default:
                    break;
                }
                break;
            case mips::R_TYPE:
                /* write back ALU result */
                myRF.ReadWrite(0u, 0u, ops.rt.rd, myALU.ALUresult, 1u);
                break;
            default:
                break;
            }

            /* dump RF */
            myRF.OutputRF();
        }

        /**
         * @brief Default Constructor
         *
         * Launches the MIPS emulator instance, ends at HALT instruction
         *
         */
        mips_cu()
        {
            while (1)
            {
                /* log for debug */
                std::cout << "==============================\nCPU Cycle : " << iteration++ << "\nPC : " << myPC << std::endl;

                /* fetch instruction */
                std::bitset<32> instruction = myInsMem.ReadMemory(myPC);

                /* decode */
                try {
                    decoder.decode(instruction);
                } catch (std::out_of_range e) {
                    std::cout << e.what() << std::endl;
                    break;
                }
                _curr_mode = decoder.get_opmode();
                mips::unified_t &ops = decoder.get_ops();

                stageRF();

                stageEX();

                stageDMEM();

                stageWB();

                /* increment PC */
                switch (_curr_mode)
                {
                case mips::J_TYPE:
                    /* JumpAddress = {PC + WORD_LEN [31:28], addr, 0b00 } */
                    myPC = (((myPC + WORD_LEN) >> 28u) << 28u) | (ops.jt.addr.to_ulong() << 2u) | 0b00;
                    break;
                case mips::I_TYPE:
                    /* decode I-Type */
                    switch (ops.it.opcode.to_ullong())
                    {
                    case (itype_ops_t::BEQ):
                        /* do nothing , PC handled in RF stage */
                        break;
                    default:
                        myPC += WORD_LEN;
                        break;
                    }
                    break;
                default:
                    myPC += WORD_LEN;
                    break;
                }
            }

            /* dump data mem */
            myDataMem.OutputDataMem();
        }
    };
}

int main()
{
    mips::mips_cu test = mips::mips_cu();
    return 0;
}
