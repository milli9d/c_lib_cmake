# add base library
add_library(c_hashmap SHARED hashmap.c)

# includes
target_include_directories(c_hashmap PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# add alias for ease of usage
add_library(C::hashmap ALIAS c_hashmap)

add_executable(hashmap_tb test_bench.c)

target_link_libraries(hashmap_tb
    PRIVATE C::hashmap
    PRIVATE C::linked_list
)

add_custom_target(hashmap_demo COMMAND hashmap_tb)
