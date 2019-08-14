#include <vector>

#ifndef ASSET_BUNDLE_REQUEST_H
#define ASSET_BUNDLE_REQUEST_H

#include "AsyncOperation.h"
#include "UnityObject.h"

using std::vector;

struct AssetBundleRequest : public AsyncOperation, Il2CppObject
{
    enum struct MethodList
    {
        GetAsset
    };
    static const MethodInfo* getMethod(MethodList method);
    static Il2CppClass* getKlass();
    vector<UnityObject> allAssets;
    UnityObject asset;
    UnityObject* getAsset();
};

#endif