# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.15.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.15.4/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/peiwvy/Desktop/C++/P5M1 Concurrency/02_Passing_Data_Between_Threads/03_Threads_vs_Tasks"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/peiwvy/Desktop/C++/P5M1 Concurrency/02_Passing_Data_Between_Threads/03_Threads_vs_Tasks/build"

# Include any dependencies generated for this target.
include CMakeFiles/example_1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/example_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/example_1.dir/flags.make

CMakeFiles/example_1.dir/example_1.cpp.o: CMakeFiles/example_1.dir/flags.make
CMakeFiles/example_1.dir/example_1.cpp.o: ../example_1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/peiwvy/Desktop/C++/P5M1 Concurrency/02_Passing_Data_Between_Threads/03_Threads_vs_Tasks/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/example_1.dir/example_1.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example_1.dir/example_1.cpp.o -c "/Users/peiwvy/Desktop/C++/P5M1 Concurrency/02_Passing_Data_Between_Threads/03_Threads_vs_Tasks/example_1.cpp"

CMakeFiles/example_1.dir/example_1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example_1.dir/example_1.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/peiwvy/Desktop/C++/P5M1 Concurrency/02_Passing_Data_Between_Threads/03_Threads_vs_Tasks/example_1.cpp" > CMakeFiles/example_1.dir/example_1.cpp.i

CMakeFiles/example_1.dir/example_1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example_1.dir/example_1.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/peiwvy/Desktop/C++/P5M1 Concurrency/02_Passing_Data_Between_Threads/03_Threads_vs_Tasks/example_1.cpp" -o CMakeFiles/example_1.dir/example_1.cpp.s

# Object files for target example_1
example_1_OBJECTS = \
"CMakeFiles/example_1.dir/example_1.cpp.o"

# External object files for target example_1
example_1_EXTERNAL_OBJECTS =

example_1: CMakeFiles/example_1.dir/example_1.cpp.o
example_1: CMakeFiles/example_1.dir/build.make
example_1: CMakeFiles/example_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/peiwvy/Desktop/C++/P5M1 Concurrency/02_Passing_Data_Between_Threads/03_Threads_vs_Tasks/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable example_1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/example_1.dir/build: example_1

.PHONY : CMakeFiles/example_1.dir/build

CMakeFiles/example_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/example_1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/example_1.dir/clean

CMakeFiles/example_1.dir/depend:
	cd "/Users/peiwvy/Desktop/C++/P5M1 Concurrency/02_Passing_Data_Between_Threads/03_Threads_vs_Tasks/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/peiwvy/Desktop/C++/P5M1 Concurrency/02_Passing_Data_Between_Threads/03_Threads_vs_Tasks" "/Users/peiwvy/Desktop/C++/P5M1 Concurrency/02_Passing_Data_Between_Threads/03_Threads_vs_Tasks" "/Users/peiwvy/Desktop/C++/P5M1 Concurrency/02_Passing_Data_Between_Threads/03_Threads_vs_Tasks/build" "/Users/peiwvy/Desktop/C++/P5M1 Concurrency/02_Passing_Data_Between_Threads/03_Threads_vs_Tasks/build" "/Users/peiwvy/Desktop/C++/P5M1 Concurrency/02_Passing_Data_Between_Threads/03_Threads_vs_Tasks/build/CMakeFiles/example_1.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/example_1.dir/depend

