#ifndef COMMON_STRUCTS_H
#define COMMON_STRUCTS_H

#include "../../beatsaber-hook/shared/utils/utils.h"

using std::string;
using il2cpp_utils::createcsstr;
using il2cpp_utils::GetClassFromName;
using il2cpp_utils::New;
using namespace il2cpp_functions;

namespace CommonStructs
{

    // Structs //

    template <class T>
    struct List : Il2CppObject
    {
        Array<T> *items;
        int size;
        int version;    // ?
        void *syncRoot; // ?
        uint padding2;  // ?
        uint padding3;  // ?
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

    typedef struct Vector4 : Il2CppObject {
        float w;
        float x;
        float y;
        float z;
    } Vector4;

    struct FrustumPlanes : Il2CppObject
    {
        // Position in view space of the bottom side of the near projection plane.
        float bottom;	

        // Position in view space of the left side of the near projection plane.
        float left;	

        // Position in view space of the right side of the near projection plane.
        float right;	

        // Position in view space of the top side of the near projection plane.
        float top;	

        // Z distance from the origin of view space to the far projection plane.
        float zFar;	

        // Z distance from the origin of view space to the near projection plane.
        float zNear;	
    };

    enum struct SendMessageOptions
    {
        RequireReceiver,
        DontRequireReceiver
    };

    // Light probe interpolation type.
    enum struct LightProbeUsage
    {
        // Light Probes are not used. The Scene's ambient probe is provided to the shader.
        Off,	
        // Simple light probe interpolation is used.
        BlendProbes,	
        // Uses a 3D grid of interpolated light probes.
        UseProxyVolume,	
        // The light probe shader uniform values are extracted from the material property block set on the renderer.
        CustomProvided	
    };

    // The type of motion vectors that should be generated.
    enum struct MotionVectorGenerationMode 
    {
        // Use only camera movement to track motion.
        Camera,	
        // Use a specific pass (if required) to track motion.
        Object,	
        // Do not track motion. Motion vectors will be 0.
        ForceNoMotion	
    };

    // Reflection Probe usage.
    enum struct ReflectionProbeUsage
    {
        // Reflection probes are disabled, skybox will be used for reflection.
        Off,
        // Reflection probes are enabled. Blending occurs only between probes, useful in indoor environments. The renderer will use default reflection if there are no reflection probes nearby, but no blending between default reflection and probe will occur.
        BlendProbes,
        // Reflection probes are enabled. Blending occurs between probes or probes and default reflection, useful for outdoor environments.
        BlendProbesAndSkybox,
        // Reflection probes are enabled, but no blending will occur between probes when there are two overlapping volumes.
        Simple	
    };

    // How shadows are cast from this object.
    enum struct ShadowCastingMode
    {
        // No shadows are cast from this object.
        Off,
        // Shadows are cast from this object.
        On,
        // Shadows are cast from this object, treating it as two-sided.
        TwoSided, 
        // Object casts shadows, but is otherwise invisible in the Scene.
        ShadowsOnly	
    };

    // Methods //

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

};
#endif