using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Reflection;

namespace Test
{
    class Program
    {
        static void Main(string[] args)
        {
            var assemBytes = File.ReadAllBytes("LibTemplate.dll");
            Assembly assem = Assembly.Load(assemBytes);
            var classes = assem.ExportedTypes;
            var instance = assem.CreateInstance("c02RevitHelloWorld.Class1", false);

        }
    }
}
