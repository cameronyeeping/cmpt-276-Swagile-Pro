# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.29.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.29.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/build

# Include any dependencies generated for this target.
include CMakeFiles/Swagile_Pro.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Swagile_Pro.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Swagile_Pro.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Swagile_Pro.dir/flags.make

CMakeFiles/Swagile_Pro.dir/src/create_report.cpp.o: CMakeFiles/Swagile_Pro.dir/flags.make
CMakeFiles/Swagile_Pro.dir/src/create_report.cpp.o: /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/create_report.cpp
CMakeFiles/Swagile_Pro.dir/src/create_report.cpp.o: CMakeFiles/Swagile_Pro.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Swagile_Pro.dir/src/create_report.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Swagile_Pro.dir/src/create_report.cpp.o -MF CMakeFiles/Swagile_Pro.dir/src/create_report.cpp.o.d -o CMakeFiles/Swagile_Pro.dir/src/create_report.cpp.o -c /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/create_report.cpp

CMakeFiles/Swagile_Pro.dir/src/create_report.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Swagile_Pro.dir/src/create_report.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/create_report.cpp > CMakeFiles/Swagile_Pro.dir/src/create_report.cpp.i

CMakeFiles/Swagile_Pro.dir/src/create_report.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Swagile_Pro.dir/src/create_report.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/create_report.cpp -o CMakeFiles/Swagile_Pro.dir/src/create_report.cpp.s

CMakeFiles/Swagile_Pro.dir/src/database_connection.cpp.o: CMakeFiles/Swagile_Pro.dir/flags.make
CMakeFiles/Swagile_Pro.dir/src/database_connection.cpp.o: /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/database_connection.cpp
CMakeFiles/Swagile_Pro.dir/src/database_connection.cpp.o: CMakeFiles/Swagile_Pro.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Swagile_Pro.dir/src/database_connection.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Swagile_Pro.dir/src/database_connection.cpp.o -MF CMakeFiles/Swagile_Pro.dir/src/database_connection.cpp.o.d -o CMakeFiles/Swagile_Pro.dir/src/database_connection.cpp.o -c /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/database_connection.cpp

CMakeFiles/Swagile_Pro.dir/src/database_connection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Swagile_Pro.dir/src/database_connection.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/database_connection.cpp > CMakeFiles/Swagile_Pro.dir/src/database_connection.cpp.i

CMakeFiles/Swagile_Pro.dir/src/database_connection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Swagile_Pro.dir/src/database_connection.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/database_connection.cpp -o CMakeFiles/Swagile_Pro.dir/src/database_connection.cpp.s

CMakeFiles/Swagile_Pro.dir/src/globals.cpp.o: CMakeFiles/Swagile_Pro.dir/flags.make
CMakeFiles/Swagile_Pro.dir/src/globals.cpp.o: /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/globals.cpp
CMakeFiles/Swagile_Pro.dir/src/globals.cpp.o: CMakeFiles/Swagile_Pro.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Swagile_Pro.dir/src/globals.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Swagile_Pro.dir/src/globals.cpp.o -MF CMakeFiles/Swagile_Pro.dir/src/globals.cpp.o.d -o CMakeFiles/Swagile_Pro.dir/src/globals.cpp.o -c /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/globals.cpp

CMakeFiles/Swagile_Pro.dir/src/globals.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Swagile_Pro.dir/src/globals.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/globals.cpp > CMakeFiles/Swagile_Pro.dir/src/globals.cpp.i

CMakeFiles/Swagile_Pro.dir/src/globals.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Swagile_Pro.dir/src/globals.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/globals.cpp -o CMakeFiles/Swagile_Pro.dir/src/globals.cpp.s

CMakeFiles/Swagile_Pro.dir/src/main.cpp.o: CMakeFiles/Swagile_Pro.dir/flags.make
CMakeFiles/Swagile_Pro.dir/src/main.cpp.o: /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/main.cpp
CMakeFiles/Swagile_Pro.dir/src/main.cpp.o: CMakeFiles/Swagile_Pro.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Swagile_Pro.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Swagile_Pro.dir/src/main.cpp.o -MF CMakeFiles/Swagile_Pro.dir/src/main.cpp.o.d -o CMakeFiles/Swagile_Pro.dir/src/main.cpp.o -c /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/main.cpp

