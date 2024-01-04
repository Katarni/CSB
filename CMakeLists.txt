cmake_minimum_required(VERSION 3.26)
project(RelativistycDynamic)

set(CMAKE_CXX_STANDARD 17)

add_executable(RelativistycDynamic tests/main.cpp
        includes/Dynamic.cpp
        includes/Dynamic.h
        includes/Vector3.h
        includes/Particle.h
        includes/headers.h
        includes/Write.cpp
        includes/Write.h
        includes/Read.cpp
        includes/Read.h
)
