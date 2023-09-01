#
add_library(c_array_ring_buffer INTERFACE)

target_include_directories(c_array_ring_buffer
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include/
)

add_library(CPP::array_ring_buffer ALIAS c_array_ring_buffer)

add_executable(c_array_ring_buffer_tb array_ring_buffer_tb.cpp)

target_link_libraries(c_array_ring_buffer_tb
    PRIVATE CPP::array_ring_buffer
)

add_custom_target(c_array_ring_buffer_run COMMAND c_array_ring_buffer_tb)