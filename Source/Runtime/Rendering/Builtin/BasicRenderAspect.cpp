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
	float4x4 Mvp;
};
struct VS_INPUT
{
    float3 pos : POSITION;
    float3 normal : NORMAL;
    float3 tangent : TANGENT0;
    float3 bitangent : TANGENT1;
    float2 uv : TEXCOORD0;
};
            
struct PS_INPUT
{
    float4 pos : SV_POSITION;
    float2 uv : TEXCOORD0;
	float3 normal : TEXCOORD1;
	float3 tangent : TEXCOORD2;
	float3 bitangent : TEXCOORD3;
};
            
PS_INPUT main(VS_INPUT input)
{
    PS_INPUT output;
    output.pos = float4(input.pos, 1.0f)*Mvp;
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
				float4 pos : SV_POSITION;
				float2 uv : TEXCOORD0;
				float3 normal : TEXCOORD1;
				float3 tangent : TEXCOORD2;
				float3 bitangent : TEXCOORD3;
			};

          
			float4 main(PS_INPUT input) : SV_Target
			{
				float4 out_col = texture0.Sample(sampler0,input.uv);
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
