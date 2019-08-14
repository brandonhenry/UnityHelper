#ifndef MESHFILTER_H
#define MESHFILTER_H

#include "Mesh.h"
#include "Component.h"

class MeshFilter : public Component, Il2CppObject
{
public: 
    // Returns the instantiated Mesh assigned to the mesh filter.
    Mesh mesh;	

    // Returns the shared mesh of the mesh filter.
    Mesh sharedMesh;	

    // Methods //

    static void* getType();
    static Il2CppClass* getKlass();
    MeshFilter();
};

#endif