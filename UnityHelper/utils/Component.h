#ifndef COMPONENT_H
#define COMPONENT_H

#include "UnityObject.h"
#include "GameObject.h"
#include "Transform.h"
#include "CommonStructs.h"

using namespace CommonStructs;

class Component : public UnityObject
{
    public: 

        enum struct MethodList {
            GetComponentsInChildren,
            GetGameObject
        };

        static const MethodInfo* getMethod(MethodList method);

        // Fields : Il2Cpp //

        Il2CppException *exception;

        // // Fields //

        // The game object this component is attached to. A component is always attached to a game object.
        GameObject gameObject;

        // The tag of this game object.
        string tag;

        // The Transform attached to this GameObject.
        Transform transform;

        // Public Methods // 

        GameObject* getGameObject();

        string getTag();

        Transform getTransform();

        // Returns all components of Type type in the GameObject or any of its children.
        Array<Component *>* GetComponentsInChildren(void* t, bool includeInactive);

        static Il2CppClass* getKlass();

        // Calls the method named methodName on every MonoBehaviour in this game object or any of its children.
        void BroadcastMessage(string methodName, SendMessageOptions options);

        // Is this game object tagged with tag ?
        bool CompareTag(string tag); 

        // Returns the component of Type type if the game object has one attached, null if it doesn't.
        Component GetComponent(Il2CppType type);

        // Returns the component of Type type in the GameObject or any of its children using depth first search.
        Component GetComponentInChildren(Il2CppType t);

        // Returns the component of Type type in the GameObject or any of its parents.
        Component GetComponentInParent(Il2CppType t);	

        // Returns all components of Type type in the GameObject.
        Component* GetComponents(Il2CppType type);	

        // Returns all components of Type type in the GameObject or any of its parents.
        Component* GetComponentsInParent(Il2CppType t, bool includeInactive = false);

        // Calls the method named methodName on every MonoBehaviour in this game object.
        void SendMessage(string methodName, void* value);

        // Calls the method named methodName on every MonoBehaviour in this game object and on every ancestor of the behaviour.
        void SendMessageUpwards(string methodName, SendMessageOptions options);

        // Gets the component of the specified type, if it exists.
        bool TryGetComponent(Il2CppType type, Component *component);
};

#endif