#ifndef ASSET_OPERATION_H
#define ASSET_OPERATION_H

class AsyncOperation {
    //Allow Scenes to be activated as soon as it is ready.
    bool allowSceneActivation;
    // Has the operation finished? (Read Only)
    bool isDone;	
    // Priority lets you tweak in which order async operation calls will be performed.
    int priority	;
    // What's the operation's progress. (Read Only)
    float progress;	

    void setAllowSceneActivation(bool allow)
    {
        const MethodInfo *asyncOperationSetAllowSceneActivation = class_get_method_from_name(AsyncOperation::getKlass(), "set_allowSceneActivation", 1);
        void *setSceneActivationParams[] = {&allow};
        runtime_invoke(asyncOperationSetAllowSceneActivation, this, setSceneActivationParams, &exception);
    }

    bool getIsDone(){
        return isDone;
    }

    static Il2CppClass* getKlass()
    {
        return GetClassFromName("UnityEngine", "AsyncOperation");
    }
};

#endif