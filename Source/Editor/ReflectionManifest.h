
#pragma once
#include <Runtime/Reflection/Reflection.h>
#include <Runtime/Reflection/ReflectionManifest.h>
#include <Runtime/Reflection/TypeDispatcher.h>
#include "Domain\DomainModule.h"
#include "Project\ProjectDescriptor.h"


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
		void* CreateDomainModule() {return new Portakal::DomainModule();}
		void* CreateProjectDescriptor() {return new Portakal::ProjectDescriptor();}

extern "C"
{
	__declspec(dllexport) Portakal::ReflectionManifest* GenerateModuleManifest()
	{
		Portakal::ReflectionManifest* pManifest = nullptr;

		//Create types here
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
		Portakal::Type* pDomainModule = Portakal::TypeDispatcher::CreateType("DomainModule",sizeof(Portakal::DomainModule),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateDomainModule,Portakal::TypeDispatcher::GetTypeAddress<Portakal::DomainModule>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::DomainModule>(pDomainModule);
;		Portakal::Type* pProjectDescriptor = Portakal::TypeDispatcher::CreateType("ProjectDescriptor",sizeof(Portakal::ProjectDescriptor),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateProjectDescriptor,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ProjectDescriptor>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ProjectDescriptor>(pProjectDescriptor);
;
        //Register enums here

        //Register fields here
		Portakal::TypeDispatcher::RegisterField("Name",offsetof(Portakal::ProjectDescriptor,Name),typeof(Portakal::String),Portakal::FieldMode::Normal,pProjectDescriptor);
		Portakal::TypeDispatcher::RegisterField("ID",offsetof(Portakal::ProjectDescriptor,ID),typeof(Portakal::Guid),Portakal::FieldMode::Normal,pProjectDescriptor);
		Portakal::TypeDispatcher::RegisterField("VersionMajor",offsetof(Portakal::ProjectDescriptor,VersionMajor),typeof(Portakal::uint32),Portakal::FieldMode::Normal,pProjectDescriptor);
		Portakal::TypeDispatcher::RegisterField("VersionMinor",offsetof(Portakal::ProjectDescriptor,VersionMinor),typeof(Portakal::uint32),Portakal::FieldMode::Normal,pProjectDescriptor);
		Portakal::TypeDispatcher::RegisterField("VersionPatch",offsetof(Portakal::ProjectDescriptor,VersionPatch),typeof(Portakal::uint32),Portakal::FieldMode::Normal,pProjectDescriptor);

        //Register attributes here

        //Register base types here
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::DomainModule),typeof(Portakal::ApplicationModule));

		//Create manifest here
		Portakal::Array<Portakal::Type*> types = {pDomainModule,pProjectDescriptor,};
		pManifest = new Portakal::ReflectionManifest("Runtime", types);

		return pManifest;
	}
}
