#include <android/log.h>
#include <stdlib.h>
#include <time.h>
#include <stdalign.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <array>
#include <vector>
#include <limits>
#include <map>

#include "../beatsaber-hook/shared/inline-hook/inlineHook.h"
#include "../beatsaber-hook/shared/utils/utils.h"

#include "utils/CommonStructs.h"
#include "utils/AssetBundleCreateRequest.h"
#include "utils/Scene.h"
#include "utils/GameObject.h"
#include "utils/MeshFilter.h"
#include "utils/Renderer.h"
#include "utils/BeatSaberUtils/Saber.h"
#include "utils/BeatSaberUtils/ColorManager.h"
#include "utils/Shader.h"
#include "utils/Resources.h"

//#undef log
//#define log(INFO,...) __android_log_print(ANDROID_LOG_INFO, "QuestHook", "[UnityHelper v0.1.0] " __VA_ARGS__)

//Hook offsets
#define set_active_scene_offset 0xD902B4
#define gameplay_core_scene_setup_start_offset 0x5268D0
#define saber_start_offset 0x538890
#define tutorial_controller_awake_offset 0x626A4C
#define MOD_ID "UnityHelper"
#define VERSION "0.1.0"

using il2cpp_utils::createcsstr;
using il2cpp_utils::GetClassFromName;
using il2cpp_utils::New;
using namespace il2cpp_functions;
using namespace CommonStructs;

static AssetBundleCreateRequest *asyncBundle;

MAKE_HOOK(set_active_scene, set_active_scene_offset, bool, int scene)
{
    log(INFO, "Called set_active_scene hook");
    bool result = set_active_scene(scene);

    //Get Scene Name
    auto sceneName = Scene::GetNameInternal(scene);

    //Code to run if menuCore
    if (std::strncmp(sceneName, "MenuCore", 8) == 0)
    {
        log(INFO, "MenuCore Scene");
    }
    log(INFO, "End set_active_scene hook");
    return result;
}

AssetBundle *customSaberAssetBundle;
GameObject *customSaberGameObject;
string saberLocation = "/sdcard/Android/data/com.beatgames.beatsaber/files/sabers/testSaber.qsaber";

MAKE_HOOK(gameplay_core_scene_setup_start, gameplay_core_scene_setup_start_offset, void, void *self)
{
    log(INFO, "Called gameplay_core_scene_setup_start hook");
    gameplay_core_scene_setup_start(self);
    if (asyncBundle == nullptr)
    {
        asyncBundle = AssetBundle::LoadFromFileAsync(saberLocation);
        (*asyncBundle).setAllowSceneActivation(true);
        log(INFO, "Loaded Async Bundle");
    }
    customSaberGameObject = nullptr;
}

MAKE_HOOK(tutorial_controller_awake, tutorial_controller_awake_offset, void, void *self)
{
    log(INFO, "Called tutorial_controller_awake hook");
    tutorial_controller_awake(self);
    
    if (asyncBundle == nullptr)
    {
        asyncBundle = AssetBundle::LoadFromFileAsync(saberLocation);
        (*asyncBundle).setAllowSceneActivation(true);
        log(INFO, "Loaded Async Bundle");
    }
    customSaberGameObject = nullptr;
}

void ReplaceSaber(Saber *, GameObject *);
MAKE_HOOK(saber_start, saber_start_offset, void, Saber *self)
{
    saber_start(self);

    log(INFO, "Called saber_start hook");
    //Load Custom Saber Objects if not loaded
    if (customSaberAssetBundle == nullptr)
    {
        customSaberAssetBundle = (*asyncBundle).getAsset();
        log(INFO, "Grabbed Asset bundle");
        asyncBundle = nullptr;
    }

    if (customSaberGameObject == nullptr && customSaberAssetBundle != nullptr)
    {
        static AssetBundleRequest* assetAsync = (*customSaberAssetBundle).LoadAssetAsync("_customsaber");
        AssetBundle *customSaberObject = reinterpret_cast<AssetBundle *>((*assetAsync).getAsset());
        customSaberGameObject = reinterpret_cast<GameObject *>(UnityObject::Instantiate(customSaberObject));
    }

    if (customSaberGameObject != nullptr)
    {
        log(INFO, "Replacing Saber with Custom Saber");
        ReplaceSaber(self, customSaberGameObject);
    }
}


