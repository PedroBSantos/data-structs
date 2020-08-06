cmake_minimum_required(VERSION 3.0.0)
project(fila-de-prioridade-c++ VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(fila-de-prioridade-c++ src/main.cpp src/fila.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
