
#pragma once
#include <Runtime/Reflection/Reflection.h>
#include <Runtime/Reflection/ReflectionManifest.h>
#include <Runtime/Reflection/TypeDispatcher.h>
#include "Domain\DomainModule.h"
#include "GUI\ContextCreateItem.h"
#include "GUI\CreateFolderContextAction.h"
#include "GUI\GUIDirection.h"
#include "GUI\IContextCreateAction.h"
#include "ImGui\ImGuiModule.h"
#include "ImGui\ImGuiRenderEndModule.h"
#include "ImGui\ImGuiRenderStartModule.h"
#include "Project\ProjectDescriptor.h"
#include "Project\ProjectModule.h"
#include "Resource\IResourceSerializer.h"
#include "Resource\ResourceSerializerAttribute.h"
#include "GUI\Window\GUIWindow.h"
#include "GUI\Window\GUIWindowDescriptor.h"
#include "GUI\Window\GUIWindowModule.h"
#include "GUI\Window\GUIWindowSettings.h"
#include "Resource\Texture\TextureSerializer.h"
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
		void* CreateDomainModule() {return new Portakal::DomainModule();}
		void* CreateContextCreateItem() {return new Portakal::ContextCreateItem();}
		void* CreateCreateFolderContextAction() {return new Portakal::CreateFolderContextAction();}
		void* CreateGUIDirection() {return new Portakal::GUIDirection();}
		void* CreateIContextCreateAction() {return nullptr;}
		void* CreateImGuiModule() {return new Portakal::ImGuiModule();}
		void* CreateImGuiRenderEndModule() {return new Portakal::ImGuiRenderEndModule();}
		void* CreateImGuiRenderStartModule() {return new Portakal::ImGuiRenderStartModule();}
		void* CreateProjectDescriptor() {return new Portakal::ProjectDescriptor();}
		void* CreateProjectModule() {return new Portakal::ProjectModule();}
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
		Portakal::Type* pDomainModule = Portakal::TypeDispatcher::CreateType("DomainModule",sizeof(Portakal::DomainModule),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateDomainModule,Portakal::TypeDispatcher::GetTypeAddress<Portakal::DomainModule>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::DomainModule>(pDomainModule);
;		Portakal::Type* pContextCreateItem = Portakal::TypeDispatcher::CreateType("ContextCreateItem",sizeof(Portakal::ContextCreateItem),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateContextCreateItem,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ContextCreateItem>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ContextCreateItem>(pContextCreateItem);
;		Portakal::Type* pCreateFolderContextAction = Portakal::TypeDispatcher::CreateType("CreateFolderContextAction",sizeof(Portakal::CreateFolderContextAction),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateCreateFolderContextAction,Portakal::TypeDispatcher::GetTypeAddress<Portakal::CreateFolderContextAction>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::CreateFolderContextAction>(pCreateFolderContextAction);
;		Portakal::Type* pGUIDirection = Portakal::TypeDispatcher::CreateType("GUIDirection",sizeof(Portakal::GUIDirection),Portakal::TypeModes::Enum,Portakal::TypeCodes::Composed,CreateGUIDirection,Portakal::TypeDispatcher::GetTypeAddress<Portakal::GUIDirection>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::GUIDirection>(pGUIDirection);
;		Portakal::Type* pIContextCreateAction = Portakal::TypeDispatcher::CreateType("IContextCreateAction",sizeof(Portakal::IContextCreateAction),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateIContextCreateAction,Portakal::TypeDispatcher::GetTypeAddress<Portakal::IContextCreateAction>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::IContextCreateAction>(pIContextCreateAction);
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
;
        //Register enums here
		Portakal::TypeDispatcher::RegisterEnum("None",-1,pGUIDirection);
		Portakal::TypeDispatcher::RegisterEnum("Left",0,pGUIDirection);
		Portakal::TypeDispatcher::RegisterEnum("Right",1,pGUIDirection);
		Portakal::TypeDispatcher::RegisterEnum("Up",2,pGUIDirection);
		Portakal::TypeDispatcher::RegisterEnum("Down",3,pGUIDirection);

        //Register fields here
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
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::ContextCreateItem>(pCreateFolderContextAction, "Create Folder");
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::ResourceSerializerAttribute>(pTextureSerializer, "texture");

        //Register base types here
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::DomainModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ContextCreateItem),typeof(Portakal::Attribute));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::CreateFolderContextAction),typeof(Portakal::IContextCreateAction));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ImGuiModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ImGuiRenderEndModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ImGuiRenderStartModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ProjectModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ResourceSerializerAttribute),typeof(Portakal::Attribute));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::GUIWindowModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::TextureSerializer),typeof(Portakal::IResourceSerializer));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::DomainWindow),typeof(Portakal::GUIWindow));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::GameWindow),typeof(Portakal::GUIWindow));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ObjectWindow),typeof(Portakal::GUIWindow));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::SceneWindow),typeof(Portakal::GUIWindow));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::WorldWindow),typeof(Portakal::GUIWindow));

		//Create manifest here
		Portakal::Array<Portakal::Type*> types = {pDomainModule,pContextCreateItem,pCreateFolderContextAction,pGUIDirection,pIContextCreateAction,pImGuiModule,pImGuiRenderEndModule,pImGuiRenderStartModule,pProjectDescriptor,pProjectModule,pIResourceSerializer,pResourceSerializerAttribute,pGUIWindow,pGUIWindowDescriptor,pGUIWindowModule,pGUIWindowSettings,pTextureSerializer,pDomainWindow,pGameWindow,pObjectWindow,pSceneWindow,pWorldWindow,};
		pManifest = new Portakal::ReflectionManifest("Runtime", types);

		return pManifest;
	}
}
