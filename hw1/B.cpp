
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework1
{
    public class Program
    {
        public static int N;

        public static int[,] Matrix;

        public static void ReadN()
        {
            var str = Console.ReadLine();
            N = Int32.Parse(str);
        }

        public static void ReadMatrix()
        {
            Matrix = new int[N, N];
            for (int i = 0; i < N; i++)
            {
                var str = Console.ReadLine();
                var toParse = str.Split(' ');
                var ints = toParse.Select(s => Int32.Parse(s)).ToArray();
                for (int j = 0; j < N; j++)
                {
                    Matrix[i, j] = ints[j];
                }
            }
        }

        public static List<Tuple<int, int>> Transform()
        {
            var list = new List<Tuple<int, int>>();
            for (int i = 0; i < N; i++)
            {
                for (int j = i + 1; j < N; j++)
                {
                    if (Matrix[i, j] != 0)
                    {
                        list.Add(Tuple.Create(i + 1, j + 1));
                    }
                }
            }
            return list;
        }
		public static void ExA()
        {
            ReadN();
            ReadMatrix();
            var arr = Transform();
            foreach (var a in arr)
            {
                Console.WriteLine(a.Item1 + " " +  a.Item2);
            }
        }
		 public static void Main(string[] args)
        {
            ExA();
        }
    }
}
