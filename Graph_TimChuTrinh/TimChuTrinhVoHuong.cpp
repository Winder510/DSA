#include<iostream>
#include<vector>
using namespace std;
vector<int> edge[100];
bool visited[100];
int n, m, s, e;
int a[100][100];
int parent[100];
/*
7 6
1 2
2 3
2 4 
3 6
6 7
7 3
*/
bool dfs(int u)
{
	visited[u] = true;
	for (int v : edge[u])
	{
		if (!visited[v])
		{
			parent[v] = u;
			if (dfs(v)) return true;
		}	
		else if (v !=parent[u])
		{
			s = v; e = u;
			return true;
		}
	}
	return false;
}
void input()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)	
	{
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
}
int main()
{
	input();
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			if (dfs(i))
			{
				vector<int> cycle;
				cycle.push_back(s);
				cout << "yes"<<endl;
				while (e != s)
				{
					cycle.push_back(e);
					e = parent[e];
				}
				cycle.push_back(s);
				reverse(cycle.begin(), cycle.end());
				for (int i : cycle)
					cout << i << " ";
				return 0;
			}
		}
	}
	

}