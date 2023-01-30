# add base library
add_library(c_double_linked_list SHARED double_linked_list.c)

# includes
target_include_directories(c_double_linked_list PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# add alias for ease of usage
add_library(C::double_linked_list ALIAS c_double_linked_list)

add_executable(double_linked_list_tb test_bench.c)

target_link_libraries(double_linked_list_tb 
        PRIVATE C::double_linked_list
)

add_custom_target(double_linked_list_demo COMMAND double_linked_list_tb)
