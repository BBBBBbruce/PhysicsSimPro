//
// Created by bruce on 25/04/22.
//

#ifndef PHYSICSSIMPRO_RIGIDGRAPHICS_H
#define PHYSICSSIMPRO_RIGIDGRAPHICS_H

#include <vector>

#include "PxPhysicsAPI.h"

#include "../external_lib/PhysX/physx/snippets/snippetrender/SnippetRender.h"
#include "../external_lib/PhysX/physx/snippets/snippetrender/SnippetCamera.h"
#include "RigidPhysics.h"

using namespace physx;

void motionCallback(int x, int y);

void keyboardCallback(unsigned char key, int x, int y);

void mouseCallback(int button, int state, int x, int y);

void idleCallback();
void renderCallback();

void exitCallback(void);

void renderLoop();

#endif //PHYSICSSIMPRO_RIGIDGRAPHICS_H
