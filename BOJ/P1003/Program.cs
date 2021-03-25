using System;

namespace P1003
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());

            for(int i = 0; i< t; i++)
            {
                int n = int.Parse(Console.ReadLine());

                fibonacci(n);
            }
        }

        static void fibonacci(int n)
        {
            int[] zero = new int[41];
            int[] one = new int[41];

            zero[0] = 1;
            one[0] = 0;
            zero[1] = 0;
            one[1] = 1;
            for (int i = 2; i <= n; i++)
            {
                zero[i] = zero[i - 1] + zero[i - 2];
                one[i] = one[i - 1] + one[i - 2];
            }

            Console.WriteLine(zero[n] + " " + one[n]);
        }
    }
}
