# configure cmake sub-component
add_executable(ss_mips MIPS.cpp)

target_include_directories(ss_mips
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_custom_target(ss_mips_demo COMMAND ss_mips)

# Utility to generate instructions from MIPS asm
add_executable(mips_bin_compiler bin_compiler.cpp)

target_include_directories(mips_bin_compiler
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_custom_target(mips_bin_compile COMMAND mips_bin_compiler)