#include "UnityObject.h"

UnityObject::UnityObject()
    :exception(new Il2CppException){};

int UnityObject::GetInstanceID(){};

string UnityObject::ToString()
{
    // MethodInfo *toString = class_get_method_from_name(UnityObject::getKlass(), "ToString", 0);
    // void *newName = runtime_invoke(toString, this, nullptr, &exception);
    // return reinterpret_cast<Il2CppString *>(newName);
    return name;
}

void UnityObject::Destroy(){};

void UnityObject::DestroyImmediate(){};	

void UnityObject::DontDestroyOnLoad(){};	

void* UnityObject::FindObjectOfType(){};	

void** UnityObject::FindObjectsOfType(){};	

UnityObject* UnityObject::Instantiate(UnityObject* obj){
    static Il2CppException *exception;
    const MethodInfo *objectInstantiate = UnityObject::getMethod(UnityObject::MethodList::Instantiate);
    //Attempt to Instaniate GameObject
    void *instantiateParams[] = {obj};
    log(INFO, "Instantiated Asset Object");
    return reinterpret_cast<UnityObject *>(runtime_invoke(objectInstantiate, nullptr, instantiateParams, &exception));
};

Il2CppClass* UnityObject::getKlass()
{
    return GetClassFromName("UnityEngine", "Object");
}

const MethodInfo* UnityObject::getMethod(MethodList method)
{
    switch (method)
    {
        case MethodList::Instantiate:
            return class_get_method_from_name(UnityObject::getKlass(), "Instantiate", 1);
    }
}