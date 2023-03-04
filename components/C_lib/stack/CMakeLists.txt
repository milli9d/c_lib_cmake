# add base library
add_library(c_stack SHARED stack.c)

# includes
target_include_directories(c_stack PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# add alias for ease of usage
add_library(C::stack ALIAS c_stack)

# add demo test_bench
add_executable(stack_tb test_bench.c)

link_directories(${LIB_DIR})

target_link_libraries(stack_tb
    PUBLIC C::linked_list
    PUBLIC C::stack
)

add_custom_target(stack_demo COMMAND stack_tb)