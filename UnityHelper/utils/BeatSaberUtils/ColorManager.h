#ifndef COLOR_MANAGER_H
#define COLOR_MANAGER_H

#include "SimpleColorSO.h"
#include "PlayerDataModelSO.h"

class ColorManager : public ScriptableObject, Il2CppObject
{
public:
    SimpleColorSO _colorA;
    SimpleColorSO _colorB;
    PlayerDataModelSO _playerModel;

    static Color ColorForSaberType(int saberType);
    static Il2CppClass* getKlass();
};

#endif