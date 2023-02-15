# add base library
add_library(c_queue SHARED queue.c)

# includes
target_include_directories(c_queue PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# add alias for ease of usage
add_library(C::queue ALIAS c_queue)

# add demo test_bench
add_executable(queue_tb test_bench.c)

link_directories(${LIB_DIR})

target_link_libraries(queue_tb 
    PRIVATE     C::linked_list
    PRIVATE     C::queue
)

add_custom_target(queue_demo COMMAND queue_tb)