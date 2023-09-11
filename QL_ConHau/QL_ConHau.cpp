/*
Cho 01 bàn cờ vua 8x8. Trình bày giải thuật cách đặt 8 quân hậu trên bàn cờ sao cho chúng không ăn lẫn nhau.
Cài đặt bài toán.
*/

#include<iostream>
using namespace std;


const int N = 8;

int queens[10];   // mảng lưu vị trí của các quân hậu
bool cows[100]={0};    // mảng đánh dấu cot đã sử dụng
bool diag1[100]={0}; // mảng đánh dấu đường chéo đã sử dụng
bool diag2[100]={0}; // mảng đánh dấu đường chéo ngược đã sử dụng
int cnt = 0;   // biến đếm số lời giải

void print()
{
	for(int i=1;i<=N;i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (queens[i] == j)
				cout << "Q";
			else
				cout << ".";
		}
		cout << endl;
	}
	cout << endl;
}
void solve(int row)
{
	for (int col = 1; col <= N; col++)
	{
		if (cows[col] == 0 && diag1[col + row - 1 ] == 0 && diag2[col - row + N] == 0)
		{
			queens[row] = col;


			cows[col] = 1;
			diag1[col + row - 1 ] = 1;
			diag2[col - row + N] = 1;

			if (row == N)
				print();
			else 
				solve(row + 1);

			// backtrack
			cows[col] = 0;
			diag1[col + row - 1 ] = 0;
			diag2[col - row + N] = 0;
		}
	}
}
int main()
{
	solve(1);
}