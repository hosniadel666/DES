cmake_minimum_required(VERSION 3.22.0-rc1)

project(DES LANGUAGES CXX)

add_executable(main.out main.cpp)


add_subdirectory(include)

target_include_directories(main.out PUBLIC include)

target_link_directories(main.out PRIVATE include)

target_link_libraries(main.out des util)

