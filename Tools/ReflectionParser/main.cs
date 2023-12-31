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

            //Check for main reflection manifest path
            string folderPath = args[0];
            if (!Directory.Exists(folderPath))
            {
                Message.Error($"Given folder path is invalid! {folderPath}");
                return;
            }

            //Check for parameters
            List<string> parameters = new List<string>();
            for (int i = 1; i < args.Length;i++)
            {
                string parameter = args[i];
                if(Directory.Exists(parameter))
                    parameters.Add(parameter);
            }

            Message.Info($"Parsing {folderPath}...");
            //Invoke the parser
            if(!Parser.Parse(folderPath,parameters.AsReadOnly()))
                Message.Error("Parser failed!");

            Message.Info("Parsing finished!");
        }
    }
}