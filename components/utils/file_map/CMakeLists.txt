# add base library
add_library(file_map_l SHARED file_map.cpp)

# includes
target_include_directories(file_map_l PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# add alias for ease of usage
add_library(utils::file_map ALIAS file_map_l)

add_executable(file_map_tb test_bench.cpp)

target_link_libraries(file_map_tb 
        PRIVATE utils::file_map
)

add_custom_target(file_map_demo COMMAND file_map_tb)
