cmake_minimum_required(VERSION 2.4)

project(BRL-test)

add_executable(rocket main.cpp)

set_property(TARGET rocket PROPERTY CXX_STANDARD 17)