
#pragma once
#include <Runtime/Reflection/Reflection.h>
#include <Runtime/Reflection/ReflectionManifest.h>
#include <Runtime/Reflection/TypeDispatcher.h>


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

extern "C"
{
	__declspec(dllexport) Portakal::ReflectionManifest* GenerateModuleManifest()
	{
		Portakal::ReflectionManifest* pManifest = nullptr;

		//Create types here
		Portakal::Type* pchar = Portakal::TypeDispatcher::CreateType("char",sizeof(char),Portakal::TypeModes::Class,Portakal::TypeCodes::Char,CreateChar,Portakal::TypeDispatcher::GetTypeAddress<char>());
		Portakal::Type* pbyte = Portakal::TypeDispatcher::CreateType("byte",sizeof(Portakal::byte),Portakal::TypeModes::Class,Portakal::TypeCodes::Byte,CreateByte,Portakal::TypeDispatcher::GetTypeAddress<Portakal::byte>());
		Portakal::Type* puint16 = Portakal::TypeDispatcher::CreateType("uint16",sizeof(Portakal::uint16),Portakal::TypeModes::Class,Portakal::TypeCodes::UInt16,CreateUInt16,Portakal::TypeDispatcher::GetTypeAddress<Portakal::uint16>());
		Portakal::Type* puint32 = Portakal::TypeDispatcher::CreateType("uint32",sizeof(Portakal::uint32),Portakal::TypeModes::Class,Portakal::TypeCodes::UInt32,CreateUInt32,Portakal::TypeDispatcher::GetTypeAddress<Portakal::uint32>());
		Portakal::Type* puint64 = Portakal::TypeDispatcher::CreateType("uint64",sizeof(Portakal::uint64),Portakal::TypeModes::Class,Portakal::TypeCodes::UInt64,CreateUInt64,Portakal::TypeDispatcher::GetTypeAddress<Portakal::uint64>());
		Portakal::Type* pint16 = Portakal::TypeDispatcher::CreateType("int16",sizeof(Portakal::int16),Portakal::TypeModes::Class,Portakal::TypeCodes::Int16,CreateInt16,Portakal::TypeDispatcher::GetTypeAddress<Portakal::int16>());
		Portakal::Type* pint32 = Portakal::TypeDispatcher::CreateType("int32",sizeof(Portakal::int32),Portakal::TypeModes::Class,Portakal::TypeCodes::Int32,CreateInt32,Portakal::TypeDispatcher::GetTypeAddress<Portakal::int32>());
		Portakal::Type* pint64 = Portakal::TypeDispatcher::CreateType("int64",sizeof(Portakal::int64),Portakal::TypeModes::Class,Portakal::TypeCodes::Int64,CreateInt64,Portakal::TypeDispatcher::GetTypeAddress<Portakal::int64>());
		Portakal::Type* pfloat = Portakal::TypeDispatcher::CreateType("float",sizeof(float),Portakal::TypeModes::Class,Portakal::TypeCodes::Float,CreateFloat,Portakal::TypeDispatcher::GetTypeAddress<float>());
		Portakal::Type* pdouble = Portakal::TypeDispatcher::CreateType("double",sizeof(double),Portakal::TypeModes::Class,Portakal::TypeCodes::Double,CreateDouble,Portakal::TypeDispatcher::GetTypeAddress<double>());

        //Register enums here

        //Register fields here

        //Register attributes here

        //Register base types here

		//Create manifest here
		Portakal::Array<Portakal::Type*> types = {};
		pManifest = new Portakal::ReflectionManifest("Runtime", types);

		return pManifest;
	}
}
