#include <iostream>
#include <cstring>
#include <string>
#define M 10		// M là số nút có trên bảng băm, đủ để chứa các nút nhập vào bảng băm
#define NULLKEY -1
using namespace std;

//###INSERT CODE HERE -
struct node
{
    int key;
    int value;
};

struct Hash
{
    int m;
    node* hashtable;
    int N;
};
void initHash(Hash &H)
{
    H.m = M;
    H.hashtable = new node[M];
    for (int i = 0; i < H.m; i++)
    {
        H.hashtable[i].key = NULLKEY;
        H.hashtable[i].value = NULLKEY;
    }
    H.N = 0;
}

int f(int key)
{
    return key % M;
}

int rehash(int key, int j)
{
    return (f(key) + j) % M;
}
void insertHash(Hash& H, int key)
{
    if (H.N >= H.m)
    {
        cout << "Hang doi da day ";
        return;
    }
    else
    {
        int i = f(key);
        int j = 0;
        while (H.hashtable[i].key != NULLKEY)
        {
            j++;
            i = rehash(key, j);
        }
        cout << "\nInsert " << key<<endl;
        H.hashtable[i].key = key;
        H.N++;
    }
}
void Xuat(Hash H)
{
    for (int i = 0; i < M; i++)
    {
        cout << i << "\t" << H.hashtable[i].key;
        cout << endl;
    }
}
int main()
{
    Hash H;
    initHash(H);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insertHash(H, x);
    }
    cout << endl;
    Xuat(H);
}