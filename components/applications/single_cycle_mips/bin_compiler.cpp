/**
 * @brief ASM-Binary Compiler for MIPS
 *
 */

#include <iostream>
#include <filesystem>
#include <fcntl.h>
#include <unistd.h>
#include <getopt.h>

#include "include/bin_compiler.hpp"

namespace mips
{

    bin_compiler::bin_compiler(std::filesystem::path in, std::filesystem::path out)
        : _in(in), _out(out)
    {
        std::cout << _in << std::endl;
        std::cout << _out << std::endl;

    }

    bin_compiler::~bin_compiler()
    {
        
    }

}


/**
 * @brief Driver code
 * 
 * This runs the bin compiler on the provided file path argument
 */
int main(int argc, char** argv)
{
    int c;
    std::filesystem::path in_path{};
    std::filesystem::path out_path{};

    int this_option_optind = optind ? optind : 1;
    int option_index = 0;
    static struct option long_options[] = {
        {"input", required_argument, 0, 'c'},
        {"output", required_argument, 0, 'o'},
        {0, 0, 0, 0}};

    while((c = getopt_long(argc, argv, "o:c:", long_options, &option_index)) != -1) {
        switch (c)
        {
        case 'c':
            in_path = optarg;
            break;
        case 'o':
            out_path = optarg;
            break;
        default:
            break;
        }
    }

    mips::bin_compiler run(in_path, out_path);

    
    return 0;
}