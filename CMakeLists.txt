cmake_minimum_required(VERSION 3.30)

project(lab3)

add_subdirectory(src/interface)
add_subdirectory(src/tests)

add_executable(lab3 main.cpp)
target_include_directories(lab3 PUBLIC src/interface/include)
target_link_libraries(lab3 interface)