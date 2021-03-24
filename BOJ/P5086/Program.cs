using System;
using System.Text;
using System.IO;

namespace P5086
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            StringBuilder sb = new StringBuilder();

            while(true)
            {
                string[] s = sr.ReadLine().Split(' ');
                int num1 = int.Parse(s[0]);
                int num2 = int.Parse(s[1]);
                if (num1 == 0 && num2 == 0)
                    break;

                if (num2 % num1 == 0 && num1 < num2)
                    sb.AppendLine("factor");
                else if (num1 % num2 == 0 && num1 > num2)
                    sb.AppendLine("multiple");
                else
                    sb.AppendLine("neither");
            }

            Console.WriteLine(sb);
        }
    }
}
