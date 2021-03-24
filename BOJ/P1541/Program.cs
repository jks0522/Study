using System;
using System.Collections;

namespace P1541
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split('-');
            int sum = 0;


            for(int i = 0; i < s.Length; i++)
            {
                if(s[i].Contains("+"))
                {
                    string[] arr = s[i].Split('+');
                    foreach(string sPlus in arr)
                    {
                        if (i == 0)
                            sum += int.Parse(sPlus);
                        else
                            sum -= int.Parse(sPlus);
                    }
                }
                else if ( i ==0)
                {
                    sum += int.Parse(s[i]);
                }
                else
                {
                    sum -= int.Parse(s[i]);
                }
            }

            Console.WriteLine(sum);
        }
    }
}
