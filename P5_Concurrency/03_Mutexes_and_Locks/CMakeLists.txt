cmake_minimum_required(VERSION 2.8)
project(P503)

set(CMAKE_BUILD_TYPE "Release")

# set compiler as c++17
set(CMAKE_CXX_FLAGS "-std=c++17 -O2")
add_compile_options(-std=c++17)
add_definitions(-std=c++17)

# add subdirectory cmake
add_subdirectory(02_Using_a_Mutex_to_Protect_Shared_Data)
add_subdirectory(03_Using_Locks_to_Avoid_Deadlocks)

# without 04
#add_subdirectory(05_Starting_a_Thread_with_Variadic_Templates_and_Member_Functions)