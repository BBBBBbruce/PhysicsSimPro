cmake_minimum_required(VERSION 3.16)
project(PhysicsSimPro)

add_compile_definitions(_DEBUG)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -no-pie")


include_directories(PhysicsSimPro external_lib/PhysX/physx/include)
include_directories(PhysicsSimPro external_lib/PhysX/pxshared/include)
include_directories(PhysocsSimPro external_lib/MFEM/mfem-4.3)

add_executable(PhysicsSimPro main.cpp inc/utilities.h src/utilities.cpp src/RigidPhysics.cpp inc/RigidPhysics.h src/RigidGraphics.cpp inc/RigidGraphics.h src/SoftPhysics.cpp inc/SoftPhysics.h src/World.cpp inc/World.h src/Engine.cpp inc/Engine.h src/Object.cpp inc/Object.h src/RigidObject.cpp inc/RigidObject.h src/SoftObject.cpp inc/SoftObject.h src/RigidObject_Static.cpp inc/RigidObject_Static.h src/RigidObject_Dynamic.cpp inc/RigidObject_Dynamic.h)

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

find_library(mfem mfem HINTS "external_lib/MFEM/mfem-4.3")
target_link_libraries(PhysicsSimPro PUBLIC ${mfem})

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
#target_link_libraries(PhysicsSimPro  PUBLIC ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})
#target_link_libraries(PhysicsSimPro PUBLIC OpenGL::GL GLUT::GLUT)
target_link_libraries(PhysicsSimPro  PUBLIC ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})

find_package(CUDA 10.1 REQUIRED)
target_link_libraries(PhysicsSimPro PUBLIC ${CUDA_LIBRARIES})
find_package(CUDAToolkit REQUIRED)
target_link_libraries(PhysicsSimPro PUBLIC CUDA::cusparse)

target_link_libraries(PhysicsSimPro PUBLIC ${CMAKE_DL_LIBS})

message(STATUS "foo include dir: ${pxsnippetrender} ${pxsnippetutils} ${pxcar} ${pxcook} ")
