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
CMAKE_COMMAND = /snap/clion/92/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/92/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/omiguelgomes/Desktop/FEUP/AEDA_PROJ

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AEDA_PROJ.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AEDA_PROJ.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AEDA_PROJ.dir/flags.make

CMakeFiles/AEDA_PROJ.dir/src/main.cpp.o: CMakeFiles/AEDA_PROJ.dir/flags.make
CMakeFiles/AEDA_PROJ.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AEDA_PROJ.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AEDA_PROJ.dir/src/main.cpp.o -c /home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/src/main.cpp

CMakeFiles/AEDA_PROJ.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AEDA_PROJ.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/src/main.cpp > CMakeFiles/AEDA_PROJ.dir/src/main.cpp.i

CMakeFiles/AEDA_PROJ.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AEDA_PROJ.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/src/main.cpp -o CMakeFiles/AEDA_PROJ.dir/src/main.cpp.s

CMakeFiles/AEDA_PROJ.dir/src/tests.cpp.o: CMakeFiles/AEDA_PROJ.dir/flags.make
CMakeFiles/AEDA_PROJ.dir/src/tests.cpp.o: ../src/tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/AEDA_PROJ.dir/src/tests.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AEDA_PROJ.dir/src/tests.cpp.o -c /home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/src/tests.cpp

CMakeFiles/AEDA_PROJ.dir/src/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AEDA_PROJ.dir/src/tests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/src/tests.cpp > CMakeFiles/AEDA_PROJ.dir/src/tests.cpp.i

CMakeFiles/AEDA_PROJ.dir/src/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AEDA_PROJ.dir/src/tests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/src/tests.cpp -o CMakeFiles/AEDA_PROJ.dir/src/tests.cpp.s

CMakeFiles/AEDA_PROJ.dir/src/Data.cpp.o: CMakeFiles/AEDA_PROJ.dir/flags.make
CMakeFiles/AEDA_PROJ.dir/src/Data.cpp.o: ../src/Data.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/AEDA_PROJ.dir/src/Data.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AEDA_PROJ.dir/src/Data.cpp.o -c /home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/src/Data.cpp

CMakeFiles/AEDA_PROJ.dir/src/Data.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AEDA_PROJ.dir/src/Data.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/src/Data.cpp > CMakeFiles/AEDA_PROJ.dir/src/Data.cpp.i

CMakeFiles/AEDA_PROJ.dir/src/Data.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AEDA_PROJ.dir/src/Data.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/src/Data.cpp -o CMakeFiles/AEDA_PROJ.dir/src/Data.cpp.s

CMakeFiles/AEDA_PROJ.dir/src/Hora.cpp.o: CMakeFiles/AEDA_PROJ.dir/flags.make
CMakeFiles/AEDA_PROJ.dir/src/Hora.cpp.o: ../src/Hora.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/AEDA_PROJ.dir/src/Hora.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AEDA_PROJ.dir/src/Hora.cpp.o -c /home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/src/Hora.cpp

CMakeFiles/AEDA_PROJ.dir/src/Hora.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AEDA_PROJ.dir/src/Hora.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/src/Hora.cpp > CMakeFiles/AEDA_PROJ.dir/src/Hora.cpp.i

CMakeFiles/AEDA_PROJ.dir/src/Hora.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AEDA_PROJ.dir/src/Hora.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/src/Hora.cpp -o CMakeFiles/AEDA_PROJ.dir/src/Hora.cpp.s

CMakeFiles/AEDA_PROJ.dir/src/Reserva.cpp.o: CMakeFiles/AEDA_PROJ.dir/flags.make
CMakeFiles/AEDA_PROJ.dir/src/Reserva.cpp.o: ../src/Reserva.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/AEDA_PROJ.dir/src/Reserva.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AEDA_PROJ.dir/src/Reserva.cpp.o -c /home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/src/Reserva.cpp

CMakeFiles/AEDA_PROJ.dir/src/Reserva.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AEDA_PROJ.dir/src/Reserva.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/src/Reserva.cpp > CMakeFiles/AEDA_PROJ.dir/src/Reserva.cpp.i

CMakeFiles/AEDA_PROJ.dir/src/Reserva.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AEDA_PROJ.dir/src/Reserva.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/src/Reserva.cpp -o CMakeFiles/AEDA_PROJ.dir/src/Reserva.cpp.s

CMakeFiles/AEDA_PROJ.dir/src/Transacao.cpp.o: CMakeFiles/AEDA_PROJ.dir/flags.make
CMakeFiles/AEDA_PROJ.dir/src/Transacao.cpp.o: ../src/Transacao.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/AEDA_PROJ.dir/src/Transacao.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AEDA_PROJ.dir/src/Transacao.cpp.o -c /home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/src/Transacao.cpp

CMakeFiles/AEDA_PROJ.dir/src/Transacao.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AEDA_PROJ.dir/src/Transacao.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/src/Transacao.cpp > CMakeFiles/AEDA_PROJ.dir/src/Transacao.cpp.i

