#include<iostream>
#include<stack>
using namespace std;
void Solve()
{
	stack<char> st;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
			st.push(s[i]);
		else
		{
			if (st.empty())
			{
				cout << "No";
				return;
			}
			else st.pop();
		}
	}
	if (st.empty()) cout << "yes";
	else cout << "No";
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Solve();
	}
}