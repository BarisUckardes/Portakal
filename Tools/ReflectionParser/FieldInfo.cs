using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Portakal
{
    public enum FieldMode
    {
        Normal,
        Object,
        Array
    }
    public struct FieldInfo
    {
        public string VariableType;
        public string VariableName;
        public string ElementType;
        public FieldMode Mode;
    }
}
