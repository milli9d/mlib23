# Add the 'include/' directory to the include path
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Get a list of all source files in the 'src/' directory
file(GLOB clib_sources "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

# Loop over each source file
foreach(source_file ${clib_sources})
  # Extract the filename without the extension
  get_filename_component(filename_we ${source_file} NAME_WE)

  # Create an executable for each source file
  add_library(c_lib_${filename_we} SHARED ${source_file})
  add_library(c_lib::${filename_we} ALIAS c_lib_${filename_we})

  # If additional libraries are needed, you can link them like so:
  target_include_directories(c_lib_${filename_we} 
      PUBLIC    ${CMAKE_CURRENT_SOURCE_DIR}/include
  )
endforeach()
