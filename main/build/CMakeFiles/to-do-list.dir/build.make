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
CMAKE_SOURCE_DIR = /home/mahmoud/To-Do/main

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mahmoud/To-Do/main/build

# Include any dependencies generated for this target.
include CMakeFiles/to-do-list.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/to-do-list.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/to-do-list.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/to-do-list.dir/flags.make

to-do-list_autogen/YVFBJBHUOL/qrc_qml.cpp: /home/mahmoud/To-Do/GUI/src/qml/qml.qrc
to-do-list_autogen/YVFBJBHUOL/qrc_qml.cpp: CMakeFiles/to-do-list_autogen.dir/AutoRcc_qml_YVFBJBHUOL_Info.json
to-do-list_autogen/YVFBJBHUOL/qrc_qml.cpp: /home/mahmoud/To-Do/GUI/src/qml/main.qml
to-do-list_autogen/YVFBJBHUOL/qrc_qml.cpp: /home/mahmoud/To-Do/GUI/src/qml/TaskInput/TaskInput.qml
to-do-list_autogen/YVFBJBHUOL/qrc_qml.cpp: /home/mahmoud/To-Do/GUI/src/qml/CheckBox/CheckBox.qml
to-do-list_autogen/YVFBJBHUOL/qrc_qml.cpp: /home/mahmoud/To-Do/GUI/src/qml/Button/AddButton.qml
to-do-list_autogen/YVFBJBHUOL/qrc_qml.cpp: /home/mahmoud/To-Do/GUI/src/assests/images/tick.png
to-do-list_autogen/YVFBJBHUOL/qrc_qml.cpp: /home/mahmoud/To-Do/GUI/src/assests/images/approve.png
to-do-list_autogen/YVFBJBHUOL/qrc_qml.cpp: /home/mahmoud/To-Do/GUI/src/assests/images/add.png
to-do-list_autogen/YVFBJBHUOL/qrc_qml.cpp: /home/mahmoud/To-Do/GUI/src/assests/images/arrow-down.png
to-do-list_autogen/YVFBJBHUOL/qrc_qml.cpp: /home/mahmoud/To-Do/GUI/src/assests/images/arrow-up.png
to-do-list_autogen/YVFBJBHUOL/qrc_qml.cpp: /usr/lib/qt5/bin/rcc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/mahmoud/To-Do/main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic RCC for ../GUI/src/qml/qml.qrc"
	/usr/bin/cmake -E cmake_autorcc /home/mahmoud/To-Do/main/build/CMakeFiles/to-do-list_autogen.dir/AutoRcc_qml_YVFBJBHUOL_Info.json 

CMakeFiles/to-do-list.dir/to-do-list_autogen/mocs_compilation.cpp.o: CMakeFiles/to-do-list.dir/flags.make
CMakeFiles/to-do-list.dir/to-do-list_autogen/mocs_compilation.cpp.o: to-do-list_autogen/mocs_compilation.cpp
CMakeFiles/to-do-list.dir/to-do-list_autogen/mocs_compilation.cpp.o: CMakeFiles/to-do-list.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mahmoud/To-Do/main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/to-do-list.dir/to-do-list_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/to-do-list.dir/to-do-list_autogen/mocs_compilation.cpp.o -MF CMakeFiles/to-do-list.dir/to-do-list_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/to-do-list.dir/to-do-list_autogen/mocs_compilation.cpp.o -c /home/mahmoud/To-Do/main/build/to-do-list_autogen/mocs_compilation.cpp

CMakeFiles/to-do-list.dir/to-do-list_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/to-do-list.dir/to-do-list_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mahmoud/To-Do/main/build/to-do-list_autogen/mocs_compilation.cpp > CMakeFiles/to-do-list.dir/to-do-list_autogen/mocs_compilation.cpp.i

CMakeFiles/to-do-list.dir/to-do-list_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/to-do-list.dir/to-do-list_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mahmoud/To-Do/main/build/to-do-list_autogen/mocs_compilation.cpp -o CMakeFiles/to-do-list.dir/to-do-list_autogen/mocs_compilation.cpp.s

CMakeFiles/to-do-list.dir/main.cpp.o: CMakeFiles/to-do-list.dir/flags.make
CMakeFiles/to-do-list.dir/main.cpp.o: ../main.cpp
CMakeFiles/to-do-list.dir/main.cpp.o: CMakeFiles/to-do-list.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mahmoud/To-Do/main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/to-do-list.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/to-do-list.dir/main.cpp.o -MF CMakeFiles/to-do-list.dir/main.cpp.o.d -o CMakeFiles/to-do-list.dir/main.cpp.o -c /home/mahmoud/To-Do/main/main.cpp

