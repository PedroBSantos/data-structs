# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.18

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "G:\Compiladores e Interpretadores\C++\cmake-3.18.1-win64-x64\bin\cmake.exe"

# The command to remove a file.
RM = "G:\Compiladores e Interpretadores\C++\cmake-3.18.1-win64-x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "G:\Dev\C++ Programs\Projetos Visual Studio Code\Estruturas de Dados\Fila de Prioridade"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "G:\Dev\C++ Programs\Projetos Visual Studio Code\Estruturas de Dados\Fila de Prioridade\build"

# Utility rule file for ContinuousCoverage.

# Include the progress variables for this target.
include CMakeFiles/ContinuousCoverage.dir/progress.make

CMakeFiles/ContinuousCoverage:
	"G:\Compiladores e Interpretadores\C++\cmake-3.18.1-win64-x64\bin\ctest.exe" -D ContinuousCoverage

ContinuousCoverage: CMakeFiles/ContinuousCoverage
ContinuousCoverage: CMakeFiles/ContinuousCoverage.dir/build.make

.PHONY : ContinuousCoverage

# Rule to build all files generated by this target.
CMakeFiles/ContinuousCoverage.dir/build: ContinuousCoverage

.PHONY : CMakeFiles/ContinuousCoverage.dir/build

CMakeFiles/ContinuousCoverage.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ContinuousCoverage.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ContinuousCoverage.dir/clean

CMakeFiles/ContinuousCoverage.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "G:\Dev\C++ Programs\Projetos Visual Studio Code\Estruturas de Dados\Fila de Prioridade" "G:\Dev\C++ Programs\Projetos Visual Studio Code\Estruturas de Dados\Fila de Prioridade" "G:\Dev\C++ Programs\Projetos Visual Studio Code\Estruturas de Dados\Fila de Prioridade\build" "G:\Dev\C++ Programs\Projetos Visual Studio Code\Estruturas de Dados\Fila de Prioridade\build" "G:\Dev\C++ Programs\Projetos Visual Studio Code\Estruturas de Dados\Fila de Prioridade\build\CMakeFiles\ContinuousCoverage.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ContinuousCoverage.dir/depend

