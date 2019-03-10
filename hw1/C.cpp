
#include <iostream>
#include <vector>

using namespace std;

int n; // число вершин
int m; // число ребер
vector<int> g[100000]; // граф
bool has_cycle = false;
char used[100000];
vector<int> sorted_list;

void dfs(int v) {
	used[v] = 1;
	for (int i = 0; i < g[v].size(); ++i) {
		int	to = g[v][i];
		if (!used[to])
		{
			dfs(to);
		}
		if (used[to] == 1)
		{
			has_cycle = true;
		}
	}
	used[v] = 2;
	sorted_list.push_back(v);
}

void print_list()
{
	for (int i = 0; i < n; i++)
	{
		cout << sorted_list[i] + 1 << " ";
	}
	cout << endl;
}

void reverse(vector<int> &sorted_list)
{
	int len = sorted_list.size();
	for (int i = 0; i < len / 2; i++)
	{
		swap(sorted_list[i], sorted_list[len - 1 - i]);
	}
}

void topological_sort() {
	for (int i = 0; i < n; ++i)
		used[i] = 0;
	sorted_list.clear();
	for (int i = 0; i < n; ++i)
	{
		if (!used[i])
		{
			dfs(i);
		}
	}
	reverse(sorted_list);
	if (!has_cycle) 
	{ 
		print_list(); 
	}
	else { 
		cout << -1 << endl; 
	}
}

void read_data()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		used[i] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		int a = 0;
		int b = 0;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
	}
}

void print_g()
{
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ":";
		for (int j = 0; j < g[i].size(); j++)
		{
			cout << g[i][j] + 1 << " ";
		}
		cout << endl;
		}
}

int main()
{
	read_data();
	/*n = 10000;
	m = n - 1;
	for (int i = 0; i < n; i++)
	{
		used[i] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		g[i].push_back(i + 1);
	}*/
	//print_g();
	topological_sort();
	return 0;
}