using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework1
{
    public static class B
    {
        public static int M;

        public static int N;

        public static Dictionary<int, List<int>> graph =  new Dictionary<int, List<int>>();

        public static void ReadMN()
        {
            var str = Console.ReadLine();
            var toParse = str.Split(' ');
            var a = toParse.Select(s => Int32.Parse(s)).ToArray();
            N = a[0];
            M = a[1];
        }

        public static void ReadEdges()
        {
            for (int i = 0; i < M; i++)
            {
                var str = Console.ReadLine();
                var toParse = str.Split(' ');
                var a = toParse.Select(x => Int32.Parse(x)).ToArray();
                var f = a[0] - 1;
                var s = a[1] - 1;
                if (graph.ContainsKey(f))
                {
                    var values = graph[f];
                    graph.Remove(f);
                    values.Add(s);
                    graph.Add(f, values);
                }
                else
                {
                    graph.Add(f, new List<int>() { s });
                }
                if (graph.ContainsKey(s))
                {
                    var values = graph[s];
                    graph.Remove(s);
                    values.Add(f);
                    graph.Add(s, values);
                }
                else
                {
                    graph.Add(s, new List<int>() { f });
                }
            } 
        }

        public static List<int> DFS()
        {
            var list = new List<int>();
            bool[] used = new bool[N];
            var stack = new Stack<int>();
            var pair = graph.First();
            used[pair.Key] = true;
            list.Add(pair.Key + 1);
            foreach (var v in pair.Value)
            {
                stack.Push(v);
            }
            while (stack.Count != 0)
            {
                var v = stack.Pop();
                if (used[v]) continue;
                used[v] = true;
                list.Add(v + 1);
                if (!graph.ContainsKey(v)) continue;
                var values = graph[v];
                foreach(var node in values)
                {
                    stack.Push(node);
                }
            }
            return list;
        }

        public static bool IsConnected()
        {
            return DFS().Count == N;
        }
    }
}
