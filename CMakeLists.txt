#Nome do Projeto
project(NFA)

# Esta linha é importante para garantir que não se tente usar uma versão antiga
# do CMake. Freqüentemente são introduzidas novas features, então é importante.
cmake_minimum_required(VERSION 2.8)

#set G++ arm compiler

# Seta o compilador para trabalhar com as diretivas do C++ 11.
SET(CMAKE_CXX_COMPILER "g++")
#SET(CMAKE_CXX_COMPILER "arm-linux-gnueabi-g++")

SET( GCC_COVERAGE_COMPILE_FLAGS "-std=c++11" )
SET( CMAKE_CXX_FLAGS  "${GCC_COVERAGE_COMPILE_FLAGS}" )

SET( CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3 -Wall -pedantic -Wextra -fpermissive" )

SET( CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2" )

# Cria uma variável com um valor inicial e também a torna acessível para o
# usuário através da interface gráfica ou curses.
SET(MAIN_FILE "app/run.cpp" CACHE STRING "Main file ...")

#include_directories(usr/arm-linux-gnueabi/include)
#include_directories(usr/arm-linux-gnueabi/include/c++/4.7.3)

# Adicionamos o diretório de include deste projeto.
include_directories(include)

include_directories(/usr/lib/jvm/java-8-oracle/include)
include_directories(/usr/lib/jvm/java-8-oracle/include/linux)

# Este comando busca todos os arquivos *.cpp dentro do diretório src,
# recursivamente, e armazena a lista na variável lib_sources.
file(GLOB_RECURSE lib_sources src/*.c*)

# Este comando busca todos os arquivos *.hpp dentro do diretorio include,
# recursivamente e armazena a lista na variável lib_includes.
file(GLOB_RECURSE lib_include include/*.hpp)

# Aqui dizemos ao CMake que queremos construir uma biblioteca chamada ex (que
# será libex.so no Linux e ex.dll no Windows) composta pelos arquivos contidos
# na variável lib_sources.
add_library(auto SHARED ${lib_sources} ${lib_include} )

# Esta biblioteca que estamos criando depende das bibliotecas do OpenCV e do
#target_link_libraries(auto pthread)
target_link_libraries(auto pthread)

# Informamos ao CMake para criar um executável chamado test (test.exe no
# Windows) a partir do arquivo app/test.cpp.
add_executable(run ${MAIN_FILE})

# Este executável depende da biblioteca ex, também construída por este arquivo.
target_link_libraries(run auto)
