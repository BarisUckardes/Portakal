
#pragma once
#include <Runtime/Reflection/Reflection.h>
#include <Runtime/Reflection/ReflectionManifest.h>
#include <Runtime/Reflection/TypeDispatcher.h>
#include "Domain\DomainModule.h"
#include "Project\ProjectDescriptor.h"
#include "Project\ProjectModule.h"
#include "Resource\IResourceSerializer.h"
#include "Resource\ResourceSerializerAttribute.h"
#include "Resource\Texture\TextureSerializer.h"


		void* CreateBool8() {return new Portakal::bool8();}
		void* CreateChar() {return new char();}
		void* CreateByte() {return new Portakal::byte();}
		void* CreateUInt16() {return new Portakal::uint16();}
		void* CreateUInt32() {return new Portakal::uint32();}
		void* CreateUInt64() {return new Portakal::uint64();}
		void* CreateInt16() {return new Portakal::int16();}
		void* CreateInt32() {return new Portakal::int32();}
		void* CreateInt64() {return new Portakal::int64();}
		void* CreateFloat() {return new float();}
		void* CreateDouble() {return new double();}
		void* CreateString() {return new Portakal::String();}
		void* CreateDomainModule() {return new Portakal::DomainModule();}
		void* CreateProjectDescriptor() {return new Portakal::ProjectDescriptor();}
		void* CreateProjectModule() {return new Portakal::ProjectModule();}
		void* CreateIResourceSerializer() {return nullptr;}
		void* CreateResourceSerializerAttribute() {return new Portakal::ResourceSerializerAttribute();}
		void* CreateTextureSerializer() {return new Portakal::TextureSerializer();}

