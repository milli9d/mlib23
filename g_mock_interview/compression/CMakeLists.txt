# add sub-project
file(GLOB app_srcs ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(compress_tb tb.cpp ${app_srcs})