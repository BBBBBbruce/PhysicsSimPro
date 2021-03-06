//
// Created by bruce on 25/04/22.
//

#include "../inc/RigidPhysics.h"

using namespace physx;

PxDefaultAllocator		gAllocator;
PxDefaultErrorCallback	gErrorCallback;

PxFoundation*			gFoundation = NULL;
PxPhysics*				gPhysics	= NULL;

PxDefaultCpuDispatcher*	gDispatcher = NULL;
PxScene*				gScene		= NULL;

PxMaterial*				gMaterial	= NULL;

PxPvd*                  gPvd        = NULL;

PxReal stackZ = 50.0f;

PxRigidDynamic* createDynamic(const PxTransform& t, const PxGeometry& geometry, const PxVec3& velocity)
{
    PxRigidDynamic* dynamic = PxCreateDynamic(*gPhysics, t, geometry, *gMaterial, 10.0f);
    dynamic->setAngularDamping(0.5f);
    dynamic->setLinearVelocity(velocity);
    gScene->addActor(*dynamic);
    return dynamic;
}

PxRigidStatic* createStatic(const PxTransform& t, const PxGeometry& geometry){

    PxRigidStatic* PhysStatic = PxCreateStatic(*gPhysics, t, geometry, *gMaterial);
    gScene->addActor(*PhysStatic);
    return PhysStatic;
}

void createStack(const PxTransform& t, PxU32 size, PxReal halfExtent)
{
    PxShape* shape = gPhysics->createShape(PxBoxGeometry(halfExtent, halfExtent, halfExtent), *gMaterial);
    for(PxU32 i=0; i<size;i++)
    {
        for(PxU32 j=0;j<size-i;j++)
        {
            PxTransform localTm(PxVec3(PxReal(j*2) - PxReal(size-i), PxReal(i*2+1), 0) * halfExtent);
            PxRigidDynamic* body = gPhysics->createRigidDynamic(t.transform(localTm));
            body->attachShape(*shape);
            PxRigidBodyExt::updateMassAndInertia(*body, 10.0f);
            gScene->addActor(*body);
        }
    }
    shape->release();
}

void initPhysics(bool interactive)
{
    gFoundation = PxCreateFoundation(PX_PHYSICS_VERSION, gAllocator, gErrorCallback);

    gPvd = PxCreatePvd(*gFoundation);
    PxPvdTransport* transport = PxDefaultPvdSocketTransportCreate(PVD_HOST, 5425, 10);
    gPvd->connect(*transport,PxPvdInstrumentationFlag::eALL);

    gPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *gFoundation, PxTolerancesScale(),true,gPvd);

    PxSceneDesc sceneDesc(gPhysics->getTolerancesScale());
    sceneDesc.gravity = PxVec3(0.0f, -9.81f, 0.0f);
    gDispatcher = PxDefaultCpuDispatcherCreate(2);
    sceneDesc.cpuDispatcher	= gDispatcher;
    sceneDesc.filterShader	= PxDefaultSimulationFilterShader;
    gScene = gPhysics->createScene(sceneDesc);

    PxPvdSceneClient* pvdClient = gScene->getScenePvdClient();
    if(pvdClient)
    {
        pvdClient->setScenePvdFlag(PxPvdSceneFlag::eTRANSMIT_CONSTRAINTS, true);
        pvdClient->setScenePvdFlag(PxPvdSceneFlag::eTRANSMIT_CONTACTS, true);
        pvdClient->setScenePvdFlag(PxPvdSceneFlag::eTRANSMIT_SCENEQUERIES, true);
    }
    gMaterial = gPhysics->createMaterial(0.5f, 0.5f, 0.6f);

    PxRigidStatic* groundPlane = PxCreatePlane(*gPhysics, PxPlane(0,1,0,0), *gMaterial);
    gScene->addActor(*groundPlane);

    for(PxU32 i=0;i<10;i++)
        createStack(PxTransform(PxVec3(0,0,stackZ-=4.0f)), 10, 2.0f);

    createStatic(PxTransform(PxVec3(0,100,0)), PxSphereGeometry(10));

    if(!interactive)
        createDynamic(PxTransform(PxVec3(0,40,100)), PxSphereGeometry(10), PxVec3(0,-50,-100));
}

void stepPhysics(bool /*interactive*/)
{
    gScene->simulate(1.0f/60.0f);
    gScene->fetchResults(true);
}

void cleanupPhysics(bool /*interactive*/)
{
    PX_RELEASE(gScene);
    PX_RELEASE(gDispatcher);
    PX_RELEASE(gPhysics);
    if(gPvd)
    {
        PxPvdTransport* transport = gPvd->getTransport();
        gPvd->release();	gPvd = NULL;
        PX_RELEASE(transport);
    }
    PX_RELEASE(gFoundation);

    printf("SnippetHelloWorld done.\n");
}

void keyPress(unsigned char key, const PxTransform& camera)
{
    (void)camera;
    switch(toupper(key))
    {
        case 'B':	createStack(PxTransform(PxVec3(0,0,stackZ-=2.0f)), 10, 2.0f);						break;
        case ' ':	createDynamic(PxTransform(PxVec3(0,80,0)), PxSphereGeometry(5), PxVec3(0,0,0));  break;
    }

}

void renderPhysics(){
    static const PxU32 frameCount = 100;
    initPhysics(false);
    for(PxU32 i=0; i<frameCount; i++)
        stepPhysics(false);
    cleanupPhysics(false);
}