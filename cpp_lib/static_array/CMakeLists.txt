# add interface library
add_library(c_static_array INTERFACE)

target_include_directories(c_static_array
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/
)

add_library(CPP::static_array ALIAS c_static_array)

add_executable(c_static_array_tb static_array_tb.cpp)

target_link_libraries(c_static_array_tb
    PRIVATE CPP::static_array
)

add_custom_target(c_static_array_run COMMAND c_static_array_tb)