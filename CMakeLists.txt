cmake_minimum_required(VERSION 3.16)
project(PhysicsSimPro)

set(CMAKE_CXX_STANDARD 17)
add_compile_definitions(_DEBUG)
include_directories(PhysicsSimPro external_lib/PhysX/physx/include)
include_directories(PhysicsSimPro external_lib/PhysX/pxshared/include)


add_executable(PhysicsSimPro main.cpp inc/utilities.h src/utilities.cpp)



set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(PhysicsSimPro PUBLIC Threads::Threads)



find_library(pxstatic PhysX_static_64 HINTS "external_lib/PhysX/physx/bin/linux.clang/checked")
target_link_libraries(PhysicsSimPro PUBLIC ${pxstatic})

find_library(pxpvd PhysXPvdSDK_static_64 HINTS "external_lib/PhysX/physx/bin/linux.clang/checked")
target_link_libraries(PhysicsSimPro PUBLIC ${pxpvd})

find_library(pxcar PhysXVehicle_static_64 HINTS "external_lib/PhysX/physx/bin/linux.clang/checked")
target_link_libraries(PhysicsSimPro PUBLIC ${pxcar})

find_library(pxkinematic PhysXCharacterKinematic_static_64 HINTS "external_lib/PhysX/physx/bin/linux.clang/checked")
target_link_libraries(PhysicsSimPro PUBLIC ${pxkinematic})

find_library(pxext PhysXExtensions_static_64 HINTS "external_lib/PhysX/physx/bin/linux.clang/checked")
target_link_libraries(PhysicsSimPro PUBLIC ${pxext})

find_library(pxcook PhysXCooking_static_64 HINTS "external_lib/PhysX/physx/bin/linux.clang/checked")
target_link_libraries(PhysicsSimPro PUBLIC ${pxcook})

find_library(pxcommon PhysXCommon_static_64 HINTS "external_lib/PhysX/physx/bin/linux.clang/checked")
target_link_libraries(PhysicsSimPro PUBLIC ${pxcommon})

find_library(pxfound PhysXFoundation_static_64 HINTS "external_lib/PhysX/physx/bin/linux.clang/checked")
target_link_libraries(PhysicsSimPro PUBLIC ${pxfound})

target_link_libraries(PhysicsSimPro PRIVATE ${CMAKE_DL_LIBS})
message(STATUS "foo include dir: ${pxsnippetrender} ${pxsnippetutils} ${pxcar} ${pxcook} ")
