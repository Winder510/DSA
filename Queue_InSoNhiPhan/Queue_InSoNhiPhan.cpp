#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<string> v;
		v.push_back("1");
		queue<string> q;
		q.push("1");
		while (v.size() < 1000)
		{
			string top = q.front();
			q.pop();
			q.push(top + "0");
			q.push(top + "1");
			v.push_back(top + "0");
			v.push_back(top + "1");

		}
		for (int i = 0; i < n; i++)
			cout << v[i] << " ";
		cout << endl;
	}
}					





