# add base library
add_library(cpp_string_tool SHARED string_tool.cpp)

# includes
target_include_directories(cpp_string_tool PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# add alias for ease of usage
add_library(utils::string_tool ALIAS cpp_string_tool)

add_executable(cpp_string_tool_tb test_bench.cpp)

target_link_libraries(cpp_string_tool_tb
    PUBLIC utils::string_tool
)

add_custom_target(cpp_string_tool_demo COMMAND cpp_string_tool_tb)
