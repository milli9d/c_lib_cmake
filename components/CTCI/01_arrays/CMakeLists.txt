# ======================= CH 01 EX 01
add_executable(ex01_01 ex01_01.c)

# includes
target_include_directories(ex01_01 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(ex01_01 
    PRIVATE     C::array
    PRIVATE     C::hashmap
)

add_custom_target(r_ex01_01 COMMAND ex01_01)


# ======================= CH 01 EX 02
add_executable(ex01_02 ex01_02.c)

# includes
target_include_directories(ex01_02 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(ex01_02 
    PRIVATE     C::array
    PRIVATE     C::hashmap
)

add_custom_target(r_ex01_02 COMMAND ex01_02)


# ======================= CH 01 EX 03
add_executable(ex01_03 ex01_03.c)

# includes
target_include_directories(ex01_03 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(ex01_03)

add_custom_target(r_ex01_03 COMMAND ex01_03)


# ======================= CH 01 EX 07
add_executable(ex01_07 ex01_07.c)

# includes
target_include_directories(ex01_07 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(ex01_07 
    PRIVATE     C::array
    PRIVATE     C::hashmap
)

add_custom_target(r_ex01_07 COMMAND ex01_07)