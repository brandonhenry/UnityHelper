
// Serves as a Helper library for Unity Scripting (https://docs.unity3d.com/ScriptReference/index.html)
// for Il2Cpp Unity projects

#ifndef UNITY_HELPER_H
#define UNITY_HELPER_H

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

namespace UnityHelper
{
    int UnityHelper();
}

#endif /* UNITY_HELPER_H */