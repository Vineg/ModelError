cmake_minimum_required(VERSION 3.12)
project(ModelError)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/tinyply-master)

link_libraries("tinyply")

include_directories(lib/tinyply-master/source)

include_directories(inc)

add_executable(ModelError src/main.cpp src/Box.cpp src/double3.cpp src/Face.cpp src/Node.cpp src/Point.cpp src/structs.cpp)