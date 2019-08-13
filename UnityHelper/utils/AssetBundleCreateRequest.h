#ifndef ASSET_BUNDLE_CREATE_REQUEST_H
#define ASSET_BUNDLE_CREATE_REQUEST_H

#include "AssetBundle.h"
#include "AsyncOperation.h"

using std::string;
using il2cpp_utils::createcsstr;
using il2cpp_utils::GetClassFromName;
using il2cpp_utils::New;
using namespace il2cpp_functions;

class AssetBundleCreateRequest : AsyncOperation
{
    public: 
        AssetBundle assetBundle;
        void* assetBundleCreateRequest; 

        AssetBundleCreateRequest(AssetBundle assetBundle, void* assetBundleCreateRequest)
        {
            this->assetBundle = assetBundle;
            this->assetBundleCreateRequest = assetBundleCreateRequest;
        };

        static void* getAssetBundle()
        {
            const MethodInfo *assetBundleFromAsync = class_get_method_from_name(AssetBundleCreateRequest::getKlass(), "get_assetBundle", 0);
            return runtime_invoke(assetBundleCreateRequest, assetBundle.asyncBundle(), nullptr, &exception);
        }

        Il2CppClass* getKlass(){
            return GetClassFromName("UnityEngine", "AssetBundleCreateRequest");
        }
        
};

#endif