using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace program
{
    internal class removeExclamation
    {
        public static string remove(string enterString)
        {
            enterString = enterString.Replace("!", "");
            return $"{enterString/*.Trim('!')*/}!";
        }
    }
}
