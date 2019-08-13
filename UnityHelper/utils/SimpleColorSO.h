#ifndef SIMPLE_COLOR_SO_H
#define SIMPLE_COLOR_SO_H

class SimpleColorSO : ColorSO
{
public: 
    Color _color;

    override Color getColor(){
        return _color;
    }

    void setColor(Color c)
    {
        this->_color = c;
    }
}

#endif