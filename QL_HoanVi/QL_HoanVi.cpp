// Bài toán hoán vị
#include<iostream>
using namespace std;
int n, X[1000];
int used[1000] = { 0 };
void inkq()
{
	for (int i = 1; i <= n; i++)
		cout << X[i];
	cout << endl;
}
void Try(int i)
{
	for (int j = 1; j <= n; j++)
	{
		if (used[j] == 0)
		{
			X[i] = j;
			used[j] = 1;

			if (i == n) {
				inkq();
			}
			else {
				Try(i + 1);
			}

			// backtrack
			used[j] = 0;
		}
	}
	
}
int main()
{
	cin >> n;
	Try(1);
}