
#include "PxPhysicsAPI.h"
#include "mfem.hpp"

#include <iostream>
#include <fstream>

#include "inc/RigidPhysics.h"
#include "inc/RigidGraphics.h"
#include "inc/SoftPhysics.h"

using namespace std;
using namespace mfem;

int main(int argc, char *argv[])
{
    // 1. Parse command-line options.
    const char *mesh_file = "/media/bruce/HDD_2T/Bruce_Projects/BBBBBbruce/PhysicsSimPro/external_lib/MFEM/mfem-4.3/data/beam-tet.mesh";
    int order = 1;
    bool static_cond = false;
    bool visualization = 1;

    OptionsParser args(argc, argv);
    args.AddOption(&mesh_file, "-m", "--mesh",
                   "Mesh file to use.");
    args.AddOption(&order, "-o", "--order",
                   "Finite element order (polynomial degree).");
    args.AddOption(&static_cond, "-sc", "--static-condensation", "-no-sc",
                   "--no-static-condensation", "Enable static condensation.");
    args.AddOption(&visualization, "-vis", "--visualization", "-no-vis",
                   "--no-visualization",
                   "Enable or disable GLVis visualization.");
    args.Parse();
    if (!args.Good())
    {
        args.PrintUsage(cout);
        return 1;
    }
    args.PrintOptions(cout);

    //deformation_sim(mesh_file,order, static_cond ,visualization);
    //renderLoop();



    return 0;
}
