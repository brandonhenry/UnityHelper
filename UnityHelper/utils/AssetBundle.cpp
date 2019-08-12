#include "UnityHelper.h"
#include "AssetBundle.h"
#include "GameObject.h"

#include "../../../beatsaber-hook/**"

using std::string;

class AssetBundle 
{
    AssetBundle()
    {
        klass = GetClassFromName("UnityEngine", "AssetBundle");
    }

    /*
    Asynchronously loads an AssetBundle from a file on disk. The function supports bundles of any compression type. 
    In case of lzma compression, the data will be decompressed to the memory. Uncompressed and chunk-compressed bundles 
    can be read directly from disk. This is the fastest way to load an AssetBundle.
    */
    void* LoadFromFileAsync(string assetFilePath){
        // Grab method
        MethodInfo *assetBundleFromFileAsync;
        assetBundleFromFileAsync = class_get_method_from_name(klass, "LoadFromFileAsync", 1);

        // Setup args
        Il2CppString *assetFilePathCStr = createcsstr(assetFilePath);
        void *fromFileParams[] = {assetFilePathCStr};

        // run method and store result
        asyncBundle = runtime_invoke(assetBundleFromFileAsync, nullptr, fromFileParams, &exception);
        return asyncBundle;
    }

    /*
    Synchronously loads asset with name of a given T from the bundle. 
    */
    void LoadAssetAsync(string assetPath){
        // Grab method
        MethodInfo *loadAssetAsync;
        loadAssetAsync = class_get_method_from_name(assetBundleClass, "LoadAssetAsync", 2);

        // Setup args
        Il2CppString *assetPathCStr = createcsstr(assetPath);
        void *assetPathParams[] = {assetPathCStr, type_get_object(class_get_type(GameObject.getKlass()))};

    }

    // Returns this class
    Il2CppClass* getClass()
    {
        return klass;
    }

    // refreshes this classes fields
    void refresh(){
        
    }
    

};