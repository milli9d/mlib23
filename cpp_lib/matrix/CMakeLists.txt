# add cpp_matrix library
add_library(cpp_matrix INTERFACE)

target_include_directories(cpp_matrix
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include/
)

add_library(CPP::matrix ALIAS cpp_matrix)

add_executable(cpp_matrix_tb tb.cpp)

target_link_libraries(cpp_matrix_tb
    PRIVATE CPP::matrix
)