CMakeFiles/Swagile_Pro.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Swagile_Pro.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/main.cpp > CMakeFiles/Swagile_Pro.dir/src/main.cpp.i

CMakeFiles/Swagile_Pro.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Swagile_Pro.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/main.cpp -o CMakeFiles/Swagile_Pro.dir/src/main.cpp.s

CMakeFiles/Swagile_Pro.dir/src/issue_manag.cpp.o: CMakeFiles/Swagile_Pro.dir/flags.make
CMakeFiles/Swagile_Pro.dir/src/issue_manag.cpp.o: /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/issue_manag.cpp
CMakeFiles/Swagile_Pro.dir/src/issue_manag.cpp.o: CMakeFiles/Swagile_Pro.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Swagile_Pro.dir/src/issue_manag.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Swagile_Pro.dir/src/issue_manag.cpp.o -MF CMakeFiles/Swagile_Pro.dir/src/issue_manag.cpp.o.d -o CMakeFiles/Swagile_Pro.dir/src/issue_manag.cpp.o -c /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/issue_manag.cpp

CMakeFiles/Swagile_Pro.dir/src/issue_manag.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Swagile_Pro.dir/src/issue_manag.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/issue_manag.cpp > CMakeFiles/Swagile_Pro.dir/src/issue_manag.cpp.i

CMakeFiles/Swagile_Pro.dir/src/issue_manag.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Swagile_Pro.dir/src/issue_manag.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/issue_manag.cpp -o CMakeFiles/Swagile_Pro.dir/src/issue_manag.cpp.s

CMakeFiles/Swagile_Pro.dir/src/issue_queries.cpp.o: CMakeFiles/Swagile_Pro.dir/flags.make
CMakeFiles/Swagile_Pro.dir/src/issue_queries.cpp.o: /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/issue_queries.cpp
CMakeFiles/Swagile_Pro.dir/src/issue_queries.cpp.o: CMakeFiles/Swagile_Pro.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Swagile_Pro.dir/src/issue_queries.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Swagile_Pro.dir/src/issue_queries.cpp.o -MF CMakeFiles/Swagile_Pro.dir/src/issue_queries.cpp.o.d -o CMakeFiles/Swagile_Pro.dir/src/issue_queries.cpp.o -c /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/issue_queries.cpp

CMakeFiles/Swagile_Pro.dir/src/issue_queries.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Swagile_Pro.dir/src/issue_queries.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/issue_queries.cpp > CMakeFiles/Swagile_Pro.dir/src/issue_queries.cpp.i

CMakeFiles/Swagile_Pro.dir/src/issue_queries.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Swagile_Pro.dir/src/issue_queries.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/issue_queries.cpp -o CMakeFiles/Swagile_Pro.dir/src/issue_queries.cpp.s

CMakeFiles/Swagile_Pro.dir/src/product_maint.cpp.o: CMakeFiles/Swagile_Pro.dir/flags.make
CMakeFiles/Swagile_Pro.dir/src/product_maint.cpp.o: /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/product_maint.cpp
CMakeFiles/Swagile_Pro.dir/src/product_maint.cpp.o: CMakeFiles/Swagile_Pro.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Swagile_Pro.dir/src/product_maint.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Swagile_Pro.dir/src/product_maint.cpp.o -MF CMakeFiles/Swagile_Pro.dir/src/product_maint.cpp.o.d -o CMakeFiles/Swagile_Pro.dir/src/product_maint.cpp.o -c /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/product_maint.cpp

CMakeFiles/Swagile_Pro.dir/src/product_maint.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Swagile_Pro.dir/src/product_maint.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/product_maint.cpp > CMakeFiles/Swagile_Pro.dir/src/product_maint.cpp.i

CMakeFiles/Swagile_Pro.dir/src/product_maint.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Swagile_Pro.dir/src/product_maint.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/product_maint.cpp -o CMakeFiles/Swagile_Pro.dir/src/product_maint.cpp.s

CMakeFiles/Swagile_Pro.dir/src/product_queries.cpp.o: CMakeFiles/Swagile_Pro.dir/flags.make
CMakeFiles/Swagile_Pro.dir/src/product_queries.cpp.o: /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/product_queries.cpp
CMakeFiles/Swagile_Pro.dir/src/product_queries.cpp.o: CMakeFiles/Swagile_Pro.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Swagile_Pro.dir/src/product_queries.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Swagile_Pro.dir/src/product_queries.cpp.o -MF CMakeFiles/Swagile_Pro.dir/src/product_queries.cpp.o.d -o CMakeFiles/Swagile_Pro.dir/src/product_queries.cpp.o -c /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/product_queries.cpp

