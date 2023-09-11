/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <string>
#define MAX 1000
using namespace std;

//###INSERT CODE HERE -
struct node
{
    int key;
    node* next;
};
struct Hash
{
    node* bucket[MAX];
    int m;
};
void initHash(Hash& H)
{
    for (int i = 0; i < H.m; i++)
    {
        H.bucket[i] = NULL;
    }
}
node* getNode(int x)
{
    node* p = new node();
    p->key = x;
    p->next = NULL;
    return p;
}
int hashFunc(Hash& H ,int x)
{
    return x % H.m;
}
void insertHash(Hash& H, int x)
{
    int add = hashFunc(H,x);
    node* p = H.bucket[add];
    node* q = NULL;
    while (p != NULL)
    {
        if (p->key > x) break;
        q = p;
        p = p->next;
    }
    node* newNode = getNode(x);
    if (H.bucket[add] == NULL || p == H.bucket[add])
    {
        newNode->next = H.bucket[add];
        H.bucket[add] = newNode;
    }
    else
    {
        q->next = newNode;
        newNode->next = p;
    }
}
void traverseAllHash(Hash H)
{
    for (int i = 0; i < H.m; i++)
    {
        node* p = H.bucket[i];
        cout << "Bucket " << i << ": ";
        while (p != NULL)
        {
            cout << p->key << " ";
            p = p->next;
        }
        cout << endl;
    }
}
int main()
{
    Hash H;
    cin >> H.m; // m la so dia chi co trong bang bam
    initHash(H); //khoi tao cac bucket

    int n, x; cin >> n; // n la so luong gia tri can phai luu tru
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        insertHash(H, x); // them 1 gia tri du lieu vao bang bam
    }
    cout << "Created Hash:" << endl;
    traverseAllHash(H); // Xuat toan bo cac bucket cua Bang bam

    return 0;
}

