#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define INF 1e9

int v,e;
vector<vector<int>>matrix;
vector<string> names;
map<string, int> v_index;
vector<bool> close;
//stack<string>openD;
//queue<string>openB;
map<string, string> parent;
vector<int> d;

void Nhap()
{
	cin >> v >> e;
	names = vector<string>(v, "");
	matrix = vector<vector<int>>(v, vector<int>(v, 0));
	for (int i = 0; i < v; i++)
	{
		string s;
		cin >> s;
		names.push_back(s);
		v_index[s] = i;
		names[i] = s;
	}
	for(int i =0;i<e;i++)
	{
		string x, y; 
		int w;
		cin >> x >> y;
		cin>> w;
		matrix[v_index[x]][v_index[y]] = w;
		//matrix[v_index[y]][v_index[x]] = w;
		
	}
	close = vector<bool>(v, false);
	d = vector<int>(v, INF);
}
void Dijkstra(string st,string en)
{
	d[v_index[st]] = 0;
	parent[st] = st;
	bool found = false;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qu;
	qu.push({ 0,v_index[st] });
	while (!qu.empty()) {
		pair<int, int> top = qu.top();
		qu.pop();
		int u = top.second;
		if (u == v_index[en]) {
			found = true;
			break;
		}
		if (close[u]) continue;
		close[u] = true;
		for (int i=0;i<v;i++){
			if (matrix[u][i]&&!close[i]) {
				int v = i;
				int w = matrix[u][i];
				if (d[v] > d[u] + w) {
					d[v] = d[u] + w;
					qu.push({ d[v],v });
					parent[names[v]] = names[u];
				}
			}
		}
	}
	if (found)
	{
		vector<string> path;
		while (en!=st) {
			path.push_back(en);
			en = parent[en];
		}
		path.push_back(st);
		reverse(path.begin(), path.end());
		for (string v : path)
			cout << v << " ";
	}
}
int main()
{
	Nhap();
	string x, y;
	cin >> x >> y;
	Dijkstra(x,y);
}
/*
10 14
A B C D E F G H I J
A B 20
A C 35
A D 30
B E 40
B F 45
C F 15
C G 10
E H 30
E I 25
F J 10
G J 20
H B 60
I J 30
J C 40
*/