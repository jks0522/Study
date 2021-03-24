using System;
using System.IO;

namespace P13305
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sw = new StreamReader(Console.OpenStandardInput());
            
            int n = int.Parse(sw.ReadLine());
            string[] s1 = sw.ReadLine().Split(' ');
            string[] s2 = sw.ReadLine().Split(' ');
            int[] length = new int[n-1];
            int[] city = new int[n];
            int min = 1000000000;
            long minCost = 0;

            for(int i =0; i < n; i++)
            {
                if(i <= n-2)
                    length[i] = int.Parse(s1[i]);
                city[i] = int.Parse(s2[i]);
            }

            for(int i = 0 ; i < n - 1; i++)
            {
                if(city[i] < min)
                {
                    minCost += (long)length[i] * city[i];
                    min = city[i];
                }
                else
                {
                    minCost += (long)length[i] * min;
                }
            }

            Console.WriteLine(minCost);
        }
    }
}
