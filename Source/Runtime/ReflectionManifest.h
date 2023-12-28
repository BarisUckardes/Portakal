
#pragma once
#include <Runtime/Reflection/Reflection.h>
#include <Runtime/Reflection/ReflectionManifest.h>
#include <Runtime/Reflection/TypeDispatcher.h>
#include "MyAttribute.h"
#include "TestClass.h"
#include "Application\ApplicationModule.h"
#include "Containers\String.h"
#include "Object\Object.h"
#include "Platform\PlatformType.h"
#include "Reflection\Attribute.h"
#include "Rendering\RenderGraph.h"
#include "Rendering\RenderOperation.h"
#include "Resource\ResourceSubObject.h"
#include "World\Component.h"
#include "World\SceneAspect.h"
#include "Resource\Mesh\MeshResource.h"
#include "Resource\Texture\TextureResource.h"


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
		void* CreateMyAttribute() {return new Portakal::MyAttribute();}
		void* CreateTestClass() {return new Portakal::TestClass();}
		void* CreateApplicationModule() {return nullptr;}
		void* CreateString() {return new Portakal::String();}
		void* CreateObject() {return nullptr;}
		void* CreatePlatformType() {return new Portakal::PlatformType();}
		void* CreateAttribute() {return new Portakal::Attribute();}
		void* CreateRenderGraph() {return new Portakal::RenderGraph();}
		void* CreateRenderOperation() {return nullptr;}
		void* CreateResourceSubObject() {return nullptr;}
		void* CreateComponent() {return nullptr;}
		void* CreateSceneAspect() {return nullptr;}
		void* CreateMeshResource() {return new Portakal::MeshResource();}
		void* CreateTextureResource() {return new Portakal::TextureResource();}

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
		Portakal::Type* pMyAttribute = Portakal::TypeDispatcher::CreateType("MyAttribute",sizeof(Portakal::MyAttribute),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateMyAttribute,Portakal::TypeDispatcher::GetTypeAddress<Portakal::MyAttribute>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::MyAttribute>(pMyAttribute);
;		Portakal::Type* pTestClass = Portakal::TypeDispatcher::CreateType("TestClass",sizeof(Portakal::TestClass),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateTestClass,Portakal::TypeDispatcher::GetTypeAddress<Portakal::TestClass>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::TestClass>(pTestClass);
;		Portakal::Type* pApplicationModule = Portakal::TypeDispatcher::CreateType("ApplicationModule",sizeof(Portakal::ApplicationModule),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateApplicationModule,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ApplicationModule>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ApplicationModule>(pApplicationModule);
;		Portakal::Type* pString = Portakal::TypeDispatcher::CreateType("String",sizeof(Portakal::String),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateString,Portakal::TypeDispatcher::GetTypeAddress<Portakal::String>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::String>(pString);
;		Portakal::Type* pObject = Portakal::TypeDispatcher::CreateType("Object",sizeof(Portakal::Object),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateObject,Portakal::TypeDispatcher::GetTypeAddress<Portakal::Object>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::Object>(pObject);
;		Portakal::Type* pPlatformType = Portakal::TypeDispatcher::CreateType("PlatformType",sizeof(Portakal::PlatformType),Portakal::TypeModes::Enum,Portakal::TypeCodes::Composed,CreatePlatformType,Portakal::TypeDispatcher::GetTypeAddress<Portakal::PlatformType>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::PlatformType>(pPlatformType);
;		Portakal::Type* pAttribute = Portakal::TypeDispatcher::CreateType("Attribute",sizeof(Portakal::Attribute),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateAttribute,Portakal::TypeDispatcher::GetTypeAddress<Portakal::Attribute>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::Attribute>(pAttribute);
;		Portakal::Type* pRenderGraph = Portakal::TypeDispatcher::CreateType("RenderGraph",sizeof(Portakal::RenderGraph),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateRenderGraph,Portakal::TypeDispatcher::GetTypeAddress<Portakal::RenderGraph>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::RenderGraph>(pRenderGraph);
;		Portakal::Type* pRenderOperation = Portakal::TypeDispatcher::CreateType("RenderOperation",sizeof(Portakal::RenderOperation),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateRenderOperation,Portakal::TypeDispatcher::GetTypeAddress<Portakal::RenderOperation>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::RenderOperation>(pRenderOperation);
;		Portakal::Type* pResourceSubObject = Portakal::TypeDispatcher::CreateType("ResourceSubObject",sizeof(Portakal::ResourceSubObject),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateResourceSubObject,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ResourceSubObject>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ResourceSubObject>(pResourceSubObject);
;		Portakal::Type* pComponent = Portakal::TypeDispatcher::CreateType("Component",sizeof(Portakal::Component),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateComponent,Portakal::TypeDispatcher::GetTypeAddress<Portakal::Component>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::Component>(pComponent);
;		Portakal::Type* pSceneAspect = Portakal::TypeDispatcher::CreateType("SceneAspect",sizeof(Portakal::SceneAspect),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateSceneAspect,Portakal::TypeDispatcher::GetTypeAddress<Portakal::SceneAspect>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::SceneAspect>(pSceneAspect);
;		Portakal::Type* pMeshResource = Portakal::TypeDispatcher::CreateType("MeshResource",sizeof(Portakal::MeshResource),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateMeshResource,Portakal::TypeDispatcher::GetTypeAddress<Portakal::MeshResource>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::MeshResource>(pMeshResource);
;		Portakal::Type* pTextureResource = Portakal::TypeDispatcher::CreateType("TextureResource",sizeof(Portakal::TextureResource),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateTextureResource,Portakal::TypeDispatcher::GetTypeAddress<Portakal::TextureResource>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::TextureResource>(pTextureResource);
;
        //Register enums here
		Portakal::TypeDispatcher::RegisterEnum("Windows",112,pPlatformType);
		Portakal::TypeDispatcher::RegisterEnum("Linux",113,pPlatformType);
		Portakal::TypeDispatcher::RegisterEnum("Mac",155,pPlatformType);
		Portakal::TypeDispatcher::RegisterEnum("PS5",156,pPlatformType);
		Portakal::TypeDispatcher::RegisterEnum("Switch",157,pPlatformType);

        //Register fields here
		Portakal::TypeDispatcher::RegisterField("mMyType",offsetof(Portakal::TestClass,mMyType),typeof(Portakal::uint32),Portakal::FieldMode::Normal,pTestClass);
		Portakal::TypeDispatcher::RegisterField("mMahString",offsetof(Portakal::TestClass,mMahString),typeof(Portakal::String),Portakal::FieldMode::Normal,pTestClass);
		Portakal::TypeDispatcher::RegisterField("mMahObjectString",offsetof(Portakal::TestClass,mMahObjectString),typeof(Portakal::String),Portakal::FieldMode::Object,pTestClass);
		Portakal::TypeDispatcher::RegisterField("mMahArray",offsetof(Portakal::TestClass,mMahArray),typeof(Portakal::String),Portakal::FieldMode::Array,pTestClass);

        //Register attributes here
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::MyAttribute>(pTestClass);

        //Register base types here
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::MyAttribute),typeof(Portakal::Attribute));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::TestClass),typeof(Portakal::Object));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::RenderGraph),typeof(Portakal::Object));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::MeshResource),typeof(Portakal::ResourceSubObject));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::TextureResource),typeof(Portakal::ResourceSubObject));

		//Create manifest here
		Portakal::Array<Portakal::Type*> types = {pMyAttribute,pTestClass,pApplicationModule,pString,pObject,pPlatformType,pAttribute,pRenderGraph,pRenderOperation,pResourceSubObject,pComponent,pSceneAspect,pMeshResource,pTextureResource,};
		pManifest = new Portakal::ReflectionManifest("Runtime", types);

		return pManifest;
	}
}
