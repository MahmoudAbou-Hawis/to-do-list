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
CMAKE_SOURCE_DIR = /home/mahmoud/Documents/to-do-list/curl-wrapper/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mahmoud/Documents/to-do-list/curl-wrapper/test/build

# Include any dependencies generated for this target.
include CMakeFiles/URIBuilderTest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/URIBuilderTest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/URIBuilderTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/URIBuilderTest.dir/flags.make

CMakeFiles/URIBuilderTest.dir/uribuildertest.cpp.o: CMakeFiles/URIBuilderTest.dir/flags.make
CMakeFiles/URIBuilderTest.dir/uribuildertest.cpp.o: ../uribuildertest.cpp
CMakeFiles/URIBuilderTest.dir/uribuildertest.cpp.o: CMakeFiles/URIBuilderTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mahmoud/Documents/to-do-list/curl-wrapper/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/URIBuilderTest.dir/uribuildertest.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/URIBuilderTest.dir/uribuildertest.cpp.o -MF CMakeFiles/URIBuilderTest.dir/uribuildertest.cpp.o.d -o CMakeFiles/URIBuilderTest.dir/uribuildertest.cpp.o -c /home/mahmoud/Documents/to-do-list/curl-wrapper/test/uribuildertest.cpp

CMakeFiles/URIBuilderTest.dir/uribuildertest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/URIBuilderTest.dir/uribuildertest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mahmoud/Documents/to-do-list/curl-wrapper/test/uribuildertest.cpp > CMakeFiles/URIBuilderTest.dir/uribuildertest.cpp.i

CMakeFiles/URIBuilderTest.dir/uribuildertest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/URIBuilderTest.dir/uribuildertest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mahmoud/Documents/to-do-list/curl-wrapper/test/uribuildertest.cpp -o CMakeFiles/URIBuilderTest.dir/uribuildertest.cpp.s

CMakeFiles/URIBuilderTest.dir/home/mahmoud/Documents/to-do-list/curl-wrapper/src/uri.cpp.o: CMakeFiles/URIBuilderTest.dir/flags.make
CMakeFiles/URIBuilderTest.dir/home/mahmoud/Documents/to-do-list/curl-wrapper/src/uri.cpp.o: /home/mahmoud/Documents/to-do-list/curl-wrapper/src/uri.cpp
CMakeFiles/URIBuilderTest.dir/home/mahmoud/Documents/to-do-list/curl-wrapper/src/uri.cpp.o: CMakeFiles/URIBuilderTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mahmoud/Documents/to-do-list/curl-wrapper/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/URIBuilderTest.dir/home/mahmoud/Documents/to-do-list/curl-wrapper/src/uri.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/URIBuilderTest.dir/home/mahmoud/Documents/to-do-list/curl-wrapper/src/uri.cpp.o -MF CMakeFiles/URIBuilderTest.dir/home/mahmoud/Documents/to-do-list/curl-wrapper/src/uri.cpp.o.d -o CMakeFiles/URIBuilderTest.dir/home/mahmoud/Documents/to-do-list/curl-wrapper/src/uri.cpp.o -c /home/mahmoud/Documents/to-do-list/curl-wrapper/src/uri.cpp

CMakeFiles/URIBuilderTest.dir/home/mahmoud/Documents/to-do-list/curl-wrapper/src/uri.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/URIBuilderTest.dir/home/mahmoud/Documents/to-do-list/curl-wrapper/src/uri.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mahmoud/Documents/to-do-list/curl-wrapper/src/uri.cpp > CMakeFiles/URIBuilderTest.dir/home/mahmoud/Documents/to-do-list/curl-wrapper/src/uri.cpp.i

CMakeFiles/URIBuilderTest.dir/home/mahmoud/Documents/to-do-list/curl-wrapper/src/uri.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/URIBuilderTest.dir/home/mahmoud/Documents/to-do-list/curl-wrapper/src/uri.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mahmoud/Documents/to-do-list/curl-wrapper/src/uri.cpp -o CMakeFiles/URIBuilderTest.dir/home/mahmoud/Documents/to-do-list/curl-wrapper/src/uri.cpp.s

