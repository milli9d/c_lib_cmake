# ======================= CH 01 EX 01
add_executable(ex02_01 ex02_01.c)

# includes
target_include_directories(ex02_01 PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(ex02_01
    PUBLIC C::hashmap
    PUBLIC C::linked_list
)

add_custom_target(r_ex02_01 COMMAND ex02_01)