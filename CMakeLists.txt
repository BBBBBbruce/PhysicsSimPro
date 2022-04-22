cmake_minimum_required(VERSION 3.22)
project(PhysicsSimPro)

set(CMAKE_CXX_STANDARD 17)
add_compile_definitions(_DEBUG)
include_directories(external_lib/PhysX/physx/include)
include_directories(external_lib/PhysX/pxshared/include)

add_executable(PhysicsSimPro main.cpp inc/utilities.h src/utilities.cpp)

find_library(PX_LIB PhysX HINTS "external_lib/PhysX/physx/bin/linux.clang/checked")
target_link_libraries(PhysicsSimPro PUBLIC ${PX_LIB})

message(STATUS "foo include dir: ${PX_LIB}")
