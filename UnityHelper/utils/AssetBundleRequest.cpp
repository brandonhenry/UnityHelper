#include "AssetBundleRequest.h"

UnityObject* AssetBundleRequest::getAsset()
{
    return &asset;
}

Il2CppClass* AssetBundleRequest::getKlass()
{
    return GetClassFromName("UnityEngine", "AssetBundleRequest");
}


const MethodInfo* AssetBundleRequest::getMethod(MethodList method)
{
    switch (method)
    {
        case MethodList::GetAsset:
            return class_get_method_from_name(AssetBundleRequest::getKlass(), "get_asset", 0);
    }
}