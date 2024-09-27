cmake_minimum_required(VERSION 3.26)
project(ExpressionTruthTable)

set(CMAKE_CXX_STANDARD 17)

add_executable(ExpressionTruthTable main.cpp
        demo.cpp
        arrayList.h
        stack.h)
