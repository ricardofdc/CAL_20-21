# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.5\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\ricar\Desktop\FEUP\2ano\2sem\cal\Projeto

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\ricar\Desktop\FEUP\2ano\2sem\cal\Projeto\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Project.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Project.dir/flags.make

CMakeFiles/Project.dir/src/main.cpp.obj: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/src/main.cpp.obj: CMakeFiles/Project.dir/includes_CXX.rsp
CMakeFiles/Project.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ricar\Desktop\FEUP\2ano\2sem\cal\Projeto\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Project.dir/src/main.cpp.obj"
	C:\MinGW64\x86_64-7.3.0-posix-seh-rt_v5-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Project.dir\src\main.cpp.obj -c C:\Users\ricar\Desktop\FEUP\2ano\2sem\cal\Projeto\src\main.cpp

CMakeFiles/Project.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/src/main.cpp.i"
	C:\MinGW64\x86_64-7.3.0-posix-seh-rt_v5-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ricar\Desktop\FEUP\2ano\2sem\cal\Projeto\src\main.cpp > CMakeFiles\Project.dir\src\main.cpp.i

CMakeFiles/Project.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/src/main.cpp.s"
	C:\MinGW64\x86_64-7.3.0-posix-seh-rt_v5-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ricar\Desktop\FEUP\2ano\2sem\cal\Projeto\src\main.cpp -o CMakeFiles\Project.dir\src\main.cpp.s

# Object files for target Project
Project_OBJECTS = \
"CMakeFiles/Project.dir/src/main.cpp.obj"

# External object files for target Project
Project_EXTERNAL_OBJECTS =

Project.exe: CMakeFiles/Project.dir/src/main.cpp.obj
Project.exe: CMakeFiles/Project.dir/build.make
Project.exe: ../lib/GraphViewerCpp/lib/libgraphviewer.a
Project.exe: lib/GraphViewerCpp/SFML/lib/libsfml-graphics-d.a
Project.exe: lib/GraphViewerCpp/SFML/lib/libsfml-window-d.a
Project.exe: lib/GraphViewerCpp/SFML/lib/libsfml-system-d.a
Project.exe: CMakeFiles/Project.dir/linklibs.rsp
Project.exe: CMakeFiles/Project.dir/objects1.rsp
Project.exe: CMakeFiles/Project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\ricar\Desktop\FEUP\2ano\2sem\cal\Projeto\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Project.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Project.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Project.dir/build: Project.exe

.PHONY : CMakeFiles/Project.dir/build

CMakeFiles/Project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Project.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Project.dir/clean

CMakeFiles/Project.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\ricar\Desktop\FEUP\2ano\2sem\cal\Projeto C:\Users\ricar\Desktop\FEUP\2ano\2sem\cal\Projeto C:\Users\ricar\Desktop\FEUP\2ano\2sem\cal\Projeto\cmake-build-debug C:\Users\ricar\Desktop\FEUP\2ano\2sem\cal\Projeto\cmake-build-debug C:\Users\ricar\Desktop\FEUP\2ano\2sem\cal\Projeto\cmake-build-debug\CMakeFiles\Project.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Project.dir/depend

