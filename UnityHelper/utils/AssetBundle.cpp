
#include "AssetBundle.h"

AssetBundle::AssetBundle()
    :isStreamedSceneAssetBundle(false)
    {};

bool AssetBundle::getIsStreamedSceneAssetBundle()
{
    return isStreamedSceneAssetBundle;
}

AssetBundleCreateRequest* AssetBundle::LoadFromFileAsync(string assetFilePath){
    static Il2CppException *exception;
    
    // Grab method
    static const MethodInfo *assetBundleFromFileAsync = getMethod(AssetBundle::MethodList::LoadFromFileAsync);

    // Setup args
    Il2CppString *filePathCStr = createcsstr(assetFilePath);
    static void *params[] = {filePathCStr};

    // run method and store result
    AssetBundleCreateRequest* assetBundleCreateRequest = reinterpret_cast<AssetBundleCreateRequest *>(runtime_invoke(assetBundleFromFileAsync, nullptr, params, &exception));

    // null out references and return

    assetBundleFromFileAsync = nullptr;
    return assetBundleCreateRequest;
}

/*
Synchronously loads asset with name of a given T from the bundle. 
*/
AssetBundleRequest* AssetBundle::LoadAssetAsync(string assetPath){
    // Grab method
    const MethodInfo *loadAssetAsync = AssetBundle::getMethod(AssetBundle::MethodList::LoadFromFileAsync);;

    // Setup args
    Il2CppString *assetPathCStr = createcsstr(assetPath);
    
    void *params[] = {assetPathCStr, type_get_object(class_get_type(GameObject::getKlass()))};

    // run method and store result
    AssetBundleRequest* assetBundleRequest = reinterpret_cast<AssetBundleRequest *>(runtime_invoke(loadAssetAsync, this, params, &exception));

    // catch error
    if (exception != nullptr)
    {
        const MethodInfo *exceptionToString = class_get_method_from_name(exception->klass, "ToString", 0);
        void *exceptionString = runtime_invoke(exceptionToString, exception, nullptr, &exception);
        Il2CppString *message = reinterpret_cast<Il2CppString *>(exceptionString);
        log(INFO, "Exception: %s", to_utf8(csstrtostr(message)).c_str());
    }

    log(INFO, "Grabbed Asset Async Request");
    
    loadAssetAsync = nullptr;
    return assetBundleRequest;
}

const MethodInfo* AssetBundle::getMethod(MethodList method)
{
    const MethodInfo *grabbedMethod;
    Il2CppClass *myKlass = AssetBundle::getKlass();

    switch (method)
    {
        case MethodList::LoadAssetAsync:
            return class_get_method_from_name(myKlass, "LoadAssetAsync", 2);
        case MethodList::LoadFromFileAsync:
            return class_get_method_from_name(myKlass, "LoadFromFileAsync", 1);
    }
}

static Il2CppClass* getKlass()
{
    return GetClassFromName("UnityEngine", "AssetBundle");
}

const MethodInfo* UnityObject::getMethod(MethodList method)
{
    switch (method)
    {
        case MethodList::Instantiate:
            return class_get_method_from_name(UnityObject::getKlass(), "Instantiate", 1);
    }
}