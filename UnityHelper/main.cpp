#include <android/log.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h> 
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <linux/limits.h>
#include <sys/sendfile.h>
#include <sys/stat.h>

#define MOD_ID "Enable Bloom"
#define VERSION "0.0.1"

#include "../beatsaber-hook/shared/inline-hook/inlineHook.h"
#include "../beatsaber-hook/shared/utils/utils.h"
#ifndef JSMN_INCLUDED
#endif

#undef log
#define log(...) __android_log_print(ANDROID_LOG_INFO, "QuestHook", "[Enable Bloom v0.0.1] " __VA_ARGS__)

// Constants
#define WallLayer 25
#define MoveBackLayer 27


using il2cpp_utils::GetClassFromName;
using il2cpp_utils::New;
using il2cpp_utils::createcsstr;
using namespace il2cpp_functions;
using std::string;

static Il2CppClass *meshClass;
static const MethodInfo *meshSetColors;

void GrabMethods();

#define OFFSET 0x47E2D4
MAKE_HOOK(TestHook, OFFSET, void, void* self)
{
    log("Guess whattttttt");
    return TestHook(self);
}

// INSTALL HOOKS

__attribute__((constructor)) void lib_main()
{
    log("Installing Test Hook...");
    INSTALL_HOOK(TestHook);
    log("Success!");
}

void GrabMethods()
{
    // if (meshClass == nullptr)
    //     meshClass = GetClassFromName("UnityEngine", "Mesh");
    // if (meshSetColors == nullptr)
    //     meshSetColors = class_get_method_from_name(meshClass, "SetColors", 1);
}