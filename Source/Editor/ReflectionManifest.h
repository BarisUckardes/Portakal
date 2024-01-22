
#pragma once
#include <Runtime/Reflection/Reflection.h>
#include <Runtime/Reflection/ReflectionManifest.h>
#include <Runtime/Reflection/TypeDispatcher.h>
#include "Domain\DomainFileDescriptor.h"
#include "Domain\DomainModule.h"
#include "GUI\GUIDirection.h"
#include "ImGui\ImGuiModule.h"
#include "ImGui\ImGuiRenderEndModule.h"
#include "ImGui\ImGuiRenderStartModule.h"
#include "Project\ProjectDescriptor.h"
#include "Project\ProjectModule.h"
#include "Resource\CustomResourceSerializer.h"
#include "Resource\EditorResourceModule.h"
#include "Resource\IResourceSerializer.h"
#include "GUI\Component\CustomComponentPainter.h"
#include "GUI\Component\IComponentPainter.h"
#include "GUI\ContextMenu\CustomContextMenuItem.h"
#include "GUI\ContextMenu\IContextMenuItem.h"
#include "GUI\Object\CustomObjectPainter.h"
#include "GUI\Object\EditorObjectModule.h"
#include "GUI\Object\IObjectPainter.h"
#include "GUI\OpenAction\CustomFileOpenAction.h"
#include "GUI\OpenAction\IFileOpenAction.h"
#include "GUI\Thumbnail\CustomThumbnail.h"
#include "GUI\Thumbnail\IThumbnail.h"
#include "GUI\Window\GUIWindow.h"
#include "GUI\Window\GUIWindowDescriptor.h"
#include "GUI\Window\GUIWindowModule.h"
#include "GUI\Window\GUIWindowSettings.h"
#include "Resource\Mesh\MeshSerializer.h"
#include "Resource\Sampler\SamplerSerializer.h"
#include "Resource\Scene\SceneSerializer.h"
#include "Resource\Shader\ShaderSerializer.h"
#include "Resource\Texture\TextureSerializer.h"
#include "GUI\Component\Builtin\BasicCameraPainter.h"
#include "GUI\ContextMenu\Builtin\CreateFolderContextMenuItem.h"
#include "GUI\ContextMenu\Builtin\CreateSamplerContextMenuItem.h"
#include "GUI\ContextMenu\Builtin\CreateSceneContextMenuItem.h"
#include "GUI\ContextMenu\Builtin\CreateShaderContextMenuItem.h"
#include "GUI\Object\Builtin\EntityObjectPainter.h"
#include "GUI\Object\Builtin\SamplerObjectPainter.h"
#include "GUI\Object\Builtin\ShaderObjectPainter.h"
#include "GUI\Object\Builtin\TextureObjectPainter.h"
#include "GUI\OpenAction\Builtin\SceneFileOpenAction.h"
#include "GUI\OpenAction\Builtin\ShaderFileOpenAction.h"
#include "GUI\OpenAction\Builtin\TextureFileOpenAction.h"
#include "GUI\Thumbnail\Builtin\DefaultThumbnail.h"
#include "GUI\Thumbnail\Builtin\MeshThumbnail.h"
#include "GUI\Thumbnail\Builtin\SamplerThumbnail.h"
#include "GUI\Thumbnail\Builtin\SceneThumbnail.h"
#include "GUI\Thumbnail\Builtin\ShaderThumbnail.h"
#include "GUI\Thumbnail\Builtin\TextureThumbnail.h"
#include "GUI\Window\Builtin\DomainWindow.h"
#include "GUI\Window\Builtin\GameWindow.h"
#include "GUI\Window\Builtin\ObjectWindow.h"
#include "GUI\Window\Builtin\SceneWindow.h"
#include "GUI\Window\Builtin\WorldWindow.h"


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
		Portakal::Type* pDomainFileDescriptor = Portakal::TypeDispatcher::CreateType("DomainFileDescriptor",sizeof(Portakal::DomainFileDescriptor),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateDomainFileDescriptor,Portakal::TypeDispatcher::GetTypeAddress<Portakal::DomainFileDescriptor>());
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
;
        //Register enums here
		Portakal::TypeDispatcher::RegisterEnum("None",-1,pGUIDirection);
		Portakal::TypeDispatcher::RegisterEnum("Left",0,pGUIDirection);
		Portakal::TypeDispatcher::RegisterEnum("Right",1,pGUIDirection);
		Portakal::TypeDispatcher::RegisterEnum("Up",2,pGUIDirection);
		Portakal::TypeDispatcher::RegisterEnum("Down",3,pGUIDirection);

        //Register fields here
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

		//Create manifest here
		Portakal::Array<Portakal::Type*> types = {pDomainFileDescriptor,pDomainModule,pGUIDirection,pImGuiModule,pImGuiRenderEndModule,pImGuiRenderStartModule,pProjectDescriptor,pProjectModule,pCustomResourceSerializer,pEditorResourceModule,pIResourceSerializer,pCustomComponentPainter,pIComponentPainter,pCustomContextMenuItem,pIContextMenuItem,pCustomObjectPainter,pEditorObjectModule,pIObjectPainter,pCustomFileOpenAction,pIFileOpenAction,pCustomThumbnail,pIThumbnail,pGUIWindow,pGUIWindowDescriptor,pGUIWindowModule,pGUIWindowSettings,pMeshSerializer,pSamplerSerializer,pSceneSerializer,pShaderSerializer,pTextureSerializer,pBasicCameraPainter,pCreateFolderContextMenuItem,pCreateSamplerContextMenuItem,pCreateSceneContextMenuItem,pCreateShaderContextMenuItem,pEntityObjectPainter,pSamplerObjectPainter,pShaderObjectPainter,pTextureObjectPainter,pSceneFileOpenAction,pShaderFileOpenAction,pTextureFileOpenAction,pDefaultThumbnail,pMeshThumbnail,pSamplerThumbnail,pSceneThumbnail,pShaderThumbnail,pTextureThumbnail,pDomainWindow,pGameWindow,pObjectWindow,pSceneWindow,pWorldWindow,};
		pManifest = new Portakal::ReflectionManifest("Runtime", types);

		return pManifest;
	}
}
