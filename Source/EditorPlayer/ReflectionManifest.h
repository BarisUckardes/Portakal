
#pragma once
#include <Runtime/Reflection/Reflection.h>
#include <Runtime/Reflection/ReflectionManifest.h>
#include <Runtime/Reflection/TypeDispatcher.h>
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\MyAttribute.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\TestClass.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Application\ApplicationModule.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Containers\Guid.h"
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
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Resource\Texture\TextureDeserializer.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Runtime\Resource\Texture\TextureResource.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\Domain\DomainModule.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\ImGui\ImGuiModule.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\Project\ProjectDescriptor.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\Project\ProjectModule.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\Resource\IResourceSerializer.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\Resource\ResourceSerializerAttribute.h"
#include "C:/Users/Roveldo/Documents/GitHub/Portakal/Source/Editor\Resource\Texture\TextureSerializer.h"
#include "EditorPlayerGDeviceModule.h"
#include "EditorPlayerProjectModule.h"
#include "EditorPlayerWindowModule.h"


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
		void* CreateMyAttribute() {return new Portakal::MyAttribute();}
		void* CreateTestClass() {return new Portakal::TestClass();}
		void* CreateApplicationModule() {return nullptr;}
		void* CreateGuid() {return new Portakal::Guid();}
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
		void* CreateTextureDeserializer() {return new Portakal::TextureDeserializer();}
		void* CreateTextureResource() {return new Portakal::TextureResource();}
		void* CreateDomainModule() {return new Portakal::DomainModule();}
		void* CreateImGuiModule() {return new Portakal::ImGuiModule();}
		void* CreateProjectDescriptor() {return new Portakal::ProjectDescriptor();}
		void* CreateProjectModule() {return new Portakal::ProjectModule();}
		void* CreateIResourceSerializer() {return nullptr;}
		void* CreateResourceSerializerAttribute() {return new Portakal::ResourceSerializerAttribute();}
		void* CreateTextureSerializer() {return new Portakal::TextureSerializer();}
		void* CreateEditorPlayerGDeviceModule() {return new Portakal::EditorPlayerGDeviceModule();}
		void* CreateEditorPlayerProjectModule() {return new Portakal::EditorPlayerProjectModule();}
		void* CreateEditorPlayerWindowModule() {return new Portakal::EditorPlayerWindowModule();}

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
		Portakal::Type* pMyAttribute = Portakal::TypeDispatcher::CreateType("MyAttribute",sizeof(Portakal::MyAttribute),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateMyAttribute,Portakal::TypeDispatcher::GetTypeAddress<Portakal::MyAttribute>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::MyAttribute>(pMyAttribute);
;		Portakal::Type* pTestClass = Portakal::TypeDispatcher::CreateType("TestClass",sizeof(Portakal::TestClass),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateTestClass,Portakal::TypeDispatcher::GetTypeAddress<Portakal::TestClass>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::TestClass>(pTestClass);
;		Portakal::Type* pApplicationModule = Portakal::TypeDispatcher::CreateType("ApplicationModule",sizeof(Portakal::ApplicationModule),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateApplicationModule,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ApplicationModule>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ApplicationModule>(pApplicationModule);
;		Portakal::Type* pGuid = Portakal::TypeDispatcher::CreateType("Guid",sizeof(Portakal::Guid),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateGuid,Portakal::TypeDispatcher::GetTypeAddress<Portakal::Guid>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::Guid>(pGuid);
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
;		Portakal::Type* pTextureDeserializer = Portakal::TypeDispatcher::CreateType("TextureDeserializer",sizeof(Portakal::TextureDeserializer),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateTextureDeserializer,Portakal::TypeDispatcher::GetTypeAddress<Portakal::TextureDeserializer>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::TextureDeserializer>(pTextureDeserializer);
;		Portakal::Type* pTextureResource = Portakal::TypeDispatcher::CreateType("TextureResource",sizeof(Portakal::TextureResource),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateTextureResource,Portakal::TypeDispatcher::GetTypeAddress<Portakal::TextureResource>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::TextureResource>(pTextureResource);
;		Portakal::Type* pDomainModule = Portakal::TypeDispatcher::CreateType("DomainModule",sizeof(Portakal::DomainModule),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateDomainModule,Portakal::TypeDispatcher::GetTypeAddress<Portakal::DomainModule>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::DomainModule>(pDomainModule);
;		Portakal::Type* pImGuiModule = Portakal::TypeDispatcher::CreateType("ImGuiModule",sizeof(Portakal::ImGuiModule),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,CreateImGuiModule,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ImGuiModule>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ImGuiModule>(pImGuiModule);
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

        //Register fields here
		Portakal::TypeDispatcher::RegisterField("mMyType",offsetof(Portakal::TestClass,mMyType),typeof(Portakal::uint32),Portakal::FieldMode::Normal,pTestClass);
		Portakal::TypeDispatcher::RegisterField("mMahString",offsetof(Portakal::TestClass,mMahString),typeof(Portakal::String),Portakal::FieldMode::Normal,pTestClass);
		Portakal::TypeDispatcher::RegisterField("mMahObjectString",offsetof(Portakal::TestClass,mMahObjectString),typeof(Portakal::String),Portakal::FieldMode::Object,pTestClass);
		Portakal::TypeDispatcher::RegisterField("mMahArray",offsetof(Portakal::TestClass,mMahArray),typeof(Portakal::String),Portakal::FieldMode::Array,pTestClass);
		Portakal::TypeDispatcher::RegisterField("A",offsetof(Portakal::Guid,A),typeof(Portakal::uint32),Portakal::FieldMode::Normal,pGuid);
		Portakal::TypeDispatcher::RegisterField("B",offsetof(Portakal::Guid,B),typeof(Portakal::uint32),Portakal::FieldMode::Normal,pGuid);
		Portakal::TypeDispatcher::RegisterField("C",offsetof(Portakal::Guid,C),typeof(Portakal::uint32),Portakal::FieldMode::Normal,pGuid);
		Portakal::TypeDispatcher::RegisterField("D",offsetof(Portakal::Guid,D),typeof(Portakal::uint32),Portakal::FieldMode::Normal,pGuid);
		Portakal::TypeDispatcher::RegisterField("Path",offsetof(Portakal::ResourceDescriptor,Path),typeof(Portakal::String),Portakal::FieldMode::Normal,pResourceDescriptor);
		Portakal::TypeDispatcher::RegisterField("ResourceType",offsetof(Portakal::ResourceDescriptor,ResourceType),typeof(Portakal::String),Portakal::FieldMode::Normal,pResourceDescriptor);
		Portakal::TypeDispatcher::RegisterField("Name",offsetof(Portakal::ResourceDescriptor,Name),typeof(Portakal::String),Portakal::FieldMode::Normal,pResourceDescriptor);
		Portakal::TypeDispatcher::RegisterField("ID",offsetof(Portakal::ResourceDescriptor,ID),typeof(Portakal::Guid),Portakal::FieldMode::Normal,pResourceDescriptor);
		Portakal::TypeDispatcher::RegisterField("FileOffset",offsetof(Portakal::ResourceDescriptor,FileOffset),typeof(Portakal::uint64),Portakal::FieldMode::Normal,pResourceDescriptor);
		Portakal::TypeDispatcher::RegisterField("FileSize",offsetof(Portakal::ResourceDescriptor,FileSize),typeof(Portakal::uint64),Portakal::FieldMode::Normal,pResourceDescriptor);
		Portakal::TypeDispatcher::RegisterField("bOptimized",offsetof(Portakal::ResourceDescriptor,bOptimized),typeof(Portakal::bool8),Portakal::FieldMode::Normal,pResourceDescriptor);
		Portakal::TypeDispatcher::RegisterField("Name",offsetof(Portakal::ProjectDescriptor,Name),typeof(Portakal::String),Portakal::FieldMode::Normal,pProjectDescriptor);
		Portakal::TypeDispatcher::RegisterField("ID",offsetof(Portakal::ProjectDescriptor,ID),typeof(Portakal::Guid),Portakal::FieldMode::Normal,pProjectDescriptor);
		Portakal::TypeDispatcher::RegisterField("VersionMajor",offsetof(Portakal::ProjectDescriptor,VersionMajor),typeof(Portakal::uint32),Portakal::FieldMode::Normal,pProjectDescriptor);
		Portakal::TypeDispatcher::RegisterField("VersionMinor",offsetof(Portakal::ProjectDescriptor,VersionMinor),typeof(Portakal::uint32),Portakal::FieldMode::Normal,pProjectDescriptor);
		Portakal::TypeDispatcher::RegisterField("VersionPatch",offsetof(Portakal::ProjectDescriptor,VersionPatch),typeof(Portakal::uint32),Portakal::FieldMode::Normal,pProjectDescriptor);

        //Register attributes here
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::MyAttribute>(pTestClass);
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::ResourceAttribute>(pTextureResource, "texture");
		Portakal::TypeDispatcher::RegisterAttribute<Portakal::ResourceSerializerAttribute>(pTextureSerializer, "texture");

        //Register base types here
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::MyAttribute),typeof(Portakal::Attribute));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::TestClass),typeof(Portakal::Object));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ReflectionModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::RenderGraph),typeof(Portakal::Object));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ResourceDeserializerAttribute),typeof(Portakal::Attribute));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::WindowModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::MeshResource),typeof(Portakal::ResourceSubObject));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::TextureDeserializer),typeof(Portakal::IResourceDeserializer));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::TextureResource),typeof(Portakal::ResourceSubObject));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::DomainModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ImGuiModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ProjectModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::ResourceSerializerAttribute),typeof(Portakal::Attribute));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::TextureSerializer),typeof(Portakal::IResourceSerializer));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::EditorPlayerGDeviceModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::EditorPlayerProjectModule),typeof(Portakal::ApplicationModule));
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::EditorPlayerWindowModule),typeof(Portakal::ApplicationModule));

		//Create manifest here
		Portakal::Array<Portakal::Type*> types = {pMyAttribute,pTestClass,pApplicationModule,pGuid,pObject,pPlatformType,pAttribute,pReflectionModule,pRenderGraph,pRenderOperation,pIResourceDeserializer,pResourceDescriptor,pResourceDeserializerAttribute,pResourceSubObject,pWindowModule,pComponent,pSceneAspect,pMeshResource,pTextureDeserializer,pTextureResource,pDomainModule,pImGuiModule,pProjectDescriptor,pProjectModule,pIResourceSerializer,pResourceSerializerAttribute,pTextureSerializer,pEditorPlayerGDeviceModule,pEditorPlayerProjectModule,pEditorPlayerWindowModule,};
		pManifest = new Portakal::ReflectionManifest("Runtime", types);

		return pManifest;
	}
}
