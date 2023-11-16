cmake_minimum_required(VERSION 3.26)
project(Base64)

set(CMAKE_CXX_STANDARD 23)

add_executable(Base64 main.cpp
        Base64.cpp
        Base64.h
        ByteInput.cpp
        ByteInput.h
        Input.cpp
        Input.h
        StringInput.cpp
        StringInput.h
)
