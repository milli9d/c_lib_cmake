#include <stdio.h>
#include <stdint.h>
#include <vector>

#include "include/array.hpp"

#define ARR_DATA_T uint16_t
#define ARR_LEN 25u

int main(int argc, char **argv)
{
    cpp_lib::static_array<ARR_DATA_T, ARR_LEN> test;    

    cpp_lib::static_array<ARR_DATA_T,ARR_LEN>::iterator itr = &test[0u];

    for(auto& i : test) {
        i = 10u;
    }

    try{
        ARR_DATA_T val = test.at(15u);
        std::cout << val << std::endl;
    } catch (std::out_of_range e){
        std::cout << e.what() << std::endl;
    }

    std::cout << test;

    return 0;
}