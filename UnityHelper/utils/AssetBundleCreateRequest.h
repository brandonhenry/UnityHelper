#ifndef ASSET_BUNDLE_CREATE_REQUEST_H
#define ASSET_BUNDLE_CREATE_REQUEST_H

#include "AssetBundle.h"
#include "AsyncOperation.h"

using std::string;
using il2cpp_utils::createcsstr;
using il2cpp_utils::GetClassFromName;
using il2cpp_utils::New;
using namespace il2cpp_functions;

class AssetBundleCreateRequest : public AsyncOperation, Il2CppObject
{
    public: 
        AssetBundle assetBundle;
        AssetBundleCreateRequest();

        static AssetBundle* getAssetBundle();

        AssetBundle* getAsset();
        static Il2CppClass* getKlass();
};

#endif