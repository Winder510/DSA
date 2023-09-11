#include<iostream>
#include<stack>
using namespace std;
int main()
{
	int arr[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	stack<int> s;
	int res = 0;
	int i = 0;
	while (i < n)
	{
		if (s.empty() || arr[i] >= arr[s.top()])
		{
			s.push(i);
			++i;
		}
		else
		{
			int pos = s.top();
			s.pop();

			if (s.empty()) {
				res = max(res, arr[pos] * i);
			}
			else
			{
				res = max(res, arr[pos] * (i - s.top() - 1));
			}
		}
	}
	while (!s.empty())
	{
		int pos = s.top();
		s.pop();

		if (s.empty()) {
			res = max(res, arr[pos] * i);
		}
		else
		{
			res = max(res, arr[pos] * (i - s.top() - 1));
		}
	}
	cout << res << endl;
}