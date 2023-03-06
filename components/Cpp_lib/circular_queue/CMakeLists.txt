# add base library
add_library(cpp_circular_queue SHARED circular_queue.cpp)

# includes
target_include_directories(cpp_circular_queue 
    PUBLIC    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# add alias for ease of usage
add_library(Cpp::circular_queue ALIAS cpp_circular_queue)

add_executable(cpp_circular_queue_tb test_bench.cpp)

target_link_libraries(cpp_circular_queue_tb 
        PRIVATE Cpp::circular_queue
)

add_custom_target(cpp_circular_queue_demo COMMAND cpp_circular_queue_tb)