CMakeFiles/AEDA_PROJ.dir/src/Transacao.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AEDA_PROJ.dir/src/Transacao.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/src/Transacao.cpp -o CMakeFiles/AEDA_PROJ.dir/src/Transacao.cpp.s

CMakeFiles/AEDA_PROJ.dir/src/Utilizador.cpp.o: CMakeFiles/AEDA_PROJ.dir/flags.make
CMakeFiles/AEDA_PROJ.dir/src/Utilizador.cpp.o: ../src/Utilizador.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/AEDA_PROJ.dir/src/Utilizador.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AEDA_PROJ.dir/src/Utilizador.cpp.o -c /home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/src/Utilizador.cpp

CMakeFiles/AEDA_PROJ.dir/src/Utilizador.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AEDA_PROJ.dir/src/Utilizador.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/src/Utilizador.cpp > CMakeFiles/AEDA_PROJ.dir/src/Utilizador.cpp.i

CMakeFiles/AEDA_PROJ.dir/src/Utilizador.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AEDA_PROJ.dir/src/Utilizador.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/src/Utilizador.cpp -o CMakeFiles/AEDA_PROJ.dir/src/Utilizador.cpp.s

CMakeFiles/AEDA_PROJ.dir/src/Veiculo.cpp.o: CMakeFiles/AEDA_PROJ.dir/flags.make
CMakeFiles/AEDA_PROJ.dir/src/Veiculo.cpp.o: ../src/Veiculo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/AEDA_PROJ.dir/src/Veiculo.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AEDA_PROJ.dir/src/Veiculo.cpp.o -c /home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/src/Veiculo.cpp

CMakeFiles/AEDA_PROJ.dir/src/Veiculo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AEDA_PROJ.dir/src/Veiculo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/src/Veiculo.cpp > CMakeFiles/AEDA_PROJ.dir/src/Veiculo.cpp.i

CMakeFiles/AEDA_PROJ.dir/src/Veiculo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AEDA_PROJ.dir/src/Veiculo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/src/Veiculo.cpp -o CMakeFiles/AEDA_PROJ.dir/src/Veiculo.cpp.s

# Object files for target AEDA_PROJ
AEDA_PROJ_OBJECTS = \
"CMakeFiles/AEDA_PROJ.dir/src/main.cpp.o" \
"CMakeFiles/AEDA_PROJ.dir/src/tests.cpp.o" \
"CMakeFiles/AEDA_PROJ.dir/src/Data.cpp.o" \
"CMakeFiles/AEDA_PROJ.dir/src/Hora.cpp.o" \
"CMakeFiles/AEDA_PROJ.dir/src/Reserva.cpp.o" \
"CMakeFiles/AEDA_PROJ.dir/src/Transacao.cpp.o" \
"CMakeFiles/AEDA_PROJ.dir/src/Utilizador.cpp.o" \
"CMakeFiles/AEDA_PROJ.dir/src/Veiculo.cpp.o"

# External object files for target AEDA_PROJ
AEDA_PROJ_EXTERNAL_OBJECTS =

AEDA_PROJ: CMakeFiles/AEDA_PROJ.dir/src/main.cpp.o
AEDA_PROJ: CMakeFiles/AEDA_PROJ.dir/src/tests.cpp.o
AEDA_PROJ: CMakeFiles/AEDA_PROJ.dir/src/Data.cpp.o
AEDA_PROJ: CMakeFiles/AEDA_PROJ.dir/src/Hora.cpp.o
AEDA_PROJ: CMakeFiles/AEDA_PROJ.dir/src/Reserva.cpp.o
AEDA_PROJ: CMakeFiles/AEDA_PROJ.dir/src/Transacao.cpp.o
AEDA_PROJ: CMakeFiles/AEDA_PROJ.dir/src/Utilizador.cpp.o
AEDA_PROJ: CMakeFiles/AEDA_PROJ.dir/src/Veiculo.cpp.o
AEDA_PROJ: CMakeFiles/AEDA_PROJ.dir/build.make
AEDA_PROJ: lib/libgtestd.a
AEDA_PROJ: lib/libgtest_maind.a
AEDA_PROJ: lib/libgtestd.a
AEDA_PROJ: CMakeFiles/AEDA_PROJ.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable AEDA_PROJ"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AEDA_PROJ.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AEDA_PROJ.dir/build: AEDA_PROJ

.PHONY : CMakeFiles/AEDA_PROJ.dir/build

CMakeFiles/AEDA_PROJ.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AEDA_PROJ.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AEDA_PROJ.dir/clean

CMakeFiles/AEDA_PROJ.dir/depend:
	cd /home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/omiguelgomes/Desktop/FEUP/AEDA_PROJ /home/omiguelgomes/Desktop/FEUP/AEDA_PROJ /home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/cmake-build-debug /home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/cmake-build-debug /home/omiguelgomes/Desktop/FEUP/AEDA_PROJ/cmake-build-debug/CMakeFiles/AEDA_PROJ.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AEDA_PROJ.dir/depend

