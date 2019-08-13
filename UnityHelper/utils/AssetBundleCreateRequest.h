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

        AssetBundleCreateRequest()
        {
            
        };

        static void* getAssetBundle()
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
            return runtime_invoke(assetBundleFromAsync, this, nullptr, &exception);
        }

        AssetBundle getAsset(){
            return assetBundle;
        }

        Il2CppClass* getKlass(){
            return GetClassFromName("UnityEngine", "AssetBundleCreateRequest");
        }
        
};

#endif