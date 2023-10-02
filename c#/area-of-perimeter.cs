using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace program
{
    internal class areaOfPerimeter
    {
        public static int area(int length, int width)
        {
            int area = 0;
            if (length==width)
            {
                area = length * width;
            }
            else
            {
                area = (length*2)+(width*2);
            }
            return area;
        }
    }
}
