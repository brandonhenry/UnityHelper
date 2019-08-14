#include "Scene.h"

auto Scene::GetNameInternal(int scene){
    const MethodInfo *sceneNameMethodInfo = getMethod(MethodList::GetNameInternal);

    Il2CppException *exception = nullptr;
    void *sceneNameparams[] = {&scene};

    auto nameResult = runtime_invoke(sceneNameMethodInfo, nullptr, sceneNameparams, &exception);
    Il2CppString *csName = reinterpret_cast<Il2CppString *>(nameResult);

    return to_utf8(csstrtostr(csName)).c_str();
}

Il2CppClass* Scene::getKlass()
{
    return GetClassFromName("UnityEngine.SceneManagement", "Scene");
}

const MethodInfo* Scene::getMethod(MethodList method)
{
    switch (method)
    {
        case MethodList::GetNameInternal:
            return class_get_method_from_name(Scene::getKlass(), "GetNameInternal", 1);
    }
}