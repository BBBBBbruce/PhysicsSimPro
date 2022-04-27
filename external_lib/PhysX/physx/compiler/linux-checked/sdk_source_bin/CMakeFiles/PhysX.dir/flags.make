# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# compile CXX with /usr/bin/clang++
CXX_FLAGS =  -std=c++11 -fno-rtti -fno-exceptions -ffunction-sections -fdata-sections -fstrict-aliasing -ferror-limit=0 -Wall -Wextra -Werror -Wno-alloca -Wno-anon-enum-enum-conversion -Wstrict-aliasing=2 -Weverything -Wno-documentation-deprecated-sync -Wno-documentation-unknown-command -Wno-gnu-anonymous-struct -Wno-undef -Wno-unused-function -Wno-nested-anon-types -Wno-float-equal -Wno-padded -Wno-weak-vtables -Wno-cast-align -Wno-conversion -Wno-missing-noreturn -Wno-missing-variable-declarations -Wno-shift-sign-overflow -Wno-covered-switch-default -Wno-exit-time-destructors -Wno-global-constructors -Wno-missing-prototypes -Wno-unreachable-code -Wno-unused-macros -Wno-unused-member-function -Wno-used-but-marked-unused -Wno-weak-template-vtables -Wno-deprecated -Wno-non-virtual-dtor -Wno-invalid-noreturn -Wno-return-type-c-linkage -Wno-reserved-id-macro -Wno-c++98-compat-pedantic -Wno-unused-local-typedef -Wno-old-style-cast -Wno-newline-eof -Wno-unused-private-field -Wno-format-nonliteral -Wno-implicit-fallthrough -Wno-undefined-reinterpret-cast -Wno-disabled-macro-expansion -Wno-zero-as-null-pointer-constant -Wno-shadow -Wno-unknown-warning-option -Wno-atomic-implicit-seq-cst -Wno-extra-semi-stmt -O3 -g3 -gdwarf-2 -fPIC  

CXX_DEFINES = -DNDEBUG -DPX_CHECKED=1 -DPX_NVTX=0 -DPX_PHYSX_GPU_SHARED_LIB_NAME=libPhysXGpu_64.so -DPX_PHYSX_STATIC_LIB -DPX_SUPPORT_PVD=1

CXX_INCLUDES = -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/include -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/common/include -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/common/src -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/physx/src -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/physx/src/device -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/physx/src/buffering -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/physxgpu/include -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/geomutils/include -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/geomutils/src -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/geomutils/src/contact -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/geomutils/src/common -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/geomutils/src/convex -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/geomutils/src/distance -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/geomutils/src/sweep -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/geomutils/src/gjk -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/geomutils/src/intersection -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/geomutils/src/mesh -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/geomutils/src/hf -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/geomutils/src/pcm -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/geomutils/src/ccd -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/lowlevel/api/include -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/lowlevel/software/include -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/lowlevel/common/include/pipeline -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/lowlevelaabb/include -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/lowleveldynamics/include -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/simulationcontroller/include -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/simulationcontroller/src -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/physxcooking/src -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/physxcooking/src/mesh -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/physxcooking/src/convex -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/scenequery/include -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/physxmetadata/core/include -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/immediatemode/include -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/pvd/include -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/../pxshared/include -I/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/PhysX/physx/source/foundation/include 
