# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspaces/CS225-Final-project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/CS225-Final-project/build

# Include any dependencies generated for this target.
include src/CMakeFiles/src.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/src.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/src.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/src.dir/flags.make

src/CMakeFiles/src.dir/Airport.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/Airport.cpp.o: ../src/Airport.cpp
src/CMakeFiles/src.dir/Airport.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/CS225-Final-project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/src.dir/Airport.cpp.o"
	cd /workspaces/CS225-Final-project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/Airport.cpp.o -MF CMakeFiles/src.dir/Airport.cpp.o.d -o CMakeFiles/src.dir/Airport.cpp.o -c /workspaces/CS225-Final-project/src/Airport.cpp

src/CMakeFiles/src.dir/Airport.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/Airport.cpp.i"
	cd /workspaces/CS225-Final-project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/CS225-Final-project/src/Airport.cpp > CMakeFiles/src.dir/Airport.cpp.i

src/CMakeFiles/src.dir/Airport.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/Airport.cpp.s"
	cd /workspaces/CS225-Final-project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/CS225-Final-project/src/Airport.cpp -o CMakeFiles/src.dir/Airport.cpp.s

src/CMakeFiles/src.dir/BFS.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/BFS.cpp.o: ../src/BFS.cpp
src/CMakeFiles/src.dir/BFS.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/CS225-Final-project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/src.dir/BFS.cpp.o"
	cd /workspaces/CS225-Final-project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/BFS.cpp.o -MF CMakeFiles/src.dir/BFS.cpp.o.d -o CMakeFiles/src.dir/BFS.cpp.o -c /workspaces/CS225-Final-project/src/BFS.cpp

src/CMakeFiles/src.dir/BFS.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/BFS.cpp.i"
	cd /workspaces/CS225-Final-project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/CS225-Final-project/src/BFS.cpp > CMakeFiles/src.dir/BFS.cpp.i

src/CMakeFiles/src.dir/BFS.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/BFS.cpp.s"
	cd /workspaces/CS225-Final-project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/CS225-Final-project/src/BFS.cpp -o CMakeFiles/src.dir/BFS.cpp.s

src/CMakeFiles/src.dir/Dijkstra.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/Dijkstra.cpp.o: ../src/Dijkstra.cpp
src/CMakeFiles/src.dir/Dijkstra.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/CS225-Final-project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/src.dir/Dijkstra.cpp.o"
	cd /workspaces/CS225-Final-project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/Dijkstra.cpp.o -MF CMakeFiles/src.dir/Dijkstra.cpp.o.d -o CMakeFiles/src.dir/Dijkstra.cpp.o -c /workspaces/CS225-Final-project/src/Dijkstra.cpp

src/CMakeFiles/src.dir/Dijkstra.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/Dijkstra.cpp.i"
	cd /workspaces/CS225-Final-project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/CS225-Final-project/src/Dijkstra.cpp > CMakeFiles/src.dir/Dijkstra.cpp.i

src/CMakeFiles/src.dir/Dijkstra.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/Dijkstra.cpp.s"
	cd /workspaces/CS225-Final-project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/CS225-Final-project/src/Dijkstra.cpp -o CMakeFiles/src.dir/Dijkstra.cpp.s

src/CMakeFiles/src.dir/Edge.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/Edge.cpp.o: ../src/Edge.cpp
src/CMakeFiles/src.dir/Edge.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/CS225-Final-project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/src.dir/Edge.cpp.o"
	cd /workspaces/CS225-Final-project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/Edge.cpp.o -MF CMakeFiles/src.dir/Edge.cpp.o.d -o CMakeFiles/src.dir/Edge.cpp.o -c /workspaces/CS225-Final-project/src/Edge.cpp

src/CMakeFiles/src.dir/Edge.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/Edge.cpp.i"
	cd /workspaces/CS225-Final-project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/CS225-Final-project/src/Edge.cpp > CMakeFiles/src.dir/Edge.cpp.i

src/CMakeFiles/src.dir/Edge.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/Edge.cpp.s"
	cd /workspaces/CS225-Final-project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/CS225-Final-project/src/Edge.cpp -o CMakeFiles/src.dir/Edge.cpp.s

src/CMakeFiles/src.dir/Graph.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/Graph.cpp.o: ../src/Graph.cpp
src/CMakeFiles/src.dir/Graph.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/CS225-Final-project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/src.dir/Graph.cpp.o"
	cd /workspaces/CS225-Final-project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/Graph.cpp.o -MF CMakeFiles/src.dir/Graph.cpp.o.d -o CMakeFiles/src.dir/Graph.cpp.o -c /workspaces/CS225-Final-project/src/Graph.cpp

src/CMakeFiles/src.dir/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/Graph.cpp.i"
	cd /workspaces/CS225-Final-project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/CS225-Final-project/src/Graph.cpp > CMakeFiles/src.dir/Graph.cpp.i

src/CMakeFiles/src.dir/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/Graph.cpp.s"
	cd /workspaces/CS225-Final-project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/CS225-Final-project/src/Graph.cpp -o CMakeFiles/src.dir/Graph.cpp.s

src/CMakeFiles/src.dir/Route.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/Route.cpp.o: ../src/Route.cpp
src/CMakeFiles/src.dir/Route.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/CS225-Final-project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/src.dir/Route.cpp.o"
	cd /workspaces/CS225-Final-project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/Route.cpp.o -MF CMakeFiles/src.dir/Route.cpp.o.d -o CMakeFiles/src.dir/Route.cpp.o -c /workspaces/CS225-Final-project/src/Route.cpp

src/CMakeFiles/src.dir/Route.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/Route.cpp.i"
	cd /workspaces/CS225-Final-project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/CS225-Final-project/src/Route.cpp > CMakeFiles/src.dir/Route.cpp.i

src/CMakeFiles/src.dir/Route.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/Route.cpp.s"
	cd /workspaces/CS225-Final-project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/CS225-Final-project/src/Route.cpp -o CMakeFiles/src.dir/Route.cpp.s

# Object files for target src
src_OBJECTS = \
"CMakeFiles/src.dir/Airport.cpp.o" \
"CMakeFiles/src.dir/BFS.cpp.o" \
"CMakeFiles/src.dir/Dijkstra.cpp.o" \
"CMakeFiles/src.dir/Edge.cpp.o" \
"CMakeFiles/src.dir/Graph.cpp.o" \
"CMakeFiles/src.dir/Route.cpp.o"

# External object files for target src
src_EXTERNAL_OBJECTS =

src/libsrc.a: src/CMakeFiles/src.dir/Airport.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/BFS.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/Dijkstra.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/Edge.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/Graph.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/Route.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/build.make
src/libsrc.a: src/CMakeFiles/src.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/CS225-Final-project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library libsrc.a"
	cd /workspaces/CS225-Final-project/build/src && $(CMAKE_COMMAND) -P CMakeFiles/src.dir/cmake_clean_target.cmake
	cd /workspaces/CS225-Final-project/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/src.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/src.dir/build: src/libsrc.a
.PHONY : src/CMakeFiles/src.dir/build

src/CMakeFiles/src.dir/clean:
	cd /workspaces/CS225-Final-project/build/src && $(CMAKE_COMMAND) -P CMakeFiles/src.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/src.dir/clean

src/CMakeFiles/src.dir/depend:
	cd /workspaces/CS225-Final-project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/CS225-Final-project /workspaces/CS225-Final-project/src /workspaces/CS225-Final-project/build /workspaces/CS225-Final-project/build/src /workspaces/CS225-Final-project/build/src/CMakeFiles/src.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/src.dir/depend

