# add base library
add_library(c_array SHARED array.c)

# includes
target_include_directories(c_array PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(c_array
    PUBLIC          C::common_defines
)

# add alias for ease of usage
add_library(C::array ALIAS c_array)

# add base library
add_library(c_2d_array SHARED 2d_array.c)

# includes
target_include_directories(c_2d_array PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(c_2d_array
    PUBLIC          C::array
    PUBLIC          C::common_defines
)

# add alias for ease of usage
add_library(C::2d_array ALIAS c_2d_array)

# add testbench
add_executable(array_tb test_bench.cpp)

target_link_libraries(array_tb
    PUBLIC      C::array
    PUBLIC      C::2d_array
    PUBLIC      C::common_defines
)

add_custom_target(array_demo COMMAND array_tb)