CMakeFiles/Swagile_Pro.dir/src/product_queries.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Swagile_Pro.dir/src/product_queries.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/product_queries.cpp > CMakeFiles/Swagile_Pro.dir/src/product_queries.cpp.i

CMakeFiles/Swagile_Pro.dir/src/product_queries.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Swagile_Pro.dir/src/product_queries.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/product_queries.cpp -o CMakeFiles/Swagile_Pro.dir/src/product_queries.cpp.s

CMakeFiles/Swagile_Pro.dir/src/ui.cpp.o: CMakeFiles/Swagile_Pro.dir/flags.make
CMakeFiles/Swagile_Pro.dir/src/ui.cpp.o: /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/ui.cpp
CMakeFiles/Swagile_Pro.dir/src/ui.cpp.o: CMakeFiles/Swagile_Pro.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Swagile_Pro.dir/src/ui.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Swagile_Pro.dir/src/ui.cpp.o -MF CMakeFiles/Swagile_Pro.dir/src/ui.cpp.o.d -o CMakeFiles/Swagile_Pro.dir/src/ui.cpp.o -c /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/ui.cpp

CMakeFiles/Swagile_Pro.dir/src/ui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Swagile_Pro.dir/src/ui.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/ui.cpp > CMakeFiles/Swagile_Pro.dir/src/ui.cpp.i

CMakeFiles/Swagile_Pro.dir/src/ui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Swagile_Pro.dir/src/ui.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/ui.cpp -o CMakeFiles/Swagile_Pro.dir/src/ui.cpp.s

CMakeFiles/Swagile_Pro.dir/src/user_maint.cpp.o: CMakeFiles/Swagile_Pro.dir/flags.make
CMakeFiles/Swagile_Pro.dir/src/user_maint.cpp.o: /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/user_maint.cpp
CMakeFiles/Swagile_Pro.dir/src/user_maint.cpp.o: CMakeFiles/Swagile_Pro.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Swagile_Pro.dir/src/user_maint.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Swagile_Pro.dir/src/user_maint.cpp.o -MF CMakeFiles/Swagile_Pro.dir/src/user_maint.cpp.o.d -o CMakeFiles/Swagile_Pro.dir/src/user_maint.cpp.o -c /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/user_maint.cpp

CMakeFiles/Swagile_Pro.dir/src/user_maint.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Swagile_Pro.dir/src/user_maint.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/user_maint.cpp > CMakeFiles/Swagile_Pro.dir/src/user_maint.cpp.i

CMakeFiles/Swagile_Pro.dir/src/user_maint.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Swagile_Pro.dir/src/user_maint.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/user_maint.cpp -o CMakeFiles/Swagile_Pro.dir/src/user_maint.cpp.s

CMakeFiles/Swagile_Pro.dir/src/user_queries.cpp.o: CMakeFiles/Swagile_Pro.dir/flags.make
CMakeFiles/Swagile_Pro.dir/src/user_queries.cpp.o: /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/user_queries.cpp
CMakeFiles/Swagile_Pro.dir/src/user_queries.cpp.o: CMakeFiles/Swagile_Pro.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Swagile_Pro.dir/src/user_queries.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Swagile_Pro.dir/src/user_queries.cpp.o -MF CMakeFiles/Swagile_Pro.dir/src/user_queries.cpp.o.d -o CMakeFiles/Swagile_Pro.dir/src/user_queries.cpp.o -c /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/user_queries.cpp

CMakeFiles/Swagile_Pro.dir/src/user_queries.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Swagile_Pro.dir/src/user_queries.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/user_queries.cpp > CMakeFiles/Swagile_Pro.dir/src/user_queries.cpp.i

CMakeFiles/Swagile_Pro.dir/src/user_queries.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Swagile_Pro.dir/src/user_queries.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/user_queries.cpp -o CMakeFiles/Swagile_Pro.dir/src/user_queries.cpp.s

