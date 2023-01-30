# add base library
add_library(c_array SHARED array.c)

# includes
target_include_directories(c_array PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# add alias for ease of usage
add_library(C::array ALIAS c_array)

add_executable(array_tb test_bench.c)

target_link_libraries(array_tb 
    PRIVATE     C::array
)

add_custom_target(array_demo COMMAND array_tb)