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
CMAKE_SOURCE_DIR = /home/jovyan/final-project-yuri-alex

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jovyan/final-project-yuri-alex/build

# Include any dependencies generated for this target.
include CMakeFiles/run_app_1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/run_app_1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/run_app_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/run_app_1.dir/flags.make

CMakeFiles/run_app_1.dir/app_1/main_1.cpp.o: CMakeFiles/run_app_1.dir/flags.make
CMakeFiles/run_app_1.dir/app_1/main_1.cpp.o: ../app_1/main_1.cpp
CMakeFiles/run_app_1.dir/app_1/main_1.cpp.o: CMakeFiles/run_app_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jovyan/final-project-yuri-alex/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/run_app_1.dir/app_1/main_1.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/run_app_1.dir/app_1/main_1.cpp.o -MF CMakeFiles/run_app_1.dir/app_1/main_1.cpp.o.d -o CMakeFiles/run_app_1.dir/app_1/main_1.cpp.o -c /home/jovyan/final-project-yuri-alex/app_1/main_1.cpp

CMakeFiles/run_app_1.dir/app_1/main_1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_app_1.dir/app_1/main_1.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jovyan/final-project-yuri-alex/app_1/main_1.cpp > CMakeFiles/run_app_1.dir/app_1/main_1.cpp.i

CMakeFiles/run_app_1.dir/app_1/main_1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_app_1.dir/app_1/main_1.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jovyan/final-project-yuri-alex/app_1/main_1.cpp -o CMakeFiles/run_app_1.dir/app_1/main_1.cpp.s

CMakeFiles/run_app_1.dir/code_1/hash.cpp.o: CMakeFiles/run_app_1.dir/flags.make
CMakeFiles/run_app_1.dir/code_1/hash.cpp.o: ../code_1/hash.cpp
CMakeFiles/run_app_1.dir/code_1/hash.cpp.o: CMakeFiles/run_app_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jovyan/final-project-yuri-alex/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/run_app_1.dir/code_1/hash.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/run_app_1.dir/code_1/hash.cpp.o -MF CMakeFiles/run_app_1.dir/code_1/hash.cpp.o.d -o CMakeFiles/run_app_1.dir/code_1/hash.cpp.o -c /home/jovyan/final-project-yuri-alex/code_1/hash.cpp

CMakeFiles/run_app_1.dir/code_1/hash.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_app_1.dir/code_1/hash.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jovyan/final-project-yuri-alex/code_1/hash.cpp > CMakeFiles/run_app_1.dir/code_1/hash.cpp.i

CMakeFiles/run_app_1.dir/code_1/hash.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_app_1.dir/code_1/hash.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jovyan/final-project-yuri-alex/code_1/hash.cpp -o CMakeFiles/run_app_1.dir/code_1/hash.cpp.s

CMakeFiles/run_app_1.dir/code_1/miniGit.cpp.o: CMakeFiles/run_app_1.dir/flags.make
CMakeFiles/run_app_1.dir/code_1/miniGit.cpp.o: ../code_1/miniGit.cpp
CMakeFiles/run_app_1.dir/code_1/miniGit.cpp.o: CMakeFiles/run_app_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jovyan/final-project-yuri-alex/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/run_app_1.dir/code_1/miniGit.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/run_app_1.dir/code_1/miniGit.cpp.o -MF CMakeFiles/run_app_1.dir/code_1/miniGit.cpp.o.d -o CMakeFiles/run_app_1.dir/code_1/miniGit.cpp.o -c /home/jovyan/final-project-yuri-alex/code_1/miniGit.cpp

CMakeFiles/run_app_1.dir/code_1/miniGit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_app_1.dir/code_1/miniGit.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jovyan/final-project-yuri-alex/code_1/miniGit.cpp > CMakeFiles/run_app_1.dir/code_1/miniGit.cpp.i

CMakeFiles/run_app_1.dir/code_1/miniGit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_app_1.dir/code_1/miniGit.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jovyan/final-project-yuri-alex/code_1/miniGit.cpp -o CMakeFiles/run_app_1.dir/code_1/miniGit.cpp.s

# Object files for target run_app_1
run_app_1_OBJECTS = \
"CMakeFiles/run_app_1.dir/app_1/main_1.cpp.o" \
"CMakeFiles/run_app_1.dir/code_1/hash.cpp.o" \
"CMakeFiles/run_app_1.dir/code_1/miniGit.cpp.o"

# External object files for target run_app_1
run_app_1_EXTERNAL_OBJECTS =

run_app_1: CMakeFiles/run_app_1.dir/app_1/main_1.cpp.o
run_app_1: CMakeFiles/run_app_1.dir/code_1/hash.cpp.o
run_app_1: CMakeFiles/run_app_1.dir/code_1/miniGit.cpp.o
run_app_1: CMakeFiles/run_app_1.dir/build.make
run_app_1: CMakeFiles/run_app_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jovyan/final-project-yuri-alex/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable run_app_1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/run_app_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/run_app_1.dir/build: run_app_1
.PHONY : CMakeFiles/run_app_1.dir/build

CMakeFiles/run_app_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/run_app_1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/run_app_1.dir/clean

CMakeFiles/run_app_1.dir/depend:
	cd /home/jovyan/final-project-yuri-alex/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jovyan/final-project-yuri-alex /home/jovyan/final-project-yuri-alex /home/jovyan/final-project-yuri-alex/build /home/jovyan/final-project-yuri-alex/build /home/jovyan/final-project-yuri-alex/build/CMakeFiles/run_app_1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/run_app_1.dir/depend

