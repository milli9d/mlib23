MACRO(SUBDIRLIST result curdir)
    FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
    SET(dirlist "")

    FOREACH(child ${children})
        IF(IS_DIRECTORY ${curdir}/${child})
            LIST(APPEND dirlist ${child})
        ENDIF()
    ENDFOREACH()

    SET(${result} ${dirlist})
ENDMACRO()

add_subdirectory(${BASE_DIR}/c_lib)
add_subdirectory(${BASE_DIR}/cpp_lib)
add_subdirectory(${BASE_DIR}/CTCI/C)
add_subdirectory(${BASE_DIR}/g_mock_interview)
add_subdirectory(${BASE_DIR}/object_oriented)
