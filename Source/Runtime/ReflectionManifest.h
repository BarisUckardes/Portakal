
#pragma once
#include <Runtime/Reflection/Reflection.h>
#include <Runtime/Reflection/ReflectionManifest.h>
#include <Runtime/Reflection/TypeDispatcher.h>
#include "MyAttribute.h"
#include "TestClass.h"
#include "Application\ApplicationModule.h"
#include "Containers\Guid.h"
#include "Math\Vector2F.h"
#include "Math\Vector2I.h"
#include "Math\Vector2UI.h"
#include "Math\Vector2US.h"
#include "Object\Object.h"
#include "Platform\PlatformType.h"
#include "Reflection\Attribute.h"
#include "Reflection\FieldMode.h"
#include "Reflection\ReflectionModule.h"
#include "Rendering\RenderGraph.h"
#include "Rendering\RenderOperation.h"
#include "Resource\CustomResourceDeserializer.h"
#include "Resource\IResourceDeserializer.h"
#include "Resource\ResourceAttribute.h"
#include "Resource\ResourceDescriptor.h"
#include "Resource\ResourceModule.h"
#include "Resource\ResourceSubObject.h"
#include "Window\WindowModule.h"
#include "World\Component.h"
#include "World\Entity.h"
#include "World\SceneAspect.h"
#include "World\SceneModule.h"
#include "Graphics\Common\CompareOperation.h"
#include "Graphics\Common\LogicOperation.h"
#include "Graphics\Sampler\SamplerAddressMode.h"
#include "Graphics\Sampler\SamplerBorderColor.h"
#include "Graphics\Sampler\SamplerFiltering.h"
#include "Graphics\Sampler\SamplerMapMode.h"
#include "Graphics\Shader\ShaderLanguage.h"
#include "Graphics\Shader\ShaderStage.h"
#include "Rendering\Builtin\BasicCamera.h"
#include "Rendering\Builtin\BasicRenderAspect.h"
#include "Resource\Material\MaterialResource.h"
#include "Resource\Mesh\MeshDeserializer.h"
#include "Resource\Mesh\MeshResource.h"
#include "Resource\RenderTarget\RenderTarget.h"
#include "Resource\Sampler\SamplerDescriptor.h"
#include "Resource\Sampler\SamplerDeserializer.h"
#include "Resource\Sampler\SamplerResource.h"
#include "Resource\Scene\SceneComponentDescriptor.h"
#include "Resource\Scene\SceneComponentFieldDescriptor.h"
#include "Resource\Scene\SceneComponentFieldType.h"
#include "Resource\Scene\SceneDescriptor.h"
#include "Resource\Scene\SceneDeserializer.h"
#include "Resource\Scene\SceneEntityDescriptor.h"
#include "Resource\Scene\SceneResource.h"
#include "Resource\Shader\ShaderDescriptor.h"
#include "Resource\Shader\ShaderDeserializer.h"
#include "Resource\Shader\ShaderResource.h"
#include "Resource\Texture\TextureDeserializer.h"
#include "Resource\Texture\TextureResource.h"
#include "World\Aspects\DisplayAspect.h"


		void* CreateBool8() {return new Portakal::Bool8();}
		void* CreateChar() {return new Portakal::Char();}
		void* CreateByte() {return new Portakal::Byte();}
		void* CreateUInt16() {return new Portakal::UInt16();}
		void* CreateUInt32() {return new Portakal::UInt32();}
		void* CreateUInt64() {return new Portakal::UInt64();}
		void* CreateInt16() {return new Portakal::Int16();}
		void* CreateInt32() {return new Portakal::Int32();}
		void* CreateInt64() {return new Portakal::Int64();}
		void* CreateFloat32() {return new Portakal::Float32();}
		void* CreateFloat64() {return new Portakal::Float64();}
		void* CreateString() {return new Portakal::String();}
		void* CreateMyAttribute() {return new Portakal::MyAttribute();}
		void* CreateTestClass() {return new Portakal::TestClass();}
		void* CreateApplicationModule() {return nullptr;}
		void* CreateGuid() {return new Portakal::Guid();}
		void* CreateVector2F() {return new Portakal::Vector2F();}
		void* CreateVector2I() {return new Portakal::Vector2I();}
		void* CreateVector2UI() {return new Portakal::Vector2UI();}
		void* CreateVector2US() {return new Portakal::Vector2US();}
		void* CreateObject() {return nullptr;}
		void* CreatePlatformType() {return new Portakal::PlatformType();}
		void* CreateAttribute() {return new Portakal::Attribute();}
		void* CreateFieldMode() {return new Portakal::FieldMode();}
		void* CreateReflectionModule() {return new Portakal::ReflectionModule();}
		void* CreateRenderGraph() {return new Portakal::RenderGraph();}
		void* CreateRenderOperation() {return nullptr;}
		void* CreateCustomResourceDeserializer() {return new Portakal::CustomResourceDeserializer();}
		void* CreateIResourceDeserializer() {return nullptr;}
		void* CreateResourceAttribute() {return new Portakal::ResourceAttribute();}
		void* CreateResourceDescriptor() {return new Portakal::ResourceDescriptor();}
		void* CreateResourceModule() {return new Portakal::ResourceModule();}
		void* CreateResourceSubObject() {return nullptr;}
		void* CreateWindowModule() {return new Portakal::WindowModule();}
		void* CreateComponent() {return nullptr;}
		void* CreateEntity() {return new Portakal::Entity();}
		void* CreateSceneAspect() {return nullptr;}
		void* CreateSceneModule() {return new Portakal::SceneModule();}
		void* CreateCompareOperation() {return new Portakal::CompareOperation();}
		void* CreateLogicOperation() {return new Portakal::LogicOperation();}
		void* CreateSamplerAddressMode() {return new Portakal::SamplerAddressMode();}
		void* CreateSamplerBorderColor() {return new Portakal::SamplerBorderColor();}
		void* CreateSamplerFiltering() {return new Portakal::SamplerFiltering();}
		void* CreateSamplerMapMode() {return new Portakal::SamplerMapMode();}
		void* CreateShaderLanguage() {return new Portakal::ShaderLanguage();}
		void* CreateShaderStage() {return new Portakal::ShaderStage();}
		void* CreateBasicCamera() {return new Portakal::BasicCamera();}
		void* CreateBasicRenderAspect() {return new Portakal::BasicRenderAspect();}
		void* CreateMaterialResource() {return new Portakal::MaterialResource();}
		void* CreateMeshDeserializer() {return new Portakal::MeshDeserializer();}
		void* CreateMeshResource() {return new Portakal::MeshResource();}
		void* CreateRenderTarget() {return new Portakal::RenderTarget();}
		void* CreateSamplerDescriptor() {return new Portakal::SamplerDescriptor();}
		void* CreateSamplerDeserializer() {return new Portakal::SamplerDeserializer();}
		void* CreateSamplerResource() {return new Portakal::SamplerResource();}
		void* CreateSceneComponentDescriptor() {return new Portakal::SceneComponentDescriptor();}
		void* CreateSceneComponentFieldDescriptor() {return new Portakal::SceneComponentFieldDescriptor();}
		void* CreateSceneComponentFieldType() {return new Portakal::SceneComponentFieldType();}
		void* CreateSceneDescriptor() {return new Portakal::SceneDescriptor();}
		void* CreateSceneDeserializer() {return new Portakal::SceneDeserializer();}
		void* CreateSceneEntityDescriptor() {return new Portakal::SceneEntityDescriptor();}
		void* CreateSceneResource() {return new Portakal::SceneResource();}
		void* CreateShaderDescriptor() {return new Portakal::ShaderDescriptor();}
		void* CreateShaderDeserializer() {return new Portakal::ShaderDeserializer();}
		void* CreateShaderResource() {return new Portakal::ShaderResource();}
		void* CreateTextureDeserializer() {return new Portakal::TextureDeserializer();}
		void* CreateTextureResource() {return new Portakal::TextureResource();}
		void* CreateDisplayAspect() {return new Portakal::DisplayAspect();}

