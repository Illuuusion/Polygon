cmake_minimum_required(VERSION 3.27)
project(Polygon)

set(CMAKE_CXX_STANDARD 17)

add_executable(Polygon Sources/main.cpp
        Sources/Circle.cpp
        Headers/Circle.h
        Sources/Triangle.cpp
        Headers/Triangle.h
        Headers/Figure.h
        Headers/Point.h
        Sources/Rectangle.cpp
        Headers/Rectangle.h
        Headers/Input.h
        Sources/Input.cpp
        Sources/Menu.cpp
        Headers/Menu.h
        Sources/Figure.cpp)
