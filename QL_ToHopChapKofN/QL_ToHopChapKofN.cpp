#include<iostream>
using namespace std;
int n, X[1000],k;
void inkq()
{
	for (int i = 1; i <= k; i++)
		cout << X[i];
	cout << endl;
}
void Try(int i)
{
	// Duyet cac kha nang ma X[i] co the nhan duoc
	for (int j = X[i-1]+1; j <= n - k + i; j++)
	{
		X[i] = j;
		if (i == k)
			inkq();
		else
			Try(i + 1);
	}

}
int main()
{
	
	X[0] = 0;
	cin >> k >> n;
	Try(1);
	
}