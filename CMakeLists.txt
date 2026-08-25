cmake_minimum_required(VERSION 4.3)
project(conta_frequencia_palavras)

set(CMAKE_CXX_STANDARD 20)

add_executable(conta_frequencia_palavras main.cpp
        Programa.cpp
        Programa.h)
find_package(Boost REQUIRED COMPONENTS tokenizer)
target_link_libraries(conta_frequencia_palavras PRIVATE Boost::tokenizer)