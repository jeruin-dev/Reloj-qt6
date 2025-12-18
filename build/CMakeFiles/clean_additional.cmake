# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "CMakeFiles/appReloj_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/appReloj_autogen.dir/ParseCache.txt"
  "appReloj_autogen"
  )
endif()
