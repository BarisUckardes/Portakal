
#pragma once
#include <Runtime/Reflection/Reflection.h>
#include <Runtime/Reflection/ReflectionManifest.h>
#include <Runtime/Reflection/TypeDispatcher.h>
#include "Domain\DomainModule.h"
#include "ImGui\ImGuiModule.h"
#include "ImGui\ImGuiRenderEndModule.h"
#include "ImGui\ImGuiRenderStartModule.h"
#include "Project\ProjectDescriptor.h"
#include "Project\ProjectModule.h"
#include "Resource\IResourceSerializer.h"
#include "Resource\ResourceSerializerAttribute.h"
#include "GUI\Window\GUIWindowDescriptor.h"
#include "Resource\Texture\TextureSerializer.h"


		void* CreateBool8() {return new Portakal::Bool8();}
		void* CreateChar() {return new Portakal::Char();}
		void* CreateByte() {return new Portakal::Byte();}
		void* CreateUInt16() {return new Portakal::Uint16();}
		void* CreateUInt32() {return new Portakal::Uint32();}
		void* CreateUInt64() {return new Portakal::Uint64();}
		void* CreateInt16() {return new Portakal::Int16();}
		void* CreateInt32() {return new Portakal::Int32();}
		void* CreateInt64() {return new Portakal::Int64();}
		void* CreateFloat32() {return new Portakal::Float32();}
		void* CreateFloat64() {return new Portakal::Float64();}
		void* CreateString() {return new Portakal::String();}
		void* CreateDomainModule() {return new Portakal::DomainModule();}
		void* CreateImGuiModule() {return new Portakal::ImGuiModule();}
		void* CreateImGuiRenderEndModule() {return new Portakal::ImGuiRenderEndModule();}
		void* CreateImGuiRenderStartModule() {return new Portakal::ImGuiRenderStartModule();}
		void* CreateProjectDescriptor() {return new Portakal::ProjectDescriptor();}
		void* CreateProjectModule() {return new Portakal::ProjectModule();}
		void* CreateIResourceSerializer() {return nullptr;}
		void* CreateResourceSerializerAttribute() {return new Portakal::ResourceSerializerAttribute();}
		void* CreateGUIWindowDescriptor() {return new Portakal::GUIWindowDescriptor();}
		void* CreateTextureSerializer() {return new Portakal::TextureSerializer();}

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
		Portakal::Type* pUint16 = Portakal::TypeDispatcher::CreateType("Uint16",sizeof(Portakal::Uint16),Portakal::TypeModes::Class,Portakal::TypeCodes::UInt16,CreateUInt16,Portakal::TypeDispatcher::GetTypeAddress<Portakal::Uint16>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::Uint16>(pUint16);
		Portakal::Type* pUint32 = Portakal::TypeDispatcher::CreateType("Uint32",sizeof(Portakal::Uint32),Portakal::TypeModes::Class,Portakal::TypeCodes::UInt32,CreateUInt32,Portakal::TypeDispatcher::GetTypeAddress<Portakal::Uint32>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::Uint32>(pUint32);
		Portakal::Type* pUint64 = Portakal::TypeDispatcher::CreateType("Uint64",sizeof(Portakal::Uint64),Portakal::TypeModes::Class,Portakal::TypeCodes::UInt64,CreateUInt64,Portakal::TypeDispatcher::GetTypeAddress<Portakal::Uint64>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::Uint64>(pUint64);
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
;		Portakal::Type* pGUIWindowDescriptor = Portakal::TypeDispatcher::CreateType("GUIWindowDescriptor",sizeof(Portakal::GUIWindowDescriptor),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateGUIWindowDescriptor,Portakal::TypeDispatcher::GetTypeAddress<Portakal::GUIWindowDescriptor>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::GUIWindowDescriptor>(pGUIWindowDescriptor);
;		Portakal::Type* pTextureSerializer = Portakal::TypeDispatcher::CreateType("TextureSerializer",sizeof(Portakal::TextureSerializer),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateTextureSerializer,Portakal::TypeDispatcher::GetTypeAddress<Portakal::TextureSerializer>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::TextureSerializer>(pTextureSerializer);
;
        //Register enums here

        //Register fields here
		Portakal::TypeDispatcher::RegisterField("Name",offsetof(Portakal::ProjectDescriptor,Name),typeof(Portakal::String),Portakal::FieldMode::Normal,pProjectDescriptor);
		Portakal::TypeDispatcher::RegisterField("ID",offsetof(Portakal::ProjectDescriptor,ID),typeof(Portakal::Guid),Portakal::FieldMode::Normal,pProjectDescriptor);
		Portakal::TypeDispatcher::RegisterField("VersionMajor",offsetof(Portakal::ProjectDescriptor,VersionMajor),typeof(Portakal::Uint32),Portakal::FieldMode::Normal,pProjectDescriptor);
		Portakal::TypeDispatcher::RegisterField("VersionMinor",offsetof(Portakal::ProjectDescriptor,VersionMinor),typeof(Portakal::Uint32),Portakal::FieldMode::Normal,pProjectDescriptor);
		Portakal::TypeDispatcher::RegisterField("VersionPatch",offsetof(Portakal::ProjectDescriptor,VersionPatch),typeof(Portakal::Uint32),Portakal::FieldMode::Normal,pProjectDescriptor);
		Portakal::TypeDispatcher::RegisterField("Name",offsetof(Portakal::GUIWindowDescriptor,Name),typeof(Portakal::String),Portakal::FieldMode::Normal,pGUIWindowDescriptor);
		Portakal::TypeDispatcher::RegisterField("ID",offsetof(Portakal::GUIWindowDescriptor,ID),typeof(Portakal::Guid),Portakal::FieldMode::Normal,pGUIWindowDescriptor);
		Portakal::TypeDispatcher::RegisterField("mSize",offsetof(Portakal::GUIWindowDescriptor,mSize),typeof(Portakal::Vector2US),Portakal::FieldMode::Normal,pGUIWindowDescriptor);
		Portakal::TypeDispatcher::RegisterField("mPosition",offsetof(Portakal::GUIWindowDescriptor,mPosition),typeof(Portakal::Vector2US),Portakal::FieldMode::Normal,pGUIWindowDescriptor);

        //Register attributes here
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::ResourceSerializerAttribute>(pTextureSerializer, "texture");

        //Register base types here
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::DomainModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ImGuiModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ImGuiRenderEndModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ImGuiRenderStartModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ProjectModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ResourceSerializerAttribute),typeof(Portakal::Attribute));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::TextureSerializer),typeof(Portakal::IResourceSerializer));

		//Create manifest here
		Portakal::Array<Portakal::Type*> types = {pDomainModule,pImGuiModule,pImGuiRenderEndModule,pImGuiRenderStartModule,pProjectDescriptor,pProjectModule,pIResourceSerializer,pResourceSerializerAttribute,pGUIWindowDescriptor,pTextureSerializer,};
		pManifest = new Portakal::ReflectionManifest("Runtime", types);

		return pManifest;
	}
}
