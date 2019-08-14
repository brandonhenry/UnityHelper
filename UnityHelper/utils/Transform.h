#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Matrix4x4.h"

class Transform : public Component
{
public:
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
    Vector3 localScale	

    // Matrix that transforms a point from local space into world space (Read Only).
    Matrix4x4 localToWorldMatrix;	

    // The global scale of the object (Read Only).
    Vector3 lossyScale;	

    // The parent of the transform.
    Transform parent;	

    // The world space position of the Transform.
    Vector3 position;	

    // The red axis of the transform in world space.
    Vector3 right;	

    // Returns the topmost transform in the hierarchy.
    Transform root;	

    // A quaternion that stores the rotation of the Transform in world space.
    Quaternion rotation;	

    // The green axis of the transform in world space.
    Vector3 up;	

    // Matrix that transforms a point from world space into local space (Read Only).
    Matrix4x4 worldToLocalMatrix;

    // // Unparents all children.
    // DetachChildren	

    // Finds a child by n and returns it.
    Transform Find(string n){
        Il2CppString *saberName = createcsstr(n);
        const MethodInfo *findTransform = class_get_method_from_name(transformClass, "Find", 1);
        void *saberChildParams[] = {saberName};
        runtime_invoke(findTransform, this, saberChildParams, &exception);
    };

    Vector3 getPosition(){
        // object_unbox(runtime_invoke(transformPosGet, parentSaberTransform, nullptr, &exception));
        return position;
    }

    void setPosition(Vector3 position)
    {
        // runtime_invoke(transformPosSet, childTransform, &parentPos, &exception);
        this->position = position;
    }

    Vector3 getEulerAngles(){
        // object_unbox(runtime_invoke(transformEulerGet, parentSaberTransform, nullptr, &exception));
        return eulerAngles;
    }

    void setEulerAngles(Vector3 eulerAngles)
    {
        // runtime_invoke(transformEulerSet, childTransform, &parentRot, &exception);
        this->eulerAngles = eulerAngles;
    }

    void setParent(Component parent)
    {
        // runtime_invoke(transformParentSet, childTransform, &parentSaberTransform, &exception);
        this->parent = parent;
    }

    // // Returns a transform child by index.
    // GetChild	

    // // Gets the sibling index.
    // GetSiblingIndex	

    // // Transforms a direction from world space to local space. The opposite of Transform.TransformDirection.
    // InverseTransformDirection	

    // // Transforms position from world space to local space.
    // InverseTransformPoint	

    // // Transforms a vector from world space to local space. The opposite of Transform.TransformVector.
    // InverseTransformVector	

    // // Is this transform a child of parent?
    // IsChildOf	

    // // Rotates the transform so the forward vector points at /target/'s current position.
    // LookAt	

    // // Use Transform.Rotate to rotate GameObjects in a variety of ways. The rotation is often provided as a Euler angle and not a Quaternion.
    // Rotate	

    // // Rotates the transform about axis passing through point in world coordinates by angle degrees.
    // RotateAround	

    // // Move the transform to the start of the local transform list.
    // SetAsFirstSibling	

    // // Move the transform to the end of the local transform list.
    // SetAsLastSibling	

    // // Set the parent of the transform.
    // SetParent	

    // // Sets the world space position and rotation of the Transform component.
    // SetPositionAndRotation	

    // // Sets the sibling index.
    // SetSiblingIndex	

    // // Transforms direction from local space to world space.
    // TransformDirection	

    // // Transforms position from local space to world space.
    // TransformPoint	

    // // Transforms vector from local space to world space.
    // TransformVector	

    // // Moves the transform in the direction and distance of translation.
    // Translate	
};

#endif