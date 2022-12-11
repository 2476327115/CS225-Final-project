# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.22
cmake_policy(SET CMP0009 NEW)

# cs225_sources at lib/CMakeLists.txt:12 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/CS225-Final-project/lib/cs225/*.cpp")
set(OLD_GLOB
  "/workspaces/CS225-Final-project/lib/cs225/HSLAPixel.cpp"
  "/workspaces/CS225-Final-project/lib/cs225/PNG.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/CS225-Final-project/build/CMakeFiles/cmake.verify_globs")
endif()

# lodepng_sources at lib/CMakeLists.txt:6 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/CS225-Final-project/lib/lodepng/*.cpp")
set(OLD_GLOB
  "/workspaces/CS225-Final-project/lib/lodepng/lodepng.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/CS225-Final-project/build/CMakeFiles/cmake.verify_globs")
endif()

# lodepng_sources at lib/CMakeLists.txt:6 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/CS225-Final-project/lib/lodepng/*.h")
set(OLD_GLOB
  "/workspaces/CS225-Final-project/lib/lodepng/lodepng.h"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/CS225-Final-project/build/CMakeFiles/cmake.verify_globs")
endif()

# src_sources at src/CMakeLists.txt:5 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/CS225-Final-project/src/*.cpp")
set(OLD_GLOB
  "/workspaces/CS225-Final-project/src/Airport.cpp"
  "/workspaces/CS225-Final-project/src/BFS.cpp"
  "/workspaces/CS225-Final-project/src/Dijkstra.cpp"
  "/workspaces/CS225-Final-project/src/Edge.cpp"
  "/workspaces/CS225-Final-project/src/Graph.cpp"
  "/workspaces/CS225-Final-project/src/PageRank.cpp"
  "/workspaces/CS225-Final-project/src/Route.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/CS225-Final-project/build/CMakeFiles/cmake.verify_globs")
endif()

# tests_src at CMakeLists.txt:130 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/CS225-Final-project/tests/*.cpp")
set(OLD_GLOB
  "/workspaces/CS225-Final-project/tests/test.cpp"
  "/workspaces/CS225-Final-project/tests/tests.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/CS225-Final-project/build/CMakeFiles/cmake.verify_globs")
endif()
