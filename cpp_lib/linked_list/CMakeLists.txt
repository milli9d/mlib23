#
file(GLOB c_linked_list_srcs ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_library(c_linked_list INTERFACE ${c_linked_list_srcs})

target_include_directories(c_linked_list
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include/
)

add_library(CPP::linked_list ALIAS c_linked_list)

add_executable(c_linked_list_tb linked_list_tb.cpp)

target_link_libraries(c_linked_list_tb
    PRIVATE CPP::linked_list
)

add_custom_target(c_linked_list_run COMMAND c_linked_list_tb)