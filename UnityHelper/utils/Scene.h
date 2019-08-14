
#ifndef SCENE_H
#define SCENE_H

#include "../../beatsaber-hook/shared/utils/utils.h"

using std::string;
using il2cpp_utils::createcsstr;
using il2cpp_utils::GetClassFromName;
using il2cpp_utils::New;
using namespace il2cpp_functions;

class Scene : Il2CppObject
{
public:
    enum struct MethodList {
        GetNameInternal
    };
    static const MethodInfo* getMethod(MethodList method);

    // Fields : Il2Cpp //

    Il2CppException *exception;
    static auto GetNameInternal(int scene);
    static Il2CppClass* getKlass();
};

#endif