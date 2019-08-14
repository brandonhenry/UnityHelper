#include <iostream>

#ifndef SCRIPTABLE_OBJECT_H
#define SCRIPTABLE_OBJECT_H

#include "UnityObject.h"

using std::string;

class ScriptableObject : public UnityObject
{
    // Methods //
    static ScriptableObject CreateInstance(string klass) {

    }
};

#endif