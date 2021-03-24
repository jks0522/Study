using System;
using System.IO;
using System.Text;
using System.Collections;

namespace P4949
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            StringBuilder sb = new StringBuilder();


            while (true)
            {
                Stack stack = new Stack();
                bool isBal = true;
                string s = sr.ReadLine();
                if (s == ".")
                    break;

                for (int i = 0; i < s.Length; i++)
                {
                    if (s[i] == '(')
                        stack.Push('(');
                    else if (s[i] == '[')
                        stack.Push('[');
                    else if (s[i] == ')')
                    {
                        if (stack.Count >= 1 && (char)stack.Peek() == '(')
                            stack.Pop();
                        else
                        {
                            isBal = false;
                            break;
                        }
                    }

                    else if (s[i] == ']')
                    {
                        if (stack.Count >= 1 && (char)stack.Peek() == '[')
                            stack.Pop();
                        else
                        {
                            isBal = false;
                            break;
                        }

                    }  
                }

                if (stack.Count != 0)
                    isBal = false;
                if (isBal)
                    sb.Append("yes\n");
                else
                    sb.Append("no\n");
            }

            Console.WriteLine(sb);
        }
    }
}
