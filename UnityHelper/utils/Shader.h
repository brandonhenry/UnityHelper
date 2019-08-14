#ifndef SHADER_H
#define SHADER_H

#include "UnityObject.h"

class Shader : public UnityObject, Il2CppObject
{
public:
    enum struct MethodList {
        PropertyToID
    };

    static const MethodInfo* getMethod(MethodList method);

    // Fields : Il2Cpp //

    Il2CppException *exception;

    // Fields //
    // Shader LOD level for all shaders.
    static int globalMaximumLOD;
    
    // Render pipeline currently in use.
    static string globalRenderPipeline;

    // Can this shader run on the end-users graphics card? (Read Only)
    bool isSupported;	

    // Shader LOD level for this shader.
    int maximumLOD;	

    // Returns the number of shader passes on the active SubShader.
    int passCount;	

    // Render queue of this shader. (Read Only)
    int renderQueue;

    static int PropertyToID(string property);
    static Il2CppClass* getKlass();
};

#endif