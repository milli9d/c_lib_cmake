# ======================= CH 16 EX 01
add_executable(ex16_01 ex16_01.c)

# includes
target_include_directories(ex16_01 PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(ex16_01
    PUBLIC C::hashmap
)

add_custom_target(r_ex16_01 COMMAND ex16_01)

# ======================= CH 16 EX 02
add_executable(ex16_02 ex16_02.c)

# includes
target_include_directories(ex16_02 PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(ex16_02
    PUBLIC C::hashmap
)

add_custom_target(r_ex16_02 COMMAND ex16_02)