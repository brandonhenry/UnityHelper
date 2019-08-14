
   #include "GameObject.h"
   
   Transform* GameObject::getTransform()
    {
        // runtime_invoke(getGameObjectTransform, customSaberGameObject, nullptr, &exception);
        // runtime_invoke(getGameObjectTransform,  saber.getGameObject(), nullptr, &exception);
        return &transform;
    }

    void GameObject::setActive(bool active)
    {
        // void *disableParam[] = {&getInactive};
        // runtime_invoke(gameObjectSetActive, filterObject, disableParam, &exception);
        activeInHierarchy = active;
    }
    
    // Custom Methods //
    Il2CppClass*  GameObject::getKlass(){
    {
        return GetClassFromName("UnityEngine", "GameObject");
    };