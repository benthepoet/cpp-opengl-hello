cmake_minimum_required(VERSION 3.15)
project(myproject LANGUAGES CXX)

find_package(glbinding CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE glfw glbinding::glbinding glbinding::glbinding-aux OpenGL::GL)

target_compile_features(main PRIVATE cxx_std_17)