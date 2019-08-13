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
#include "utils/AssetBundle.h"
#include "utils/Scene.h"

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

template <class T>
struct List : Il2CppObject
{
    Array<T> *items;
    int size;
    int version;    // ?
    void *syncRoot; // ?
    uint padding2;  // ?
    uint padding3;  // ?

    //   auto static LIST_ADD_ITEM = reinterpret_cast<function_ptr_t<void, List<T> *, T>>(getRealOffset(0x12105A4));
};

typedef struct
{
    float x;
    float y;
    float z;
    float w;
} Quaternion;

struct SaveDataNoteData : Il2CppObject
{
    float time;
    int lineIndex;
    int lineLayer;
    int type;
    int cutDirection;
};

struct Bounds : Il2CppObject
{
    Vector3 center;
    Vector3 extents;
};

struct Scene : Il2CppObject
{
    int handle;
};

Quaternion ToQuaternion(float pitch, float yaw, float roll) // yaw (Z), pitch (Y), roll (X)
{
    // Abbreviations for the various angular functions
    yaw *= 0.01745329251;
    pitch *= 0.01745329251;
    roll *= 0.01745329251;
    float rollOver2 = roll * 0.5f;
    float sinRollOver2 = sinf(rollOver2);
    float cosRollOver2 = cosf(rollOver2);
    float pitchOver2 = pitch * 0.5f;
    float sinPitchOver2 = sinf(pitchOver2);
    float cosPitchOver2 = cosf(pitchOver2);
    float yawOver2 = yaw * 0.5f;
    float sinYawOver2 = sinf(yawOver2);
    float cosYawOver2 = cosf(yawOver2);
    Quaternion result;
    result.w = cosYawOver2 * cosPitchOver2 * cosRollOver2 + sinYawOver2 * sinPitchOver2 * sinRollOver2;
    result.x = cosYawOver2 * sinPitchOver2 * cosRollOver2 + sinYawOver2 * cosPitchOver2 * sinRollOver2;
    result.y = sinYawOver2 * cosPitchOver2 * cosRollOver2 - cosYawOver2 * sinPitchOver2 * sinRollOver2;
    result.z = cosYawOver2 * cosPitchOver2 * sinRollOver2 - sinYawOver2 * sinPitchOver2 * cosRollOver2;

    return result;
}

Vector3 AddVectors(Vector3 left, Vector3 right)
{

    Vector3 result;
    result.x = left.x + right.x;
    result.y = left.y + right.y;
    result.z = left.z + right.z;
    return result;
}
Vector3 SubtractVectors(Vector3 left, Vector3 right)
{
    Vector3 result;
    result.x = left.x - right.x;
    result.y = left.y - right.y;
    result.z = left.z - right.z;
    return result;
}
float VectorMagnitude(Vector3 vector)
{
    return sqrtf(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
}

static AssetBundleCreateRequest asyncBundle;

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
