#ifndef COLOR_SO_H
#define COLOR_SO_H

#include "ScriptableObject.h"

class ColorSO : public ScriptableObject, Il2CppObject
{
public: 
    Color color;

    Color getColor()
    {
        return color;
    }
}

#endif