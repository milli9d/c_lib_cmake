#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <fstream>

namespace mips
{

/**
 * memory size, in reality, the memory size should be 2^32, but for this example,
 * for the space reason, we keep it as this large number,
 * but the memory is still 32-bit addressable.
 */
#define MemSize 65536

#define WORD_LEN 4u

    /* define all operation types */
    typedef enum op_e : uint8_t
    {
        HALT = 0x3Fu,
        R_TYP = 0x00u,
        J_TYP = 0x02u
    } op_t;

    typedef enum op_mode : uint8_t
    {
        IDLE,
        R_TYPE,
        J_TYPE,
        I_TYPE,
        OP_NONE = 99u
    } op_mode_t;

    typedef enum funct_e
    {
        ADDU = 0x01u,
        SUBU = 0x03u,
        AND = 0x04u,
        OR = 0x05u,
        NOR = 0x07u
    } funct_t;

    typedef enum itype_ops_e
    {
        ADDIU = 0x09u,
        BEQ = 0x04u,
        LW = 0x23u,
        SW = 0x2Bu
    } itype_ops_t;

    typedef struct jtype_s
    {
        std::bitset<6> opcode{};
        std::bitset<26> addr{};
    } jtype_t;

    typedef struct rtype_s
    {
        std::bitset<6> opcode{};
        std::bitset<5> rs{};
        std::bitset<5> rt{};
        std::bitset<5> rd{};
        std::bitset<5> shamt{};
        std::bitset<6> funct{};
    } rtype_t;

    typedef struct itype_s
    {
        std::bitset<6> opcode{};
        std::bitset<5> rs{};
        std::bitset<5> rt{};
        std::bitset<16> imm{};
    } itype_t;

    typedef union unified_s
    {
        itype_t it;
        jtype_t jt;
        rtype_t rt;
    } unified_t;

}