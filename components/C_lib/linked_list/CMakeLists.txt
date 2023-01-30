# add base library
add_library(c_linked_list SHARED linked_list.c)

# includes
target_include_directories(c_linked_list PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# add alias for ease of usage
add_library(C::linked_list ALIAS c_linked_list)

add_executable(linked_list_tb test_bench.c)

target_link_libraries(linked_list_tb 
        PRIVATE C::linked_list
)

add_custom_target(linked_list_demo COMMAND linked_list_tb)
