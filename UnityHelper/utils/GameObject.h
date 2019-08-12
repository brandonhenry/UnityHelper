#include "Transform.h";
#include "Scene.h"
#include "Object.h"

class GameObject implements Object
{

public:

    // Fields //

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

    // Adds a component class named className to the game object.
    void AddComponent();	

    // Calls the method named methodName on every MonoBehaviour in this game object or any of its children.
    void BroadcastMessage();		

    // Is this game object tagged with tag ?
    bool CompareTag();	

    // Returns the component of Type type if the game object has one attached, null if it doesn't.
    void* GetComponent();		

    // Returns the component of Type type in the GameObject or any of its children using depth first search.
    void* GetComponentInChildren();		

    // Returns the component of Type type in the GameObject or any of its parents.
    void* GetComponentInParent();		

    // Returns all components of Type type in the GameObject.
    void** GetComponents();		

    // Returns all components of Type type in the GameObject or any of its children.
    void** GetComponentsInChildren();		

    // Returns all components of Type type in the GameObject or any of its parents.
    void** GetComponentsInParent();		

    // Calls the method named methodName on every MonoBehaviour in this game object.
    void SendMessage();	

    // Calls the method named methodName on every MonoBehaviour in this game object and on every ancestor of the behaviour.
    void SendMessageUpwards();	

    // Activates/Deactivates the GameObject, depending on the given true or false value.
    void SetActive();	

    // Gets the component of the specified type, if it exists.
    void* TryGetComponent();	

    // Static Methods //

    // Creates a game object with a primitive mesh renderer and appropriate collider.
    GameObject CreatePrimitive();	

    // Finds a GameObject by name and returns it.
    GameObject Find();	

    // Returns a list of active GameObjects tagged tag. Returns empty array if no GameObject was found.
    GameObject FindGameObjectsWithTag();	

    // Returns one active GameObject tagged tag. Returns null if no GameObject was found.
    GameObject FindWithTag();	

    // Custom Methods //
    Il2CppClass* getKlass();

private:
    Il2CppClass *klass;
};