
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
}

#endif /* UNITY_HELPER_H */