CMakeFiles/to-do-list.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/to-do-list.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mahmoud/To-Do/main/main.cpp > CMakeFiles/to-do-list.dir/main.cpp.i

CMakeFiles/to-do-list.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/to-do-list.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mahmoud/To-Do/main/main.cpp -o CMakeFiles/to-do-list.dir/main.cpp.s

CMakeFiles/to-do-list.dir/to-do-list_autogen/YVFBJBHUOL/qrc_qml.cpp.o: CMakeFiles/to-do-list.dir/flags.make
CMakeFiles/to-do-list.dir/to-do-list_autogen/YVFBJBHUOL/qrc_qml.cpp.o: to-do-list_autogen/YVFBJBHUOL/qrc_qml.cpp
CMakeFiles/to-do-list.dir/to-do-list_autogen/YVFBJBHUOL/qrc_qml.cpp.o: CMakeFiles/to-do-list.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mahmoud/To-Do/main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/to-do-list.dir/to-do-list_autogen/YVFBJBHUOL/qrc_qml.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/to-do-list.dir/to-do-list_autogen/YVFBJBHUOL/qrc_qml.cpp.o -MF CMakeFiles/to-do-list.dir/to-do-list_autogen/YVFBJBHUOL/qrc_qml.cpp.o.d -o CMakeFiles/to-do-list.dir/to-do-list_autogen/YVFBJBHUOL/qrc_qml.cpp.o -c /home/mahmoud/To-Do/main/build/to-do-list_autogen/YVFBJBHUOL/qrc_qml.cpp

CMakeFiles/to-do-list.dir/to-do-list_autogen/YVFBJBHUOL/qrc_qml.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/to-do-list.dir/to-do-list_autogen/YVFBJBHUOL/qrc_qml.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mahmoud/To-Do/main/build/to-do-list_autogen/YVFBJBHUOL/qrc_qml.cpp > CMakeFiles/to-do-list.dir/to-do-list_autogen/YVFBJBHUOL/qrc_qml.cpp.i

CMakeFiles/to-do-list.dir/to-do-list_autogen/YVFBJBHUOL/qrc_qml.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/to-do-list.dir/to-do-list_autogen/YVFBJBHUOL/qrc_qml.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mahmoud/To-Do/main/build/to-do-list_autogen/YVFBJBHUOL/qrc_qml.cpp -o CMakeFiles/to-do-list.dir/to-do-list_autogen/YVFBJBHUOL/qrc_qml.cpp.s

# Object files for target to-do-list
to__do__list_OBJECTS = \
"CMakeFiles/to-do-list.dir/to-do-list_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/to-do-list.dir/main.cpp.o" \
"CMakeFiles/to-do-list.dir/to-do-list_autogen/YVFBJBHUOL/qrc_qml.cpp.o"

# External object files for target to-do-list
to__do__list_EXTERNAL_OBJECTS =

to-do-list: CMakeFiles/to-do-list.dir/to-do-list_autogen/mocs_compilation.cpp.o
to-do-list: CMakeFiles/to-do-list.dir/main.cpp.o
to-do-list: CMakeFiles/to-do-list.dir/to-do-list_autogen/YVFBJBHUOL/qrc_qml.cpp.o
to-do-list: CMakeFiles/to-do-list.dir/build.make
to-do-list: /usr/lib/x86_64-linux-gnu/libQt5Quick.so.5.15.3
to-do-list: /usr/lib/x86_64-linux-gnu/libQt5QmlModels.so.5.15.3
to-do-list: /usr/lib/x86_64-linux-gnu/libQt5Qml.so.5.15.3
to-do-list: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.3
to-do-list: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.3
to-do-list: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.3
to-do-list: CMakeFiles/to-do-list.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mahmoud/To-Do/main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable to-do-list"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/to-do-list.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/to-do-list.dir/build: to-do-list
.PHONY : CMakeFiles/to-do-list.dir/build

CMakeFiles/to-do-list.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/to-do-list.dir/cmake_clean.cmake
.PHONY : CMakeFiles/to-do-list.dir/clean

CMakeFiles/to-do-list.dir/depend: to-do-list_autogen/YVFBJBHUOL/qrc_qml.cpp
	cd /home/mahmoud/To-Do/main/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mahmoud/To-Do/main /home/mahmoud/To-Do/main /home/mahmoud/To-Do/main/build /home/mahmoud/To-Do/main/build /home/mahmoud/To-Do/main/build/CMakeFiles/to-do-list.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/to-do-list.dir/depend

