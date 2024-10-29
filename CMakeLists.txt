cmake_minimum_required(VERSION 3.30.0 FATAL_ERROR)

project(Project2 LANGUAGES CXX)
set(CMAKE_BUILD_TYPE Debug)

add_executable(${PROJECT_NAME} "main.cpp")
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "TowersGame")

add_subdirectory(include)
add_subdirectory(src)
target_link_libraries(${PROJECT_NAME} include)
target_link_libraries(${PROJECT_NAME} src)