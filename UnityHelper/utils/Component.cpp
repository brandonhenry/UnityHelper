#include "Component.h"

GameObject* Component::getGameObject()
{
    const MethodInfo *componentGetGameObject = getMethod(MethodList::GetGameObject);
    GameObject *gameObj = reinterpret_cast<GameObject *>(runtime_invoke(componentGetGameObject, this, nullptr, &exception));
    componentGetGameObject = nullptr;
    return gameObj;
}

string Component::getTag()
{
    return tag;
}

Transform Component::getTransform()
{
    return transform;
}

// Returns all components of Type type in the GameObject or any of its children.
Array<Component *>* Component::GetComponentsInChildren(void* t, bool includeInactive){
    const MethodInfo *componentGetComponentsInChildren = getMethod(MethodList::GetComponentsInChildren);
    void *getMeshFiltersParams[] = {t, &includeInactive};
    Array<Component *>* components = reinterpret_cast<Array<Component *> *>(runtime_invoke(componentGetComponentsInChildren, this, getMeshFiltersParams, &exception));
    componentGetComponentsInChildren = nullptr;
    return components;
}

Il2CppClass* Component::getKlass()
{
    return GetClassFromName("UnityEngine", "Component");
}

const MethodInfo* Component::getMethod(MethodList method)
{
    switch (method)
    {
        case MethodList::GetComponentsInChildren:
            return class_get_method_from_name(Component::getKlass(), "GetComponentsInChildren", 2);
        case MethodList::GetGameObject:
            class_get_method_from_name(Component::getKlass(), "get_gameObject", 0);
    }
}