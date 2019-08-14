
#include <android/log.h>
#include <iostream>

#ifndef UNITYOBJECT_H
#define UNITYOBJECT_H

#include "../../beatsaber-hook/shared/utils/utils.h"

using std::string;
using il2cpp_utils::createcsstr;
using il2cpp_utils::GetClassFromName;
using il2cpp_utils::New;
using namespace il2cpp_functions;

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
    // Fields - Il2Cpp //

    void *params[];
    Il2CppException *exception;
    enum struct MethodList
    {
        Instantiate
    };

    static const MethodInfo* getMethod(MethodList method);

    // Fields - UnityEngine //

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
    string ToString();

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
    static UnityObject* Instantiate(UnityObject* obj);

    // Custom Methods //
    static Il2CppClass* getKlass();
    
};

#endif