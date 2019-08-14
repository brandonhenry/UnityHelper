#include "AssetBundleCreateRequest.h" 
 
 static AssetBundle AssetBundleCreateRequest::AssetBundle getAssetBundle()
{
    const MethodInfo *assetBundleFromAsync = class_get_method_from_name(AssetBundleCreateRequest::getKlass(), "get_assetBundle", 0);
    
    if (exception != nullptr)
    {
        const MethodInfo *exceptionToString = class_get_method_from_name(exception->klass, "ToString", 0);
        void *exceptionString = runtime_invoke(exceptionToString, exception, nullptr, &exception);
        Il2CppString *message = reinterpret_cast<Il2CppString *>(exceptionString);
        log(INFO, "Exception: %s", to_utf8(csstrtostr(message)).c_str());
    }

    log(INFO, "Grabbed Asset Object");
    
    AssetBundle assetBundle = runtime_invoke(assetBundleFromAsync, this, nullptr, &exception);
    assetBundleFromAsync = null;
    return assetBundle;
}

AssetBundle getAsset(){
    return assetBundle;
}

Il2CppClass* getKlass(){
    return GetClassFromName("UnityEngine", "AssetBundleCreateRequest");
}