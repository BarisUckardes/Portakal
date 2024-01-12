
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
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Reflection\ReflectionModule.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Rendering\RenderGraph.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Rendering\RenderOperation.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Resource\IResourceDeserializer.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Resource\ResourceDescriptor.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Resource\ResourceDeserializerAttribute.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Resource\ResourceSubObject.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Window\WindowModule.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\World\Component.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\World\SceneAspect.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Resource\Mesh\MeshResource.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Resource\RenderTarget\RenderTarget.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Resource\Texture\TextureDeserializer.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Resource\Texture\TextureResource.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\Domain\DomainModule.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\ContextMenuItem.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\CreateFolderContextMenuItem.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\GUIDirection.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\IContextMenuItem.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\ImGui\ImGuiModule.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\ImGui\ImGuiRenderEndModule.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\ImGui\ImGuiRenderStartModule.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\Project\ProjectDescriptor.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\Project\ProjectModule.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\Resource\EditorResourceModule.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\Resource\IResourceSerializer.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\Resource\ResourceSerializerAttribute.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\Window\GUIWindow.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\Window\GUIWindowDescriptor.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\Window\GUIWindowModule.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\GUI\Window\GUIWindowSettings.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\Resource\Texture\TextureSerializer.h"
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
		void* CreateReflectionModule() {return new Portakal::ReflectionModule();}
		void* CreateRenderGraph() {return new Portakal::RenderGraph();}
		void* CreateRenderOperation() {return nullptr;}
		void* CreateIResourceDeserializer() {return nullptr;}
		void* CreateResourceDescriptor() {return new Portakal::ResourceDescriptor();}
		void* CreateResourceDeserializerAttribute() {return new Portakal::ResourceDeserializerAttribute();}
		void* CreateResourceSubObject() {return nullptr;}
		void* CreateWindowModule() {return new Portakal::WindowModule();}
		void* CreateComponent() {return nullptr;}
		void* CreateSceneAspect() {return nullptr;}
		void* CreateMeshResource() {return new Portakal::MeshResource();}
		void* CreateRenderTarget() {return new Portakal::RenderTarget();}
		void* CreateTextureDeserializer() {return new Portakal::TextureDeserializer();}
		void* CreateTextureResource() {return new Portakal::TextureResource();}
		void* CreateDomainModule() {return new Portakal::DomainModule();}
		void* CreateContextMenuItem() {return new Portakal::ContextMenuItem();}
		void* CreateCreateFolderContextMenuItem() {return new Portakal::CreateFolderContextMenuItem();}
		void* CreateGUIDirection() {return new Portakal::GUIDirection();}
		void* CreateIContextMenuItem() {return nullptr;}
		void* CreateImGuiModule() {return new Portakal::ImGuiModule();}
		void* CreateImGuiRenderEndModule() {return new Portakal::ImGuiRenderEndModule();}
		void* CreateImGuiRenderStartModule() {return new Portakal::ImGuiRenderStartModule();}
		void* CreateProjectDescriptor() {return new Portakal::ProjectDescriptor();}
		void* CreateProjectModule() {return new Portakal::ProjectModule();}
		void* CreateEditorResourceModule() {return new Portakal::EditorResourceModule();}
		void* CreateIResourceSerializer() {return nullptr;}
		void* CreateResourceSerializerAttribute() {return new Portakal::ResourceSerializerAttribute();}
		void* CreateGUIWindow() {return nullptr;}
		void* CreateGUIWindowDescriptor() {return new Portakal::GUIWindowDescriptor();}
		void* CreateGUIWindowModule() {return new Portakal::GUIWindowModule();}
		void* CreateGUIWindowSettings() {return new Portakal::GUIWindowSettings();}
		void* CreateTextureSerializer() {return new Portakal::TextureSerializer();}
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
;		Portakal::Type* pReflectionModule = Portakal::TypeDispatcher::CreateType("ReflectionModule",sizeof(Portakal::ReflectionModule),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateReflectionModule,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ReflectionModule>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ReflectionModule>(pReflectionModule);
;		Portakal::Type* pRenderGraph = Portakal::TypeDispatcher::CreateType("RenderGraph",sizeof(Portakal::RenderGraph),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateRenderGraph,Portakal::TypeDispatcher::GetTypeAddress<Portakal::RenderGraph>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::RenderGraph>(pRenderGraph);
;		Portakal::Type* pRenderOperation = Portakal::TypeDispatcher::CreateType("RenderOperation",sizeof(Portakal::RenderOperation),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateRenderOperation,Portakal::TypeDispatcher::GetTypeAddress<Portakal::RenderOperation>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::RenderOperation>(pRenderOperation);
;		Portakal::Type* pIResourceDeserializer = Portakal::TypeDispatcher::CreateType("IResourceDeserializer",sizeof(Portakal::IResourceDeserializer),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateIResourceDeserializer,Portakal::TypeDispatcher::GetTypeAddress<Portakal::IResourceDeserializer>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::IResourceDeserializer>(pIResourceDeserializer);
;		Portakal::Type* pResourceDescriptor = Portakal::TypeDispatcher::CreateType("ResourceDescriptor",sizeof(Portakal::ResourceDescriptor),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateResourceDescriptor,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ResourceDescriptor>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ResourceDescriptor>(pResourceDescriptor);
;		Portakal::Type* pResourceDeserializerAttribute = Portakal::TypeDispatcher::CreateType("ResourceDeserializerAttribute",sizeof(Portakal::ResourceDeserializerAttribute),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateResourceDeserializerAttribute,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ResourceDeserializerAttribute>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ResourceDeserializerAttribute>(pResourceDeserializerAttribute);
;		Portakal::Type* pResourceSubObject = Portakal::TypeDispatcher::CreateType("ResourceSubObject",sizeof(Portakal::ResourceSubObject),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateResourceSubObject,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ResourceSubObject>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ResourceSubObject>(pResourceSubObject);
;		Portakal::Type* pWindowModule = Portakal::TypeDispatcher::CreateType("WindowModule",sizeof(Portakal::WindowModule),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateWindowModule,Portakal::TypeDispatcher::GetTypeAddress<Portakal::WindowModule>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::WindowModule>(pWindowModule);
;		Portakal::Type* pComponent = Portakal::TypeDispatcher::CreateType("Component",sizeof(Portakal::Component),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateComponent,Portakal::TypeDispatcher::GetTypeAddress<Portakal::Component>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::Component>(pComponent);
;		Portakal::Type* pSceneAspect = Portakal::TypeDispatcher::CreateType("SceneAspect",sizeof(Portakal::SceneAspect),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateSceneAspect,Portakal::TypeDispatcher::GetTypeAddress<Portakal::SceneAspect>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::SceneAspect>(pSceneAspect);
;		Portakal::Type* pMeshResource = Portakal::TypeDispatcher::CreateType("MeshResource",sizeof(Portakal::MeshResource),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateMeshResource,Portakal::TypeDispatcher::GetTypeAddress<Portakal::MeshResource>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::MeshResource>(pMeshResource);
;		Portakal::Type* pRenderTarget = Portakal::TypeDispatcher::CreateType("RenderTarget",sizeof(Portakal::RenderTarget),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateRenderTarget,Portakal::TypeDispatcher::GetTypeAddress<Portakal::RenderTarget>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::RenderTarget>(pRenderTarget);
;		Portakal::Type* pTextureDeserializer = Portakal::TypeDispatcher::CreateType("TextureDeserializer",sizeof(Portakal::TextureDeserializer),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateTextureDeserializer,Portakal::TypeDispatcher::GetTypeAddress<Portakal::TextureDeserializer>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::TextureDeserializer>(pTextureDeserializer);
;		Portakal::Type* pTextureResource = Portakal::TypeDispatcher::CreateType("TextureResource",sizeof(Portakal::TextureResource),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateTextureResource,Portakal::TypeDispatcher::GetTypeAddress<Portakal::TextureResource>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::TextureResource>(pTextureResource);
;		Portakal::Type* pDomainModule = Portakal::TypeDispatcher::CreateType("DomainModule",sizeof(Portakal::DomainModule),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateDomainModule,Portakal::TypeDispatcher::GetTypeAddress<Portakal::DomainModule>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::DomainModule>(pDomainModule);
;		Portakal::Type* pContextMenuItem = Portakal::TypeDispatcher::CreateType("ContextMenuItem",sizeof(Portakal::ContextMenuItem),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateContextMenuItem,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ContextMenuItem>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ContextMenuItem>(pContextMenuItem);
;		Portakal::Type* pCreateFolderContextMenuItem = Portakal::TypeDispatcher::CreateType("CreateFolderContextMenuItem",sizeof(Portakal::CreateFolderContextMenuItem),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateCreateFolderContextMenuItem,Portakal::TypeDispatcher::GetTypeAddress<Portakal::CreateFolderContextMenuItem>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::CreateFolderContextMenuItem>(pCreateFolderContextMenuItem);
;		Portakal::Type* pGUIDirection = Portakal::TypeDispatcher::CreateType("GUIDirection",sizeof(Portakal::GUIDirection),Portakal::TypeModes::Enum,Portakal::TypeCodes::Composed,CreateGUIDirection,Portakal::TypeDispatcher::GetTypeAddress<Portakal::GUIDirection>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::GUIDirection>(pGUIDirection);
;		Portakal::Type* pIContextMenuItem = Portakal::TypeDispatcher::CreateType("IContextMenuItem",sizeof(Portakal::IContextMenuItem),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateIContextMenuItem,Portakal::TypeDispatcher::GetTypeAddress<Portakal::IContextMenuItem>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::IContextMenuItem>(pIContextMenuItem);
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
;		Portakal::Type* pEditorResourceModule = Portakal::TypeDispatcher::CreateType("EditorResourceModule",sizeof(Portakal::EditorResourceModule),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateEditorResourceModule,Portakal::TypeDispatcher::GetTypeAddress<Portakal::EditorResourceModule>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::EditorResourceModule>(pEditorResourceModule);
;		Portakal::Type* pIResourceSerializer = Portakal::TypeDispatcher::CreateType("IResourceSerializer",sizeof(Portakal::IResourceSerializer),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateIResourceSerializer,Portakal::TypeDispatcher::GetTypeAddress<Portakal::IResourceSerializer>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::IResourceSerializer>(pIResourceSerializer);
;		Portakal::Type* pResourceSerializerAttribute = Portakal::TypeDispatcher::CreateType("ResourceSerializerAttribute",sizeof(Portakal::ResourceSerializerAttribute),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateResourceSerializerAttribute,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ResourceSerializerAttribute>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ResourceSerializerAttribute>(pResourceSerializerAttribute);
;		Portakal::Type* pGUIWindow = Portakal::TypeDispatcher::CreateType("GUIWindow",sizeof(Portakal::GUIWindow),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateGUIWindow,Portakal::TypeDispatcher::GetTypeAddress<Portakal::GUIWindow>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::GUIWindow>(pGUIWindow);
;		Portakal::Type* pGUIWindowDescriptor = Portakal::TypeDispatcher::CreateType("GUIWindowDescriptor",sizeof(Portakal::GUIWindowDescriptor),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateGUIWindowDescriptor,Portakal::TypeDispatcher::GetTypeAddress<Portakal::GUIWindowDescriptor>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::GUIWindowDescriptor>(pGUIWindowDescriptor);
;		Portakal::Type* pGUIWindowModule = Portakal::TypeDispatcher::CreateType("GUIWindowModule",sizeof(Portakal::GUIWindowModule),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateGUIWindowModule,Portakal::TypeDispatcher::GetTypeAddress<Portakal::GUIWindowModule>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::GUIWindowModule>(pGUIWindowModule);
;		Portakal::Type* pGUIWindowSettings = Portakal::TypeDispatcher::CreateType("GUIWindowSettings",sizeof(Portakal::GUIWindowSettings),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateGUIWindowSettings,Portakal::TypeDispatcher::GetTypeAddress<Portakal::GUIWindowSettings>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::GUIWindowSettings>(pGUIWindowSettings);
;		Portakal::Type* pTextureSerializer = Portakal::TypeDispatcher::CreateType("TextureSerializer",sizeof(Portakal::TextureSerializer),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateTextureSerializer,Portakal::TypeDispatcher::GetTypeAddress<Portakal::TextureSerializer>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::TextureSerializer>(pTextureSerializer);
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
		Portakal::TypeDispatcher::RegisterField("Path",offsetof(Portakal::ResourceDescriptor,Path),typeof(Portakal::String),Portakal::FieldMode::Normal,pResourceDescriptor);
		Portakal::TypeDispatcher::RegisterField("ResourceType",offsetof(Portakal::ResourceDescriptor,ResourceType),typeof(Portakal::String),Portakal::FieldMode::Normal,pResourceDescriptor);
		Portakal::TypeDispatcher::RegisterField("Name",offsetof(Portakal::ResourceDescriptor,Name),typeof(Portakal::String),Portakal::FieldMode::Normal,pResourceDescriptor);
		Portakal::TypeDispatcher::RegisterField("ID",offsetof(Portakal::ResourceDescriptor,ID),typeof(Portakal::Guid),Portakal::FieldMode::Normal,pResourceDescriptor);
		Portakal::TypeDispatcher::RegisterField("FileOffset",offsetof(Portakal::ResourceDescriptor,FileOffset),typeof(Portakal::UInt64),Portakal::FieldMode::Normal,pResourceDescriptor);
		Portakal::TypeDispatcher::RegisterField("FileSize",offsetof(Portakal::ResourceDescriptor,FileSize),typeof(Portakal::UInt64),Portakal::FieldMode::Normal,pResourceDescriptor);
		Portakal::TypeDispatcher::RegisterField("bOptimized",offsetof(Portakal::ResourceDescriptor,bOptimized),typeof(Portakal::Bool8),Portakal::FieldMode::Normal,pResourceDescriptor);
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
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::ResourceAttribute>(pTextureResource, "texture");
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::ContextMenuItem>(pCreateFolderContextMenuItem, "Create Folder");
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::ResourceSerializerAttribute>(pTextureSerializer, "texture");

        //Register base types here
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::MyAttribute),typeof(Portakal::Attribute));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::TestClass),typeof(Portakal::Object));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ReflectionModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::RenderGraph),typeof(Portakal::Object));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ResourceDeserializerAttribute),typeof(Portakal::Attribute));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::WindowModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::MeshResource),typeof(Portakal::ResourceSubObject));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::RenderTarget),typeof(Portakal::ResourceSubObject));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::TextureDeserializer),typeof(Portakal::IResourceDeserializer));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::TextureResource),typeof(Portakal::ResourceSubObject));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::DomainModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ContextMenuItem),typeof(Portakal::Attribute));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::CreateFolderContextMenuItem),typeof(Portakal::IContextMenuItem));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ImGuiModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ImGuiRenderEndModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ImGuiRenderStartModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ProjectModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::EditorResourceModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ResourceSerializerAttribute),typeof(Portakal::Attribute));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::GUIWindowModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::TextureSerializer),typeof(Portakal::IResourceSerializer));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::DomainWindow),typeof(Portakal::GUIWindow));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::GameWindow),typeof(Portakal::GUIWindow));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ObjectWindow),typeof(Portakal::GUIWindow));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::SceneWindow),typeof(Portakal::GUIWindow));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::WorldWindow),typeof(Portakal::GUIWindow));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::EditorPlayerGDeviceModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::EditorPlayerProjectModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::EditorPlayerWindowModule),typeof(Portakal::ApplicationModule));

		//Create manifest here
		Portakal::Array<Portakal::Type*> types = {pMyAttribute,pTestClass,pApplicationModule,pGuid,pVector2F,pVector2I,pVector2UI,pVector2US,pObject,pPlatformType,pAttribute,pReflectionModule,pRenderGraph,pRenderOperation,pIResourceDeserializer,pResourceDescriptor,pResourceDeserializerAttribute,pResourceSubObject,pWindowModule,pComponent,pSceneAspect,pMeshResource,pRenderTarget,pTextureDeserializer,pTextureResource,pDomainModule,pContextMenuItem,pCreateFolderContextMenuItem,pGUIDirection,pIContextMenuItem,pImGuiModule,pImGuiRenderEndModule,pImGuiRenderStartModule,pProjectDescriptor,pProjectModule,pEditorResourceModule,pIResourceSerializer,pResourceSerializerAttribute,pGUIWindow,pGUIWindowDescriptor,pGUIWindowModule,pGUIWindowSettings,pTextureSerializer,pDomainWindow,pGameWindow,pObjectWindow,pSceneWindow,pWorldWindow,pEditorPlayerGDeviceModule,pEditorPlayerProjectModule,pEditorPlayerWindowModule,};
		pManifest = new Portakal::ReflectionManifest("Runtime", types);

		return pManifest;
	}
}
