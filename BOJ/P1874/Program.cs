using System;
using System.IO;
using System.Collections;
using System.Text;

namespace P1874
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            StringBuilder sb = new StringBuilder();
            Stack stack = new Stack();

            bool isPossible = true;
            int max = 0;
            int n = int.Parse(sr.ReadLine());

            for(int i = 1; i<= n; i++)
            {
                int num = int.Parse(sr.ReadLine());

                if(i == 1)
                {
                    for (int j = 1; j <= num; j++)
                    {
                        stack.Push(j);
                        sb.Append("+\n");
                    }
                    stack.Pop();
                    sb.Append("-\n");
                    max = num;
                }
                else if(num > max)
                {
                    for(int j = max + 1; j <= num; j++)
                    {
                        stack.Push(j);
                        sb.Append("+\n");
                    }
                    stack.Pop();
                    sb.Append("-\n");
                    max = num;
                }
                else
                {
                    if ((int)stack.Pop() != num)
                    {
                        isPossible = false;
                        break;
                    }
                    else
                    {
                        sb.Append("-\n");
                    }

                }
            }

            if (isPossible == true)
                Console.WriteLine(sb);
            else
                Console.WriteLine("NO");
        }
    }
}
