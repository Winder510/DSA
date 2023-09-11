#include<iostream>
#include<queue>
using namespace std;
int n, m;
int xA, xB;
int yA, yB;
char a[100][100];
int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };
bool visited[100][100]={false};
int d[100][100] = { 0 };
/*
6 6
Axxoox
ooxoox
ooxooo
xoooxx
Bxoxoo
oooxxx

*/
void dfs(int i,int j)
{
	visited[i][j] = true;
	// duyet cac dinh ke
	//cout << i << " " << j << endl;
	for (int k = 0; k < 4; k++)
	{
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && !visited[i1][j1]&&a[i1][j1]!='x')
		{
			d[i1][j1] = d[i][j] + 1;
			dfs(i1, j1);
		}
	}
}
void BFS(int i,int j)
{
	queue<pair<int,int>> q;
	q.push({i,j});
	visited[i][j] = true;
	while (!q.empty())
	{
		pair<int,int> v = q.front();
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int i1 = v.first + dx[k];
			int j1 = v.second + dy[k];
			if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && !visited[i1][j1] && a[i1][j1] != 'x')
			{
				d[i1][j1] = d[v.first][v.second] + 1;
				//if (a[i1][j1] == 'B') return;
				q.push({ i1,j1 });
				visited[i1][j1] = true;
			}
		}
	}
}
void input()	
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 'A')
			{
				xA = i; yA = j;
			}
			if (a[i][j] == 'B')
			{
				xB = i; yB = j;
			}
		}
	// dem thanh phan co dinh ke
	/*int cnt = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] == 'x' && !visited[i][j])
			{
				cout << "Thanh phan lien thong thu " << cnt+1 << " la : \n";
				dfs(i,j);
				cnt++;
			}
		}
	cout <<"Tong so thanh phan lien thong la: "<< cnt;*/
}
int main()
{
	input();
	BFS(xA, yA);
	cout << "Buoc di ngan nhat: " << d[xB][yB]<<endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cout<<d[i][j]<<"\t";
		cout << endl;
	}
}