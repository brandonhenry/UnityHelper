#include "ColorManager.h"

Color ColorForSaberType(int saberType){
    void *colorForSaberTypeParams[] = {&saberType};
    const MethodInfo *colorManagerColorForSaberType = class_get_method_from_name(ColorManager::getKlass(), "ColorForSaberType", 1);
    return *(reinterpret_cast<Color *>(object_unbox(runtime_invoke(colorManagerColorForSaberType, ColorManager::getKlass(), colorForSaberTypeParams, &exception))));
}

Il2CppClass* getKlass()
{
    return GetClassFromName("", "ColorManager");
}