CMakeFiles/URIBuilderTest.dir/home/mahmoud/Documents/to-do-list/curl-wrapper/src/uribuilder.cpp.o: CMakeFiles/URIBuilderTest.dir/flags.make
CMakeFiles/URIBuilderTest.dir/home/mahmoud/Documents/to-do-list/curl-wrapper/src/uribuilder.cpp.o: /home/mahmoud/Documents/to-do-list/curl-wrapper/src/uribuilder.cpp
CMakeFiles/URIBuilderTest.dir/home/mahmoud/Documents/to-do-list/curl-wrapper/src/uribuilder.cpp.o: CMakeFiles/URIBuilderTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mahmoud/Documents/to-do-list/curl-wrapper/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/URIBuilderTest.dir/home/mahmoud/Documents/to-do-list/curl-wrapper/src/uribuilder.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/URIBuilderTest.dir/home/mahmoud/Documents/to-do-list/curl-wrapper/src/uribuilder.cpp.o -MF CMakeFiles/URIBuilderTest.dir/home/mahmoud/Documents/to-do-list/curl-wrapper/src/uribuilder.cpp.o.d -o CMakeFiles/URIBuilderTest.dir/home/mahmoud/Documents/to-do-list/curl-wrapper/src/uribuilder.cpp.o -c /home/mahmoud/Documents/to-do-list/curl-wrapper/src/uribuilder.cpp

CMakeFiles/URIBuilderTest.dir/home/mahmoud/Documents/to-do-list/curl-wrapper/src/uribuilder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/URIBuilderTest.dir/home/mahmoud/Documents/to-do-list/curl-wrapper/src/uribuilder.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mahmoud/Documents/to-do-list/curl-wrapper/src/uribuilder.cpp > CMakeFiles/URIBuilderTest.dir/home/mahmoud/Documents/to-do-list/curl-wrapper/src/uribuilder.cpp.i

CMakeFiles/URIBuilderTest.dir/home/mahmoud/Documents/to-do-list/curl-wrapper/src/uribuilder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/URIBuilderTest.dir/home/mahmoud/Documents/to-do-list/curl-wrapper/src/uribuilder.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mahmoud/Documents/to-do-list/curl-wrapper/src/uribuilder.cpp -o CMakeFiles/URIBuilderTest.dir/home/mahmoud/Documents/to-do-list/curl-wrapper/src/uribuilder.cpp.s

# Object files for target URIBuilderTest
URIBuilderTest_OBJECTS = \
"CMakeFiles/URIBuilderTest.dir/uribuildertest.cpp.o" \
"CMakeFiles/URIBuilderTest.dir/home/mahmoud/Documents/to-do-list/curl-wrapper/src/uri.cpp.o" \
"CMakeFiles/URIBuilderTest.dir/home/mahmoud/Documents/to-do-list/curl-wrapper/src/uribuilder.cpp.o"

# External object files for target URIBuilderTest
URIBuilderTest_EXTERNAL_OBJECTS =

URIBuilderTest: CMakeFiles/URIBuilderTest.dir/uribuildertest.cpp.o
URIBuilderTest: CMakeFiles/URIBuilderTest.dir/home/mahmoud/Documents/to-do-list/curl-wrapper/src/uri.cpp.o
URIBuilderTest: CMakeFiles/URIBuilderTest.dir/home/mahmoud/Documents/to-do-list/curl-wrapper/src/uribuilder.cpp.o
URIBuilderTest: CMakeFiles/URIBuilderTest.dir/build.make
URIBuilderTest: /usr/lib/x86_64-linux-gnu/libcurl.so
URIBuilderTest: /usr/local/lib/libgtest_main.a
URIBuilderTest: /usr/local/lib/libgtest.a
URIBuilderTest: CMakeFiles/URIBuilderTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mahmoud/Documents/to-do-list/curl-wrapper/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable URIBuilderTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/URIBuilderTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/URIBuilderTest.dir/build: URIBuilderTest
.PHONY : CMakeFiles/URIBuilderTest.dir/build

CMakeFiles/URIBuilderTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/URIBuilderTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/URIBuilderTest.dir/clean

CMakeFiles/URIBuilderTest.dir/depend:
	cd /home/mahmoud/Documents/to-do-list/curl-wrapper/test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mahmoud/Documents/to-do-list/curl-wrapper/test /home/mahmoud/Documents/to-do-list/curl-wrapper/test /home/mahmoud/Documents/to-do-list/curl-wrapper/test/build /home/mahmoud/Documents/to-do-list/curl-wrapper/test/build /home/mahmoud/Documents/to-do-list/curl-wrapper/test/build/CMakeFiles/URIBuilderTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/URIBuilderTest.dir/depend

