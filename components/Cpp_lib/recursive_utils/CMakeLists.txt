# add base library
add_library(cpp_rec_utils SHARED rec_utils.cpp)

# includes
target_include_directories(cpp_rec_utils PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# add alias for ease of usage
add_library(Cpp::rec_utils ALIAS cpp_rec_utils)

# add demo test_bench
add_executable(cpp_rec_utils_tb test_bench.cpp)

link_directories(${LIB_DIR})

target_link_libraries(cpp_rec_utils_tb 
    PUBLIC    Cpp::rec_utils
    PUBLIC    C::linked_list
)

add_custom_target(cpp_rec_utils_demo COMMAND cpp_rec_utils_tb)