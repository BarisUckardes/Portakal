#include "BasicRenderAspect.h"
#include <Runtime/World/Aspects/DisplayAspect.h>
#include <Runtime/World/Scene.h>
#include <Runtime/Graphics/GraphicsAPI.h>
#include <Runtime/ShaderCompiler/ShaderCompiler.h>
#include <Runtime/Resource/Mesh/MeshLoader.h>
#include <Runtime/Graphics/Texture/TextureLoader.h>
#include <Runtime/Rendering/Builtin/BasicMeshVertex.h>
#include <Runtime/Math/Matrix4x4.h>

namespace Portakal
{
    static const Char gTestVertexShader[] = R""""(
layout(set=0,binding=0) cbuffer vertexBuffer         
{
	Float324x4 Mvp;
};
struct VS_INPUT
{
    Float323 pos : POSITION;
    Float323 normal : NORMAL;
    Float323 tangent : TANGENT0;
    Float323 bitangent : TANGENT1;
    Float322 uv : TEXCOORD0;
};
            
struct PS_INPUT
{
    Float324 pos : SV_POSITION;
    Float322 uv : TEXCOORD0;
	Float323 normal : TEXCOORD1;
	Float323 tangent : TEXCOORD2;
	Float323 bitangent : TEXCOORD3;
};
            
PS_INPUT main(VS_INPUT input)
{
    PS_INPUT output;
    output.pos = Float324(input.pos, 1.0f)*Mvp;
    output.uv = input.uv;
	output.normal = input.normal;
	output.tangent = input.tangent;
	output.bitangent = input.bitangent;
    return output;
}
)"""";;    static const Char gTestFragmentShader[] = R""""(
			

            layout(set=0,binding=1) Texture2D texture0;
			layout(set=0,binding=2) sampler sampler0;
			struct PS_INPUT
			{
				Float324 pos : SV_POSITION;
				Float322 uv : TEXCOORD0;
				Float323 normal : TEXCOORD1;
				Float323 tangent : TEXCOORD2;
				Float323 bitangent : TEXCOORD3;
			};

          
			Float324 main(PS_INPUT input) : SV_Target
			{
				Float324 out_col = texture0.Sample(sampler0,input.uv);
				return out_col;
			}
)"""";;
    void BasicRenderAspect::RegisterCamera(const BasicCamera* pCamera)
    {
        mCameras.Add(pCamera);
    }
    void BasicRenderAspect::RemoveCamera(const BasicCamera* pCamera)
    {
        mCameras.Remove(pCamera);
    }
    void BasicRenderAspect::RegisterRenderable(const BasicRenderable* pRenderable)
    {
        mRenderables.Add(pRenderable);
    }
    void BasicRenderAspect::RemoveRenderable(const BasicRenderable* pRenderable)
    {
        mRenderables.Remove(pRenderable);
    }

    void BasicRenderAspect::OnInitialize()
    {
      
	}

    void BasicRenderAspect::OnExecute()
    {
		Scene* pScene = GetOwnerScene();
		DisplayAspect* pAspect = pScene->GetAspect<DisplayAspect>();
		if (pAspect == nullptr)
			return;

    }
}