void *GetFirstObjectOfType(Il2CppClass *);
void SpawnControllerNoteWasCut(void *BeatmapObjectSpawnController, void *NoteController, void *NoteCutInfo);
void ReplaceSaber(Saber *saber, GameObject *customSaberObject)
{
    int saberType = (*saber).getType();
    string saberName = saberType == 0 ? "LeftSaber" : "RightSaber";

    Transform *childTransform = (*customSaberGameObject).getTransform();
    childTransform = (*childTransform).Find(saberName);
    GameObject *parentGameObj = (*saber).getGameObject();
    Transform *parentSaberTransform = (*parentGameObj).getTransform();
    
    Vector3 parentPos = (*parentSaberTransform).getPosition();
    Vector3 parentRot = (*parentSaberTransform).getEulerAngles();

    Array<Component *>* meshfilters[] = {(*parentSaberTransform).GetComponentsInChildren(MeshFilter::getType(), false)};

    for (int i = 0; i < (*meshfilters)->Length(); i++)
    {
        Component *myComp = (*meshfilters)->values[i];
        GameObject *filterObject = (*myComp).getGameObject();
        (*filterObject).setActive(false);
    }

    log(INFO, "Disabled Original Saber Meshes");

    (*childTransform).setParent(parentSaberTransform);
    (*childTransform).setPosition(parentPos);
    (*childTransform).setEulerAngles(parentRot);
    
    log(INFO, "Placed Custom Saber");

    log(INFO, "Attempting to set colors of Custom Saber to colorManager Colors");
    ColorManager *colorManager = reinterpret_cast<ColorManager *>(GetFirstObjectOfType(ColorManager::getKlass()));
    if (colorManager != nullptr)
    {
        
        Color colorForType = ColorManager::ColorForSaberType(saberType);
        Array<Component *> *renderers = (*childTransform).GetComponentsInChildren(Renderer::getKlass(), false);
        
        for (int i = 0; i < renderers->Length(); ++i)
        {
            Array<Material *> *sharedMaterials = Renderer::GetSharedMaterials();
            for (int j = 0; j < sharedMaterials->Length(); ++j)
            {
                Material *myMat = sharedMaterials->values[j];
                string gameObjectName = (*myMat).ToString();

                Il2CppString *glowString = createcsstr("_Glow");
                Il2CppString *bloomString = createcsstr("_Bloom");
                Il2CppString *materialColor = createcsstr("_Color");
                void *glowStringParams[] = {glowString};
                void *bloomStringParams[] = {bloomString};
                int glowInt = Shader::PropertyToID("_Glow");
                int bloomInt = Shader::PropertyToID("_Bloom");

                bool setColor = false;
                bool hasGlow = (*myMat).hasProperty(glowInt);
                
                if (hasGlow)
                {
                    float glowFloat = (*myMat).getFloat(glowInt);
                    if (glowFloat > 0)
                        setColor = true;
                }

                if (!setColor)
                {
                    bool hasBloom = (*myMat).hasProperty(bloomInt);
                    if (hasBloom)
                    {
                        float bloomFloat = (*myMat).getFloat(bloomInt);
                        if (bloomFloat > 0)
                            setColor = true;
                    }
                }

                if (setColor)
                {
                    (*myMat).setColor("_Color", colorForType);                    
                }
            }
        }
    }
    else
    {
        log(INFO, "null colorManager");
    }

    log(INFO, "Finished With Saber");
}

void SpawnControllerNoteWasCut(void *BeatmapObjectSpawnController, void *NoteController, void *NoteCutInfo)
{
    log(INFO, "Note Was Cut Callback");
}

void *GetFirstObjectOfType(Il2CppClass *klass)
{
    Array<void *> *objects = Resources::FindObjectsOfTypeAll(klass);
    
    if (objects != nullptr)
    {
        return objects->values[0];
    }
    else
    {
        return nullptr;
    }
}

__attribute__((constructor)) void lib_main()
{
    log(INFO, "Installing Custom Sabers Hooks!");
    INSTALL_HOOK(set_active_scene);
    INSTALL_HOOK(gameplay_core_scene_setup_start);
    INSTALL_HOOK(saber_start);
    INSTALL_HOOK(tutorial_controller_awake);
    log(INFO, "Installed Custom Sabers Hooks!");
    log(INFO, "Initializing il2cpp api functions for Custom Sabers.");
    Init();
    log(INFO, "Initialized il2cpp api functions for Custom Sabers.");
}
