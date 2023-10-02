using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace program
{
    internal class matchPointsCollection
    {
        public static int totalPoints(string[] games)
        {
            int totalPoints = 0;
            for (int i = 0; i < games.Length; i++)
            {
                for (int j = 0; j < games[i].Length;)
                {
                    int x = int.Parse(games[i][j].ToString());
                    int y = int.Parse(games[i][games[i].Length-1].ToString());
                    if (x>y)
                    {
                        totalPoints += 3;
                    } 
                    else if (x==y)
                    {
                        totalPoints += 1;
                    }
                    break;
                }
            }
            return totalPoints;
        }
    }
}
