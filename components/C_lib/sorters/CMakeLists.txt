# add base library
add_library(c_sorters SHARED sorters.c)

# includes
target_include_directories(c_sorters PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# add alias for ease of usage
add_library(C::sorters ALIAS c_sorters)

# add demo test_bench
add_executable(sorters_tb test_bench.c)

link_directories(${LIB_DIR})

target_link_libraries(sorters_tb 
    PRIVATE    C::sorters
)

add_custom_target(sorters_demo COMMAND sorters_tb)