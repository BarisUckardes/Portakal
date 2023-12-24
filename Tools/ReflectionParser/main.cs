using System;

namespace Portakal
{
    internal static class Program
    {
        internal static void Main(string[] args)
        {
            Message.Info("Parsing starts...");

            //Handle argument
            if(args.Length == 0)
            {
                Message.Error("No arguments are given for the parser!");
                return;
            }

            string folderPath = args[0];
            if (!Directory.Exists(folderPath))
            {
                Message.Error($"Given folder path is invalid! {folderPath}");
                return;
            }

            Message.Info($"Parsing {folderPath}...");
            //Invoke the parser
            if(!Parser.Parse(folderPath))
                Message.Error("Parser failed!");

            Message.Info("Parsing finished!");
        }
    }
}