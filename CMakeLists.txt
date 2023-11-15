cmake_minimum_required(VERSION 3.26)
project(RelativistycDynamic)

set(CMAKE_CXX_STANDARD 17)

add_executable(RelativistycDynamic main.cpp
        Dynamic.cpp
        Dynamic.h
        Vector3.cpp
        Vector3.h
        Particle.cpp
        Particle.h
)
