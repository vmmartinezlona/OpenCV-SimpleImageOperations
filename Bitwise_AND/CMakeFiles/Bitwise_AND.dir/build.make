# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tsukimo/Documents/Vision/Bitwise_AND

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tsukimo/Documents/Vision/Bitwise_AND

# Include any dependencies generated for this target.
include CMakeFiles/Bitwise_AND.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Bitwise_AND.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Bitwise_AND.dir/flags.make

CMakeFiles/Bitwise_AND.dir/Bitwise_AND.cpp.o: CMakeFiles/Bitwise_AND.dir/flags.make
CMakeFiles/Bitwise_AND.dir/Bitwise_AND.cpp.o: Bitwise_AND.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tsukimo/Documents/Vision/Bitwise_AND/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Bitwise_AND.dir/Bitwise_AND.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Bitwise_AND.dir/Bitwise_AND.cpp.o -c /home/tsukimo/Documents/Vision/Bitwise_AND/Bitwise_AND.cpp

CMakeFiles/Bitwise_AND.dir/Bitwise_AND.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bitwise_AND.dir/Bitwise_AND.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tsukimo/Documents/Vision/Bitwise_AND/Bitwise_AND.cpp > CMakeFiles/Bitwise_AND.dir/Bitwise_AND.cpp.i

CMakeFiles/Bitwise_AND.dir/Bitwise_AND.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bitwise_AND.dir/Bitwise_AND.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tsukimo/Documents/Vision/Bitwise_AND/Bitwise_AND.cpp -o CMakeFiles/Bitwise_AND.dir/Bitwise_AND.cpp.s

CMakeFiles/Bitwise_AND.dir/Bitwise_AND.cpp.o.requires:

.PHONY : CMakeFiles/Bitwise_AND.dir/Bitwise_AND.cpp.o.requires

CMakeFiles/Bitwise_AND.dir/Bitwise_AND.cpp.o.provides: CMakeFiles/Bitwise_AND.dir/Bitwise_AND.cpp.o.requires
	$(MAKE) -f CMakeFiles/Bitwise_AND.dir/build.make CMakeFiles/Bitwise_AND.dir/Bitwise_AND.cpp.o.provides.build
.PHONY : CMakeFiles/Bitwise_AND.dir/Bitwise_AND.cpp.o.provides

CMakeFiles/Bitwise_AND.dir/Bitwise_AND.cpp.o.provides.build: CMakeFiles/Bitwise_AND.dir/Bitwise_AND.cpp.o


# Object files for target Bitwise_AND
Bitwise_AND_OBJECTS = \
"CMakeFiles/Bitwise_AND.dir/Bitwise_AND.cpp.o"

# External object files for target Bitwise_AND
Bitwise_AND_EXTERNAL_OBJECTS =

Bitwise_AND: CMakeFiles/Bitwise_AND.dir/Bitwise_AND.cpp.o
Bitwise_AND: CMakeFiles/Bitwise_AND.dir/build.make
Bitwise_AND: /usr/local/lib/libopencv_shape.so.3.1.0
Bitwise_AND: /usr/local/lib/libopencv_stitching.so.3.1.0
Bitwise_AND: /usr/local/lib/libopencv_superres.so.3.1.0
Bitwise_AND: /usr/local/lib/libopencv_videostab.so.3.1.0
Bitwise_AND: /usr/local/lib/libopencv_objdetect.so.3.1.0
Bitwise_AND: /usr/local/lib/libopencv_calib3d.so.3.1.0
Bitwise_AND: /usr/local/lib/libopencv_features2d.so.3.1.0
Bitwise_AND: /usr/local/lib/libopencv_flann.so.3.1.0
Bitwise_AND: /usr/local/lib/libopencv_highgui.so.3.1.0
Bitwise_AND: /usr/local/lib/libopencv_ml.so.3.1.0
Bitwise_AND: /usr/local/lib/libopencv_photo.so.3.1.0
Bitwise_AND: /usr/local/lib/libopencv_video.so.3.1.0
Bitwise_AND: /usr/local/lib/libopencv_videoio.so.3.1.0
Bitwise_AND: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
Bitwise_AND: /usr/local/lib/libopencv_imgproc.so.3.1.0
Bitwise_AND: /usr/local/lib/libopencv_core.so.3.1.0
Bitwise_AND: CMakeFiles/Bitwise_AND.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tsukimo/Documents/Vision/Bitwise_AND/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Bitwise_AND"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Bitwise_AND.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Bitwise_AND.dir/build: Bitwise_AND

.PHONY : CMakeFiles/Bitwise_AND.dir/build

CMakeFiles/Bitwise_AND.dir/requires: CMakeFiles/Bitwise_AND.dir/Bitwise_AND.cpp.o.requires

.PHONY : CMakeFiles/Bitwise_AND.dir/requires

CMakeFiles/Bitwise_AND.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Bitwise_AND.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Bitwise_AND.dir/clean

CMakeFiles/Bitwise_AND.dir/depend:
	cd /home/tsukimo/Documents/Vision/Bitwise_AND && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tsukimo/Documents/Vision/Bitwise_AND /home/tsukimo/Documents/Vision/Bitwise_AND /home/tsukimo/Documents/Vision/Bitwise_AND /home/tsukimo/Documents/Vision/Bitwise_AND /home/tsukimo/Documents/Vision/Bitwise_AND/CMakeFiles/Bitwise_AND.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Bitwise_AND.dir/depend

