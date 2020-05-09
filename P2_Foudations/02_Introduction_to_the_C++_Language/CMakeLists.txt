cmake_minimum_required(VERSION 2.8)
project(P2M1Foudations)

set(CMAKE_BUILD_TYPE "Release")

# set compiler as c++17
set(CMAKE_CXX_FLAGS "-std=c++17 -O2")
add_compile_options(-std=c++17)
add_definitions(-std=c++17)

# add subdirectory cmake
add_subdirectory(09_Sending_Output_to_the_Console)
add_subdirectory(12_Storing_Primitive_Types)
add_subdirectory(14_Storing_Vectors)
add_subdirectory(16_Using_Auto)
add_subdirectory(17_Store_a_Grid_in_Your_Program)
add_subdirectory(19_Working_with_Vectors)
add_subdirectory(20_For_Loops)
add_subdirectory(21_Functions)
add_subdirectory(22_Print_the_Board)
add_subdirectory(23_If_Statements_and_While_Loops)
add_subdirectory(24_Reading_From_a_File)
add_subdirectory(25_Read_the_Board_from_a_File)
add_subdirectory(26_Processing_Strings)
add_subdirectory(27_Adding_Data_to_a_Vector)
add_subdirectory(28_Parse_Lines_from_the_File)
add_subdirectory(29_Use_ParsLine_Function)
add_subdirectory(30_Formatting_the_Printed_Board)
add_subdirectory(31_Formatting_the_Printed_Board)
add_subdirectory(32_Store_the_Board_using_the_State_Enum)

