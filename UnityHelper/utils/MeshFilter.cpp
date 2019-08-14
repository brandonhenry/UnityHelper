#include "MeshFilter.h"

void* MeshFilter::getType()
{
    return type_get_object(class_get_type(MeshFilter::getKlass()));
}

Il2CppClass* MeshFilter::getKlass()
{
    return GetClassFromName("UnityEngine", "MeshFilter");
}