using System;
using System.Text;

namespace program
{
    class study
    {
        static void main()
        {
            romanNumeralsToArabic();
        }

        static void romanNumeralsToArabic()
        {
            int[] arabicNum = { 1, 5, 10, 50, 100, 500, 1000 };
            string stringRomanNum = "IVXLCDM";

            Console.WriteLine("Enter the Roman numeral");
            string enter = Console.ReadLine();
            string enterValue = enter.ToUpper();

            int[] arrResult=new int[10];
            char[] charValue = enterValue.ToCharArray();

            char[] roman=stringRomanNum.ToCharArray();
            int iterator = 0;
            Console.WriteLine();

            for (int i = 0; i < charValue.Length; i++)
            {
                for (int j = 0; j < roman.Length; j++)
                {
                    bool result = string.Equals(charValue[i], roman[j]);
                    if (result)
                    {
                        arrResult[iterator] = arabicNum[j];
                        iterator++;
                    }
                }
            }
           
            int resultAll = 0;
            int results = 0;

            for (int i = 0; i < arrResult.Length; i++)
            {
                if ( i+1<arrResult.Length &&arrResult[i] < arrResult[i + 1] && arrResult[i] != 0 && arrResult[i + 1] != 0)
                {
                    resultAll -= arrResult[i];
                }
                else
                {
                    resultAll += arrResult[i];
                }
                results += resultAll;
                resultAll = 0;
            }
            Console.WriteLine($"Result: {results}");
        }

        static void indexArray()
        {
            Array myArray = Array.CreateInstance(typeof(int), new[] { 4 }, new[] { 1 });
            myArray.SetValue(2019, 1);
            myArray.SetValue(2020, 2);
            myArray.SetValue(2021, 3);
            myArray.SetValue(2022, 4);

            Console.WriteLine($"Starting index:{myArray.GetLowerBound(0)}");
            Console.WriteLine($"Starting index:{myArray.GetUpperBound(0)}");
        }

        static void jaggedArray()
        {
            int[][] jaggedArray = new int[4][];
            jaggedArray[0] = new int[1];
            jaggedArray[1] = new int[2];
            jaggedArray[2] = new int[3];
            jaggedArray[3] = new int[4];
                
            for (int i = 0; i < jaggedArray.Length; i++)
            {
                for (int j = 0; j < jaggedArray.Length; j++)
                {
                    string st = Console.ReadLine();
                    jaggedArray[i][j] = int.Parse(st);
                }
            }
        }

        static void twoDimensionalArray()
        {
            int[,] r1 = new int[2, 3] { { 1, 2, 3 }, { 4, 5, 6 } };

            for (int i = 0; i < r1.GetLength(0); i++)
            {
                for (int j = 0; j < r1.GetLength(1); j++)
                {
                    Console.Write($"{r1[i, j]} ");
                }
                Console.WriteLine();
            }
        }

        static void authenticationTry()
        {
            Console.WriteLine("Enter login\\password");
            string correct = "johnsilver\\qwerty";
            for (int i = 0; i < 3; i++)
            {
                string current = Console.ReadLine();
                if (current==correct)
                {
                    Console.WriteLine("Enter the System");
                    break;
                }
                if (i==2)
                {
                    Console.WriteLine("The number of available tries have been exceeded");
                    break;
                }
            }

            string correctLogin = "johnsilver";
            string correctPassword = "qwerty";

            int tries = 1;
            while (tries<=3)
            {
                Console.WriteLine("Login:");
                string currentLogin = Console.ReadLine();
                Console.WriteLine("Password");
                string currentPassword = Console.ReadLine();
                if (currentLogin==correctLogin && currentPassword==correctPassword)
                {
                    Console.WriteLine("Enter the System");
                    break;
                }
                tries++;
            }
            if (tries==4)
            {
                Console.WriteLine("The number of available tries have been exceeded");
            }

        }

        static void factorial()
        {
            Console.WriteLine("Enter the factorial: ");
            Console.Write("!");
            int factorial = int.Parse(Console.ReadLine());
            int[] arr = new int[factorial];
            int result = 1;
            for (int i = 0; i < factorial; i++)
            {
                arr[i] = i+1;
                if (arr[i] != 0)
                {
                    result *= arr[i];
                }
            }
            
            Console.WriteLine(result);
        }