extern "C"
{
	__declspec(dllexport) Portakal::ReflectionManifest* GenerateModuleManifest()
	{
		Portakal::ReflectionManifest* pManifest = nullptr;

		//Create types here
		Portakal::Type* pBool8 = Portakal::TypeDispatcher::CreateType("Bool8",sizeof(Portakal::Bool8),Portakal::TypeModes::Class,Portakal::TypeCodes::Bool,CreateBool8,Portakal::TypeDispatcher::GetTypeAddress<Portakal::Bool8>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::Bool8>(pBool8);
		Portakal::Type* pChar = Portakal::TypeDispatcher::CreateType("Char",sizeof(Portakal::Char),Portakal::TypeModes::Class,Portakal::TypeCodes::Char,CreateChar,Portakal::TypeDispatcher::GetTypeAddress<Portakal::Char>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::Char>(pChar);
		Portakal::Type* pByte = Portakal::TypeDispatcher::CreateType("Byte",sizeof(Portakal::Byte),Portakal::TypeModes::Class,Portakal::TypeCodes::Byte,CreateByte,Portakal::TypeDispatcher::GetTypeAddress<Portakal::Byte>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::Byte>(pByte);
		Portakal::Type* pUInt16 = Portakal::TypeDispatcher::CreateType("UInt16",sizeof(Portakal::UInt16),Portakal::TypeModes::Class,Portakal::TypeCodes::UInt16,CreateUInt16,Portakal::TypeDispatcher::GetTypeAddress<Portakal::UInt16>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::UInt16>(pUInt16);
		Portakal::Type* pUInt32 = Portakal::TypeDispatcher::CreateType("UInt32",sizeof(Portakal::UInt32),Portakal::TypeModes::Class,Portakal::TypeCodes::UInt32,CreateUInt32,Portakal::TypeDispatcher::GetTypeAddress<Portakal::UInt32>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::UInt32>(pUInt32);
		Portakal::Type* pUInt64 = Portakal::TypeDispatcher::CreateType("UInt64",sizeof(Portakal::UInt64),Portakal::TypeModes::Class,Portakal::TypeCodes::UInt64,CreateUInt64,Portakal::TypeDispatcher::GetTypeAddress<Portakal::UInt64>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::UInt64>(pUInt64);
		Portakal::Type* pInt16 = Portakal::TypeDispatcher::CreateType("Int16",sizeof(Portakal::Int16),Portakal::TypeModes::Class,Portakal::TypeCodes::Int16,CreateInt16,Portakal::TypeDispatcher::GetTypeAddress<Portakal::Int16>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::Int16>(pInt16);
		Portakal::Type* pInt32 = Portakal::TypeDispatcher::CreateType("Int32",sizeof(Portakal::Int32),Portakal::TypeModes::Class,Portakal::TypeCodes::Int32,CreateInt32,Portakal::TypeDispatcher::GetTypeAddress<Portakal::Int32>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::Int32>(pInt32);
		Portakal::Type* pInt64 = Portakal::TypeDispatcher::CreateType("Int64",sizeof(Portakal::Int64),Portakal::TypeModes::Class,Portakal::TypeCodes::Int64,CreateInt64,Portakal::TypeDispatcher::GetTypeAddress<Portakal::Int64>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::Int64>(pInt64);
		Portakal::Type* pFloat32 = Portakal::TypeDispatcher::CreateType("Float32",sizeof(Portakal::Float32),Portakal::TypeModes::Class,Portakal::TypeCodes::Float,CreateFloat32,Portakal::TypeDispatcher::GetTypeAddress<Portakal::Float32>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::Float32>(pFloat32);
		Portakal::Type* pFloat64 = Portakal::TypeDispatcher::CreateType("Float64",sizeof(Portakal::Float64),Portakal::TypeModes::Class,Portakal::TypeCodes::Double,CreateFloat64,Portakal::TypeDispatcher::GetTypeAddress<Portakal::Float64>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::Float64>(pFloat64);
		Portakal::Type* pString = Portakal::TypeDispatcher::CreateType("String",sizeof(Portakal::String),Portakal::TypeModes::Class,Portakal::TypeCodes::String,CreateString,Portakal::TypeDispatcher::GetTypeAddress<Portakal::String>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::String>(pString);
		Portakal::Type* pMyAttribute = Portakal::TypeDispatcher::CreateType("MyAttribute",sizeof(Portakal::MyAttribute),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateMyAttribute,Portakal::TypeDispatcher::GetTypeAddress<Portakal::MyAttribute>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::MyAttribute>(pMyAttribute);
;		Portakal::Type* pTestClass = Portakal::TypeDispatcher::CreateType("TestClass",sizeof(Portakal::TestClass),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateTestClass,Portakal::TypeDispatcher::GetTypeAddress<Portakal::TestClass>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::TestClass>(pTestClass);
;		Portakal::Type* pApplicationModule = Portakal::TypeDispatcher::CreateType("ApplicationModule",sizeof(Portakal::ApplicationModule),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateApplicationModule,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ApplicationModule>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ApplicationModule>(pApplicationModule);
;		Portakal::Type* pGuid = Portakal::TypeDispatcher::CreateType("Guid",sizeof(Portakal::Guid),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateGuid,Portakal::TypeDispatcher::GetTypeAddress<Portakal::Guid>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::Guid>(pGuid);
;		Portakal::Type* pVector2F = Portakal::TypeDispatcher::CreateType("Vector2F",sizeof(Portakal::Vector2F),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateVector2F,Portakal::TypeDispatcher::GetTypeAddress<Portakal::Vector2F>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::Vector2F>(pVector2F);
;		Portakal::Type* pVector2I = Portakal::TypeDispatcher::CreateType("Vector2I",sizeof(Portakal::Vector2I),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateVector2I,Portakal::TypeDispatcher::GetTypeAddress<Portakal::Vector2I>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::Vector2I>(pVector2I);
;		Portakal::Type* pVector2UI = Portakal::TypeDispatcher::CreateType("Vector2UI",sizeof(Portakal::Vector2UI),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateVector2UI,Portakal::TypeDispatcher::GetTypeAddress<Portakal::Vector2UI>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::Vector2UI>(pVector2UI);
;		Portakal::Type* pVector2US = Portakal::TypeDispatcher::CreateType("Vector2US",sizeof(Portakal::Vector2US),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateVector2US,Portakal::TypeDispatcher::GetTypeAddress<Portakal::Vector2US>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::Vector2US>(pVector2US);
;		Portakal::Type* pObject = Portakal::TypeDispatcher::CreateType("Object",sizeof(Portakal::Object),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateObject,Portakal::TypeDispatcher::GetTypeAddress<Portakal::Object>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::Object>(pObject);
;		Portakal::Type* pPlatformType = Portakal::TypeDispatcher::CreateType("PlatformType",sizeof(Portakal::PlatformType),Portakal::TypeModes::Enum,Portakal::TypeCodes::Composed,CreatePlatformType,Portakal::TypeDispatcher::GetTypeAddress<Portakal::PlatformType>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::PlatformType>(pPlatformType);
;		Portakal::Type* pAttribute = Portakal::TypeDispatcher::CreateType("Attribute",sizeof(Portakal::Attribute),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateAttribute,Portakal::TypeDispatcher::GetTypeAddress<Portakal::Attribute>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::Attribute>(pAttribute);
;		Portakal::Type* pFieldMode = Portakal::TypeDispatcher::CreateType("FieldMode",sizeof(Portakal::FieldMode),Portakal::TypeModes::Enum,Portakal::TypeCodes::Composed,CreateFieldMode,Portakal::TypeDispatcher::GetTypeAddress<Portakal::FieldMode>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::FieldMode>(pFieldMode);
;		Portakal::Type* pReflectionModule = Portakal::TypeDispatcher::CreateType("ReflectionModule",sizeof(Portakal::ReflectionModule),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateReflectionModule,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ReflectionModule>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ReflectionModule>(pReflectionModule);
;		Portakal::Type* pRenderGraph = Portakal::TypeDispatcher::CreateType("RenderGraph",sizeof(Portakal::RenderGraph),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateRenderGraph,Portakal::TypeDispatcher::GetTypeAddress<Portakal::RenderGraph>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::RenderGraph>(pRenderGraph);
;		Portakal::Type* pRenderOperation = Portakal::TypeDispatcher::CreateType("RenderOperation",sizeof(Portakal::RenderOperation),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateRenderOperation,Portakal::TypeDispatcher::GetTypeAddress<Portakal::RenderOperation>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::RenderOperation>(pRenderOperation);
;		Portakal::Type* pCustomResourceDeserializer = Portakal::TypeDispatcher::CreateType("CustomResourceDeserializer",sizeof(Portakal::CustomResourceDeserializer),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateCustomResourceDeserializer,Portakal::TypeDispatcher::GetTypeAddress<Portakal::CustomResourceDeserializer>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::CustomResourceDeserializer>(pCustomResourceDeserializer);
;		Portakal::Type* pIResourceDeserializer = Portakal::TypeDispatcher::CreateType("IResourceDeserializer",sizeof(Portakal::IResourceDeserializer),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateIResourceDeserializer,Portakal::TypeDispatcher::GetTypeAddress<Portakal::IResourceDeserializer>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::IResourceDeserializer>(pIResourceDeserializer);
;		Portakal::Type* pResourceAttribute = Portakal::TypeDispatcher::CreateType("ResourceAttribute",sizeof(Portakal::ResourceAttribute),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateResourceAttribute,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ResourceAttribute>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ResourceAttribute>(pResourceAttribute);
;		Portakal::Type* pResourceDescriptor = Portakal::TypeDispatcher::CreateType("ResourceDescriptor",sizeof(Portakal::ResourceDescriptor),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateResourceDescriptor,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ResourceDescriptor>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ResourceDescriptor>(pResourceDescriptor);
;		Portakal::Type* pResourceModule = Portakal::TypeDispatcher::CreateType("ResourceModule",sizeof(Portakal::ResourceModule),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateResourceModule,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ResourceModule>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ResourceModule>(pResourceModule);
;		Portakal::Type* pResourceSubObject = Portakal::TypeDispatcher::CreateType("ResourceSubObject",sizeof(Portakal::ResourceSubObject),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateResourceSubObject,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ResourceSubObject>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ResourceSubObject>(pResourceSubObject);
;		Portakal::Type* pWindowModule = Portakal::TypeDispatcher::CreateType("WindowModule",sizeof(Portakal::WindowModule),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateWindowModule,Portakal::TypeDispatcher::GetTypeAddress<Portakal::WindowModule>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::WindowModule>(pWindowModule);
;		Portakal::Type* pComponent = Portakal::TypeDispatcher::CreateType("Component",sizeof(Portakal::Component),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateComponent,Portakal::TypeDispatcher::GetTypeAddress<Portakal::Component>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::Component>(pComponent);
;		Portakal::Type* pEntity = Portakal::TypeDispatcher::CreateType("Entity",sizeof(Portakal::Entity),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateEntity,Portakal::TypeDispatcher::GetTypeAddress<Portakal::Entity>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::Entity>(pEntity);
;		Portakal::Type* pSceneAspect = Portakal::TypeDispatcher::CreateType("SceneAspect",sizeof(Portakal::SceneAspect),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateSceneAspect,Portakal::TypeDispatcher::GetTypeAddress<Portakal::SceneAspect>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::SceneAspect>(pSceneAspect);
;		Portakal::Type* pSceneModule = Portakal::TypeDispatcher::CreateType("SceneModule",sizeof(Portakal::SceneModule),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateSceneModule,Portakal::TypeDispatcher::GetTypeAddress<Portakal::SceneModule>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::SceneModule>(pSceneModule);
;		Portakal::Type* pCompareOperation = Portakal::TypeDispatcher::CreateType("CompareOperation",sizeof(Portakal::CompareOperation),Portakal::TypeModes::Enum,Portakal::TypeCodes::Composed,CreateCompareOperation,Portakal::TypeDispatcher::GetTypeAddress<Portakal::CompareOperation>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::CompareOperation>(pCompareOperation);
;		Portakal::Type* pLogicOperation = Portakal::TypeDispatcher::CreateType("LogicOperation",sizeof(Portakal::LogicOperation),Portakal::TypeModes::Enum,Portakal::TypeCodes::Composed,CreateLogicOperation,Portakal::TypeDispatcher::GetTypeAddress<Portakal::LogicOperation>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::LogicOperation>(pLogicOperation);
;		Portakal::Type* pSamplerAddressMode = Portakal::TypeDispatcher::CreateType("SamplerAddressMode",sizeof(Portakal::SamplerAddressMode),Portakal::TypeModes::Enum,Portakal::TypeCodes::Composed,CreateSamplerAddressMode,Portakal::TypeDispatcher::GetTypeAddress<Portakal::SamplerAddressMode>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::SamplerAddressMode>(pSamplerAddressMode);
;		Portakal::Type* pSamplerBorderColor = Portakal::TypeDispatcher::CreateType("SamplerBorderColor",sizeof(Portakal::SamplerBorderColor),Portakal::TypeModes::Enum,Portakal::TypeCodes::Composed,CreateSamplerBorderColor,Portakal::TypeDispatcher::GetTypeAddress<Portakal::SamplerBorderColor>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::SamplerBorderColor>(pSamplerBorderColor);
;		Portakal::Type* pSamplerFiltering = Portakal::TypeDispatcher::CreateType("SamplerFiltering",sizeof(Portakal::SamplerFiltering),Portakal::TypeModes::Enum,Portakal::TypeCodes::Composed,CreateSamplerFiltering,Portakal::TypeDispatcher::GetTypeAddress<Portakal::SamplerFiltering>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::SamplerFiltering>(pSamplerFiltering);
;		Portakal::Type* pSamplerMapMode = Portakal::TypeDispatcher::CreateType("SamplerMapMode",sizeof(Portakal::SamplerMapMode),Portakal::TypeModes::Enum,Portakal::TypeCodes::Composed,CreateSamplerMapMode,Portakal::TypeDispatcher::GetTypeAddress<Portakal::SamplerMapMode>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::SamplerMapMode>(pSamplerMapMode);
;		Portakal::Type* pShaderLanguage = Portakal::TypeDispatcher::CreateType("ShaderLanguage",sizeof(Portakal::ShaderLanguage),Portakal::TypeModes::Enum,Portakal::TypeCodes::Composed,CreateShaderLanguage,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ShaderLanguage>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ShaderLanguage>(pShaderLanguage);
;		Portakal::Type* pShaderStage = Portakal::TypeDispatcher::CreateType("ShaderStage",sizeof(Portakal::ShaderStage),Portakal::TypeModes::Enum,Portakal::TypeCodes::Composed,CreateShaderStage,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ShaderStage>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ShaderStage>(pShaderStage);
;		Portakal::Type* pBasicCamera = Portakal::TypeDispatcher::CreateType("BasicCamera",sizeof(Portakal::BasicCamera),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateBasicCamera,Portakal::TypeDispatcher::GetTypeAddress<Portakal::BasicCamera>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::BasicCamera>(pBasicCamera);
;		Portakal::Type* pBasicRenderAspect = Portakal::TypeDispatcher::CreateType("BasicRenderAspect",sizeof(Portakal::BasicRenderAspect),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateBasicRenderAspect,Portakal::TypeDispatcher::GetTypeAddress<Portakal::BasicRenderAspect>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::BasicRenderAspect>(pBasicRenderAspect);
;		Portakal::Type* pMaterialResource = Portakal::TypeDispatcher::CreateType("MaterialResource",sizeof(Portakal::MaterialResource),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateMaterialResource,Portakal::TypeDispatcher::GetTypeAddress<Portakal::MaterialResource>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::MaterialResource>(pMaterialResource);
;		Portakal::Type* pMeshDeserializer = Portakal::TypeDispatcher::CreateType("MeshDeserializer",sizeof(Portakal::MeshDeserializer),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateMeshDeserializer,Portakal::TypeDispatcher::GetTypeAddress<Portakal::MeshDeserializer>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::MeshDeserializer>(pMeshDeserializer);
;		Portakal::Type* pMeshResource = Portakal::TypeDispatcher::CreateType("MeshResource",sizeof(Portakal::MeshResource),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateMeshResource,Portakal::TypeDispatcher::GetTypeAddress<Portakal::MeshResource>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::MeshResource>(pMeshResource);
;		Portakal::Type* pRenderTarget = Portakal::TypeDispatcher::CreateType("RenderTarget",sizeof(Portakal::RenderTarget),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateRenderTarget,Portakal::TypeDispatcher::GetTypeAddress<Portakal::RenderTarget>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::RenderTarget>(pRenderTarget);
;		Portakal::Type* pSamplerDescriptor = Portakal::TypeDispatcher::CreateType("SamplerDescriptor",sizeof(Portakal::SamplerDescriptor),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateSamplerDescriptor,Portakal::TypeDispatcher::GetTypeAddress<Portakal::SamplerDescriptor>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::SamplerDescriptor>(pSamplerDescriptor);
;		Portakal::Type* pSamplerDeserializer = Portakal::TypeDispatcher::CreateType("SamplerDeserializer",sizeof(Portakal::SamplerDeserializer),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateSamplerDeserializer,Portakal::TypeDispatcher::GetTypeAddress<Portakal::SamplerDeserializer>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::SamplerDeserializer>(pSamplerDeserializer);
;		Portakal::Type* pSamplerResource = Portakal::TypeDispatcher::CreateType("SamplerResource",sizeof(Portakal::SamplerResource),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateSamplerResource,Portakal::TypeDispatcher::GetTypeAddress<Portakal::SamplerResource>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::SamplerResource>(pSamplerResource);
;		Portakal::Type* pSceneComponentDescriptor = Portakal::TypeDispatcher::CreateType("SceneComponentDescriptor",sizeof(Portakal::SceneComponentDescriptor),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateSceneComponentDescriptor,Portakal::TypeDispatcher::GetTypeAddress<Portakal::SceneComponentDescriptor>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::SceneComponentDescriptor>(pSceneComponentDescriptor);
;		Portakal::Type* pSceneComponentFieldDescriptor = Portakal::TypeDispatcher::CreateType("SceneComponentFieldDescriptor",sizeof(Portakal::SceneComponentFieldDescriptor),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateSceneComponentFieldDescriptor,Portakal::TypeDispatcher::GetTypeAddress<Portakal::SceneComponentFieldDescriptor>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::SceneComponentFieldDescriptor>(pSceneComponentFieldDescriptor);
;		Portakal::Type* pSceneComponentFieldType = Portakal::TypeDispatcher::CreateType("SceneComponentFieldType",sizeof(Portakal::SceneComponentFieldType),Portakal::TypeModes::Enum,Portakal::TypeCodes::Composed,CreateSceneComponentFieldType,Portakal::TypeDispatcher::GetTypeAddress<Portakal::SceneComponentFieldType>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::SceneComponentFieldType>(pSceneComponentFieldType);
;		Portakal::Type* pSceneDescriptor = Portakal::TypeDispatcher::CreateType("SceneDescriptor",sizeof(Portakal::SceneDescriptor),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateSceneDescriptor,Portakal::TypeDispatcher::GetTypeAddress<Portakal::SceneDescriptor>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::SceneDescriptor>(pSceneDescriptor);
;		Portakal::Type* pSceneDeserializer = Portakal::TypeDispatcher::CreateType("SceneDeserializer",sizeof(Portakal::SceneDeserializer),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateSceneDeserializer,Portakal::TypeDispatcher::GetTypeAddress<Portakal::SceneDeserializer>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::SceneDeserializer>(pSceneDeserializer);
;		Portakal::Type* pSceneEntityDescriptor = Portakal::TypeDispatcher::CreateType("SceneEntityDescriptor",sizeof(Portakal::SceneEntityDescriptor),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateSceneEntityDescriptor,Portakal::TypeDispatcher::GetTypeAddress<Portakal::SceneEntityDescriptor>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::SceneEntityDescriptor>(pSceneEntityDescriptor);
;		Portakal::Type* pSceneResource = Portakal::TypeDispatcher::CreateType("SceneResource",sizeof(Portakal::SceneResource),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateSceneResource,Portakal::TypeDispatcher::GetTypeAddress<Portakal::SceneResource>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::SceneResource>(pSceneResource);
;		Portakal::Type* pShaderDescriptor = Portakal::TypeDispatcher::CreateType("ShaderDescriptor",sizeof(Portakal::ShaderDescriptor),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateShaderDescriptor,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ShaderDescriptor>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ShaderDescriptor>(pShaderDescriptor);
;		Portakal::Type* pShaderDeserializer = Portakal::TypeDispatcher::CreateType("ShaderDeserializer",sizeof(Portakal::ShaderDeserializer),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateShaderDeserializer,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ShaderDeserializer>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ShaderDeserializer>(pShaderDeserializer);
;		Portakal::Type* pShaderResource = Portakal::TypeDispatcher::CreateType("ShaderResource",sizeof(Portakal::ShaderResource),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateShaderResource,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ShaderResource>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ShaderResource>(pShaderResource);
;		Portakal::Type* pTextureDeserializer = Portakal::TypeDispatcher::CreateType("TextureDeserializer",sizeof(Portakal::TextureDeserializer),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateTextureDeserializer,Portakal::TypeDispatcher::GetTypeAddress<Portakal::TextureDeserializer>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::TextureDeserializer>(pTextureDeserializer);
;		Portakal::Type* pTextureResource = Portakal::TypeDispatcher::CreateType("TextureResource",sizeof(Portakal::TextureResource),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateTextureResource,Portakal::TypeDispatcher::GetTypeAddress<Portakal::TextureResource>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::TextureResource>(pTextureResource);
;		Portakal::Type* pDisplayAspect = Portakal::TypeDispatcher::CreateType("DisplayAspect",sizeof(Portakal::DisplayAspect),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateDisplayAspect,Portakal::TypeDispatcher::GetTypeAddress<Portakal::DisplayAspect>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::DisplayAspect>(pDisplayAspect);
;
        //Register enums here
		Portakal::TypeDispatcher::RegisterEnum("Windows",112,pPlatformType);
		Portakal::TypeDispatcher::RegisterEnum("Linux",113,pPlatformType);
		Portakal::TypeDispatcher::RegisterEnum("Mac",155,pPlatformType);
		Portakal::TypeDispatcher::RegisterEnum("PS5",156,pPlatformType);
		Portakal::TypeDispatcher::RegisterEnum("Switch",157,pPlatformType);
		Portakal::TypeDispatcher::RegisterEnum("Normal",0,pFieldMode);
		Portakal::TypeDispatcher::RegisterEnum("Object",1,pFieldMode);
		Portakal::TypeDispatcher::RegisterEnum("Array",2,pFieldMode);
		Portakal::TypeDispatcher::RegisterEnum("Never",0,pCompareOperation);
		Portakal::TypeDispatcher::RegisterEnum("Less",1,pCompareOperation);
		Portakal::TypeDispatcher::RegisterEnum("Equal",2,pCompareOperation);
		Portakal::TypeDispatcher::RegisterEnum("LessEqual",3,pCompareOperation);
		Portakal::TypeDispatcher::RegisterEnum("Greater",4,pCompareOperation);
		Portakal::TypeDispatcher::RegisterEnum("NotEqual",5,pCompareOperation);
		Portakal::TypeDispatcher::RegisterEnum("GreaterEqual",6,pCompareOperation);
		Portakal::TypeDispatcher::RegisterEnum("Always",7,pCompareOperation);
		Portakal::TypeDispatcher::RegisterEnum("Clear",0,pLogicOperation);
		Portakal::TypeDispatcher::RegisterEnum("Set",1,pLogicOperation);
		Portakal::TypeDispatcher::RegisterEnum("Copy",2,pLogicOperation);
		Portakal::TypeDispatcher::RegisterEnum("CopyInverted",3,pLogicOperation);
		Portakal::TypeDispatcher::RegisterEnum("NoOp",4,pLogicOperation);
		Portakal::TypeDispatcher::RegisterEnum("Invert",5,pLogicOperation);
		Portakal::TypeDispatcher::RegisterEnum("And",6,pLogicOperation);
		Portakal::TypeDispatcher::RegisterEnum("NotAnd",7,pLogicOperation);
		Portakal::TypeDispatcher::RegisterEnum("Or",8,pLogicOperation);
		Portakal::TypeDispatcher::RegisterEnum("Nor",9,pLogicOperation);
		Portakal::TypeDispatcher::RegisterEnum("Xor",10,pLogicOperation);
		Portakal::TypeDispatcher::RegisterEnum("Equal",11,pLogicOperation);
		Portakal::TypeDispatcher::RegisterEnum("AndReverse",12,pLogicOperation);
		Portakal::TypeDispatcher::RegisterEnum("AndInverted",13,pLogicOperation);
		Portakal::TypeDispatcher::RegisterEnum("OrReverse",14,pLogicOperation);
		Portakal::TypeDispatcher::RegisterEnum("OrInverted",15,pLogicOperation);
		Portakal::TypeDispatcher::RegisterEnum("Repeat",0,pSamplerAddressMode);
		Portakal::TypeDispatcher::RegisterEnum("MirroredRepeat",1,pSamplerAddressMode);
		Portakal::TypeDispatcher::RegisterEnum("ClampToEdge",2,pSamplerAddressMode);
		Portakal::TypeDispatcher::RegisterEnum("ClampToBorder",3,pSamplerAddressMode);
		Portakal::TypeDispatcher::RegisterEnum("MirrorClampToEdge",4,pSamplerAddressMode);
		Portakal::TypeDispatcher::RegisterEnum("TransparentBlack",0,pSamplerBorderColor);
		Portakal::TypeDispatcher::RegisterEnum("OpaqueBlack",1,pSamplerBorderColor);
		Portakal::TypeDispatcher::RegisterEnum("OpaqueWhite",2,pSamplerBorderColor);
		Portakal::TypeDispatcher::RegisterEnum("None",0,pSamplerFiltering);
		Portakal::TypeDispatcher::RegisterEnum("Linear",1,pSamplerFiltering);
		Portakal::TypeDispatcher::RegisterEnum("Nearest",2,pSamplerFiltering);
		Portakal::TypeDispatcher::RegisterEnum("None",0,pSamplerMapMode);
		Portakal::TypeDispatcher::RegisterEnum("Linear",1,pSamplerMapMode);
		Portakal::TypeDispatcher::RegisterEnum("Nearest",2,pSamplerMapMode);
		Portakal::TypeDispatcher::RegisterEnum("Unknown",0,pShaderLanguage);
		Portakal::TypeDispatcher::RegisterEnum("GLSL",1,pShaderLanguage);
		Portakal::TypeDispatcher::RegisterEnum("HLSL",2,pShaderLanguage);
		Portakal::TypeDispatcher::RegisterEnum("MSL",3,pShaderLanguage);
		Portakal::TypeDispatcher::RegisterEnum("VertexStage",1,pShaderStage);
		Portakal::TypeDispatcher::RegisterEnum("FragmentStage",2,pShaderStage);
		Portakal::TypeDispatcher::RegisterEnum("ComputeStage",4,pShaderStage);
		Portakal::TypeDispatcher::RegisterEnum("EntityComponent",0,pSceneComponentFieldType);
		Portakal::TypeDispatcher::RegisterEnum("Resource",1,pSceneComponentFieldType);

        //Register fields here
		Portakal::TypeDispatcher::RegisterField("mMyType",offsetof(Portakal::TestClass,mMyType),typeof(Portakal::UInt32),Portakal::FieldMode::Normal,pTestClass);
		Portakal::TypeDispatcher::RegisterField("mMahString",offsetof(Portakal::TestClass,mMahString),typeof(Portakal::String),Portakal::FieldMode::Normal,pTestClass);
		Portakal::TypeDispatcher::RegisterField("mMahObjectString",offsetof(Portakal::TestClass,mMahObjectString),typeof(Portakal::String),Portakal::FieldMode::Object,pTestClass);
		Portakal::TypeDispatcher::RegisterField("mMahArray",offsetof(Portakal::TestClass,mMahArray),typeof(Portakal::String),Portakal::FieldMode::Array,pTestClass);
		Portakal::TypeDispatcher::RegisterField("A",offsetof(Portakal::Guid,A),typeof(Portakal::UInt32),Portakal::FieldMode::Normal,pGuid);
		Portakal::TypeDispatcher::RegisterField("B",offsetof(Portakal::Guid,B),typeof(Portakal::UInt32),Portakal::FieldMode::Normal,pGuid);
		Portakal::TypeDispatcher::RegisterField("C",offsetof(Portakal::Guid,C),typeof(Portakal::UInt32),Portakal::FieldMode::Normal,pGuid);
		Portakal::TypeDispatcher::RegisterField("D",offsetof(Portakal::Guid,D),typeof(Portakal::UInt32),Portakal::FieldMode::Normal,pGuid);
		Portakal::TypeDispatcher::RegisterField("X",offsetof(Portakal::Vector2F,X),typeof(Portakal::Float32),Portakal::FieldMode::Normal,pVector2F);
		Portakal::TypeDispatcher::RegisterField("Y",offsetof(Portakal::Vector2F,Y),typeof(Portakal::Float32),Portakal::FieldMode::Normal,pVector2F);
		Portakal::TypeDispatcher::RegisterField("X",offsetof(Portakal::Vector2I,X),typeof(Portakal::Int32),Portakal::FieldMode::Normal,pVector2I);
		Portakal::TypeDispatcher::RegisterField("Y",offsetof(Portakal::Vector2I,Y),typeof(Portakal::Int32),Portakal::FieldMode::Normal,pVector2I);
		Portakal::TypeDispatcher::RegisterField("X",offsetof(Portakal::Vector2UI,X),typeof(Portakal::UInt32),Portakal::FieldMode::Normal,pVector2UI);
		Portakal::TypeDispatcher::RegisterField("Y",offsetof(Portakal::Vector2UI,Y),typeof(Portakal::UInt32),Portakal::FieldMode::Normal,pVector2UI);
		Portakal::TypeDispatcher::RegisterField("X",offsetof(Portakal::Vector2US,X),typeof(Portakal::UInt16),Portakal::FieldMode::Normal,pVector2US);
		Portakal::TypeDispatcher::RegisterField("Y",offsetof(Portakal::Vector2US,Y),typeof(Portakal::UInt16),Portakal::FieldMode::Normal,pVector2US);
		Portakal::TypeDispatcher::RegisterField("SourcePath",offsetof(Portakal::ResourceDescriptor,SourcePath),typeof(Portakal::String),Portakal::FieldMode::Normal,pResourceDescriptor);
		Portakal::TypeDispatcher::RegisterField("ResourceType",offsetof(Portakal::ResourceDescriptor,ResourceType),typeof(Portakal::String),Portakal::FieldMode::Normal,pResourceDescriptor);
		Portakal::TypeDispatcher::RegisterField("Name",offsetof(Portakal::ResourceDescriptor,Name),typeof(Portakal::String),Portakal::FieldMode::Normal,pResourceDescriptor);
		Portakal::TypeDispatcher::RegisterField("ID",offsetof(Portakal::ResourceDescriptor,ID),typeof(Portakal::Guid),Portakal::FieldMode::Normal,pResourceDescriptor);
		Portakal::TypeDispatcher::RegisterField("FileOffset",offsetof(Portakal::ResourceDescriptor,FileOffset),typeof(Portakal::UInt64),Portakal::FieldMode::Normal,pResourceDescriptor);
		Portakal::TypeDispatcher::RegisterField("FileSize",offsetof(Portakal::ResourceDescriptor,FileSize),typeof(Portakal::UInt64),Portakal::FieldMode::Normal,pResourceDescriptor);
		Portakal::TypeDispatcher::RegisterField("bOptimized",offsetof(Portakal::ResourceDescriptor,bOptimized),typeof(Portakal::Bool8),Portakal::FieldMode::Normal,pResourceDescriptor);
		Portakal::TypeDispatcher::RegisterField("mFieldOfView",offsetof(Portakal::BasicCamera,mFieldOfView),typeof(Portakal::Float32),Portakal::FieldMode::Normal,pBasicCamera);
		Portakal::TypeDispatcher::RegisterField("mNearPlane",offsetof(Portakal::BasicCamera,mNearPlane),typeof(Portakal::Float32),Portakal::FieldMode::Normal,pBasicCamera);
		Portakal::TypeDispatcher::RegisterField("mFarPlane",offsetof(Portakal::BasicCamera,mFarPlane),typeof(Portakal::Float32),Portakal::FieldMode::Normal,pBasicCamera);
		Portakal::TypeDispatcher::RegisterField("mMinFilter",offsetof(Portakal::SamplerDescriptor,mMinFilter),typeof(Portakal::SamplerFiltering),Portakal::FieldMode::Normal,pSamplerDescriptor);
		Portakal::TypeDispatcher::RegisterField("mMagFilter",offsetof(Portakal::SamplerDescriptor,mMagFilter),typeof(Portakal::SamplerFiltering),Portakal::FieldMode::Normal,pSamplerDescriptor);
		Portakal::TypeDispatcher::RegisterField("mMipmapMode",offsetof(Portakal::SamplerDescriptor,mMipmapMode),typeof(Portakal::SamplerMapMode),Portakal::FieldMode::Normal,pSamplerDescriptor);
		Portakal::TypeDispatcher::RegisterField("mAddressModeU",offsetof(Portakal::SamplerDescriptor,mAddressModeU),typeof(Portakal::SamplerAddressMode),Portakal::FieldMode::Normal,pSamplerDescriptor);
		Portakal::TypeDispatcher::RegisterField("mAddressModeV",offsetof(Portakal::SamplerDescriptor,mAddressModeV),typeof(Portakal::SamplerAddressMode),Portakal::FieldMode::Normal,pSamplerDescriptor);
		Portakal::TypeDispatcher::RegisterField("mAddressModeW",offsetof(Portakal::SamplerDescriptor,mAddressModeW),typeof(Portakal::SamplerAddressMode),Portakal::FieldMode::Normal,pSamplerDescriptor);
		Portakal::TypeDispatcher::RegisterField("mMipLodBias",offsetof(Portakal::SamplerDescriptor,mMipLodBias),typeof(Portakal::Float32),Portakal::FieldMode::Normal,pSamplerDescriptor);
		Portakal::TypeDispatcher::RegisterField("mMaxAnisotropy",offsetof(Portakal::SamplerDescriptor,mMaxAnisotropy),typeof(Portakal::Float32),Portakal::FieldMode::Normal,pSamplerDescriptor);
		Portakal::TypeDispatcher::RegisterField("mComparisonEnabled",offsetof(Portakal::SamplerDescriptor,mComparisonEnabled),typeof(Portakal::Bool8),Portakal::FieldMode::Normal,pSamplerDescriptor);
		Portakal::TypeDispatcher::RegisterField("mCompareOperation",offsetof(Portakal::SamplerDescriptor,mCompareOperation),typeof(Portakal::CompareOperation),Portakal::FieldMode::Normal,pSamplerDescriptor);
		Portakal::TypeDispatcher::RegisterField("mMinLod",offsetof(Portakal::SamplerDescriptor,mMinLod),typeof(Portakal::Float32),Portakal::FieldMode::Normal,pSamplerDescriptor);
		Portakal::TypeDispatcher::RegisterField("mMaxLod",offsetof(Portakal::SamplerDescriptor,mMaxLod),typeof(Portakal::Float32),Portakal::FieldMode::Normal,pSamplerDescriptor);
		Portakal::TypeDispatcher::RegisterField("mBorderColor",offsetof(Portakal::SamplerDescriptor,mBorderColor),typeof(Portakal::SamplerBorderColor),Portakal::FieldMode::Normal,pSamplerDescriptor);
		Portakal::TypeDispatcher::RegisterField("Name",offsetof(Portakal::SceneComponentDescriptor,Name),typeof(Portakal::String),Portakal::FieldMode::Normal,pSceneComponentDescriptor);
		Portakal::TypeDispatcher::RegisterField("ID",offsetof(Portakal::SceneComponentDescriptor,ID),typeof(Portakal::Guid),Portakal::FieldMode::Normal,pSceneComponentDescriptor);
		Portakal::TypeDispatcher::RegisterField("TypeName",offsetof(Portakal::SceneComponentDescriptor,TypeName),typeof(Portakal::String),Portakal::FieldMode::Normal,pSceneComponentDescriptor);
		Portakal::TypeDispatcher::RegisterField("Fields",offsetof(Portakal::SceneComponentDescriptor,Fields),typeof(Portakal::SceneComponentFieldDescriptor),Portakal::FieldMode::Array,pSceneComponentDescriptor);
		Portakal::TypeDispatcher::RegisterField("FieldName",offsetof(Portakal::SceneComponentFieldDescriptor,FieldName),typeof(Portakal::String),Portakal::FieldMode::Normal,pSceneComponentFieldDescriptor);
		Portakal::TypeDispatcher::RegisterField("Mode",offsetof(Portakal::SceneComponentFieldDescriptor,Mode),typeof(Portakal::FieldMode),Portakal::FieldMode::Normal,pSceneComponentFieldDescriptor);
		Portakal::TypeDispatcher::RegisterField("FieldValue",offsetof(Portakal::SceneComponentFieldDescriptor,FieldValue),typeof(Portakal::String),Portakal::FieldMode::Normal,pSceneComponentFieldDescriptor);
		Portakal::TypeDispatcher::RegisterField("Entities",offsetof(Portakal::SceneDescriptor,Entities),typeof(Portakal::SceneEntityDescriptor),Portakal::FieldMode::Array,pSceneDescriptor);
		Portakal::TypeDispatcher::RegisterField("Resources",offsetof(Portakal::SceneDescriptor,Resources),typeof(Portakal::Guid),Portakal::FieldMode::Array,pSceneDescriptor);
		Portakal::TypeDispatcher::RegisterField("Aspects",offsetof(Portakal::SceneDescriptor,Aspects),typeof(Portakal::String),Portakal::FieldMode::Array,pSceneDescriptor);
		Portakal::TypeDispatcher::RegisterField("Name",offsetof(Portakal::SceneEntityDescriptor,Name),typeof(Portakal::String),Portakal::FieldMode::Normal,pSceneEntityDescriptor);
		Portakal::TypeDispatcher::RegisterField("ID",offsetof(Portakal::SceneEntityDescriptor,ID),typeof(Portakal::Guid),Portakal::FieldMode::Normal,pSceneEntityDescriptor);
		Portakal::TypeDispatcher::RegisterField("Components",offsetof(Portakal::SceneEntityDescriptor,Components),typeof(Portakal::SceneComponentDescriptor),Portakal::FieldMode::Array,pSceneEntityDescriptor);
		Portakal::TypeDispatcher::RegisterField("Source",offsetof(Portakal::ShaderDescriptor,Source),typeof(Portakal::String),Portakal::FieldMode::Normal,pShaderDescriptor);
		Portakal::TypeDispatcher::RegisterField("EntryMethodName",offsetof(Portakal::ShaderDescriptor,EntryMethodName),typeof(Portakal::String),Portakal::FieldMode::Normal,pShaderDescriptor);
		Portakal::TypeDispatcher::RegisterField("Stage",offsetof(Portakal::ShaderDescriptor,Stage),typeof(Portakal::ShaderStage),Portakal::FieldMode::Normal,pShaderDescriptor);
		Portakal::TypeDispatcher::RegisterField("Language",offsetof(Portakal::ShaderDescriptor,Language),typeof(Portakal::ShaderLanguage),Portakal::FieldMode::Normal,pShaderDescriptor);

        //Register attributes here
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::MyAttribute>(pTestClass);
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::ResourceAttribute>(pMaterialResource, "material");
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::CustomResourceDeserializer>(pMeshDeserializer, "mesh");
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::ResourceAttribute>(pMeshResource, "mesh");
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::ResourceAttribute>(pRenderTarget, "rendertarget");
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::CustomResourceDeserializer>(pSamplerDeserializer, "sampler");
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::ResourceAttribute>(pSamplerResource, "sampler");
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::CustomResourceDeserializer>(pSceneDeserializer,"scene");
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::ResourceAttribute>(pSceneResource, "scene");
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::CustomResourceDeserializer>(pShaderDeserializer, "shader");
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::ResourceAttribute>(pShaderResource, "shader");
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::CustomResourceDeserializer>(pTextureDeserializer,"texture");
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::ResourceAttribute>(pTextureResource, "texture");

        //Register base types here
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::MyAttribute),typeof(Portakal::Attribute));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::TestClass),typeof(Portakal::Object));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ReflectionModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::RenderGraph),typeof(Portakal::Object));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::BasicCamera),typeof(Portakal::Component));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::BasicRenderAspect),typeof(Portakal::SceneAspect));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::MaterialResource),typeof(Portakal::ResourceSubObject));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::MeshDeserializer),typeof(Portakal::IResourceDeserializer));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::MeshResource),typeof(Portakal::ResourceSubObject));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::RenderTarget),typeof(Portakal::ResourceSubObject));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::SamplerDeserializer),typeof(Portakal::IResourceDeserializer));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::SamplerResource),typeof(Portakal::ResourceSubObject));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::SceneDeserializer),typeof(Portakal::IResourceDeserializer));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::SceneResource),typeof(Portakal::ResourceSubObject));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ShaderDeserializer),typeof(Portakal::IResourceDeserializer));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ShaderResource),typeof(Portakal::ResourceSubObject));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::TextureDeserializer),typeof(Portakal::IResourceDeserializer));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::TextureResource),typeof(Portakal::ResourceSubObject));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::DisplayAspect),typeof(Portakal::SceneAspect));

		//Create manifest here
		Portakal::Array<Portakal::Type*> types = {pMyAttribute,pTestClass,pApplicationModule,pGuid,pVector2F,pVector2I,pVector2UI,pVector2US,pObject,pPlatformType,pAttribute,pFieldMode,pReflectionModule,pRenderGraph,pRenderOperation,pCustomResourceDeserializer,pIResourceDeserializer,pResourceAttribute,pResourceDescriptor,pResourceModule,pResourceSubObject,pWindowModule,pComponent,pEntity,pSceneAspect,pSceneModule,pCompareOperation,pLogicOperation,pSamplerAddressMode,pSamplerBorderColor,pSamplerFiltering,pSamplerMapMode,pShaderLanguage,pShaderStage,pBasicCamera,pBasicRenderAspect,pMaterialResource,pMeshDeserializer,pMeshResource,pRenderTarget,pSamplerDescriptor,pSamplerDeserializer,pSamplerResource,pSceneComponentDescriptor,pSceneComponentFieldDescriptor,pSceneComponentFieldType,pSceneDescriptor,pSceneDeserializer,pSceneEntityDescriptor,pSceneResource,pShaderDescriptor,pShaderDeserializer,pShaderResource,pTextureDeserializer,pTextureResource,pDisplayAspect,};
		pManifest = new Portakal::ReflectionManifest("Runtime", types);

		return pManifest;
	}
}