CMakeFiles/Swagile_Pro.dir/src/report_queries.cpp.o: CMakeFiles/Swagile_Pro.dir/flags.make
CMakeFiles/Swagile_Pro.dir/src/report_queries.cpp.o: /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/report_queries.cpp
CMakeFiles/Swagile_Pro.dir/src/report_queries.cpp.o: CMakeFiles/Swagile_Pro.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Swagile_Pro.dir/src/report_queries.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Swagile_Pro.dir/src/report_queries.cpp.o -MF CMakeFiles/Swagile_Pro.dir/src/report_queries.cpp.o.d -o CMakeFiles/Swagile_Pro.dir/src/report_queries.cpp.o -c /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/report_queries.cpp

CMakeFiles/Swagile_Pro.dir/src/report_queries.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Swagile_Pro.dir/src/report_queries.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/report_queries.cpp > CMakeFiles/Swagile_Pro.dir/src/report_queries.cpp.i

CMakeFiles/Swagile_Pro.dir/src/report_queries.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Swagile_Pro.dir/src/report_queries.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/src/report_queries.cpp -o CMakeFiles/Swagile_Pro.dir/src/report_queries.cpp.s

# Object files for target Swagile_Pro
Swagile_Pro_OBJECTS = \
"CMakeFiles/Swagile_Pro.dir/src/create_report.cpp.o" \
"CMakeFiles/Swagile_Pro.dir/src/database_connection.cpp.o" \
"CMakeFiles/Swagile_Pro.dir/src/globals.cpp.o" \
"CMakeFiles/Swagile_Pro.dir/src/main.cpp.o" \
"CMakeFiles/Swagile_Pro.dir/src/issue_manag.cpp.o" \
"CMakeFiles/Swagile_Pro.dir/src/issue_queries.cpp.o" \
"CMakeFiles/Swagile_Pro.dir/src/product_maint.cpp.o" \
"CMakeFiles/Swagile_Pro.dir/src/product_queries.cpp.o" \
"CMakeFiles/Swagile_Pro.dir/src/ui.cpp.o" \
"CMakeFiles/Swagile_Pro.dir/src/user_maint.cpp.o" \
"CMakeFiles/Swagile_Pro.dir/src/user_queries.cpp.o" \
"CMakeFiles/Swagile_Pro.dir/src/report_queries.cpp.o"

# External object files for target Swagile_Pro
Swagile_Pro_EXTERNAL_OBJECTS =

Swagile_Pro: CMakeFiles/Swagile_Pro.dir/src/create_report.cpp.o
Swagile_Pro: CMakeFiles/Swagile_Pro.dir/src/database_connection.cpp.o
Swagile_Pro: CMakeFiles/Swagile_Pro.dir/src/globals.cpp.o
Swagile_Pro: CMakeFiles/Swagile_Pro.dir/src/main.cpp.o
Swagile_Pro: CMakeFiles/Swagile_Pro.dir/src/issue_manag.cpp.o
Swagile_Pro: CMakeFiles/Swagile_Pro.dir/src/issue_queries.cpp.o
Swagile_Pro: CMakeFiles/Swagile_Pro.dir/src/product_maint.cpp.o
Swagile_Pro: CMakeFiles/Swagile_Pro.dir/src/product_queries.cpp.o
Swagile_Pro: CMakeFiles/Swagile_Pro.dir/src/ui.cpp.o
Swagile_Pro: CMakeFiles/Swagile_Pro.dir/src/user_maint.cpp.o
Swagile_Pro: CMakeFiles/Swagile_Pro.dir/src/user_queries.cpp.o
Swagile_Pro: CMakeFiles/Swagile_Pro.dir/src/report_queries.cpp.o
Swagile_Pro: CMakeFiles/Swagile_Pro.dir/build.make
Swagile_Pro: /Library/Developer/CommandLineTools/SDKs/MacOSX14.4.sdk/usr/lib/libsqlite3.tbd
Swagile_Pro: CMakeFiles/Swagile_Pro.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable Swagile_Pro"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Swagile_Pro.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Swagile_Pro.dir/build: Swagile_Pro
.PHONY : CMakeFiles/Swagile_Pro.dir/build

CMakeFiles/Swagile_Pro.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Swagile_Pro.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Swagile_Pro.dir/clean

CMakeFiles/Swagile_Pro.dir/depend:
	cd /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/build /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/build /Users/cameron/Desktop/projects/repos/cmpt-276-Swagile-Pro/build/CMakeFiles/Swagile_Pro.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Swagile_Pro.dir/depend

