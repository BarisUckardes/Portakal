
#pragma once
#include <Runtime/Reflection/Reflection.h>
#include <Runtime/Reflection/ReflectionManifest.h>
#include <Runtime/Reflection/TypeDispatcher.h>
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\MyAttribute.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\TestClass.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Application\ApplicationModule.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Containers\Guid.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Math\Vector2F.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Math\Vector2I.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Math\Vector2UI.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Math\Vector2US.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Object\Object.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Platform\PlatformType.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Reflection\Attribute.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Reflection\FieldMode.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Reflection\ReflectionModule.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Rendering\RenderGraph.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Rendering\RenderOperation.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Resource\CustomResourceDeserializer.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Resource\IResourceDeserializer.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Resource\ResourceDescriptor.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Resource\ResourceModule.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Resource\ResourceSubObject.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Window\WindowModule.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\World\Component.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\World\Entity.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\World\SceneAspect.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\World\SceneModule.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Graphics\Common\CompareOperation.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Graphics\Common\LogicOperation.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Graphics\Sampler\SamplerAddressMode.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Graphics\Sampler\SamplerBorderColor.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Graphics\Sampler\SamplerFiltering.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Graphics\Sampler\SamplerMapMode.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Graphics\Shader\ShaderLanguage.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Graphics\Shader\ShaderStage.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Rendering\Builtin\BasicCamera.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Rendering\Builtin\BasicRenderAspect.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Resource\Mesh\MeshDeserializer.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Resource\Mesh\MeshResource.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Resource\RenderTarget\RenderTargetResource.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Resource\Sampler\SamplerDescriptor.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Resource\Sampler\SamplerResource.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Resource\Scene\SceneComponentDescriptor.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Resource\Scene\SceneComponentFieldDescriptor.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Resource\Scene\SceneComponentFieldType.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Resource\Scene\SceneDescriptor.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Resource\Scene\SceneDeserializer.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Resource\Scene\SceneEntityDescriptor.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Resource\Scene\SceneResource.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Resource\Shader\ShaderDescriptor.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Resource\Shader\ShaderDeserializer.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Resource\Shader\ShaderResource.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Resource\Texture\TextureDeserializer.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Resource\Texture\TextureResource.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\World\Aspects\DisplayAspect.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\Domain\DomainFileDescriptor.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\Domain\DomainModule.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\GUIDirection.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\ImGui\ImGuiModule.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\ImGui\ImGuiRenderEndModule.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\ImGui\ImGuiRenderStartModule.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\Project\ProjectDescriptor.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\Project\ProjectModule.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\Resource\CustomResourceSerializer.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\Resource\EditorResourceModule.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\Resource\IResourceSerializer.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\Component\CustomComponentPainter.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\Component\IComponentPainter.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\ContextMenu\CustomContextMenuItem.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\ContextMenu\IContextMenuItem.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\Object\CustomObjectPainter.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\Object\EditorObjectModule.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\Object\IObjectPainter.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\OpenAction\CustomFileOpenAction.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\OpenAction\IFileOpenAction.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\Thumbnail\CustomThumbnail.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\Thumbnail\IThumbnail.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\Window\GUIWindow.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\Window\GUIWindowDescriptor.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\Window\GUIWindowModule.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\Window\GUIWindowSettings.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\Resource\Mesh\MeshSerializer.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\Resource\Sampler\SamplerSerializer.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\Resource\Scene\SceneSerializer.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\Resource\Shader\ShaderSerializer.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\Resource\Texture\TextureSerializer.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\Component\Builtin\BasicCameraPainter.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\ContextMenu\Builtin\CreateFolderContextMenuItem.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\ContextMenu\Builtin\CreateSamplerContextMenuItem.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\ContextMenu\Builtin\CreateSceneContextMenuItem.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\ContextMenu\Builtin\CreateShaderContextMenuItem.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\Object\Builtin\EntityObjectPainter.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\Object\Builtin\SamplerObjectPainter.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\Object\Builtin\ShaderObjectPainter.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\Object\Builtin\TextureObjectPainter.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\OpenAction\Builtin\SceneFileOpenAction.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\OpenAction\Builtin\ShaderFileOpenAction.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\OpenAction\Builtin\TextureFileOpenAction.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\Thumbnail\Builtin\DefaultThumbnail.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\Thumbnail\Builtin\MeshThumbnail.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\Thumbnail\Builtin\SamplerThumbnail.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\Thumbnail\Builtin\SceneThumbnail.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\Thumbnail\Builtin\ShaderThumbnail.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\Thumbnail\Builtin\TextureThumbnail.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\Window\Builtin\DomainWindow.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\Window\Builtin\GameWindow.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\Window\Builtin\ObjectWindow.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\Window\Builtin\SceneWindow.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\Window\Builtin\WorldWindow.h"
#include "EditorPlayerGDeviceModule.h"
#include "EditorPlayerProjectModule.h"
#include "EditorPlayerWindowModule.h"


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
		void* CreateMeshDeserializer() {return new Portakal::MeshDeserializer();}
		void* CreateMeshResource() {return new Portakal::MeshResource();}
		void* CreateRenderTargetResource() {return new Portakal::RenderTargetResource();}
		void* CreateSamplerDescriptor() {return new Portakal::SamplerDescriptor();}
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
		void* CreateDomainFileDescriptor() {return new Portakal::DomainFileDescriptor();}
		void* CreateDomainModule() {return new Portakal::DomainModule();}
		void* CreateGUIDirection() {return new Portakal::GUIDirection();}
		void* CreateImGuiModule() {return new Portakal::ImGuiModule();}
		void* CreateImGuiRenderEndModule() {return new Portakal::ImGuiRenderEndModule();}
		void* CreateImGuiRenderStartModule() {return new Portakal::ImGuiRenderStartModule();}
		void* CreateProjectDescriptor() {return new Portakal::ProjectDescriptor();}
		void* CreateProjectModule() {return new Portakal::ProjectModule();}
		void* CreateCustomResourceSerializer() {return new Portakal::CustomResourceSerializer();}
		void* CreateEditorResourceModule() {return new Portakal::EditorResourceModule();}
		void* CreateIResourceSerializer() {return nullptr;}
		void* CreateCustomComponentPainter() {return new Portakal::CustomComponentPainter();}
		void* CreateIComponentPainter() {return nullptr;}
		void* CreateCustomContextMenuItem() {return new Portakal::CustomContextMenuItem();}
		void* CreateIContextMenuItem() {return nullptr;}
		void* CreateCustomObjectPainter() {return new Portakal::CustomObjectPainter();}
		void* CreateEditorObjectModule() {return new Portakal::EditorObjectModule();}
		void* CreateIObjectPainter() {return nullptr;}
		void* CreateCustomFileOpenAction() {return new Portakal::CustomFileOpenAction();}
		void* CreateIFileOpenAction() {return nullptr;}
		void* CreateCustomThumbnail() {return new Portakal::CustomThumbnail();}
		void* CreateIThumbnail() {return new Portakal::IThumbnail();}
		void* CreateGUIWindow() {return nullptr;}
		void* CreateGUIWindowDescriptor() {return new Portakal::GUIWindowDescriptor();}
		void* CreateGUIWindowModule() {return new Portakal::GUIWindowModule();}
		void* CreateGUIWindowSettings() {return new Portakal::GUIWindowSettings();}
		void* CreateMeshSerializer() {return new Portakal::MeshSerializer();}
		void* CreateSamplerSerializer() {return new Portakal::SamplerSerializer();}
		void* CreateSceneSerializer() {return new Portakal::SceneSerializer();}
		void* CreateShaderSerializer() {return new Portakal::ShaderSerializer();}
		void* CreateTextureSerializer() {return new Portakal::TextureSerializer();}
		void* CreateBasicCameraPainter() {return new Portakal::BasicCameraPainter();}
		void* CreateCreateFolderContextMenuItem() {return new Portakal::CreateFolderContextMenuItem();}
		void* CreateCreateSamplerContextMenuItem() {return new Portakal::CreateSamplerContextMenuItem();}
		void* CreateCreateSceneContextMenuItem() {return new Portakal::CreateSceneContextMenuItem();}
		void* CreateCreateShaderContextMenuItem() {return new Portakal::CreateShaderContextMenuItem();}
		void* CreateEntityObjectPainter() {return new Portakal::EntityObjectPainter();}
		void* CreateSamplerObjectPainter() {return new Portakal::SamplerObjectPainter();}
		void* CreateShaderObjectPainter() {return new Portakal::ShaderObjectPainter();}
		void* CreateTextureObjectPainter() {return new Portakal::TextureObjectPainter();}
		void* CreateSceneFileOpenAction() {return new Portakal::SceneFileOpenAction();}
		void* CreateShaderFileOpenAction() {return new Portakal::ShaderFileOpenAction();}
		void* CreateTextureFileOpenAction() {return new Portakal::TextureFileOpenAction();}
		void* CreateDefaultThumbnail() {return new Portakal::DefaultThumbnail();}
		void* CreateMeshThumbnail() {return new Portakal::MeshThumbnail();}
		void* CreateSamplerThumbnail() {return new Portakal::SamplerThumbnail();}
		void* CreateSceneThumbnail() {return new Portakal::SceneThumbnail();}
		void* CreateShaderThumbnail() {return new Portakal::ShaderThumbnail();}
		void* CreateTextureThumbnail() {return new Portakal::TextureThumbnail();}
		void* CreateDomainWindow() {return new Portakal::DomainWindow();}
		void* CreateGameWindow() {return new Portakal::GameWindow();}
		void* CreateObjectWindow() {return new Portakal::ObjectWindow();}
		void* CreateSceneWindow() {return new Portakal::SceneWindow();}
		void* CreateWorldWindow() {return new Portakal::WorldWindow();}
		void* CreateEditorPlayerGDeviceModule() {return new Portakal::EditorPlayerGDeviceModule();}
		void* CreateEditorPlayerProjectModule() {return new Portakal::EditorPlayerProjectModule();}
		void* CreateEditorPlayerWindowModule() {return new Portakal::EditorPlayerWindowModule();}

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
;		Portakal::Type* pMeshDeserializer = Portakal::TypeDispatcher::CreateType("MeshDeserializer",sizeof(Portakal::MeshDeserializer),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateMeshDeserializer,Portakal::TypeDispatcher::GetTypeAddress<Portakal::MeshDeserializer>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::MeshDeserializer>(pMeshDeserializer);
;		Portakal::Type* pMeshResource = Portakal::TypeDispatcher::CreateType("MeshResource",sizeof(Portakal::MeshResource),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateMeshResource,Portakal::TypeDispatcher::GetTypeAddress<Portakal::MeshResource>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::MeshResource>(pMeshResource);
;		Portakal::Type* pRenderTargetResource = Portakal::TypeDispatcher::CreateType("RenderTargetResource",sizeof(Portakal::RenderTargetResource),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateRenderTargetResource,Portakal::TypeDispatcher::GetTypeAddress<Portakal::RenderTargetResource>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::RenderTargetResource>(pRenderTargetResource);
;		Portakal::Type* pSamplerDescriptor = Portakal::TypeDispatcher::CreateType("SamplerDescriptor",sizeof(Portakal::SamplerDescriptor),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateSamplerDescriptor,Portakal::TypeDispatcher::GetTypeAddress<Portakal::SamplerDescriptor>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::SamplerDescriptor>(pSamplerDescriptor);
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
;		Portakal::Type* pDomainFileDescriptor = Portakal::TypeDispatcher::CreateType("DomainFileDescriptor",sizeof(Portakal::DomainFileDescriptor),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateDomainFileDescriptor,Portakal::TypeDispatcher::GetTypeAddress<Portakal::DomainFileDescriptor>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::DomainFileDescriptor>(pDomainFileDescriptor);
;		Portakal::Type* pDomainModule = Portakal::TypeDispatcher::CreateType("DomainModule",sizeof(Portakal::DomainModule),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateDomainModule,Portakal::TypeDispatcher::GetTypeAddress<Portakal::DomainModule>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::DomainModule>(pDomainModule);
;		Portakal::Type* pGUIDirection = Portakal::TypeDispatcher::CreateType("GUIDirection",sizeof(Portakal::GUIDirection),Portakal::TypeModes::Enum,Portakal::TypeCodes::Composed,CreateGUIDirection,Portakal::TypeDispatcher::GetTypeAddress<Portakal::GUIDirection>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::GUIDirection>(pGUIDirection);
;		Portakal::Type* pImGuiModule = Portakal::TypeDispatcher::CreateType("ImGuiModule",sizeof(Portakal::ImGuiModule),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateImGuiModule,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ImGuiModule>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ImGuiModule>(pImGuiModule);
;		Portakal::Type* pImGuiRenderEndModule = Portakal::TypeDispatcher::CreateType("ImGuiRenderEndModule",sizeof(Portakal::ImGuiRenderEndModule),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateImGuiRenderEndModule,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ImGuiRenderEndModule>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ImGuiRenderEndModule>(pImGuiRenderEndModule);
;		Portakal::Type* pImGuiRenderStartModule = Portakal::TypeDispatcher::CreateType("ImGuiRenderStartModule",sizeof(Portakal::ImGuiRenderStartModule),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateImGuiRenderStartModule,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ImGuiRenderStartModule>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ImGuiRenderStartModule>(pImGuiRenderStartModule);
;		Portakal::Type* pProjectDescriptor = Portakal::TypeDispatcher::CreateType("ProjectDescriptor",sizeof(Portakal::ProjectDescriptor),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateProjectDescriptor,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ProjectDescriptor>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ProjectDescriptor>(pProjectDescriptor);
;		Portakal::Type* pProjectModule = Portakal::TypeDispatcher::CreateType("ProjectModule",sizeof(Portakal::ProjectModule),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateProjectModule,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ProjectModule>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ProjectModule>(pProjectModule);
;		Portakal::Type* pCustomResourceSerializer = Portakal::TypeDispatcher::CreateType("CustomResourceSerializer",sizeof(Portakal::CustomResourceSerializer),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateCustomResourceSerializer,Portakal::TypeDispatcher::GetTypeAddress<Portakal::CustomResourceSerializer>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::CustomResourceSerializer>(pCustomResourceSerializer);
;		Portakal::Type* pEditorResourceModule = Portakal::TypeDispatcher::CreateType("EditorResourceModule",sizeof(Portakal::EditorResourceModule),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateEditorResourceModule,Portakal::TypeDispatcher::GetTypeAddress<Portakal::EditorResourceModule>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::EditorResourceModule>(pEditorResourceModule);
;		Portakal::Type* pIResourceSerializer = Portakal::TypeDispatcher::CreateType("IResourceSerializer",sizeof(Portakal::IResourceSerializer),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateIResourceSerializer,Portakal::TypeDispatcher::GetTypeAddress<Portakal::IResourceSerializer>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::IResourceSerializer>(pIResourceSerializer);
;		Portakal::Type* pCustomComponentPainter = Portakal::TypeDispatcher::CreateType("CustomComponentPainter",sizeof(Portakal::CustomComponentPainter),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateCustomComponentPainter,Portakal::TypeDispatcher::GetTypeAddress<Portakal::CustomComponentPainter>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::CustomComponentPainter>(pCustomComponentPainter);
;		Portakal::Type* pIComponentPainter = Portakal::TypeDispatcher::CreateType("IComponentPainter",sizeof(Portakal::IComponentPainter),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateIComponentPainter,Portakal::TypeDispatcher::GetTypeAddress<Portakal::IComponentPainter>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::IComponentPainter>(pIComponentPainter);
;		Portakal::Type* pCustomContextMenuItem = Portakal::TypeDispatcher::CreateType("CustomContextMenuItem",sizeof(Portakal::CustomContextMenuItem),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateCustomContextMenuItem,Portakal::TypeDispatcher::GetTypeAddress<Portakal::CustomContextMenuItem>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::CustomContextMenuItem>(pCustomContextMenuItem);
;		Portakal::Type* pIContextMenuItem = Portakal::TypeDispatcher::CreateType("IContextMenuItem",sizeof(Portakal::IContextMenuItem),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateIContextMenuItem,Portakal::TypeDispatcher::GetTypeAddress<Portakal::IContextMenuItem>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::IContextMenuItem>(pIContextMenuItem);
;		Portakal::Type* pCustomObjectPainter = Portakal::TypeDispatcher::CreateType("CustomObjectPainter",sizeof(Portakal::CustomObjectPainter),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateCustomObjectPainter,Portakal::TypeDispatcher::GetTypeAddress<Portakal::CustomObjectPainter>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::CustomObjectPainter>(pCustomObjectPainter);
;		Portakal::Type* pEditorObjectModule = Portakal::TypeDispatcher::CreateType("EditorObjectModule",sizeof(Portakal::EditorObjectModule),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateEditorObjectModule,Portakal::TypeDispatcher::GetTypeAddress<Portakal::EditorObjectModule>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::EditorObjectModule>(pEditorObjectModule);
;		Portakal::Type* pIObjectPainter = Portakal::TypeDispatcher::CreateType("IObjectPainter",sizeof(Portakal::IObjectPainter),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateIObjectPainter,Portakal::TypeDispatcher::GetTypeAddress<Portakal::IObjectPainter>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::IObjectPainter>(pIObjectPainter);
;		Portakal::Type* pCustomFileOpenAction = Portakal::TypeDispatcher::CreateType("CustomFileOpenAction",sizeof(Portakal::CustomFileOpenAction),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateCustomFileOpenAction,Portakal::TypeDispatcher::GetTypeAddress<Portakal::CustomFileOpenAction>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::CustomFileOpenAction>(pCustomFileOpenAction);
;		Portakal::Type* pIFileOpenAction = Portakal::TypeDispatcher::CreateType("IFileOpenAction",sizeof(Portakal::IFileOpenAction),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateIFileOpenAction,Portakal::TypeDispatcher::GetTypeAddress<Portakal::IFileOpenAction>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::IFileOpenAction>(pIFileOpenAction);
;		Portakal::Type* pCustomThumbnail = Portakal::TypeDispatcher::CreateType("CustomThumbnail",sizeof(Portakal::CustomThumbnail),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateCustomThumbnail,Portakal::TypeDispatcher::GetTypeAddress<Portakal::CustomThumbnail>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::CustomThumbnail>(pCustomThumbnail);
;		Portakal::Type* pIThumbnail = Portakal::TypeDispatcher::CreateType("IThumbnail",sizeof(Portakal::IThumbnail),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateIThumbnail,Portakal::TypeDispatcher::GetTypeAddress<Portakal::IThumbnail>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::IThumbnail>(pIThumbnail);
;		Portakal::Type* pGUIWindow = Portakal::TypeDispatcher::CreateType("GUIWindow",sizeof(Portakal::GUIWindow),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateGUIWindow,Portakal::TypeDispatcher::GetTypeAddress<Portakal::GUIWindow>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::GUIWindow>(pGUIWindow);
;		Portakal::Type* pGUIWindowDescriptor = Portakal::TypeDispatcher::CreateType("GUIWindowDescriptor",sizeof(Portakal::GUIWindowDescriptor),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateGUIWindowDescriptor,Portakal::TypeDispatcher::GetTypeAddress<Portakal::GUIWindowDescriptor>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::GUIWindowDescriptor>(pGUIWindowDescriptor);
;		Portakal::Type* pGUIWindowModule = Portakal::TypeDispatcher::CreateType("GUIWindowModule",sizeof(Portakal::GUIWindowModule),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateGUIWindowModule,Portakal::TypeDispatcher::GetTypeAddress<Portakal::GUIWindowModule>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::GUIWindowModule>(pGUIWindowModule);
;		Portakal::Type* pGUIWindowSettings = Portakal::TypeDispatcher::CreateType("GUIWindowSettings",sizeof(Portakal::GUIWindowSettings),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateGUIWindowSettings,Portakal::TypeDispatcher::GetTypeAddress<Portakal::GUIWindowSettings>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::GUIWindowSettings>(pGUIWindowSettings);
;		Portakal::Type* pMeshSerializer = Portakal::TypeDispatcher::CreateType("MeshSerializer",sizeof(Portakal::MeshSerializer),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateMeshSerializer,Portakal::TypeDispatcher::GetTypeAddress<Portakal::MeshSerializer>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::MeshSerializer>(pMeshSerializer);
;		Portakal::Type* pSamplerSerializer = Portakal::TypeDispatcher::CreateType("SamplerSerializer",sizeof(Portakal::SamplerSerializer),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateSamplerSerializer,Portakal::TypeDispatcher::GetTypeAddress<Portakal::SamplerSerializer>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::SamplerSerializer>(pSamplerSerializer);
;		Portakal::Type* pSceneSerializer = Portakal::TypeDispatcher::CreateType("SceneSerializer",sizeof(Portakal::SceneSerializer),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateSceneSerializer,Portakal::TypeDispatcher::GetTypeAddress<Portakal::SceneSerializer>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::SceneSerializer>(pSceneSerializer);
;		Portakal::Type* pShaderSerializer = Portakal::TypeDispatcher::CreateType("ShaderSerializer",sizeof(Portakal::ShaderSerializer),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateShaderSerializer,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ShaderSerializer>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ShaderSerializer>(pShaderSerializer);
;		Portakal::Type* pTextureSerializer = Portakal::TypeDispatcher::CreateType("TextureSerializer",sizeof(Portakal::TextureSerializer),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateTextureSerializer,Portakal::TypeDispatcher::GetTypeAddress<Portakal::TextureSerializer>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::TextureSerializer>(pTextureSerializer);
;		Portakal::Type* pBasicCameraPainter = Portakal::TypeDispatcher::CreateType("BasicCameraPainter",sizeof(Portakal::BasicCameraPainter),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateBasicCameraPainter,Portakal::TypeDispatcher::GetTypeAddress<Portakal::BasicCameraPainter>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::BasicCameraPainter>(pBasicCameraPainter);
;		Portakal::Type* pCreateFolderContextMenuItem = Portakal::TypeDispatcher::CreateType("CreateFolderContextMenuItem",sizeof(Portakal::CreateFolderContextMenuItem),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateCreateFolderContextMenuItem,Portakal::TypeDispatcher::GetTypeAddress<Portakal::CreateFolderContextMenuItem>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::CreateFolderContextMenuItem>(pCreateFolderContextMenuItem);
;		Portakal::Type* pCreateSamplerContextMenuItem = Portakal::TypeDispatcher::CreateType("CreateSamplerContextMenuItem",sizeof(Portakal::CreateSamplerContextMenuItem),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateCreateSamplerContextMenuItem,Portakal::TypeDispatcher::GetTypeAddress<Portakal::CreateSamplerContextMenuItem>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::CreateSamplerContextMenuItem>(pCreateSamplerContextMenuItem);
;		Portakal::Type* pCreateSceneContextMenuItem = Portakal::TypeDispatcher::CreateType("CreateSceneContextMenuItem",sizeof(Portakal::CreateSceneContextMenuItem),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateCreateSceneContextMenuItem,Portakal::TypeDispatcher::GetTypeAddress<Portakal::CreateSceneContextMenuItem>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::CreateSceneContextMenuItem>(pCreateSceneContextMenuItem);
;		Portakal::Type* pCreateShaderContextMenuItem = Portakal::TypeDispatcher::CreateType("CreateShaderContextMenuItem",sizeof(Portakal::CreateShaderContextMenuItem),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateCreateShaderContextMenuItem,Portakal::TypeDispatcher::GetTypeAddress<Portakal::CreateShaderContextMenuItem>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::CreateShaderContextMenuItem>(pCreateShaderContextMenuItem);
;		Portakal::Type* pEntityObjectPainter = Portakal::TypeDispatcher::CreateType("EntityObjectPainter",sizeof(Portakal::EntityObjectPainter),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateEntityObjectPainter,Portakal::TypeDispatcher::GetTypeAddress<Portakal::EntityObjectPainter>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::EntityObjectPainter>(pEntityObjectPainter);
;		Portakal::Type* pSamplerObjectPainter = Portakal::TypeDispatcher::CreateType("SamplerObjectPainter",sizeof(Portakal::SamplerObjectPainter),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateSamplerObjectPainter,Portakal::TypeDispatcher::GetTypeAddress<Portakal::SamplerObjectPainter>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::SamplerObjectPainter>(pSamplerObjectPainter);
;		Portakal::Type* pShaderObjectPainter = Portakal::TypeDispatcher::CreateType("ShaderObjectPainter",sizeof(Portakal::ShaderObjectPainter),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateShaderObjectPainter,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ShaderObjectPainter>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ShaderObjectPainter>(pShaderObjectPainter);
;		Portakal::Type* pTextureObjectPainter = Portakal::TypeDispatcher::CreateType("TextureObjectPainter",sizeof(Portakal::TextureObjectPainter),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateTextureObjectPainter,Portakal::TypeDispatcher::GetTypeAddress<Portakal::TextureObjectPainter>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::TextureObjectPainter>(pTextureObjectPainter);
;		Portakal::Type* pSceneFileOpenAction = Portakal::TypeDispatcher::CreateType("SceneFileOpenAction",sizeof(Portakal::SceneFileOpenAction),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateSceneFileOpenAction,Portakal::TypeDispatcher::GetTypeAddress<Portakal::SceneFileOpenAction>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::SceneFileOpenAction>(pSceneFileOpenAction);
;		Portakal::Type* pShaderFileOpenAction = Portakal::TypeDispatcher::CreateType("ShaderFileOpenAction",sizeof(Portakal::ShaderFileOpenAction),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateShaderFileOpenAction,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ShaderFileOpenAction>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ShaderFileOpenAction>(pShaderFileOpenAction);
;		Portakal::Type* pTextureFileOpenAction = Portakal::TypeDispatcher::CreateType("TextureFileOpenAction",sizeof(Portakal::TextureFileOpenAction),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateTextureFileOpenAction,Portakal::TypeDispatcher::GetTypeAddress<Portakal::TextureFileOpenAction>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::TextureFileOpenAction>(pTextureFileOpenAction);
;		Portakal::Type* pDefaultThumbnail = Portakal::TypeDispatcher::CreateType("DefaultThumbnail",sizeof(Portakal::DefaultThumbnail),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateDefaultThumbnail,Portakal::TypeDispatcher::GetTypeAddress<Portakal::DefaultThumbnail>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::DefaultThumbnail>(pDefaultThumbnail);
;		Portakal::Type* pMeshThumbnail = Portakal::TypeDispatcher::CreateType("MeshThumbnail",sizeof(Portakal::MeshThumbnail),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateMeshThumbnail,Portakal::TypeDispatcher::GetTypeAddress<Portakal::MeshThumbnail>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::MeshThumbnail>(pMeshThumbnail);
;		Portakal::Type* pSamplerThumbnail = Portakal::TypeDispatcher::CreateType("SamplerThumbnail",sizeof(Portakal::SamplerThumbnail),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateSamplerThumbnail,Portakal::TypeDispatcher::GetTypeAddress<Portakal::SamplerThumbnail>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::SamplerThumbnail>(pSamplerThumbnail);
;		Portakal::Type* pSceneThumbnail = Portakal::TypeDispatcher::CreateType("SceneThumbnail",sizeof(Portakal::SceneThumbnail),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateSceneThumbnail,Portakal::TypeDispatcher::GetTypeAddress<Portakal::SceneThumbnail>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::SceneThumbnail>(pSceneThumbnail);
;		Portakal::Type* pShaderThumbnail = Portakal::TypeDispatcher::CreateType("ShaderThumbnail",sizeof(Portakal::ShaderThumbnail),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateShaderThumbnail,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ShaderThumbnail>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ShaderThumbnail>(pShaderThumbnail);
;		Portakal::Type* pTextureThumbnail = Portakal::TypeDispatcher::CreateType("TextureThumbnail",sizeof(Portakal::TextureThumbnail),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateTextureThumbnail,Portakal::TypeDispatcher::GetTypeAddress<Portakal::TextureThumbnail>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::TextureThumbnail>(pTextureThumbnail);
;		Portakal::Type* pDomainWindow = Portakal::TypeDispatcher::CreateType("DomainWindow",sizeof(Portakal::DomainWindow),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateDomainWindow,Portakal::TypeDispatcher::GetTypeAddress<Portakal::DomainWindow>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::DomainWindow>(pDomainWindow);
;		Portakal::Type* pGameWindow = Portakal::TypeDispatcher::CreateType("GameWindow",sizeof(Portakal::GameWindow),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateGameWindow,Portakal::TypeDispatcher::GetTypeAddress<Portakal::GameWindow>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::GameWindow>(pGameWindow);
;		Portakal::Type* pObjectWindow = Portakal::TypeDispatcher::CreateType("ObjectWindow",sizeof(Portakal::ObjectWindow),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateObjectWindow,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ObjectWindow>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ObjectWindow>(pObjectWindow);
;		Portakal::Type* pSceneWindow = Portakal::TypeDispatcher::CreateType("SceneWindow",sizeof(Portakal::SceneWindow),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateSceneWindow,Portakal::TypeDispatcher::GetTypeAddress<Portakal::SceneWindow>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::SceneWindow>(pSceneWindow);
;		Portakal::Type* pWorldWindow = Portakal::TypeDispatcher::CreateType("WorldWindow",sizeof(Portakal::WorldWindow),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateWorldWindow,Portakal::TypeDispatcher::GetTypeAddress<Portakal::WorldWindow>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::WorldWindow>(pWorldWindow);
;		Portakal::Type* pEditorPlayerGDeviceModule = Portakal::TypeDispatcher::CreateType("EditorPlayerGDeviceModule",sizeof(Portakal::EditorPlayerGDeviceModule),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateEditorPlayerGDeviceModule,Portakal::TypeDispatcher::GetTypeAddress<Portakal::EditorPlayerGDeviceModule>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::EditorPlayerGDeviceModule>(pEditorPlayerGDeviceModule);
;		Portakal::Type* pEditorPlayerProjectModule = Portakal::TypeDispatcher::CreateType("EditorPlayerProjectModule",sizeof(Portakal::EditorPlayerProjectModule),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateEditorPlayerProjectModule,Portakal::TypeDispatcher::GetTypeAddress<Portakal::EditorPlayerProjectModule>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::EditorPlayerProjectModule>(pEditorPlayerProjectModule);
;		Portakal::Type* pEditorPlayerWindowModule = Portakal::TypeDispatcher::CreateType("EditorPlayerWindowModule",sizeof(Portakal::EditorPlayerWindowModule),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateEditorPlayerWindowModule,Portakal::TypeDispatcher::GetTypeAddress<Portakal::EditorPlayerWindowModule>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::EditorPlayerWindowModule>(pEditorPlayerWindowModule);
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
		Portakal::TypeDispatcher::RegisterEnum("None",-1,pGUIDirection);
		Portakal::TypeDispatcher::RegisterEnum("Left",0,pGUIDirection);
		Portakal::TypeDispatcher::RegisterEnum("Right",1,pGUIDirection);
		Portakal::TypeDispatcher::RegisterEnum("Up",2,pGUIDirection);
		Portakal::TypeDispatcher::RegisterEnum("Down",3,pGUIDirection);

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
		Portakal::TypeDispatcher::RegisterField("Target",offsetof(Portakal::DomainFileDescriptor,Target),typeof(Portakal::String),Portakal::FieldMode::Normal,pDomainFileDescriptor);
		Portakal::TypeDispatcher::RegisterField("Type",offsetof(Portakal::DomainFileDescriptor,Type),typeof(Portakal::String),Portakal::FieldMode::Normal,pDomainFileDescriptor);
		Portakal::TypeDispatcher::RegisterField("ID",offsetof(Portakal::DomainFileDescriptor,ID),typeof(Portakal::Guid),Portakal::FieldMode::Normal,pDomainFileDescriptor);
		Portakal::TypeDispatcher::RegisterField("Name",offsetof(Portakal::ProjectDescriptor,Name),typeof(Portakal::String),Portakal::FieldMode::Normal,pProjectDescriptor);
		Portakal::TypeDispatcher::RegisterField("ID",offsetof(Portakal::ProjectDescriptor,ID),typeof(Portakal::Guid),Portakal::FieldMode::Normal,pProjectDescriptor);
		Portakal::TypeDispatcher::RegisterField("VersionMajor",offsetof(Portakal::ProjectDescriptor,VersionMajor),typeof(Portakal::UInt32),Portakal::FieldMode::Normal,pProjectDescriptor);
		Portakal::TypeDispatcher::RegisterField("VersionMinor",offsetof(Portakal::ProjectDescriptor,VersionMinor),typeof(Portakal::UInt32),Portakal::FieldMode::Normal,pProjectDescriptor);
		Portakal::TypeDispatcher::RegisterField("VersionPatch",offsetof(Portakal::ProjectDescriptor,VersionPatch),typeof(Portakal::UInt32),Portakal::FieldMode::Normal,pProjectDescriptor);
		Portakal::TypeDispatcher::RegisterField("Name",offsetof(Portakal::GUIWindowDescriptor,Name),typeof(Portakal::String),Portakal::FieldMode::Normal,pGUIWindowDescriptor);
		Portakal::TypeDispatcher::RegisterField("ID",offsetof(Portakal::GUIWindowDescriptor,ID),typeof(Portakal::Guid),Portakal::FieldMode::Normal,pGUIWindowDescriptor);
		Portakal::TypeDispatcher::RegisterField("Size",offsetof(Portakal::GUIWindowDescriptor,Size),typeof(Portakal::Vector2US),Portakal::FieldMode::Normal,pGUIWindowDescriptor);
		Portakal::TypeDispatcher::RegisterField("Position",offsetof(Portakal::GUIWindowDescriptor,Position),typeof(Portakal::Vector2US),Portakal::FieldMode::Normal,pGUIWindowDescriptor);
		Portakal::TypeDispatcher::RegisterField("DockDirection",offsetof(Portakal::GUIWindowDescriptor,DockDirection),typeof(Portakal::GUIDirection),Portakal::FieldMode::Normal,pGUIWindowDescriptor);
		Portakal::TypeDispatcher::RegisterField("Settings",offsetof(Portakal::GUIWindowSettings,Settings),typeof(Portakal::GUIWindowDescriptor),Portakal::FieldMode::Array,pGUIWindowSettings);

        //Register attributes here
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::MyAttribute>(pTestClass);
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::CustomResourceDeserializer>(pMeshDeserializer, "mesh");
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::ResourceAttribute>(pSamplerResource, "sampler");
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::CustomResourceDeserializer>(pSceneDeserializer,"scene");
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::CustomResourceDeserializer>(pShaderDeserializer, "shader");
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::CustomResourceDeserializer>(pTextureDeserializer,"texture");
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::ResourceAttribute>(pTextureResource, "texture");
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::CustomResourceSerializer>(pMeshSerializer,"mesh",STRARRAY(".fbx",".obj"));
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::CustomResourceSerializer>(pSamplerSerializer, "sampler", STRARRAY(".psampler"));
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::CustomResourceSerializer>(pSceneSerializer, "scene",STRARRAY(".pscene"));
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::CustomResourceSerializer>(pShaderSerializer,"shader",STRARRAY(".pshader"));
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::CustomResourceSerializer>(pTextureSerializer, "texture",STRARRAY(".png",".jpg"));
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::CustomComponentPainter>(pBasicCameraPainter,typeof(Portakal::BasicCamera));
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::CustomContextMenuItem>(pCreateFolderContextMenuItem, "Create Folder");
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::CustomContextMenuItem>(pCreateSamplerContextMenuItem, "Create Sampler");
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::CustomContextMenuItem>(pCreateSceneContextMenuItem,"Create Scene");
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::CustomContextMenuItem>(pCreateShaderContextMenuItem, "Create Shader");
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::CustomObjectPainter>(pEntityObjectPainter,typeof(Portakal::Entity));
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::CustomObjectPainter>(pSamplerObjectPainter, typeof(Portakal::SamplerResource));
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::CustomObjectPainter>(pShaderObjectPainter, typeof(Portakal::ShaderResource));
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::CustomObjectPainter>(pTextureObjectPainter, typeof(Portakal::TextureResource));
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::CustomFileOpenAction>(pSceneFileOpenAction,"scene");
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::CustomFileOpenAction>(pShaderFileOpenAction, "shader");
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::CustomFileOpenAction>(pTextureFileOpenAction, "texture");
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::CustomThumbnail>(pMeshThumbnail, "mesh");
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::CustomThumbnail>(pSamplerThumbnail, "sampler");
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::CustomThumbnail>(pSceneThumbnail,"scene");
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::CustomThumbnail>(pShaderThumbnail, "shader");
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::CustomThumbnail>(pTextureThumbnail, "texture");

        //Register base types here
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::MyAttribute),typeof(Portakal::Attribute));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::TestClass),typeof(Portakal::Object));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ReflectionModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::RenderGraph),typeof(Portakal::Object));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::CustomResourceDeserializer),typeof(Portakal::Attribute));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ResourceModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::WindowModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::Entity),typeof(Portakal::Object));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::SceneModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::BasicCamera),typeof(Portakal::Component));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::BasicRenderAspect),typeof(Portakal::SceneAspect));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::MeshDeserializer),typeof(Portakal::IResourceDeserializer));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::MeshResource),typeof(Portakal::ResourceSubObject));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::RenderTargetResource),typeof(Portakal::ResourceSubObject));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::SamplerResource),typeof(Portakal::ResourceSubObject));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::SceneDeserializer),typeof(Portakal::IResourceDeserializer));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::SceneResource),typeof(Portakal::ResourceSubObject));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ShaderDeserializer),typeof(Portakal::IResourceDeserializer));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ShaderResource),typeof(Portakal::ResourceSubObject));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::TextureDeserializer),typeof(Portakal::IResourceDeserializer));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::TextureResource),typeof(Portakal::ResourceSubObject));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::DisplayAspect),typeof(Portakal::SceneAspect));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::DomainModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ImGuiModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ImGuiRenderEndModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ImGuiRenderStartModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ProjectModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::CustomResourceSerializer),typeof(Portakal::Attribute));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::EditorResourceModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::CustomComponentPainter),typeof(Portakal::Attribute));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::CustomContextMenuItem),typeof(Portakal::Attribute));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::CustomObjectPainter),typeof(Portakal::Attribute));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::EditorObjectModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::CustomFileOpenAction),typeof(Portakal::Attribute));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::CustomThumbnail),typeof(Portakal::Attribute));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::IThumbnail),typeof(Portakal::Object));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::GUIWindowModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::MeshSerializer),typeof(Portakal::IResourceSerializer));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::SamplerSerializer),typeof(Portakal::IResourceSerializer));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::SceneSerializer),typeof(Portakal::IResourceSerializer));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ShaderSerializer),typeof(Portakal::IResourceSerializer));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::TextureSerializer),typeof(Portakal::IResourceSerializer));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::BasicCameraPainter),typeof(Portakal::IComponentPainter));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::CreateFolderContextMenuItem),typeof(Portakal::IContextMenuItem));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::CreateSamplerContextMenuItem),typeof(Portakal::IContextMenuItem));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::CreateSceneContextMenuItem),typeof(Portakal::IContextMenuItem));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::CreateShaderContextMenuItem),typeof(Portakal::IContextMenuItem));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::EntityObjectPainter),typeof(Portakal::IObjectPainter));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::SamplerObjectPainter),typeof(Portakal::IObjectPainter));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ShaderObjectPainter),typeof(Portakal::IObjectPainter));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::TextureObjectPainter),typeof(Portakal::IObjectPainter));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::SceneFileOpenAction),typeof(Portakal::IFileOpenAction));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ShaderFileOpenAction),typeof(Portakal::IFileOpenAction));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::TextureFileOpenAction),typeof(Portakal::IFileOpenAction));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::DefaultThumbnail),typeof(Portakal::IThumbnail));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::MeshThumbnail),typeof(Portakal::IThumbnail));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::SamplerThumbnail),typeof(Portakal::IThumbnail));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::SceneThumbnail),typeof(Portakal::IThumbnail));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ShaderThumbnail),typeof(Portakal::IThumbnail));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::TextureThumbnail),typeof(Portakal::IThumbnail));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::DomainWindow),typeof(Portakal::GUIWindow));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::GameWindow),typeof(Portakal::GUIWindow));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ObjectWindow),typeof(Portakal::GUIWindow));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::SceneWindow),typeof(Portakal::GUIWindow));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::WorldWindow),typeof(Portakal::GUIWindow));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::EditorPlayerGDeviceModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::EditorPlayerProjectModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::EditorPlayerWindowModule),typeof(Portakal::ApplicationModule));

		//Create manifest here
		Portakal::Array<Portakal::Type*> types = {pMyAttribute,pTestClass,pApplicationModule,pGuid,pVector2F,pVector2I,pVector2UI,pVector2US,pObject,pPlatformType,pAttribute,pFieldMode,pReflectionModule,pRenderGraph,pRenderOperation,pCustomResourceDeserializer,pIResourceDeserializer,pResourceDescriptor,pResourceModule,pResourceSubObject,pWindowModule,pComponent,pEntity,pSceneAspect,pSceneModule,pCompareOperation,pLogicOperation,pSamplerAddressMode,pSamplerBorderColor,pSamplerFiltering,pSamplerMapMode,pShaderLanguage,pShaderStage,pBasicCamera,pBasicRenderAspect,pMeshDeserializer,pMeshResource,pRenderTargetResource,pSamplerDescriptor,pSamplerResource,pSceneComponentDescriptor,pSceneComponentFieldDescriptor,pSceneComponentFieldType,pSceneDescriptor,pSceneDeserializer,pSceneEntityDescriptor,pSceneResource,pShaderDescriptor,pShaderDeserializer,pShaderResource,pTextureDeserializer,pTextureResource,pDisplayAspect,pDomainFileDescriptor,pDomainModule,pGUIDirection,pImGuiModule,pImGuiRenderEndModule,pImGuiRenderStartModule,pProjectDescriptor,pProjectModule,pCustomResourceSerializer,pEditorResourceModule,pIResourceSerializer,pCustomComponentPainter,pIComponentPainter,pCustomContextMenuItem,pIContextMenuItem,pCustomObjectPainter,pEditorObjectModule,pIObjectPainter,pCustomFileOpenAction,pIFileOpenAction,pCustomThumbnail,pIThumbnail,pGUIWindow,pGUIWindowDescriptor,pGUIWindowModule,pGUIWindowSettings,pMeshSerializer,pSamplerSerializer,pSceneSerializer,pShaderSerializer,pTextureSerializer,pBasicCameraPainter,pCreateFolderContextMenuItem,pCreateSamplerContextMenuItem,pCreateSceneContextMenuItem,pCreateShaderContextMenuItem,pEntityObjectPainter,pSamplerObjectPainter,pShaderObjectPainter,pTextureObjectPainter,pSceneFileOpenAction,pShaderFileOpenAction,pTextureFileOpenAction,pDefaultThumbnail,pMeshThumbnail,pSamplerThumbnail,pSceneThumbnail,pShaderThumbnail,pTextureThumbnail,pDomainWindow,pGameWindow,pObjectWindow,pSceneWindow,pWorldWindow,pEditorPlayerGDeviceModule,pEditorPlayerProjectModule,pEditorPlayerWindowModule,};
		pManifest = new Portakal::ReflectionManifest("Runtime", types);

		return pManifest;
	}
}
