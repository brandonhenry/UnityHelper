
#ifndef UNITYOBJECT_H
#define UNITYOBJECT_H

#include <iostream>

using std::string;

struct HideFlags
{
    // A normal, visible object. This is the default.
    bool None;	
    // The object will not appear in the hierarchy.
    bool HideInHierarchy;	
    // It is not possible to view it in the inspector.
    bool HideInInspector;	
    // The object will not be saved to the Scene in the editor.
    bool DontSaveInEditor;
    // The object is not be editable in the inspector.	
    bool NotEditable;	
    // The object will not be saved when building a player.
    bool DontSaveInBuild;	
    // The object will not be unloaded by Resources.UnloadUnusedAssets.
    bool DontUnloadUnusedAsset;
    // The object will not be saved to the Scene. It will not be destroyed when a new Scene is loaded. It is a shortcut for HideFlags.DontSaveInBuild | HideFlags.DontSaveInEditor | HideFlags.DontUnloadUnusedAsset.	
    bool DontSave;	
    // The GameObject is not shown in the Hierarchy, not saved to to Scenes, and not unloaded by Resources.UnloadUnusedAssets.
    bool HideAndDontSave;	
};

class UnityObject 
{

public:

    // Fields //

    // Should the object be hidden, saved with the Scene or modifiable by the user?
    HideFlags hideFlags;
    
    // The name of the object.
    string name;

    // Constructor //
    UnityObject();

    // Public Methods //

    // Returns the instance id of the object.
    int GetInstanceID();

    // Returns the name of the GameObject.
    string ToString()
    {
        // MethodInfo *toString = class_get_method_from_name(UnityObject::getKlass(), "ToString", 0);
        // void *newName = runtime_invoke(toString, this, nullptr, &exception);
        // return reinterpret_cast<Il2CppString *>(newName);
        return name;
    }

    // Static Methods //

    // Removes a gameobject, component or asset.
    void Destroy();

    // Destroys the object obj immediately. You are strongly recommended to use Destroy instead.
    void DestroyImmediate();	

    // Do not destroy the target Object when loading a new Scene.
    void DontDestroyOnLoad();	

    // Returns the first active loaded object of Type type.
    void* FindObjectOfType();	

    // Returns a list of all active loaded objects of Type type.
    void** FindObjectsOfType();	

    // Clones the object original and returns the clone.
    static UnityObject Instantiate(UnityObject obj){
        //Attempt to Instaniate GameObject
        void *instantiateParams[] = {obj};
        log(INFO, "Instantiated Asset Object");
        return runtime_invoke(objectInstantiate, nullptr, instantiateParams, &exception);
    };

    static Il2CppClass* getKlass()
    {
        return GetClassFromName("UnityEngine", "Object");
    }

private:


};

#endif