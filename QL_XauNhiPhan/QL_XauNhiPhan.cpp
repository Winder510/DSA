// Liet ke xâu nhị phân có độ dài N
#include<iostream>
using namespace std;
int n, X[1000];
void inkq()
{
	for (int i = 1; i <= n; i++)
		cout << X[i];
	cout << endl;
}
void Try(int i)
{
	// Duyet qua cac kha nang cua X[i]
	for (int j = 0; j <= 1; j++)
	{
		X[i] = j;
		if (i == n) {
			inkq();
		}
		else {
			Try(i + 1);
		}
	}
}
int main()
{
	cin >> n;
	Try(1);
}