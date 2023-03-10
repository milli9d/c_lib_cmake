add_library(c_logging SHARED logging.c)

target_include_directories(c_logging
    PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(C::logging ALIAS c_logging)

add_executable(logging_tb test_bench.c)

target_link_libraries(logging_tb
    PUBLIC  C::logging
)

add_custom_target(logging_demo COMMAND logging_tb)