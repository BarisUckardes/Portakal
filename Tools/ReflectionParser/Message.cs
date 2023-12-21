using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Portakal
{
    internal static class Message
    {
        internal static void Info(string message)
        {
            //Cache color
            ConsoleColor formerColor = Console.ForegroundColor;
            Console.ForegroundColor = ConsoleColor.White;
            Console.WriteLine(message);
            Console.ForegroundColor = formerColor;
        }
        internal static void Warning(string message)
        {
            //Cache color
            ConsoleColor formerColor = Console.ForegroundColor;
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine(message);
            Console.ForegroundColor = formerColor;
        }
        internal static void Error(string message)
        {
            //Cache color
            ConsoleColor formerColor = Console.ForegroundColor;
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine(message);
            Console.ForegroundColor = formerColor;
        }
    }
}
