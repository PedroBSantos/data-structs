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
CMAKE_SOURCE_DIR = "G:\Dev\C++ Programs\Projetos Visual Studio Code\Estruturas de Dados\Arvore Vermelho-Preto"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "G:\Dev\C++ Programs\Projetos Visual Studio Code\Estruturas de Dados\Arvore Vermelho-Preto\build"

# Include any dependencies generated for this target.
include CMakeFiles/arvore-vermelho-preto-c++.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/arvore-vermelho-preto-c++.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/arvore-vermelho-preto-c++.dir/flags.make

CMakeFiles/arvore-vermelho-preto-c++.dir/src/main.cpp.obj: CMakeFiles/arvore-vermelho-preto-c++.dir/flags.make
CMakeFiles/arvore-vermelho-preto-c++.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="G:\Dev\C++ Programs\Projetos Visual Studio Code\Estruturas de Dados\Arvore Vermelho-Preto\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/arvore-vermelho-preto-c++.dir/src/main.cpp.obj"
	"G:\Compiladores e Interpretadores\C++\msys64\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\arvore-vermelho-preto-c++.dir\src\main.cpp.obj -c "G:\Dev\C++ Programs\Projetos Visual Studio Code\Estruturas de Dados\Arvore Vermelho-Preto\src\main.cpp"

CMakeFiles/arvore-vermelho-preto-c++.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arvore-vermelho-preto-c++.dir/src/main.cpp.i"
	"G:\Compiladores e Interpretadores\C++\msys64\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "G:\Dev\C++ Programs\Projetos Visual Studio Code\Estruturas de Dados\Arvore Vermelho-Preto\src\main.cpp" > CMakeFiles\arvore-vermelho-preto-c++.dir\src\main.cpp.i

CMakeFiles/arvore-vermelho-preto-c++.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arvore-vermelho-preto-c++.dir/src/main.cpp.s"
	"G:\Compiladores e Interpretadores\C++\msys64\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "G:\Dev\C++ Programs\Projetos Visual Studio Code\Estruturas de Dados\Arvore Vermelho-Preto\src\main.cpp" -o CMakeFiles\arvore-vermelho-preto-c++.dir\src\main.cpp.s

# Object files for target arvore-vermelho-preto-c++
arvore__vermelho__preto__c_______OBJECTS = \
"CMakeFiles/arvore-vermelho-preto-c++.dir/src/main.cpp.obj"

# External object files for target arvore-vermelho-preto-c++
arvore__vermelho__preto__c_______EXTERNAL_OBJECTS =

arvore-vermelho-preto-c++.exe: CMakeFiles/arvore-vermelho-preto-c++.dir/src/main.cpp.obj
arvore-vermelho-preto-c++.exe: CMakeFiles/arvore-vermelho-preto-c++.dir/build.make
arvore-vermelho-preto-c++.exe: CMakeFiles/arvore-vermelho-preto-c++.dir/linklibs.rsp
arvore-vermelho-preto-c++.exe: CMakeFiles/arvore-vermelho-preto-c++.dir/objects1.rsp
arvore-vermelho-preto-c++.exe: CMakeFiles/arvore-vermelho-preto-c++.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="G:\Dev\C++ Programs\Projetos Visual Studio Code\Estruturas de Dados\Arvore Vermelho-Preto\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable arvore-vermelho-preto-c++.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\arvore-vermelho-preto-c++.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/arvore-vermelho-preto-c++.dir/build: arvore-vermelho-preto-c++.exe

.PHONY : CMakeFiles/arvore-vermelho-preto-c++.dir/build

CMakeFiles/arvore-vermelho-preto-c++.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\arvore-vermelho-preto-c++.dir\cmake_clean.cmake
.PHONY : CMakeFiles/arvore-vermelho-preto-c++.dir/clean

CMakeFiles/arvore-vermelho-preto-c++.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "G:\Dev\C++ Programs\Projetos Visual Studio Code\Estruturas de Dados\Arvore Vermelho-Preto" "G:\Dev\C++ Programs\Projetos Visual Studio Code\Estruturas de Dados\Arvore Vermelho-Preto" "G:\Dev\C++ Programs\Projetos Visual Studio Code\Estruturas de Dados\Arvore Vermelho-Preto\build" "G:\Dev\C++ Programs\Projetos Visual Studio Code\Estruturas de Dados\Arvore Vermelho-Preto\build" "G:\Dev\C++ Programs\Projetos Visual Studio Code\Estruturas de Dados\Arvore Vermelho-Preto\build\CMakeFiles\arvore-vermelho-preto-c++.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/arvore-vermelho-preto-c++.dir/depend
