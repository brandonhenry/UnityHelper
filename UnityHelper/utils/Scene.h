
#ifndef SCENE_H
#define SCENE_H

using std::string;
using il2cpp_utils::createcsstr;
using il2cpp_utils::GetClassFromName;
using il2cpp_utils::New;
using namespace il2cpp_functions;

class Scene 
{
public:

    static auto GetNameInternal(int scene){
        const MethodInfo *sceneNameMethodInfo = class_get_method_from_name(Scene::getKlass(), "GetNameInternal", 1);

        Il2CppException *exception = nullptr;
        void *sceneNameparams[] = {&scene};

        auto nameResult = runtime_invoke(sceneNameMethodInfo, nullptr, sceneNameparams, &exception);
        Il2CppString *csName = reinterpret_cast<Il2CppString *>(nameResult);

        return to_utf8(csstrtostr(csName)).c_str();
        
    }
    
    Il2CppClass* getKlass(){
        return GetClassFromName("UnityEngine.SceneManagement", "Scene");
    }

};

#endif