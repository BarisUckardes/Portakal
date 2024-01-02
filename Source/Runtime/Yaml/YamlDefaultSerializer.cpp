#include "YamlDefaultSerializer.h"
#include <Runtime/Reflection/Reflection.h>
#include <yaml-cpp/yaml.h>

namespace Portakal
{
	void LoadAsObject(const YAML::Node& node, void* pObject, const Type* pType);
	void GenerateObjectYAML(YAML::Emitter& emitter, const void* pObject, const Type* pType);

	void GeneratePrimitiveYAML(YAML::Emitter& emitter, const void* pObject, const Type* pType)
	{
		switch (pType->GetCode())
		{
			case TypeCodes::Composed:
			{
				break;
			}
			case TypeCodes::String:
			{
				String* pStr = (String*)pObject;
				if (pStr->GetSource() != nullptr)
					emitter << YAML::Value << **((String*)pObject);
				else
					emitter << YAML::Value << '\0';
				break;
			}
			case TypeCodes::Char:
			{
				char* pValue = (char*)pObject;
				emitter << YAML::Value << *pValue;
				break;
			}
			case TypeCodes::Byte:
			{
				unsigned char* pValue = (unsigned char*)pObject;
				emitter << YAML::Value << *pValue;
				break;
			}
			case TypeCodes::Int32:
			{
				int32* pValue = (int32*)pObject;
				emitter << YAML::Value << *pValue;
				break;
			}
			case TypeCodes::UInt32:
			{
				uint32* pValue = (uint32*)pObject;
				emitter << YAML::Value << *pValue;
				break;
			}
			case TypeCodes::Int16:
			{
				int16* pValue = (int16*)pObject;
				emitter << YAML::Value << *pValue;
				break;
			}
			case TypeCodes::UInt16:
			{
				uint16* pValue = (uint16*)pObject;
				emitter << YAML::Value << *pValue;
				break;
			}
			case TypeCodes::Float:
			{
				float* pValue = (float*)pObject;
				emitter << YAML::Value << *pValue;
				break;
			}
			case TypeCodes::Double:
			{
				double* pValue = (double*)pObject;
				emitter << YAML::Value << *pValue;
				break;
			}
			case TypeCodes::Int64:
			{
				int64* pValue = (int64*)pObject;
				emitter << YAML::Value << *pValue;
				break;
			}
			case TypeCodes::UInt64:
			{
				uint64* pValue = (uint64*)pObject;
				emitter << YAML::Value << *pValue;
				break;
			}
		}
	}
	void GenerateEnumYAML(YAML::Emitter& emitter, const void* pObject)
	{
		const uint64 value = *(uint64*)pObject;
		emitter << YAML::Value << value;
	}
	void GenerateArrayYAML(YAML::Emitter& emitter, const void* pObject, const Type* pType, const Type* pElementType)
	{
		const Array<String>* pArray = (const Array<String>*)pObject;
		const uint32 elementSizeInBytes = pElementType->GetSize();


		emitter << YAML::BeginSeq;
		for (uint32 elementIndex = 0; elementIndex < pArray->GetSize(); elementIndex++)
		{
			GenerateObjectYAML(emitter, (byte*)pArray->GetDataConst() + elementSizeInBytes * elementIndex, pElementType);
		}
	}
	void GenerateObjectYAML(YAML::Emitter& emitter, const void* pObject, const Type* pType)
	{
		//Check if type is nullptr	
		if (pType == nullptr)
			return;

		emitter << YAML::BeginMap;

		const Array<Field*> fields = pType->GetFields();
		for (const Field* pField : fields)
		{
			const Type* pFieldType = pField->GetType();
			void* pLocation = (byte*)pObject + pField->GetOffset();

			emitter << YAML::Key << *pField->GetName();

			if (pFieldType == nullptr) // array
			{
				GenerateArrayYAML(emitter, pLocation, pFieldType, pField->GetArrayElementType());
				continue;
			}

			if (pFieldType->GetCode() != TypeCodes::Composed)
			{
				GeneratePrimitiveYAML(emitter, pLocation, pFieldType);
			}
			else if (pFieldType->GetMode() == TypeModes::Enum)
			{
				GenerateEnumYAML(emitter, pLocation);
			}
			else
			{
				GenerateObjectYAML(emitter, pLocation, pFieldType);
			}
		}

		emitter << YAML::EndMap;
	}
	String YamlDefaultSerializer::ToYaml(const void* pObject, const Type* pType)
	{
		if (pObject == nullptr)
			return String();

		YAML::Emitter emitter;

		emitter << YAML::BeginDoc;

		GenerateObjectYAML(emitter, pObject, pType);

		emitter << YAML::EndDoc;

		return emitter.c_str();
	}

