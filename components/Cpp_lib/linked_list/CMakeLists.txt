# add base library
add_library(cpp_linked_list SHARED linked_list.cpp)

# includes
target_include_directories(cpp_linked_list PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# add alias for ease of usage
add_library(Cpp::linked_list ALIAS cpp_linked_list)

add_executable(cpp_linked_list_tb test_bench.cpp)

target_link_libraries(cpp_linked_list_tb 
        PRIVATE Cpp::linked_list
)

add_custom_target(cpp_linked_list_demo COMMAND cpp_linked_list_tb)
