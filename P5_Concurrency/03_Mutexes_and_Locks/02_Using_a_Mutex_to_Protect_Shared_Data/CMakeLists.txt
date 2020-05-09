project(task1)
cmake_minimum_required(VERSION 3.10)
add_compile_options(-std=c++11)

add_executable(example_2_solution example_2_solution.cpp)
target_link_libraries(example_2_solution)

add_executable(example_3_solution example_3_solution.cpp)
target_link_libraries(example_3_solution)

add_executable(example_4_solution example_4_solution.cpp)
target_link_libraries(example_4_solution)