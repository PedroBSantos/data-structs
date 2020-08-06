cmake_minimum_required(VERSION 3.0.0)
project(arvore-binaria-de-busca-c++ VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(arvore-binaria-de-busca-c++ src/main.cpp src/arvore_binaria.cpp src/no.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
