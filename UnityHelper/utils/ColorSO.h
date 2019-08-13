#ifndef COLOR_SO_H
#define COLOR_SO_H

#include "ScriptableObject.h"

class ColorSO : ScriptableObject
{
public: 
    Color color;

    Color getColor(){
        return color;
    }
}

#endif