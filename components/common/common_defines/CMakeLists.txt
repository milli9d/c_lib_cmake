# add base library
add_library(c_common_defines SHARED common_defines.c)

# includes
target_include_directories(c_common_defines 
    PUBLIC    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# add alias for ease of usage
add_library(C::common_defines ALIAS c_common_defines)