cmake_minimum_required(VERSION 3.25)
project(modelo_de_markov)

set(CMAKE_CXX_STANDARD 23)

add_executable(modelo_de_markov main.cpp cadena_de_markov.cpp cadena_de_markov.h)
