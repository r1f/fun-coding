using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace program
{
    internal class rmChar
    {
        public static string RemoveChar(string line)
        {
            line= line.Remove(0, 1);
            line = line.Remove(line.Length - 1, 1);
            return line;
        }
    }
}
