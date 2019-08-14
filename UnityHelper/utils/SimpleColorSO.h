#ifndef SIMPLE_COLOR_SO_H
#define SIMPLE_COLOR_SO_H

#include "ColorSO.h"

class SimpleColorSO : ColorSO, Il2CppObject
{
public: 
    Color _color;

    Color getColor(){
        return _color;
    }

    void setColor(Color c)
    {
        this->_color = c;
    }
};

#endif