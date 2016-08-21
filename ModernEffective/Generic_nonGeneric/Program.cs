using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Generic_nonGeneric
{
    class test
    {
        public void testC()
        {
            System.Collections.Stack s = new Stack();
            int a = 1;
            s.Push(a);
            double b = 2.0;
            s.Push(b);

            object o = s.Pop();
            object o2 = s.Pop();
            System.Collections.Generic.Queue<int> gq = new Queue<int>();
            System.Collections.Generic.Stack<int> gs = new Stack<int>();

        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            test t = new test();
            t.testC();
        }
    }
}
