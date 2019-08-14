#include "Shader.h"

int Shader::PropertyToID(string property)
{
    const MethodInfo *shaderPropertyToID = getMethod(MethodList::PropertyToID);
    Il2CppException *exception;
    Il2CppString *paramString = createcsstr(property);
    void *params[] = {paramString};
    int result = *(reinterpret_cast<int *>(object_unbox(runtime_invoke(shaderPropertyToID, nullptr, params, &exception))));
    shaderPropertyToID = nullptr;
    return result;
}

Il2CppClass* Shader::getKlass()
{
    return GetClassFromName("UnityEngine", "Shader");
}

const MethodInfo* Shader::getMethod(MethodList method)
{
    switch (method)
    {
        case MethodList::PropertyToID:
            return class_get_method_from_name(Shader::getKlass(), "PropertyToID", 1);
    }
}