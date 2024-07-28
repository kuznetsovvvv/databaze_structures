cmake_minimum_required(VERSION 3.10)
project(databaze_application)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add subdirectories for your application and library
add_subdirectory(databaze)
add_subdirectory(Functions_lib)
