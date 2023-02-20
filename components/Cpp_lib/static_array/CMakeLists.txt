# add base library
add_library(cpp_static_array SHARED include/)

set_target_properties(cpp_static_array PROPERTIES LINKER_LANGUAGE CXX)

# includes
target_include_directories(cpp_static_array PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# add alias for ease of usage
add_library(CPP::static_array ALIAS cpp_static_array)

add_executable(static_array_tb test_bench.cpp)

target_link_libraries(static_array_tb 
    PRIVATE     CPP::static_array
)

add_custom_target(static_array_demo COMMAND static_array_tb)