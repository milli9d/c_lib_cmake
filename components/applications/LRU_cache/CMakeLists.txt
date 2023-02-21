add_library(lru_cache SHARED cache.cpp)

target_include_directories(lru_cache
    PRIVATE     ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(CPP::cache ALIAS lru_cache)

add_executable(cache_tb test_bench.cpp)

target_include_directories(cache_tb
    PRIVATE     ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_custom_target(cache_demo COMMAND cache_tb)