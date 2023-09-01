cmake_minimum_required(VERSION 3.22.1)

set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_STANDARD 23)

# Add interview project files
project(interview_prep_summer_2023)

set(_C_FLAGS "-fsanitize=address -Wall -Werror -g -Og")
set(_CXX_FLAGS "-fsanitize=address -Wall -Werror -g -Og")

set(CMAKE_C_FLAGS_DEBUG ${_C_FLAGS})
set(CMAKE_C_FLAGS_MINSIZEREL ${_C_FLAGS})
set(CMAKE_C_FLAGS_RELWITHDEBINFO ${_C_FLAGS})
set(CMAKE_C_FLAGS_RELEASE ${_C_FLAGS})

set(BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(LIB_DIR ${PROJECT_SOURCE_DIR}/lib)

set(BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIB_DIR})

add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

# add sources
file(GLOB cmake_srcs ${CMAKE_CURRENT_SOURCE_DIR}/cmake/*.cmake)
include(${cmake_srcs})

# add test bench program
add_executable(test_bench test_bench.cpp)

target_link_libraries(test_bench
    PUBLIC c_lib
)

add_custom_target(run_tb COMMAND test_bench)

# add test bench program
add_executable(test_bench_c test_bench.c)

target_link_libraries(test_bench_c
)

add_custom_target(run_tb_c COMMAND test_bench)