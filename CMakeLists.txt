cmake_minimum_required(VERSION 3.28)
project(CMake_Labor13 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-fmodules-ts)

add_executable(Klausurv
        Klausurv/Fahrzeug.cpp
        Klausurv/Fuhrpark.cpp
        Klausurv/Elektro.cpp
        Klausurv/main_fuhrpark.cpp
)
