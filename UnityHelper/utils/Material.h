#ifndef MATERIAL_H
#define MATERIAL_H


class Material : public UnityObject, Il2CppObject
{
    public: 
        // // The main material's color.
        // Color color	

        // // Gets and sets whether the Double Sided Global Illumination setting is enabled for this material.
        // doubleSidedGI	

        // // Gets and sets whether GPU instancing is enabled for this material.
        // enableInstancing	

        // // Defines how the material should interact with lightmaps and lightprobes.
        // globalIlluminationFlags	

        // // The material's texture.
        // mainTexture	

        // // The texture offset of the main texture.
        // mainTextureOffset	

        // // The texture scale of the main texture.
        // mainTextureScale	

        // // How many passes are in this material (Read Only).
        // passCount	

        // // Render queue of this material.
        // renderQueue	

        // // The shader used by the material.
        // shader	

        // // Additional shader keywords set by this material.
        // shaderKeywords	

        bool hasProperty(int propID)
        {
            const MethodInfo* materialHasProperty = class_get_method_from_name(Material::getKlass(), "HasProperty", 1);
            void *params[] = {&propID};
            return runtime_invoke(materialHasProperty, this, params, &exception);
        }

        float getFloat(int namdeID){
            const MethodInfo* materialGetFloat = class_get_method_from_name(Material::getKlass(), "GetFloat", 1);
            void *params[] = {&namdeID};
            return *(reinterpret_cast<float *>(object_unbox(runtime_invoke(materialGetFloat, this, params, &exception))));
        }

        void setColor(string name, Color value){
            const MethodInfo* materialSetColor = class_get_method_from_name(materialClass, "SetColor", 2);
            void *materialColorParams[] = {name, &value};
            runtime_invoke(materialSetColor, this, materialColorParams, &exception);
        }

        static Il2CppClass* getKlass(){
            return GetClassFromName("UnityEngine", "Material");
        }


};

#endif