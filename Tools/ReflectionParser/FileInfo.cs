using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Portakal
{
    public sealed class FileInfo
    {
        public FileInfo(FileType type, string name,string path, string content)
        {
            Type = type;
            Name = name;
            Path = path;
            Content = content;
            Lines = new List<string>(content.Replace("\r", "").Split('\n'));
            _enumValues = new List<KeyValuePair<string, long>>();
            _fields = new List<FieldInfo>();
            BaseClass = string.Empty;
        }

        public FileType Type { get; private init; }
        public string Name { get; private init; }
        public string Path { get; private init; }
        public string Content { get; private init; }
        public List<string> Lines { get; private init; }
        public string BaseClass { get;set; }
        public IReadOnlyCollection<KeyValuePair<string, long>> EnumValues => _enumValues;
        public IReadOnlyCollection<FieldInfo> Fields => _fields;
        public void RegisterEnumValue(string name,long value)
        {
            _enumValues.Add(new KeyValuePair<string, long>(name, value));
        }
        public void RegisterField(string variableName,string variableType)
        {
            _fields.Add(new FieldInfo()
            {
                VariableName = variableName,
                VariableType = variableType,
            });
        }

        private List<KeyValuePair<string, long>> _enumValues;
        private List<FieldInfo> _fields;
    }
}
