using System;


namespace P1037
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            if (n == 1)
            {
                int num = int.Parse(Console.ReadLine());
                Console.WriteLine(num*num);
            }
            else
            {
                string[] arr = Console.ReadLine().Split(' ');
                int max = int.Parse(arr[0]);
                int min = int.Parse(arr[0]);
                foreach(string s in arr)
                {
                    int m = int.Parse(s);
                    if (m > max)
                        max = m;
                    else if (m < min)
                        min = m;

                }
                Console.WriteLine(max*min);
            }      
        }
    }
}
