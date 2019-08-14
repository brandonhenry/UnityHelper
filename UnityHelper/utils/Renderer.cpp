#include "Renderer.h"

Array<Material *>* Renderer::GetSharedMaterials()
{
    static Il2CppException *exception;
    const MethodInfo* rendererGetSharedMaterials = getMethod(MethodList::GetSharedMaterials);
    Array<Material *>* result = reinterpret_cast<Array<Material *> *>(runtime_invoke(rendererGetSharedMaterials, Renderer::getKlass(), nullptr, &exception));
    rendererGetSharedMaterials = nullptr;
    return result;
}

void* Renderer::getType()
{
    return type_get_object(class_get_type(Renderer::getKlass()));
}

Il2CppClass* Renderer::getKlass()
{
    return GetClassFromName("UnityEngine", "Renderer");
}


const MethodInfo* Renderer::getMethod(MethodList method)
{
    switch (method)
    {
        case MethodList::GetSharedMaterials:
            return class_get_method_from_name(Renderer::getKlass(), "get_sharedMaterials", 0);
    }
}