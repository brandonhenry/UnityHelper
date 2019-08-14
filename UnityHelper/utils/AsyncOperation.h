#include <android/log.h>
#include <iostream>

#ifndef ASSET_OPERATION_H
#define ASSET_OPERATION_H

#include "../../beatsaber-hook/shared/utils/utils.h"

using std::string;
using il2cpp_utils::createcsstr;
using il2cpp_utils::GetClassFromName;
using il2cpp_utils::New;
using namespace il2cpp_functions;

class AsyncOperation {
    
public:
    // Fields //

    Il2CppException *exception;
    enum struct MethodList
    {
        setAllowSceneActivation
    };

    static const MethodInfo* getMethod(MethodList method);

    // Allow Scenes to be activated as soon as it is ready.
    bool allowSceneActivation;

    // Has the operation finished? (Read Only)
    bool isDone;	

    // Priority lets you tweak in which order async operation calls will be performed.
    int priority;

    // What's the operation's progress. (Read Only)
    float progress;	

    // Getters & Setters //

    bool getIsDone();

    int getPriority();

    void setPriority(int p);

    float getProgress();

    void setAllowSceneActivation(bool allow);

    static Il2CppClass* getKlass();
};

#endif