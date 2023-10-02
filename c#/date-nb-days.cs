using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace program
{
    internal class dateNbDays
    {
        public static DateTime startDate = new DateTime(2016, 01, 01);
        public static DateTime endDate = new DateTime(2016, 01, 01);
        public static string dateNbDaysMethod(double startMoney, double earnedMoney, double interestRate)
        {
            double percent = percent(startMoney, interestRate);
            //percent *= earnedMoney - startMoney; 
            //if (isEquals(startMoney, earnedMoney))
            //{
            //    startMoney = earned(startMoney, earnedMoney, percent);
            //    result += startMoney;
            //    startMoney = result;
            //}
            startMoney = earned(startMoney, earnedMoney, percent, interestRate);
            startMoney = Math.Round(startMoney,2);
            Console.WriteLine(endDate);
            return $"{endDate.Year}-{endDate.Month}-{endDate.Day}";
        }

        public static double percent (double value, double percent)
        {
            double result = (value / 100) * percent;
            return result;
        }

        public static double earned(double startMoney, double earnedMoney, double percentValue, double interestRate)
        {
            int dataDays=0;
            double dailyPercentMoney = percentValue / 360;
            while (isEquals(startMoney, earnedMoney))
            {
                if (endDate.DayOfYear < 360)
                {
                    startMoney += dailyPercentMoney;
                    endDate = endDate.AddDays(1);
                }
                else
                {
                    endDate = endDate.AddYears(1);
                    DateTime buffDate = new DateTime(endDate.Year, 01, 01);
                    endDate = buffDate;
                    Console.WriteLine(endDate);
                    percentValue = percent(startMoney, interestRate);
                    dailyPercentMoney = percentValue / 360;
                    dataDays = 0;
                }
            }
            return startMoney;
        }

        public static bool isEquals(double startMoney, double earnedMoney)
        {
            return startMoney<earnedMoney ? true : false;
        }
    }
}
