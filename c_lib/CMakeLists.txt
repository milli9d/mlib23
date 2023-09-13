# add library
file(GLOB srcs ${CMAKE_CURRENT_SOURCE_DIR}/*.c)

add_library(c_lib SHARED ${srcs})

target_include_directories(c_lib 
    PUBLIC    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
