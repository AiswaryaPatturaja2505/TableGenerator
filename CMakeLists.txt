cmake_minimum_required(VERSION 3.25)
project(XMLtoHTMLConverter)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(XMLtoHTMLConverter main.cpp)
