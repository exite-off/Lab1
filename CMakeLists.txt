cmake_minimum_required(VERSION 3.31)
project(Lab1)

set(CMAKE_CXX_STANDARD 23)

add_executable(Lab1 
    main.cpp
    affineTransform.cpp
    transformSystem.cpp
    point.cpp
    fileIO.cpp
)

