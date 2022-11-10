cmake_minimum_required(VERSION 3.20)
project(randStoryCpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(randStoryCpp
        content.hpp
        exceptions.hpp
        main.cpp
        wordCategory.hpp
        wordDict.hpp)
