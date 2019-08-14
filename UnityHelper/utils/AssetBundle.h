#include <iostream>
#include <android/log.h>

#ifndef ASSETBUNDLE_H
#define ASSETBUNDLE_H

#include "../../beatsaber-hook/shared/utils/utils.h"

#include "UnityObject.h"
#include "AssetBundleRequest.h"
#include "AssetBundleCreateRequest.h"
#include "GameObject.h"

using std::string;
using il2cpp_utils::createcsstr;
using il2cpp_utils::GetClassFromName;
using il2cpp_utils::New;
using namespace il2cpp_functions;

class AssetBundle : public UnityObject
{
    public:

        enum struct MethodList {
            LoadAssetAsync,
            LoadFromFileAsync
        };

        static const MethodInfo* getMethod(MethodList method);

        // Fields : Il2Cpp //

        Il2CppException *exception;

        // Fields : UnityEngine //

        // Return true if the AssetBundle is a streamed Scene AssetBundle.
        bool isStreamedSceneAssetBundle;

        // Constructor //
        AssetBundle();

        // Getters & Setters //
        
        bool getIsStreamedSceneAssetBundle();

        // Public Methods //

        /*
        Asynchronously loads an AssetBundle from a file on disk. The function supports bundles of any compression type. 
        In case of lzma compression, the data will be decompressed to the memory. Uncompressed and chunk-compressed bundles 
        can be read directly from disk. This is the fastest way to load an AssetBundle.
        */
        static AssetBundleCreateRequest* LoadFromFileAsync(string assetFilePath);

        /*
        Synchronously loads asset with name of a given T from the bundle. 
        */
        AssetBundleRequest* LoadAssetAsync(string assetPath);

        const MethodInfo* getMethod(AssetBundle::MethodList method);

        static Il2CppClass* getKlass();
};

#endif