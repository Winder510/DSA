// dfs update
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<map>
using namespace std;
vector<vector<int>>matrix;
vector<string> names;
map<string, int> v_index;
vector<bool> close;
stack<string>openD;
queue<string>openB;
map<string, string> parent;

int v, e;
void input() // v so dinh
{
	cin >> v >> e;
	matrix = vector<vector<int>>(v, vector<int>(v, 0));
	names = vector<string>(v, "");
	close = vector<bool>(v, false);
	// Nhap vao cac dinh
	for (int i = 0; i < v; i++) {
		string s;
		cin >> s;
		names[i] = s;
		v_index[s] = i;
	}
	for (int i = 0; i < e; i++)
	{
		string x, y;
		cin >> x >> y;
		//matrix[v_index[x]][v_index[y]] = 1;
		matrix[v_index[y]][v_index[x]] = 1;

	}
}
void DFS(string s, string g)
{
	openD.push(s);
	close[v_index[s]] = 1;
	bool found = false;
	while (!openD.empty()) {
		string q = openD.top();
		openD.pop();
		int idx = v_index[q];
		if (q == g)			
		{
			found = true;
			break;
		}
		//close[idx] = true;
		for (int i = 0; i < v; i++)
		{
			if (matrix[idx][i] && !close[i])
			{
				string p = names[i];
				openD.push(p);
				parent[p] = q;
				close[i] = true;
			}
		}
	}
	if (found) {
		string current = g;
		vector<string> path;
		while (current != s) {
			path.push_back(current);
			current = parent[current];
		}
		path.push_back(s);

		for (int i = path.size() - 1; i >= 0; i--) {
			cout << path[i] << " ";
		}
	}

}
void BFS(string s, string g) {
	//map<string, string> parent;

	openB.push(s);
	close[v_index[s]] = true;
	bool found = false;

	while (!openB.empty()) {
		string q = openB.front();
		cout << q << " ";
		openB.pop();
		int idx = v_index[q];

		if (q == g) {
			found = true;
			break;
		}

		for (int i = 0; i < v; i++) {
			if (matrix[idx][i] != 0 && !close[i]) {
				string p = names[i];
				openB.push(p);
				parent[p] = q;
				close[i] = true;
			}
		}
	}
		
	if (found) {
		string current = g;
		vector<string> path;
		while (current != s) {
			path.push_back(current);
			current = parent[current];
		}
		path.push_back(s);

		for (int i = path.size() - 1; i >= 0; i--) {
			cout << path[i] << " ";
		}
	}
}
int main()
{
	input();
	string s, v;
	cin >> s >> v;
	DFS(s, v);
	cout << endl;
	//BFS(s, v);
}
/*
6 13
W K I U M Q
W M
W Q
I W
I K
I U
I M
U W
U K
U Q
M U
M Q
Q I
Q M
*/