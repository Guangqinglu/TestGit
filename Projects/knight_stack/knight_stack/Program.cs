using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace knight_stack
{
    class Program
    {
        static void Main(string[] args)
        {
            string inffix_str = "1+2*((3+4)-5)";
            char[] inffix_exp = inffix_str.ToCharArray();
            char[] suffix_exp = new char[inffix_str.Length];
            Stack<char> exp_stack = new Stack<char>(100);
            int i, j=0;
            for (i = 0; i < inffix_str.Length; i++)
            {
                switch (inffix_exp[i].ToString())
                {
                    case "*":
                    case "/":
                        while(exp_stack.Count != 0)
                        {
                            if (exp_stack.Peek() == '+' || exp_stack.Peek() == '-')
                            {
                                exp_stack.Push(inffix_exp[i]);
                                break;
                            }
                            else if (exp_stack.Peek() == '*' || exp_stack.Peek() == '/')
                            {
                                suffix_exp[j++] = exp_stack.Pop();
                            }
                            else
                            {
                                exp_stack.Push(inffix_exp[i]);
                            }
                        }
                        if(exp_stack.Count==0)
                            exp_stack.Push(inffix_exp[i]);
                        break;
                    case "+":
                    case "-":
                        while (exp_stack.Count != 0 && exp_stack.Peek()!='(')
                        {
                            suffix_exp[j++] = exp_stack.Pop();
                        }
                        exp_stack.Push(inffix_exp[i]);
                        break;
                    case "(":
                        exp_stack.Push(inffix_exp[i]);
                        break;
                    case ")":
                        while(exp_stack.Count!=0 && exp_stack.Peek()!='(')
                        {
                            suffix_exp[j++]=exp_stack.Pop();
                        }
                        if(exp_stack.Peek()=='(')
                            exp_stack.Pop();
                        break;
                    default:
                        suffix_exp[j++] = inffix_exp[i];
                        break;
                }          
            }
            while (j < inffix_str.Length && exp_stack.Count != 0)
            {
                suffix_exp[j++] = exp_stack.Pop();
            }
            //Console.Write(suffix_exp);
            foreach (char temp in suffix_exp)
            {
                Console.Write(temp);
            }
            Console.ReadKey();
        }
    }
}
