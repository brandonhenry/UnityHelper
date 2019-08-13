#ifndef COLOR_MANAGER_H
#define COLOR_MANAGER_H

#include "SimpleColorSO.h"
#include "PlayerDataModelSO.h"

class ColorManager : ScriptableObject
{
public:
    SimpleColorSO _colorA;
    SimpleColorSO _colorB;
    PlayerDataModelSO _playerModel;

    static Color ColorForSaberType(int saberType){
        void *colorForSaberTypeParams[] = {&saberType};
        colorManagerColorForSaberType = class_get_method_from_name(colorManagerClass, "ColorForSaberType", 1);
        return *(reinterpret_cast<Color *>(object_unbox(runtime_invoke(colorManagerColorForSaberType, ColorManager::getKlass(), colorForSaberTypeParams, &exception))));
    }

    static Il2CppClass* getKlass(){
        return GetClassFromName("", "ColorManager");
    }
}

#endif