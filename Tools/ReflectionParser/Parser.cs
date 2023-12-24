using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Portakal
{
    internal static class Parser
    {
        internal static bool Parse(string targetFolderPath)
        {
            //First get all the files
            string[] files = Directory.GetFiles(targetFolderPath,"*.h",SearchOption.AllDirectories);
            if(files.Length == 0)
            {
                Message.Warning("No .h files found at the given folder path");
                return false;
            }

            //Load reflection file contents
            List<string> fileContents = new List<string>(100);
            List<string> fileNames = new List<string>(100);
            foreach (string file in files)
            {
                fileContents.Add(File.ReadAllText(file));
                fileNames.Add(Path.GetFileNameWithoutExtension(file));
            }

            //Collect reflection enabled file contents
            List<FileInfo> fileInfos = new List<FileInfo>(100);
            for(int i= 0;i<fileContents.Count;i++)
            {
                string fileContent = fileContents[i];
                string fileName = fileNames[i];

                //Leave Type out
                if (fileName == "Type" || fileName == "Core")
                    continue;
                if (fileName.Contains(".reflected"))
                    continue;

                FileType type = FileType.None;
                if (fileContent.Contains("PCLASS"))
                    type = FileType.Class;
                else if (fileContent.Contains("PENUM"))
                    type = FileType.Enum;
                else
                {
                    continue;
                }

                fileInfos.Add(new FileInfo(type, fileName, files[i],fileContent));
            }

            //Handle file data
            foreach(FileInfo file in fileInfos)
            {
                //Handle different types of objects
                switch (file.Type)
                {
                    case FileType.Class:
                        {
                            ClassHandler(file);
                            break;
                        }
                    case FileType.Enum:
                        {
                            EnumHandler(file);
                            break;
                        }
                    default:
                        break;
                }
            }

            //Write .reflected includes
            foreach (FileInfo file in fileInfos)
            {
                //Create/Write .reflected file
                if (!file.Content.Contains($".reflected"))
                {
                    int lastIncludeLineIndex = GetLastLine(file.Lines, "#include");
                    int targetLineIndex = lastIncludeLineIndex + 1;
                    string line = $"#include \"{file.Name}.reflected.h\"";
                    file.Lines.Insert(targetLineIndex, line);
                }

                //Write to header file
                File.WriteAllLines(file.Path, file.Lines);

                //Create reflected file content
                string filePath = @$"{Path.GetDirectoryName(file.Path)}\{file.Name}.reflected.h";
                string forwardLineContent = string.Empty;
                switch (file.Type)
                {
                    case FileType.Class:
                        {
                            forwardLineContent = $@"#undef PCLASS(){Environment.NewLine}#define PCLASS()\{Environment.NewLine} class {file.Name};\";
                            break;
                        }
                    case FileType.Enum:
                        {
                            forwardLineContent = @$"#undef PENUM(){Environment.NewLine}#define PENUM()\{Environment.NewLine} enum class {file.Name} : int64;\";
                            break;
                        }
                }
                string reflectedFileContent = $@"
{forwardLineContent}
	template<>\
	class TypeAccessor<{file.Name}>\
	{{\
		friend class TypeDispatcher;\
	public:\
		static Type* GetType()\
		{{\
			return sType;\
		}}\
	private:\
		static void SetType(Type* pType)\
		{{\
			sType = pType;\
		}}\
		static Type** GetTypeAddress()\
		{{\
			return &sType;\
		}}\
	private:\
		static inline Type* sType = nullptr;\
	}};";

                File.WriteAllText(filePath, reflectedFileContent);
            }

            //Try find a reflection manifest
            string reflectionManifestPath = $@"{targetFolderPath}\ReflectionManifest.h";
            if(File.Exists(reflectionManifestPath))
                File.Delete(reflectionManifestPath);

            //Create new reflection manifest path
            File.Create(reflectionManifestPath).Close();

            //Write all includes
            string includeLines = string.Empty;
            foreach(FileInfo file in fileInfos)
            {
                string lineContent = $"#include \"{file.Path.Replace(targetFolderPath+@"\", "")}\"";
                includeLines += $"{lineContent}{Environment.NewLine}";
            }

            //Write all types into array
            string typeArrayContent = string.Empty;
            foreach(FileInfo file in fileInfos)
            {
                //Array list line
                typeArrayContent += $"p{file.Name},";
            }

            //First write all the types
            string typeLines = string.Empty;
            foreach (FileInfo file in fileInfos)
            {
                string lineContent = $"\t\tPortakal::Type* p{file.Name} = Portakal::TypeDispatcher::CreateType(\"{file.Name}\",sizeof(Portakal::{file.Name}),Portakal::TypeModes::{file.Type},Portakal::TypeCodes::Composed,nullptr,Portakal::TypeDispatcher::GetTypeAddress<Portakal::{file.Name}>());{Environment.NewLine}\t\tPortakal::TypeDispatcher::SetTypeAddress<Portakal::{file.Name}>(p{file.Name});{Environment.NewLine};";
                typeLines += lineContent;
            }

            //Register enums
            string enumLines = string.Empty;
            foreach(FileInfo file in fileInfos)
            {
                foreach(KeyValuePair<string,long> value in file.EnumValues)
                {
                    string line = $"\t\tPortakal::TypeDispatcher::RegisterEnum(\"{value.Key}\",{value.Value},p{file.Name});{Environment.NewLine}";
                    enumLines += line;
                }
            }

            //Register fields
            string fieldLines = string.Empty;
            foreach(FileInfo file in fileInfos)
            {
                foreach(FieldInfo field in file.Fields)
                {
                    string line = $"\t\tPortakal::TypeDispatcher::RegisterField(\"{field.VariableName}\",offsetof(Portakal::{file.Name},{field.VariableName}),typeof(Portakal::{field.VariableType}),p{file.Name});{Environment.NewLine}";
                    fieldLines += line;
                }
            }
            //Register attributes
            string attributeLines = string.Empty;

            //Register basetypes
            string baseTypeLines = string.Empty;
            foreach(FileInfo file in fileInfos)
            {
                //Validate
                if (file.BaseClass == string.Empty)
                    continue;

                string line = $"\t\tPortakal::TypeDispatcher::SetBaseType(typeof(Portakal::{file.Name}),typeof(Portakal::{file.BaseClass}));{Environment.NewLine}";
                baseTypeLines += line;
            }

            //Create manifest file string
            string manifestFileContent = $@"
#pragma once
#include <Runtime/Reflection/Reflection.h>
#include <Runtime/Reflection/ReflectionManifest.h>
#include <Runtime/Reflection/TypeDispatcher.h>
{includeLines}
extern ""C""
{{
	__declspec(dllexport) Portakal::ReflectionManifest* GenerateModuleManifest()
	{{
		Portakal::ReflectionManifest* pManifest = nullptr;

		//Create types here
{typeLines}
        //Register enums here
{enumLines}
        //Register fields here
{fieldLines}
        //Register attributes here
{attributeLines}
        //Register base types here
{baseTypeLines}
		//Create manifest here
		Portakal::Array<Portakal::Type*> types = {{{typeArrayContent}}};
		pManifest = new Portakal::ReflectionManifest(""Runtime"", types);

		return pManifest;
	}}
}}
";
            //Write to reflection manifest file
            File.WriteAllText(reflectionManifestPath, manifestFileContent);
            return true;
        }

        internal static void EnumHandler(FileInfo file)
        {
            Message.Info($"File [{file.Name}] will be handled as enum!");

            //Get enum data type
            int enumClassLineIndex = GetLine(file.Lines, @"enum class");
            if(enumClassLineIndex == -1)
            {
                Message.Error($"No enum class found in this file!");
                return;
            }

            //Get enum values
            List<KeyValuePair<string, long>> values = new List<KeyValuePair<string, long>>();
            int enumStartIndex = GetLine(file.Lines, "{", enumClassLineIndex)+1;
            int enumEndIndex = GetLine(file.Lines, "};", enumStartIndex);
            long lastValue = 0;
            for(int i = enumStartIndex;i<enumEndIndex;i++)
            {
                //Get line
                string line = file.Lines[i];

                //Handle implicit enums
                if(!line.Contains("="))
                {
                    string implicitValueName = line.Trim().Replace(",", "");
                    long implicitValue = lastValue;
                    lastValue++;
                    values.Add(new KeyValuePair<string, long>(implicitValueName, implicitValue));
                    continue;
                }

                //Handle explicit enums
                int equalIndex = line.IndexOf("=");
                int endIndex = line.IndexOf(",");

                string explicitValueName = line.Substring(0, equalIndex).Trim().Trim('\t');
                long explicitValue = long.Parse(line.Substring(equalIndex+1, endIndex - equalIndex-1).Trim().Trim('\t'));
                lastValue = explicitValue+1;
                values.Add(new KeyValuePair<string, long>(explicitValueName, explicitValue));
            }

            //Register
            foreach(KeyValuePair<string, long> pair in values)
            {
                file.RegisterEnumValue(pair.Key, pair.Value);
                Message.Info($"Enum {pair.Key}->{pair.Value}");
            }
        }
        private static void ClassHandler(FileInfo file)
        {
            Message.Info($"File [{file.Name}] will be handled as Class");

            //Get class line
            int pclassLineIndex = GetLine(file.Lines, @"PCLASS();");
            if(pclassLineIndex == -1)
            {
                Message.Error($"No class found in this file {file.Name}");
                return;
            }
            int classLineIndex = pclassLineIndex + 1;
            string enumClassLine = file.Lines[classLineIndex];

            //Check if it has a base class
            bool bHasBase = enumClassLine.Contains(":");
            //Get base class if have one
            if(bHasBase)
            {
                int publicIndex = enumClassLine.LastIndexOf("public");
                if(publicIndex == -1)
                {
                    Message.Error("No public indentifier!");
                    return;
                }
                int baseClassStartIndex = publicIndex + "public".Length + 1;
                string baseClass = enumClassLine.Substring(baseClassStartIndex,enumClassLine.Length - baseClassStartIndex);
                file.BaseClass = baseClass;
            }

            //Get fields
            IReadOnlyCollection<uint> fieldIndexes = GetLineIndexes(file.Lines, "PFIELD()");
            foreach(uint lineIndex in fieldIndexes)
            {
                string lineContent = file.Lines[(int)(lineIndex + 1)].Trim().Trim('\t').Trim(';');
                string[] splits = lineContent.Split(" ");
                string valueType = splits[0];
                string name = splits[1];
                file.RegisterField(name, valueType);
            }

            //Get attributes

        }

        private static int GetLine(List<string> lines,string target)
        {
            for(int i = 0; i < lines.Count; i++)
            {
                string line = lines[i];
                if (line.Contains(target))
                    return i;
            }

            return -1;
        }
        private static int GetLine(List<string> lines, string target,int startOffset)
        {
            for (int i = startOffset; i < lines.Count; i++)
            {
                string line = lines[i];
                if (line.Contains(target))
                    return i;
            }

            return -1;
        }
        private static int GetLineStartWith(List<string> lines, string target)
        {
            for (int i = 0; i < lines.Count; i++)
            {
                string line = lines[i];
                if (line.StartsWith(target))
                    return i;
            }

            return -1;
        }
        private static IReadOnlyCollection<uint> GetLineIndexes(List<string> lines, string target)
        {
            List<uint> indexes = new List<uint>();  
            for (int i = 0; i < lines.Count; i++)
            {
                string line = lines[i];
                if (line.Contains(target))
                    indexes.Add((uint)i);
            }

            return indexes;
        }
        private static int GetLastLine(List<string> lines,string target)
        {
            int foundLastLine = -1;
            for(int i = 0;i < lines.Count;i++)
            {
                string line = lines[i];
                if (line.Contains(target))
                    foundLastLine = i;
            }

            return foundLastLine;
        }

    }
}
