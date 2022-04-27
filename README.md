# PhysicsSimPro

This new repo is for the proper physics simulation of my first year PhD project. 
The purpose is to build a combined the physics simulation engine works for both rigid body and deformation dynamics.

The demanding for this engine is to be physics-accurate, robust and fast. 
Therefore, we can use it to generate the ground truth for deep learning training.

### Part of Tech-spec

Rigid dynamics is simulated using PhysX 4.1. (https://github.com/NVIDIAGameWorks/PhysX) This library can work natively for real-time rendering.

Deformable dynamics is chosen to use Finite Element Method(FEM). Because 1. it is the most popular way to approximate an accurate deformation and 2. also no fracture is considered in this project.

The library used for this method is MFEM: https://mfem.org/

At the moment the library enables cuda for fast computation. However, it yet supports parallel computation 
because parallel execution of MFEM requires other libraries which yet been successfully tested on my end.

The environment of my experiment is running on:\
CPU: Intel i7-7800X\
GPU: Nvidia RTX 2080\
RAM: 32GB\
OS: Ubuntu 20.04 LTS

### Class spec: 

To be added

