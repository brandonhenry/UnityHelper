#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>

#include "Transform.h"
#include "Scene.h"
#include "Component.h"
#include "UnityObject.h"

using std::string;
using il2cpp_utils::createcsstr;
using il2cpp_utils::GetClassFromName;
using il2cpp_utils::New;
using namespace il2cpp_functions;

class GameObject : public UnityObject
{
public:

    // // Fields //

    // Defines whether the GameObject is active in the Scene.
    bool activeInHierarchy;

    // The local active state of this GameObject. (Read Only)
    bool activeSelf;	

    // Editor only API that specifies if a game object is static.
    bool isStatic;	

    // The layer the game object is in.
    int layer;	

    // Scene that the GameObject is part of.
    Scene scene;	

    // The tag of this game object.
    string tag;	

    // The Transform attached to this GameObject.
    Transform transform;	

    // Constructor //
    GameObject();

    // Public Methods //

    Transform getTransform();

    void setActive(bool active);
    
    // Custom Methods //
    static Il2CppClass* getKlass();

    // Adds a component class named className to the game object.
    void AddComponent();	

    // Calls the method named methodName on every MonoBehaviour in this game object or any of its children.
    void BroadcastMessage();		

    // Is this game object tagged with tag ?
    bool CompareTag();	

    // Returns the component of Type type if the game object has one attached, null if it doesn't.
    Component GetComponent();		

    // Returns the component of Type type in the GameObject or any of its children using depth first search.
    Component GetComponentInChildren(Il2CppType type, bool includeInactive);		

    // Returns the component of Type type in the GameObject or any of its parents.
    Component GetComponentInParent(Il2CppType type);		

    // Returns all components of Type type in the GameObject.
    Component* GetComponents(Il2CppType type);		

    // Returns all components of Type type in the GameObject or any of its children.
    Component* GetComponentsInChildren(Il2CppType type, bool includeInactive = false);		

    // Returns all components of Type type in the GameObject or any of its parents.
    Component* GetComponentsInParent(Il2CppType type, bool includeInactive = false);		

    // Calls the method named methodName on every MonoBehaviour in this game object.
    void SendMessage(string methodName);	

    // Calls the method named methodName on every MonoBehaviour in this game object and on every ancestor of the behaviour.
    void SendMessageUpwards(string methodName);	

    // Activates/Deactivates the GameObject, depending on the given true or false value.
    void SetActive(bool value);	

    // Gets the component of the specified type, if it exists.
    void* TryGetComponent();	

    // Static Methods //

    // Creates a game object with a primitive mesh renderer and appropriate collider.
    static GameObject CreatePrimitive();	

    // Finds a GameObject by name and returns it.
    GameObject Find();	

    // Returns a list of active GameObjects tagged tag. Returns empty array if no GameObject was found.
    GameObject FindGameObjectsWithTag();	

    // Returns one active GameObject tagged tag. Returns null if no GameObject was found.
    GameObject FindWithTag();	
};

#endif