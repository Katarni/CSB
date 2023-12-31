cmake_minimum_required(VERSION 3.26)
project(RelativistycDynamic)

set(CMAKE_CXX_STANDARD 17)

add_executable(RelativistycDynamic src/main.cpp
        src/Dynamic.cpp
        src/Dynamic.h
        src/Vector3.cpp
        src/Vector3.h
        src/Particle.cpp
        src/Particle.h
        src/includes.h
)
