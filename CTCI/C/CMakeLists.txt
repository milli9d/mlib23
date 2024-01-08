# Add the 'include/' directory to the include path
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Get a list of all source files in the 'src/' directory
file(GLOB_RECURSE SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/*.c*"
)

# Loop over each source file
foreach(source_file ${SOURCES})
  # Extract the filename without the extension
  get_filename_component(filename_we ${source_file} NAME_WE)

  # Create an executable for each source file
  add_executable(standalone_${filename_we} ${source_file})

  # If additional libraries are needed, you can link them like so:
  target_link_libraries(standalone_${filename_we} 
      PUBLIC MLIB23::Logging
  )
endforeach()
