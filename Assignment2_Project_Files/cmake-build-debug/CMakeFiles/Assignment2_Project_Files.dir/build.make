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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\pangk\Documents\School\2021_Spring\COMP10050-Software Engineering Project 1\Assignment2\UCDCOMP10050-Assignment_2\Assignment2_Project_Files"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\pangk\Documents\School\2021_Spring\COMP10050-Software Engineering Project 1\Assignment2\UCDCOMP10050-Assignment_2\Assignment2_Project_Files\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Assignment2_Project_Files.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Assignment2_Project_Files.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Assignment2_Project_Files.dir/flags.make

CMakeFiles/Assignment2_Project_Files.dir/main.c.obj: CMakeFiles/Assignment2_Project_Files.dir/flags.make
CMakeFiles/Assignment2_Project_Files.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\pangk\Documents\School\2021_Spring\COMP10050-Software Engineering Project 1\Assignment2\UCDCOMP10050-Assignment_2\Assignment2_Project_Files\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Assignment2_Project_Files.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Assignment2_Project_Files.dir\main.c.obj   -c "C:\Users\pangk\Documents\School\2021_Spring\COMP10050-Software Engineering Project 1\Assignment2\UCDCOMP10050-Assignment_2\Assignment2_Project_Files\main.c"

CMakeFiles/Assignment2_Project_Files.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assignment2_Project_Files.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\pangk\Documents\School\2021_Spring\COMP10050-Software Engineering Project 1\Assignment2\UCDCOMP10050-Assignment_2\Assignment2_Project_Files\main.c" > CMakeFiles\Assignment2_Project_Files.dir\main.c.i

CMakeFiles/Assignment2_Project_Files.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assignment2_Project_Files.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\pangk\Documents\School\2021_Spring\COMP10050-Software Engineering Project 1\Assignment2\UCDCOMP10050-Assignment_2\Assignment2_Project_Files\main.c" -o CMakeFiles\Assignment2_Project_Files.dir\main.c.s

CMakeFiles/Assignment2_Project_Files.dir/library.c.obj: CMakeFiles/Assignment2_Project_Files.dir/flags.make
CMakeFiles/Assignment2_Project_Files.dir/library.c.obj: ../library.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\pangk\Documents\School\2021_Spring\COMP10050-Software Engineering Project 1\Assignment2\UCDCOMP10050-Assignment_2\Assignment2_Project_Files\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Assignment2_Project_Files.dir/library.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Assignment2_Project_Files.dir\library.c.obj   -c "C:\Users\pangk\Documents\School\2021_Spring\COMP10050-Software Engineering Project 1\Assignment2\UCDCOMP10050-Assignment_2\Assignment2_Project_Files\library.c"

CMakeFiles/Assignment2_Project_Files.dir/library.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assignment2_Project_Files.dir/library.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\pangk\Documents\School\2021_Spring\COMP10050-Software Engineering Project 1\Assignment2\UCDCOMP10050-Assignment_2\Assignment2_Project_Files\library.c" > CMakeFiles\Assignment2_Project_Files.dir\library.c.i

CMakeFiles/Assignment2_Project_Files.dir/library.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assignment2_Project_Files.dir/library.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\pangk\Documents\School\2021_Spring\COMP10050-Software Engineering Project 1\Assignment2\UCDCOMP10050-Assignment_2\Assignment2_Project_Files\library.c" -o CMakeFiles\Assignment2_Project_Files.dir\library.c.s

# Object files for target Assignment2_Project_Files
Assignment2_Project_Files_OBJECTS = \
"CMakeFiles/Assignment2_Project_Files.dir/main.c.obj" \
"CMakeFiles/Assignment2_Project_Files.dir/library.c.obj"

# External object files for target Assignment2_Project_Files
Assignment2_Project_Files_EXTERNAL_OBJECTS =

Assignment2_Project_Files.exe: CMakeFiles/Assignment2_Project_Files.dir/main.c.obj
Assignment2_Project_Files.exe: CMakeFiles/Assignment2_Project_Files.dir/library.c.obj
Assignment2_Project_Files.exe: CMakeFiles/Assignment2_Project_Files.dir/build.make
Assignment2_Project_Files.exe: CMakeFiles/Assignment2_Project_Files.dir/linklibs.rsp
Assignment2_Project_Files.exe: CMakeFiles/Assignment2_Project_Files.dir/objects1.rsp
Assignment2_Project_Files.exe: CMakeFiles/Assignment2_Project_Files.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\pangk\Documents\School\2021_Spring\COMP10050-Software Engineering Project 1\Assignment2\UCDCOMP10050-Assignment_2\Assignment2_Project_Files\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Assignment2_Project_Files.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Assignment2_Project_Files.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Assignment2_Project_Files.dir/build: Assignment2_Project_Files.exe

.PHONY : CMakeFiles/Assignment2_Project_Files.dir/build

CMakeFiles/Assignment2_Project_Files.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Assignment2_Project_Files.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Assignment2_Project_Files.dir/clean

CMakeFiles/Assignment2_Project_Files.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\pangk\Documents\School\2021_Spring\COMP10050-Software Engineering Project 1\Assignment2\UCDCOMP10050-Assignment_2\Assignment2_Project_Files" "C:\Users\pangk\Documents\School\2021_Spring\COMP10050-Software Engineering Project 1\Assignment2\UCDCOMP10050-Assignment_2\Assignment2_Project_Files" "C:\Users\pangk\Documents\School\2021_Spring\COMP10050-Software Engineering Project 1\Assignment2\UCDCOMP10050-Assignment_2\Assignment2_Project_Files\cmake-build-debug" "C:\Users\pangk\Documents\School\2021_Spring\COMP10050-Software Engineering Project 1\Assignment2\UCDCOMP10050-Assignment_2\Assignment2_Project_Files\cmake-build-debug" "C:\Users\pangk\Documents\School\2021_Spring\COMP10050-Software Engineering Project 1\Assignment2\UCDCOMP10050-Assignment_2\Assignment2_Project_Files\cmake-build-debug\CMakeFiles\Assignment2_Project_Files.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Assignment2_Project_Files.dir/depend

