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
CMAKE_SOURCE_DIR = "/mnt/c/Users/hecto/Documents/Archives/GitHub Archive/Project-Eidos"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/hecto/Documents/Archives/GitHub Archive/Project-Eidos/build"

# Include any dependencies generated for this target.
include CMakeFiles/Project-Eidos.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Project-Eidos.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Project-Eidos.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Project-Eidos.dir/flags.make

CMakeFiles/Project-Eidos.dir/main.cc.o: CMakeFiles/Project-Eidos.dir/flags.make
CMakeFiles/Project-Eidos.dir/main.cc.o: ../main.cc
CMakeFiles/Project-Eidos.dir/main.cc.o: CMakeFiles/Project-Eidos.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/hecto/Documents/Archives/GitHub Archive/Project-Eidos/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Project-Eidos.dir/main.cc.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project-Eidos.dir/main.cc.o -MF CMakeFiles/Project-Eidos.dir/main.cc.o.d -o CMakeFiles/Project-Eidos.dir/main.cc.o -c "/mnt/c/Users/hecto/Documents/Archives/GitHub Archive/Project-Eidos/main.cc"

CMakeFiles/Project-Eidos.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project-Eidos.dir/main.cc.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/hecto/Documents/Archives/GitHub Archive/Project-Eidos/main.cc" > CMakeFiles/Project-Eidos.dir/main.cc.i

CMakeFiles/Project-Eidos.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project-Eidos.dir/main.cc.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/hecto/Documents/Archives/GitHub Archive/Project-Eidos/main.cc" -o CMakeFiles/Project-Eidos.dir/main.cc.s

# Object files for target Project-Eidos
Project__Eidos_OBJECTS = \
"CMakeFiles/Project-Eidos.dir/main.cc.o"

# External object files for target Project-Eidos
Project__Eidos_EXTERNAL_OBJECTS =

Project-Eidos: CMakeFiles/Project-Eidos.dir/main.cc.o
Project-Eidos: CMakeFiles/Project-Eidos.dir/build.make
Project-Eidos: src/graph/libgraph.a
Project-Eidos: CMakeFiles/Project-Eidos.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/hecto/Documents/Archives/GitHub Archive/Project-Eidos/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Project-Eidos"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Project-Eidos.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Project-Eidos.dir/build: Project-Eidos
.PHONY : CMakeFiles/Project-Eidos.dir/build

CMakeFiles/Project-Eidos.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Project-Eidos.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Project-Eidos.dir/clean

CMakeFiles/Project-Eidos.dir/depend:
	cd "/mnt/c/Users/hecto/Documents/Archives/GitHub Archive/Project-Eidos/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/hecto/Documents/Archives/GitHub Archive/Project-Eidos" "/mnt/c/Users/hecto/Documents/Archives/GitHub Archive/Project-Eidos" "/mnt/c/Users/hecto/Documents/Archives/GitHub Archive/Project-Eidos/build" "/mnt/c/Users/hecto/Documents/Archives/GitHub Archive/Project-Eidos/build" "/mnt/c/Users/hecto/Documents/Archives/GitHub Archive/Project-Eidos/build/CMakeFiles/Project-Eidos.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Project-Eidos.dir/depend