extern "C"
{
	__declspec(dllexport) Portakal::ReflectionManifest* GenerateModuleManifest()
	{
		Portakal::ReflectionManifest* pManifest = nullptr;

		//Create types here
		Portakal::Type* pbool8 = Portakal::TypeDispatcher::CreateType("bool8",sizeof(Portakal::bool8),Portakal::TypeModes::Class,Portakal::TypeCodes::Bool,CreateBool8,Portakal::TypeDispatcher::GetTypeAddress<Portakal::bool8>());
		Portakal::TypeDispatcher::SetTypeAddress<bool>(pbool8);
		Portakal::Type* pchar = Portakal::TypeDispatcher::CreateType("char",sizeof(char),Portakal::TypeModes::Class,Portakal::TypeCodes::Char,CreateChar,Portakal::TypeDispatcher::GetTypeAddress<char>());
		Portakal::TypeDispatcher::SetTypeAddress<char>(pchar);
		Portakal::Type* pbyte = Portakal::TypeDispatcher::CreateType("byte",sizeof(Portakal::byte),Portakal::TypeModes::Class,Portakal::TypeCodes::Byte,CreateByte,Portakal::TypeDispatcher::GetTypeAddress<Portakal::byte>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::byte>(pbyte);
		Portakal::Type* puint16 = Portakal::TypeDispatcher::CreateType("uint16",sizeof(Portakal::uint16),Portakal::TypeModes::Class,Portakal::TypeCodes::UInt16,CreateUInt16,Portakal::TypeDispatcher::GetTypeAddress<Portakal::uint16>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::uint16>(puint16);
		Portakal::Type* puint32 = Portakal::TypeDispatcher::CreateType("uint32",sizeof(Portakal::uint32),Portakal::TypeModes::Class,Portakal::TypeCodes::UInt32,CreateUInt32,Portakal::TypeDispatcher::GetTypeAddress<Portakal::uint32>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::uint32>(puint32);
		Portakal::Type* puint64 = Portakal::TypeDispatcher::CreateType("uint64",sizeof(Portakal::uint64),Portakal::TypeModes::Class,Portakal::TypeCodes::UInt64,CreateUInt64,Portakal::TypeDispatcher::GetTypeAddress<Portakal::uint64>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::uint64>(puint64);
		Portakal::Type* pint16 = Portakal::TypeDispatcher::CreateType("int16",sizeof(Portakal::int16),Portakal::TypeModes::Class,Portakal::TypeCodes::Int16,CreateInt16,Portakal::TypeDispatcher::GetTypeAddress<Portakal::int16>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::int16>(pint16);
		Portakal::Type* pint32 = Portakal::TypeDispatcher::CreateType("int32",sizeof(Portakal::int32),Portakal::TypeModes::Class,Portakal::TypeCodes::Int32,CreateInt32,Portakal::TypeDispatcher::GetTypeAddress<Portakal::int32>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::int32>(pint32);
		Portakal::Type* pint64 = Portakal::TypeDispatcher::CreateType("int64",sizeof(Portakal::int64),Portakal::TypeModes::Class,Portakal::TypeCodes::Int64,CreateInt64,Portakal::TypeDispatcher::GetTypeAddress<Portakal::int64>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::int64>(pint64);
		Portakal::Type* pfloat = Portakal::TypeDispatcher::CreateType("float",sizeof(float),Portakal::TypeModes::Class,Portakal::TypeCodes::Float,CreateFloat,Portakal::TypeDispatcher::GetTypeAddress<float>());
		Portakal::TypeDispatcher::SetTypeAddress<float>(pfloat);
		Portakal::Type* pdouble = Portakal::TypeDispatcher::CreateType("double",sizeof(double),Portakal::TypeModes::Class,Portakal::TypeCodes::Double,CreateDouble,Portakal::TypeDispatcher::GetTypeAddress<double>());
		Portakal::TypeDispatcher::SetTypeAddress<double>(pdouble);
		Portakal::Type* pString = Portakal::TypeDispatcher::CreateType("String",sizeof(Portakal::String),Portakal::TypeModes::Class,Portakal::TypeCodes::String,CreateString,Portakal::TypeDispatcher::GetTypeAddress<Portakal::String>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::String>(pString);
		Portakal::Type* pDomainModule = Portakal::TypeDispatcher::CreateType("DomainModule",sizeof(Portakal::DomainModule),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateDomainModule,Portakal::TypeDispatcher::GetTypeAddress<Portakal::DomainModule>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::DomainModule>(pDomainModule);
;		Portakal::Type* pProjectDescriptor = Portakal::TypeDispatcher::CreateType("ProjectDescriptor",sizeof(Portakal::ProjectDescriptor),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateProjectDescriptor,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ProjectDescriptor>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ProjectDescriptor>(pProjectDescriptor);
;		Portakal::Type* pProjectModule = Portakal::TypeDispatcher::CreateType("ProjectModule",sizeof(Portakal::ProjectModule),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateProjectModule,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ProjectModule>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ProjectModule>(pProjectModule);
;		Portakal::Type* pIResourceSerializer = Portakal::TypeDispatcher::CreateType("IResourceSerializer",sizeof(Portakal::IResourceSerializer),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateIResourceSerializer,Portakal::TypeDispatcher::GetTypeAddress<Portakal::IResourceSerializer>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::IResourceSerializer>(pIResourceSerializer);
;		Portakal::Type* pResourceSerializerAttribute = Portakal::TypeDispatcher::CreateType("ResourceSerializerAttribute",sizeof(Portakal::ResourceSerializerAttribute),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateResourceSerializerAttribute,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ResourceSerializerAttribute>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ResourceSerializerAttribute>(pResourceSerializerAttribute);
;		Portakal::Type* pTextureSerializer = Portakal::TypeDispatcher::CreateType("TextureSerializer",sizeof(Portakal::TextureSerializer),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateTextureSerializer,Portakal::TypeDispatcher::GetTypeAddress<Portakal::TextureSerializer>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::TextureSerializer>(pTextureSerializer);
;
        //Register enums here

        //Register fields here
		Portakal::TypeDispatcher::RegisterField("Name",offsetof(Portakal::ProjectDescriptor,Name),typeof(Portakal::String),Portakal::FieldMode::Normal,pProjectDescriptor);
		Portakal::TypeDispatcher::RegisterField("ID",offsetof(Portakal::ProjectDescriptor,ID),typeof(Portakal::Guid),Portakal::FieldMode::Normal,pProjectDescriptor);
		Portakal::TypeDispatcher::RegisterField("VersionMajor",offsetof(Portakal::ProjectDescriptor,VersionMajor),typeof(Portakal::uint32),Portakal::FieldMode::Normal,pProjectDescriptor);
		Portakal::TypeDispatcher::RegisterField("VersionMinor",offsetof(Portakal::ProjectDescriptor,VersionMinor),typeof(Portakal::uint32),Portakal::FieldMode::Normal,pProjectDescriptor);
		Portakal::TypeDispatcher::RegisterField("VersionPatch",offsetof(Portakal::ProjectDescriptor,VersionPatch),typeof(Portakal::uint32),Portakal::FieldMode::Normal,pProjectDescriptor);

        //Register attributes here
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::ResourceSerializerAttribute>(pTextureSerializer, "texture");

        //Register base types here
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::DomainModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ProjectModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ResourceSerializerAttribute),typeof(Portakal::Attribute));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::TextureSerializer),typeof(Portakal::IResourceSerializer));

		//Create manifest here
		Portakal::Array<Portakal::Type*> types = {pDomainModule,pProjectDescriptor,pProjectModule,pIResourceSerializer,pResourceSerializerAttribute,pTextureSerializer,};
		pManifest = new Portakal::ReflectionManifest("Runtime", types);

		return pManifest;
	}
}
