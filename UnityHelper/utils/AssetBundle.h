#include <iostream>
#include <android/log.h>

#ifndef ASSETBUNDLE_H
#define ASSETBUNDLE_H

using std::string;
using il2cpp_utils::createcsstr;
using il2cpp_utils::GetClassFromName;
using il2cpp_utils::New;
using namespace il2cpp_functions;

#include "UnityObject.h"
#include "GameObject.h"
#include "AssetBundleCreateRequest.h"


class AssetBundle : UnityObject
{
    public:

        // Fields //

        // Return true if the AssetBundle is a streamed Scene AssetBundle.
        bool isStreamedSceneAssetBundle;
        void *asyncBundle;
        Il2CppException *exception;
        const MethodInfo *assetBundleFromFileAsync;
        void *customSaberAssetBundle;

        // Constructor //
        AssetBundle()
        {
            
        }

        // Public Methods //

        /*
        Asynchronously loads an AssetBundle from a file on disk. The function supports bundles of any compression type. 
        In case of lzma compression, the data will be decompressed to the memory. Uncompressed and chunk-compressed bundles 
        can be read directly from disk. This is the fastest way to load an AssetBundle.
        */
        void* LoadFromFileAsync(string assetFilePath){
            
           
            // Grab method
            assetBundleFromFileAsync = class_get_method_from_name(AssetBundle::getKlass(), "LoadFromFileAsync", 1);

            // Setup args
            Il2CppString *assetFilePathCStr = createcsstr(assetFilePath);
            void *fromFileParams[] = {assetFilePathCStr};

            // run method and store result
            AssetBundleCreateRequest asyncBundle = new AssetBundleCreateRequest(this, runtime_invoke(assetBundleFromFileAsync, nullptr, fromFileParams, &exception));

            // null out references and return

            assetBundleFromFileAsync = nullptr;
            return asyncBundle;
        }

       void* getAsyncBundle(){
           return asyncBundle;
       }


        /*
        Synchronously loads asset with name of a given T from the bundle. 
        */
        void LoadAssetAsync(string assetPath){

            if (customSaberAssetBundle == nullptr)
            {
                customSaberAssetBundle = runtime_invoke(assetBundleFromAsync, asyncBundle, nullptr, &exception);
                log(INFO, "Grabbed Asset bundle");
                asyncBundle = nullptr;
            }

            // Grab method
            const MethodInfo *loadAssetAsync = class_get_method_from_name(AssetBundle::getKlass(), "LoadAssetAsync", 2);

            void* customSaberAssetBundle = AssetBundleCreateRequest::getAssetBundle(asyncBundle);

            if (customSaberAssetBundle != nullptr){
                // Setup args
                Il2CppString *assetPathCStr = createcsstr(assetPath);
                void *assetPathParams[] = {assetPathCStr, type_get_object(class_get_type(GameObject::getKlass()))};
            }

            // run method and store result
            void *assetAsync = runtime_invoke(loadAssetAsync, customSaberAssetBundle, assetPathParams, &exception);

            if (exception != nullptr)
            {
                const MethodInfo *exceptionToString = class_get_method_from_name(exception->klass, "ToString", 0);
                void *exceptionString = runtime_invoke(exceptionToString, exception, nullptr, &exception);
                Il2CppString *message = reinterpret_cast<Il2CppString *>(exceptionString);
                log(INFO, "Exception: %s", to_utf8(csstrtostr(message)).c_str());
            }
            log(INFO, "Grabbed Asset Async Request");

        }

        // refreshes this classes fields
        void refresh(){
            
        }

        void* getAsyncBundle(){
            return asyncBundle;
        }
        
        static Il2CppClass* getKlass()
        {
            return GetClassFromName("UnityEngine", "AssetBundle");
        }

};

#endif