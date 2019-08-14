 #include "Transform.h"
 
 Transform* Transform::Find(string n){
    Il2CppString *saberName = createcsstr(n);
    const MethodInfo *findTransform = class_get_method_from_name(Transform::getKlass(), "Find", 1);
    void *saberChildParams[] = {saberName};
    runtime_invoke(findTransform, this, saberChildParams, &exception);
};

Vector3 Transform::getPosition(){
    // object_unbox(runtime_invoke(transformPosGet, parentSaberTransform, nullptr, &exception));
    return position;
}

void Transform::setPosition(Vector3 position)
{
    // runtime_invoke(transformPosSet, childTransform, &parentPos, &exception);
    this->position = position;
}

Vector3 Transform::getEulerAngles(){
    // object_unbox(runtime_invoke(transformEulerGet, parentSaberTransform, nullptr, &exception));
    return eulerAngles;
}

void Transform::setEulerAngles(Vector3 eulerAngles)
{
    // runtime_invoke(transformEulerSet, childTransform, &parentRot, &exception);
    this->eulerAngles = eulerAngles;
}

void Transform::setParent(Component *parent)
{
    // runtime_invoke(transformParentSet, childTransform, &parentSaberTransform, &exception);
    this->parent = reinterpret_cast<Transform *>(parent);
}