        static void avarageOfTen()
        {
            Console.WriteLine("Enter the values");
            int[] arr = new int[10];

            for (int i = 0; i < arr.Length; i++)
            {
                arr[i] = int.Parse(Console.ReadLine());
                if (arr.Length > 10)
                {
                    break;
                }
                else if (arr[i] == 0)
                {
                    break;
                }
            }

            Console.WriteLine();
            double avarage = 0;
            int ZeroCount = 0;

            for (int i = 0; i < arr.Length; i++)
            {
                if (arr[i] != 0 && arr[i]>0 && arr[i]%3==0)
                {
                    avarage += arr[i];
                }
                else ZeroCount++;
            }

            Console.WriteLine(avarage / (arr.Length - ZeroCount));
        }

        static void fibonacciSequence()
        {
            Console.WriteLine("Enter the value you want to generate in Fibonacci Sequence");
            int N = int.Parse(Console.ReadLine());
            int[] arr = new int[N];
            arr[0] = 0;
            arr[1] = 1;

            for (int i = 2; i < N; i++)
            {
                arr[i]=arr[i-1]+arr[i-2];
            }

            foreach(int i in arr)
            {
                Console.Write($"{i} ");
            }
        }

        static void cycles()
        {
            int[] numbers = { 1, 2, -3, 4, 5, 6, -7, 8, -9, 10, -11, };
            for (int i = 0; i < numbers.Length; i++)
            {
                Console.Write(numbers[i] + " ");
            }
            Console.WriteLine();
            foreach(int val in numbers)
            {
                Console.Write(val + " ");
            }

            for (int i = 0; i < numbers.Length; i++)
            {
                for (int j = i + 1; j < numbers.Length; j++)
                {
                    int atI = numbers[i];
                    int atJ = numbers[j];
                    for (int k = j + 1; k < numbers.Length; k++)
                    {
                        int atK = numbers[k];
                        if (atI + atJ + atK == 0)
                        {
                            Console.WriteLine($"Pair({atI});({atJ}). Indexes({i};{j})");
                        }
                    }
                }
            }

            int age = 0;
            while (age<18)
            {
                Console.WriteLine("What is your age?");
                age = int.Parse(Console.ReadLine());
            }

        }

        static void controlFlow()
        {
            Console.WriteLine("weight, growth");
            double weight = double.Parse(Console.ReadLine());
            double growth = double.Parse(Console.ReadLine());
            double BodyMassIndex = weight / (Math.Pow(growth, 2));

            bool IsToLow = BodyMassIndex <= 18.5;
            bool InNormal = BodyMassIndex > 18.5 && BodyMassIndex < 25;
            bool IsAboveNormal = BodyMassIndex >= 25 && BodyMassIndex <= 30;
            bool IsTooFat = BodyMassIndex > 30;

            bool IsFat = IsAboveNormal || IsTooFat;

            if (IsFat)
            {
                Console.WriteLine("You had better lose some weight");
            }
            else
            {
                Console.WriteLine("Oh, You are in a good shape.");
            }
        }

        static void userProfile()
        {
            Console.WriteLine("Surname, name, age, weight, growth");
            string surname=Console.ReadLine();
            string name=Console.ReadLine();
            int age=int.Parse(Console.ReadLine());
            double weight = double.Parse(Console.ReadLine());
            int growth=int.Parse(Console.ReadLine());

            double BodyMassIndex=weight/(Math.Pow(growth,2));

            string profile =
                $"Your profile:\n" +
                $"Full Name: {surname}, {name}\n" +
                $"Age: {age}\n" +
                $"Weight: {weight}\n" +
                $"Height: {growth}\n" +
                $"Body Mass Index: {BodyMassIndex}";

            Console.WriteLine($"Your profile:\nFull Name: {surname}, {name}\nAge: {age}\nWeight: {weight}\nHeight: {growth}\nBody Mass Index: {BodyMassIndex}");
            Console.WriteLine(profile);
        }

        static void heronsFormula()
        {
            Console.WriteLine("Enter the length of 3 triangle sides");
            float a = float.Parse(Console.ReadLine());
            float b = float.Parse(Console.ReadLine());
            float c = float.Parse(Console.ReadLine());

            float p = (a + b + c) / 2;
            Console.WriteLine("heronsFormula: ");
            Console.WriteLine(Math.Sqrt(p*(p-a)*(p-b)*(p-c)));
        }
    }
}