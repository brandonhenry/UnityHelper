#include "AsyncOperation.h"

bool AsyncOperation::getIsDone(){
    return isDone;
}

int AsyncOperation::getPriority()
{
    return priority;
}

void AsyncOperation::setPriority(int p)
{
    priority = p;
}

float AsyncOperation::getProgress()
{
    return progress;
}

void AsyncOperation::setAllowSceneActivation(bool allow)
{
    const MethodInfo *asyncOperationSetAllowSceneActivation = getMethod(MethodList::setAllowSceneActivation);
    void *setSceneActivationParams[] = {&allow};
    runtime_invoke(asyncOperationSetAllowSceneActivation, this, setSceneActivationParams, &exception);
    asyncOperationSetAllowSceneActivation = nullptr;
}

// Methods // 

Il2CppClass* AsyncOperation::getKlass()
{
    return GetClassFromName("UnityEngine", "AsyncOperation");
}

const MethodInfo* AsyncOperation::getMethod(MethodList method)
{
    switch (method)
    {
        case MethodList::setAllowSceneActivation:
            return class_get_method_from_name(AsyncOperation::getKlass(), "set_allowSceneActivation", 1);
    }
}