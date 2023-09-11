#include<iostream>
#include<vector>
using namespace std;
vector<int> edge[1000];
bool visited[1000];
int m, n;

/*
10 8
1 2
2 3
2 4
3 6
3 7
6 7
5 8
8 9
*/

void input()
{
	//Nhap vao so dinh va so canh
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	} 
}
void DFS(int u)
{
	cout << u<<" ";
	visited[u] = true;
	for (int v:edge[u])
	{
		if (!visited[v])
			DFS(v);
	}
}
void ConectedComponent()
{
	int cnt = 0;
	memset(visited, false, sizeof(visited));

	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			cnt++;
			DFS(i);
		}
	}
	cout << "So thanh phan lien thong la: " << cnt;
}
int main()
{
	input();
	ConectedComponent();
}