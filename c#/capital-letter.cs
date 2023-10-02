using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace program
{
    internal class capitalLet
    {
        public static string abbrevName(string name)
        {
            string[] words = name.Split(' ');
            return (words[0][0] + "." + words[1][0]).ToUpper();
        }
    }
}
