cmake_minimum_required(VERSION 3.16)
project(PhysicsSimPro)


add_compile_definitions(_DEBUG)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -no-pie")

include_directories(PhysicsSimPro external_lib/PhysX/physx/include)
include_directories(PhysicsSimPro external_lib/PhysX/pxshared/include)


add_executable(PhysicsSimPro main.cpp inc/utilities.h src/utilities.cpp src/RigidPhysics.cpp inc/RigidPhysics.h src/RigidGraphics.cpp inc/RigidGraphics.h)



set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(PhysicsSimPro PUBLIC Threads::Threads)

find_library(pxsnippetrender SnippetRender_static_64 HINTS "external_lib/PhysX/physx/bin/linux.clang/checked")
target_link_libraries(PhysicsSimPro PUBLIC ${pxsnippetrender})

find_library(pxsnippetutils SnippetUtils_static_64 HINTS "external_lib/PhysX/physx/bin/linux.clang/checked")
target_link_libraries(PhysicsSimPro PUBLIC ${pxsnippetutils})

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

find_package(GLUT)
find_package(OpenGL)
target_link_libraries(PhysicsSimPro  PUBLIC ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})



target_link_libraries(PhysicsSimPro PRIVATE ${CMAKE_DL_LIBS})
message(STATUS "foo include dir: ${pxsnippetrender} ${pxsnippetutils} ${pxcar} ${pxcook} ")
