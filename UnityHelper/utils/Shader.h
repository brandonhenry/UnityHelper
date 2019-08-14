#ifndef SHADER_H
#define SHADER_H

#include "UnityObject.h"

class Shader : public UnityObject
{
public:
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

    static int PropertyToID(string property)
    {
        MethodInfo *shaderPropertyToID = class_get_method_from_name(Shader::getKlass(), "PropertyToID", 1);
        Il2CppString *paramString = createcsstr(property);
        void *params[] = {paramString};
        return *(reinterpret_cast<int *>(object_unbox(runtime_invoke(shaderPropertyToID, nullptr, params, &exception))));
    }

    static Il2CppClass* getKlass(){
        return GetClassFromName("UnityEngine", "Shader");
    }


}

#endif