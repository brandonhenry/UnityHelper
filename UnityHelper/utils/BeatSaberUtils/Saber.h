#ifndef SABER_H
#define SABER_H

#include "../Component.h"

using std::string;
using il2cpp_utils::createcsstr;
using il2cpp_utils::GetClassFromName;
using il2cpp_utils::New;
using namespace il2cpp_functions;

class Saber : public Component, Il2CppObject {
public:
    enum struct MethodList {
        GetSaberType
    };
    const MethodInfo* getMethod(MethodList method);
    int getType();
    static Il2CppClass* getKlass();
};

#endif