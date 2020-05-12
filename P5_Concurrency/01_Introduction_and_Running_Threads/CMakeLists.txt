cmake_minimum_required(VERSION 2.8)
project(P501)

set(CMAKE_BUILD_TYPE "Release")

# set compiler as c++17
set(CMAKE_CXX_FLAGS "-std=c++17 -O2")
add_compile_options(-std=c++17)
add_definitions(-std=c++17)

# add subdirectory cmake
add_subdirectory(03_Running_a_Single_Thread)
add_subdirectory(04_Starting_a_Thread_with_Function_Objects)
add_subdirectory(05_Starting_a_Thread_with_Variadic_Templates_and_Member_Functions)
add_subdirectory(06_Running_Multiple_Threads)

# without 07
#add_subdirectory(05_Starting_a_Thread_with_Variadic_Templates_and_Member_Functions)