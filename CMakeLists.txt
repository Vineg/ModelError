cmake_minimum_required(VERSION 3.12)
project(ModelError)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/tinyply-master)

link_libraries("tinyply")

include_directories(lib/tinyply-master/source)

include_directories(inc)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_executable(ModelError src/main.cpp src/Box.cpp src/double3.cpp src/Face.cpp src/Node.cpp src/Point.cpp src/structs.cpp src/PlyFileData.h)