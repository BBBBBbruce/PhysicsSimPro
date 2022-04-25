//
// Created by bruce on 25/04/22.
//

#ifndef PHYSICSSIMPRO_RIGIDPHYSICS_H
#define PHYSICSSIMPRO_RIGIDPHYSICS_H

#include <ctype.h>
#include "PxPhysicsAPI.h"


#include "../external_lib/PhysX/physx/snippets/snippetcommon/SnippetPrint.h"
#include "../external_lib/PhysX/physx/snippets/snippetcommon/SnippetPVD.h"
#include "../external_lib/PhysX/physx/snippets/snippetutils/SnippetUtils.h"

using namespace physx;


PxRigidDynamic* createDynamic(const PxTransform& t, const PxGeometry& geometry, const PxVec3& velocity=PxVec3(0));
PxRigidStatic* createStatic(const PxTransform& t, const PxGeometry& geometry);
void createStack(const PxTransform& t, PxU32 size, PxReal halfExtent);
void initPhysics(bool interactive);
void stepPhysics(bool /*interactive*/);
void cleanupPhysics(bool /*interactive*/);
void keyPress(unsigned char key, const PxTransform& camera);

void renderPhysics();



#endif //PHYSICSSIMPRO_RIGIDPHYSICS_H
