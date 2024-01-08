# add logging library sources
file(GLOB srcs ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c*)

add_library(logging_common SHARED ${srcs})

target_include_directories(logging_common
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(MLIB23::Logging ALIAS logging_common)