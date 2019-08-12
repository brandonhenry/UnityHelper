#ifndef ASSETBUNDLE_H

#include "Object.h"

class AssetBundle extends Object
{
    public:

        // Fields //

        // Return true if the AssetBundle is a streamed Scene AssetBundle.
        bool isStreamedSceneAssetBundle;

        // constructor
        AssetBundle();

        // Public Methods //
        
        // Check if an AssetBundle contains a specific object.
        Contains();	

        // Return all asset names in the AssetBundle.
        GetAllAssetNames();		

        // Return all the Scene asset paths (paths to *.unity assets) in the AssetBundle.
        GetAllScenePaths();	

        // Loads all assets contained in the asset bundle that inherit from type.	
        LoadAllAssets();		

        // Loads all assets contained in the asset bundle asynchronously.
        LoadAllAssetsAsync();		

        // Loads asset with name from the bundle.
        LoadAsset();		

        // Asynchronously loads asset with name from the bundle.
        LoadAssetAsync();		

        // Loads asset and sub assets with name from the bundle.
        LoadAssetWithSubAssets();		

        // Loads asset with sub assets with name from the bundle asynchronously.
        LoadAssetWithSubAssetsAsync();		

        // Unloads all assets in the bundle.
        Unload();	

        // Static Methods //

        // To use when you need to get a list of all the currently loaded Asset Bundles.
        GetAllLoadedAssetBundles();		

        // Synchronously loads an AssetBundle from a file on disk.
        LoadFromFile();		

        // Asynchronously loads an AssetBundle from a file on disk.
        LoadFromFileAsync();		

        // Synchronously create an AssetBundle from a memory region.
        LoadFromMemory();		

        // Asynchronously create an AssetBundle from a memory region.
        LoadFromMemoryAsync();		

        // Synchronously loads an AssetBundle from a managed Stream.
        LoadFromStream();		

        // Asynchronously loads an AssetBundle from a managed Stream.
        LoadFromStreamAsync();		

        // Asynchronously recompress a downloaded/stored AssetBundle from one BuildCompression to another.
        RecompressAssetBundleAsync();		

        // Unloads all currently loaded Asset Bundles.
        UnloadAllAssetBundles();		

    private:
        Il2CppClass *klass;
        static void *asyncBundle;
        Il2CppException *exception = nullptr;
};

#endif