#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Matrix4x4.h"
#include "Component.h"
#include "CommonStructs.h"

using namespace CommonStructs;

class Transform : public Component, Il2CppObject
{
public:
    enum struct MethodList {
        
    };

    static const MethodInfo* getMethod(MethodList method);
    static Il2CppClass* getKlass();

    // Fields : Il2Cpp //

    Il2CppException *exception;

    // The number of children the parent Transform has.
    int childCount;

    // The rotation as Euler angles in degrees.
    Vector3 eulerAngles;

    // The blue axis of the transform in world space.
    Vector3 forward;	

    // Has the transform changed since the last time the flag was set to 'false'?
    bool hasChanged;	

    // The transform capacity of the transform's hierarchy data structure.
    int hierarchyCapacity;	

    // The number of transforms in the transform's hierarchy data structure.
    int hierarchyCount;

    // The rotation as Euler angles in degrees relative to the parent transform's rotation.
    Vector3 localEulerAngles;	

    // Position of the transform relative to the parent transform.
    Vector3 localPosition;	

    // The rotation of the transform relative to the transform rotation of the parent.
    Quaternion localRotation;	

    // The scale of the transform relative to the parent.
    Vector3 localScale;

    // Matrix that transforms a point from local space into world space (Read Only).
    Matrix4x4 localToWorldMatrix;	

    // The global scale of the object (Read Only).
    Vector3 lossyScale;	

    // The parent of the transform.
    Transform *parent;	

    // The world space position of the Transform.
    Vector3 position;	

    // The red axis of the transform in world space.
    Vector3 right;	

    // Returns the topmost transform in the hierarchy.
    // Transform *root;	

    // A quaternion that stores the rotation of the Transform in world space.
    Quaternion rotation;	

    // The green axis of the transform in world space.
    Vector3 up;	

    // Matrix that transforms a point from world space into local space (Read Only).
    Matrix4x4 worldToLocalMatrix;

    // Methods //

    // Unparents all children.
    void DetachChildren();

    // Finds a child by n and returns it.
    Transform* Find(string n);

    Vector3 getPosition();

    void setPosition(Vector3 position);

    Vector3 getEulerAngles();

    void setEulerAngles(Vector3 eulerAngles);

    void setParent(Component *parent);

    // Returns a transform child by index.
    Transform* GetChild(int index);	

    // Gets the sibling index.
    int GetSiblingIndex();

    // Transforms a direction from world space to local space. The opposite of Transform.TransformDirection.
    Vector3 InverseTransformDirection(Vector3 direction);

    // Transforms position from world space to local space.
    Vector3 InverseTransformPoint(Vector3 position);

    // Transforms a vector from world space to local space. The opposite of Transform.TransformVector.
    Vector3 InverseTransformVector(Vector3 vector);

    // Is this transform a child of parent?
    bool IsChildOf(Transform* parent);	

    // Rotates the transform so the forward vector points at /target/'s current position.
    void LookAt(Transform* target);	

    // Use Transform.Rotate to rotate GameObjects in a variety of ways. The rotation is often provided as a Euler angle and not a Quaternion.
    void Rotate(Vector3 eulers);	

    // Rotates the transform about axis passing through point in world coordinates by angle degrees.
    void RotateAround(Vector3 point, Vector3 axis, float angle);

    // Move the transform to the start of the local transform list.
    void SetAsFirstSibling();

    // Move the transform to the end of the local transform list.
    void SetAsLastSibling();	

    // Set the parent of the transform. If true, the parent-relative position, scale and rotation are modified such that the object keeps the same world space position, rotation and scale as before.
    void SetParent(Transform* parent, bool worldPositionStays);

    // Sets the world space position and rotation of the Transform component.
    void SetPositionAndRotation(Vector3 position, Quaternion rotation);

    // Sets the sibling index.
    void SetSiblingIndex(int index);

    // Transforms direction from local space to world space.
    Vector3 TransformDirection(Vector3 direction);	

    // Transforms position from local space to world space.
    Vector3 TransformPoint(Vector3 position);	

    // Transforms vector from local space to world space.
    Vector3 TransformVector(Vector3 vector);

    // Moves the transform in the direction and distance of translation.
    void Translate(Vector3 translation);	
};

#endif