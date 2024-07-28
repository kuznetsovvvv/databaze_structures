cmake_minimum_required(VERSION 3.10)
project(databaze_application)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../Function_lib Function_lib_dir)
add_executable(databaze_application ${CMAKE_CURRENT_SOURCE_DIR}/databaze.cpp)
target_include_directories(Function_lib PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/../Function_lib
)
target_link_libraries(databaze_application Function_lib)
