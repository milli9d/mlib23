# add array list library
add_library(c_array_list INTERFACE)

target_include_directories(c_array_list
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include/
)

add_library(CPP::array_list ALIAS c_array_list)

add_executable(c_array_list_tb array_list_tb.cpp)

target_link_libraries(c_array_list_tb
    PRIVATE CPP::array_list
)
