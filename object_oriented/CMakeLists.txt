# Add the 'include/' directory to the include path
include_directories(include)

# Get a list of all source files in the 'src/' directory
file(GLOB SOURCES "src/*.c*")

# Loop over each source file
foreach(source_file ${SOURCES})
  # Extract the filename without the extension
  get_filename_component(filename_we ${source_file} NAME_WE)

  # Create an executable for each source file
  add_executable(standalone_${filename_we} ${source_file})

  # If additional libraries are needed, you can link them like so:
  target_link_libraries(standalone_${filename_we} 
      PUBLIC c_lib::logging
  )
endforeach()
