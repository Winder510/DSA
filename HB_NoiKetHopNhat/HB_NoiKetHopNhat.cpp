#include<iostream>
using namespace std;
#define M 7
struct item
{
	int value;
	int next;
};
struct HashTable
{
	item h[M];
	int r;
};
void initHash(HashTable& t)
{
	for (int i = 0; i < M; i++)
	{
		t.h[i].value = -1;
		t.h[i].next = -1;
	}
	t.r = M - 1;
}
int hashFunc(int value)
{
	return value % M;
}
void insertHashItem(HashTable& t, int x)
{
	if (t.r >= 0)
	{
		int idx = hashFunc(x);
		if (t.h[idx].value == -1)
			t.h[idx].value = x;
		else
		{
			t.h[t.r].value = x;

			while (t.h[idx].next != -1)
				idx = t.h[idx].next;	

			t.h[idx].next = t.r; 
		}
		while (t.r >= 0 && t.h[t.r].value >= 0)
			t.r--;
	}
}
int search(HashTable t,int x)
{
	int idx = hashFunc(x);
	do
	{
		if (x == t.h[idx].value)
			return idx;

		idx = t.h[idx].next;
	} while (idx >= 0);
	return -1;
}
void Xuat(HashTable t)
{
	for (auto it : t.h)
	{
		cout << it.value << " " << it.next;
		cout << endl;
	}
}
int main()
{
	HashTable t;
	initHash(t);
	for (int i = 0; i < M; i++)
	{
		int x;
		cin >> x;
		insertHashItem(t, x);
	}
	Xuat(t);
}