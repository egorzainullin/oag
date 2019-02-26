using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework1
{
    public static class Input
    { 
        public static int ReadInt()
        {
            var str = Console.ReadLine();
            return Int32.Parse(str);
        }

        public static int[] ReadInts()
        {
            var str = Console.ReadLine();
            var toParse = str.Split(' ');
            return toParse.Select(s => Int32.Parse(s)).ToArray();
        }
    }
}
