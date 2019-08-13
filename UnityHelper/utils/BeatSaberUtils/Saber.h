#ifndef SABER_H
#define SABER_H

#include "Component.h"

using std::string;
using il2cpp_utils::createcsstr;
using il2cpp_utils::GetClassFromName;
using il2cpp_utils::New;
using namespace il2cpp_functions;

class Saber : Component {
public:
    int getType(){
        const MethodInfo *saberTypeGet = class_get_method_from_name(saberClass, "get_saberType", 0);
        return *(reinterpret_cast<int *>(object_unbox(runtime_invoke(saberTypeGet, saber, nullptr, &exception))));
    }
};

#endif