	void LoadAsPrimitive(const YAML::Node& node, void* pObject, const Type* pType)
	{
		switch (pType->GetCode())
		{
		case TypeCodes::Composed:
			break;
		case TypeCodes::String:
		default:
		{
			const std::string nodeStr = node.as<std::string>();
			const String value = nodeStr.c_str();
			*(String*)pObject = value;
			break;
		}
		case TypeCodes::Char:
		{
			const char nodeValue = node.as<char>();
			*(char*)pObject = nodeValue;
			break;
		}
		case TypeCodes::Byte:
		{
			const byte nodeValue = node.as<char>();
			*(byte*)pObject = nodeValue;
			break;
		}
		case TypeCodes::Int32:
		{
			const int32 nodeValue = node.as<int>();
			*(int32*)pObject = nodeValue;
			break;
		}
		case TypeCodes::UInt32:
		{
			const uint32 nodeValue = node.as<unsigned int>();
			*(uint32*)pObject = nodeValue;
			break;
		}
		case TypeCodes::Int16:
		{
			const int16 nodeValue = node.as<short>();
			*(int16*)pObject = nodeValue;
			break;
		}
		case TypeCodes::UInt16:
		{
			const uint16 nodeValue = node.as<unsigned short>();
			*(uint16*)pObject = nodeValue;
			break;
		}
		case TypeCodes::Float:
		{
			const float nodeValue = node.as<float>();
			*(float*)pObject = nodeValue;
			break;
		}
		case TypeCodes::Double:
		{
			const double nodeValue = node.as<double>();
			*(double*)pObject = nodeValue;
			break;
		}
		case TypeCodes::Int64:
		{
			const int64 nodeValue = node.as<long long>();
			*(int64*)pObject = nodeValue;
			break;
		}
		case TypeCodes::UInt64:
		{
			const uint64 nodeValue = node.as<unsigned long long>();
			*(uint64*)pObject = nodeValue;
			break;
		}
		}
	}
	void LoadAsEnum(const YAML::Node& node, void* pObject, const Type* pType)
	{
		const int64 value = node.as<long long>();
		*(int64*)pObject = value;
	}
	void LoadAsArray(const YAML::Node& node, void* pObject, const Type* pElementType)
	{
		const uint32 elementSizeInBytes = pElementType->GetSize();
		const uint32 elementCount = node.size();

		/*
		* Allocate array
		*/
		Array<char>* pArray = (Array<char>*)pObject;
		pArray->Clear();
		pArray->CreateIndirect(elementCount);


		/*
		* Iterate and fill
		*/
		void* pArrayStart = pArray->GetData();
		uint32 index = 0;
		for (YAML::const_iterator it = node.begin(); it != node.end(); it++)
		{
			const YAML::Node elementNode = *it;
			if (!elementNode.IsDefined())
			{
				index++;
				continue;
			}

			void* pLocation = (byte*)pArrayStart + elementSizeInBytes * index;
			LoadAsObject(elementNode, pLocation, pElementType);
			index++;
		}
	}
	void LoadAsObject(const YAML::Node& node, void* pObject, const Type* pType)
	{
		const Array<Field*> fields = pType->GetFields();

		for (const Field* pField : fields)
		{
			const Type* pFieldType = pField->GetType();
			const uint32 offsetInBytes = pField->GetOffset();
			void* pLocation = (byte*)pObject + offsetInBytes;

			/*
			* Validate if this map has a valid field name
			*/
			const YAML::Node fieldNode = node[*pField->GetName()];
			if (!fieldNode.IsDefined())
				continue;

			/*
			* Check if field is a array type
			*/
			if (pFieldType == nullptr)
			{
				LoadAsArray(fieldNode, pLocation, pField->GetArrayElementType());
				continue;
			}
			if (pFieldType->GetCode() != TypeCodes::Composed)
			{
				LoadAsPrimitive(fieldNode, pLocation, pFieldType);
			}
			else if (pFieldType->GetMode() == TypeModes::Enum)
			{
				LoadAsEnum(fieldNode, pLocation, pFieldType);
			}
			else
			{
				LoadAsObject(fieldNode, pLocation, pFieldType);
			}
		}
	}
	void YamlDefaultSerializer::ToObject(const String& yamlString, void* pObject, const Type* pType)
	{
		if (pObject == nullptr)
			return;

		/*
		* Load yaml node
		*/
		YAML::Node rootNode = YAML::Load(*yamlString);

		/*
		* Validate if it starts with map node
		*/
		if (!rootNode.IsMap())
		{
			DEV_LOG("YamlDefaultSerializer", "YAML does not start with a map node!");
			return;
		}

		LoadAsObject(rootNode, pObject, pType);
	}
}
