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
CMAKE_COMMAND = /home/darek/install/clion-2018.2.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/darek/install/clion-2018.2.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/darek/dane/Nextcloud/Studia/statystyka/projekt/program

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/darek/dane/Nextcloud/Studia/statystyka/projekt/program/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test.dir/flags.make

CMakeFiles/test.dir/market_analysis_tools.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/market_analysis_tools.cpp.o: ../market_analysis_tools.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/darek/dane/Nextcloud/Studia/statystyka/projekt/program/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test.dir/market_analysis_tools.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/market_analysis_tools.cpp.o -c /home/darek/dane/Nextcloud/Studia/statystyka/projekt/program/market_analysis_tools.cpp

CMakeFiles/test.dir/market_analysis_tools.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/market_analysis_tools.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/darek/dane/Nextcloud/Studia/statystyka/projekt/program/market_analysis_tools.cpp > CMakeFiles/test.dir/market_analysis_tools.cpp.i

CMakeFiles/test.dir/market_analysis_tools.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/market_analysis_tools.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/darek/dane/Nextcloud/Studia/statystyka/projekt/program/market_analysis_tools.cpp -o CMakeFiles/test.dir/market_analysis_tools.cpp.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/market_analysis_tools.cpp.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

test: CMakeFiles/test.dir/market_analysis_tools.cpp.o
test: CMakeFiles/test.dir/build.make
test: /usr/lib/x86_64-linux-gnu/libsqlite3.so
test: CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/darek/dane/Nextcloud/Studia/statystyka/projekt/program/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test.dir/build: test

.PHONY : CMakeFiles/test.dir/build

CMakeFiles/test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test.dir/clean

CMakeFiles/test.dir/depend:
	cd /home/darek/dane/Nextcloud/Studia/statystyka/projekt/program/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/darek/dane/Nextcloud/Studia/statystyka/projekt/program /home/darek/dane/Nextcloud/Studia/statystyka/projekt/program /home/darek/dane/Nextcloud/Studia/statystyka/projekt/program/cmake-build-debug /home/darek/dane/Nextcloud/Studia/statystyka/projekt/program/cmake-build-debug /home/darek/dane/Nextcloud/Studia/statystyka/projekt/program/cmake-build-debug/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test.dir/depend

