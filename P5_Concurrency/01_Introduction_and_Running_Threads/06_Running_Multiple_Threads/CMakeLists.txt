
project(task1)
cmake_minimum_required(VERSION 3.10)
add_compile_options(-std=c++11)

add_executable(example_1 example_1.cpp)
target_link_libraries(example_1)

add_executable(example_2 example_2.cpp)
target_link_libraries(example_2)