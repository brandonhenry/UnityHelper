#ifndef RESOURCES_H
#define RESOURCES_H

#include "UnityObject.h"

class Resources : Il2CppObject
{
    public: 

    // Fields - Il2Cpp //
    
    Il2CppException *exception;

    // Returns a list of all objects of Type type.
    static Array<void *>* FindObjectsOfTypeAll(Il2CppClass* klass)
    {
        static Il2CppException *exception;
        void *params[] = {type_get_object(class_get_type(klass))};
        const MethodInfo *resourcesFindObjectsOfTypeAll = class_get_method_from_name(Resources::getKlass(), "FindObjectsOfTypeAll", 1);
        return reinterpret_cast<Array<void *> *>(runtime_invoke(resourcesFindObjectsOfTypeAll, nullptr, params, &exception));
    }	

    static Il2CppClass* getKlass()
    {
        return GetClassFromName("UnityEngine", "Resources");
    }

    // Loads an asset stored at path in a Resources folder.
    static void* Load(string path);

    // Loads all assets in a folder or file at path in a Resources folder.
    static Array<UnityObject *> LoadAll(string path);

    // Asynchronously loads an asset stored at path in a Resources folder.
    // static ResourceRequest LoadAsync(string path);

    // Unloads assetToUnload from memory.
    static void UnloadAsset(UnityObject assetToUnload);	

    // Unloads assets that are not used.
    static AsyncOperation UnloadUnusedAssets();
};

#endif