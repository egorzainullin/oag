using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework1
{
    public class Program
    {
        public static void ExA()
        {
            A.ReadN();
            A.ReadMatrix();
            var arr = A.Transform();
            foreach (var (i, j) in arr)
            {
                Console.WriteLine($"{i} {j}");
            }
        }

        public static void ExB()
        {
            B.ReadMN();
            B.ReadEdges();
            var list = B.DFS();
            foreach (var i in list)
            {
                Console.WriteLine(i + " ");
            }
            Console.WriteLine("____");
            Console.WriteLine(B.IsConnected());
        }

        public static void Main(string[] args)
        {
            ExB();
        }
    }
}
