#ifndef MESHFILTER_H
#define MESHFILTER_H

#include "Mesh.h"
#include "Component.h"

class MeshFilter : Component
{
public: 
    // Returns the instantiated Mesh assigned to the mesh filter.
    Mesh mesh;	

    // Returns the shared mesh of the mesh filter.
    Mesh sharedMesh;	

    // Methods //

    static void* getType(){
        return type_get_object(class_get_type(MeshFilter::getKlass());)
    }

    static Il2CppClass* getKlass()
    {
        return GetClassFromName("UnityEngine", "AssetBundle");
    }
};

#endif