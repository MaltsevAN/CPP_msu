# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/alexmal/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/182.5107.21/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/alexmal/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/182.5107.21/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alexmal/Documents/MSU/Kanovodov_cpp/CPP_msu/Task_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alexmal/Documents/MSU/Kanovodov_cpp/CPP_msu/Task_1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Task_1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Task_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Task_1.dir/flags.make

CMakeFiles/Task_1.dir/main.cpp.o: CMakeFiles/Task_1.dir/flags.make
CMakeFiles/Task_1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexmal/Documents/MSU/Kanovodov_cpp/CPP_msu/Task_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Task_1.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Task_1.dir/main.cpp.o -c /home/alexmal/Documents/MSU/Kanovodov_cpp/CPP_msu/Task_1/main.cpp

CMakeFiles/Task_1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Task_1.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexmal/Documents/MSU/Kanovodov_cpp/CPP_msu/Task_1/main.cpp > CMakeFiles/Task_1.dir/main.cpp.i

CMakeFiles/Task_1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Task_1.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexmal/Documents/MSU/Kanovodov_cpp/CPP_msu/Task_1/main.cpp -o CMakeFiles/Task_1.dir/main.cpp.s

# Object files for target Task_1
Task_1_OBJECTS = \
"CMakeFiles/Task_1.dir/main.cpp.o"

# External object files for target Task_1
Task_1_EXTERNAL_OBJECTS =

Task_1: CMakeFiles/Task_1.dir/main.cpp.o
Task_1: CMakeFiles/Task_1.dir/build.make
Task_1: CMakeFiles/Task_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alexmal/Documents/MSU/Kanovodov_cpp/CPP_msu/Task_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Task_1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Task_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Task_1.dir/build: Task_1

.PHONY : CMakeFiles/Task_1.dir/build

CMakeFiles/Task_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Task_1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Task_1.dir/clean

CMakeFiles/Task_1.dir/depend:
	cd /home/alexmal/Documents/MSU/Kanovodov_cpp/CPP_msu/Task_1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alexmal/Documents/MSU/Kanovodov_cpp/CPP_msu/Task_1 /home/alexmal/Documents/MSU/Kanovodov_cpp/CPP_msu/Task_1 /home/alexmal/Documents/MSU/Kanovodov_cpp/CPP_msu/Task_1/cmake-build-debug /home/alexmal/Documents/MSU/Kanovodov_cpp/CPP_msu/Task_1/cmake-build-debug /home/alexmal/Documents/MSU/Kanovodov_cpp/CPP_msu/Task_1/cmake-build-debug/CMakeFiles/Task_1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Task_1.dir/depend

