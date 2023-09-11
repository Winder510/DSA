// Tim duong di cua do thi vo huong , khong co chu trinh
#include<iostream>
#include<vector>
using namespace std;
vector<int> adj[1000];
bool visisted[1000];
int parent[1000];
int m, n;
//Nhap vao danh sach canh
void input()
{
	cin >> n >> m;// dinh ,canh
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visisted, false, sizeof(visisted));
}
void dfs(int u)
{
	visisted[u] = true;
	for (int v : adj[u])
	{
		if (!visisted[v])
		{
			parent[v] = u;
			dfs(v);
		}
	}
}
void FindPath(int s,int t)
{
	dfs(s);
	if (!visisted[t])
		cout << "Khong co duong di ";
	else
	{
		vector<int> path;
		while (t != s)
		{
			path.push_back(t);
			t = parent[t];
		}
		path.push_back(s);

		reverse(path.begin(), path.end());
		for (int x : path)
			cout << x << " ";

	}
}

int main()
{
	input();
	int s, t;
	cin >> s >> t;
	FindPath(s,t);
}