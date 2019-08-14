#include "Saber.h"

int Saber::getType()
{
    const MethodInfo *saberTypeGet = getMethod(MethodList::GetSaberType);
    int result = *(reinterpret_cast<int *>(object_unbox(runtime_invoke(saberTypeGet, this, nullptr, &exception))));
    saberTypeGet = nullptr;
    return result;
}

static Il2CppClass* getKlass()
{
    return GetClassFromName("", "Saber");
}

const MethodInfo* Saber::getMethod(MethodList method)
{
    switch (method)
    {
        case MethodList::GetSaberType:
            return class_get_method_from_name(Saber::getKlass(), "get_saberType", 1);
    }
}