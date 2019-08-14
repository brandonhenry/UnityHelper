#ifndef RENDERER_H
#define RENDERER_H

#include "Mesh.h"
#include "Component.h"
#include "CommonStructs.h"
#include "Material.h"

using namespace CommonStructs;

class Renderer : public Component, Il2CppObject
{
public: 

    enum struct MethodList {
        GetSharedMaterials
    };

    static const MethodInfo* getMethod(MethodList method);

    // Fields : Il2Cpp //

    Il2CppException *exception;

    // Fields //

    // Controls if dynamic occlusion culling should be performed for this renderer.
    bool allowOcclusionWhenDynamic;

    // The bounding volume of the renderer (Read Only).
    Bounds bounds;

    // Makes the rendered 3D object visible if enabled.
    bool enabled;	

    // Has this renderer been statically batched with any other renderers?
    bool isPartOfStaticBatch;	

    // Is this renderer visible in any camera? (Read Only)
    bool isVisible;	

    // The index of the baked lightmap applied to this renderer.
    int lightmapIndex;	

    // The UV scale & offset used for a lightmap.
    Vector4 lightmapScaleOffset;	

    // If set, the Renderer will use the Light Probe Proxy Volume component attached to the source GameObject.
    GameObject lightProbeProxyVolumeOverride;	

    // The light probe interpolation type.
    LightProbeUsage lightProbeUsage;	

    // Matrix that transforms a point from local space into world space (Read Only).
    Matrix4x4 localToWorldMatrix;	

    // Returns the first instantiated Material assigned to the renderer.
    Material material;	

    // Returns all the instantiated materials of this object.
    Array<Material *> materials;	

    // Specifies the mode for motion vector rendering.
    MotionVectorGenerationMode motionVectorGenerationMode;	

    // If set, Renderer will use this Transform's position to find the light or reflection probe.
    Transform probeAnchor;	

    // The index of the realtime lightmap applied to this renderer.
    int realtimeLightmapIndex;	

    // The UV scale & offset used for a realtime lightmap.
    Vector4 realtimeLightmapScaleOffset;	

    // Does this object receive shadows?
    bool receiveShadows;	

    // Should reflection probes be used for this Renderer?
    ReflectionProbeUsage reflectionProbeUsage;

    // This value sorts renderers by priority. Lower values are rendered first and higher values are rendered last.
    int rendererPriority;	

    // Determines which rendering layer this renderer lives on.
    uint renderingLayerMask;	

    // Does this object cast shadows?
    ShadowCastingMode shadowCastingMode;	

    // The shared material of this object.
    Material sharedMaterial;	

    // All the shared materials of this object.
    Array<Material *> sharedMaterials;	

    // Unique ID of the Renderer's sorting layer.
    int sortingLayerID;	

    // Name of the Renderer's sorting layer.
    string sortingLayerName;	

    // Renderer's order within a sorting layer.
    int sortingOrder;	

    // Matrix that transforms a point from world space into local space (Read Only).
    Matrix4x4 worldToLocalMatrix;	

    // Methods //

    // Returns all the shared materials of this object.
    static Array<Material *>* GetSharedMaterials();

    static void* getType();

    static Il2CppClass* getKlass();
};

#endif