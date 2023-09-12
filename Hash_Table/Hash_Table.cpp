// Nối kết trực tiếp 
#include<iostream>
using namespace std;
#define M 7
struct Node
{
	int value;
	Node* pNext;
};
typedef struct Node Node;
void initHash(Node* heads[])
{
	for (int i = 0; i < M; i++)
		heads[i] = NULL;
}
Node* createNode(int x)
{
	Node* p = new Node;
	p->value = x;
	p->pNext = NULL;
	return p;
}
int hashFunc(int value)
{
	return value % M;
}
void insertNode(Node* heads[], int value)
{
	int index = hashFunc(value);
	Node* r = heads[index];
	Node* prev = NULL;
	while (r != NULL && r->value < value)
	{
		prev = r;
		r=r->pNext;
	}
	Node* p = createNode(value);
	if (prev == NULL) // them dau
	{
		heads[index] = p;
		p->pNext = r;

	}
	else if (r == NULL) // them cuoi
	{
		prev->pNext = p;
	}
	else
	{
		prev->pNext = p;
		p->pNext = r;
	}
}
void DeleteNode(Node* heads[], int value)
{
	int index = hashFunc(value);
	Node* p = heads[index];
	Node* prev = NULL;
	while (p != NULL)
	{
		if (p->value == value) break;
		prev = p;
		p = p->pNext;
	}
	if (p == NULL) return; // không tìm thấy gtri value
	else
	{
		if (prev == NULL)
		{
			heads[index] = p->pNext;
			delete p;
		}
		else
		{
			prev->pNext = p->pNext;
			delete p;
		}
	}

}
Node* Search(Node* heads[], int value)
{
	int index = hashFunc(value);
	Node* p = heads[index];
	while (p != NULL)
	{
		if (p->value == value)
			return p;
		p = p->pNext;
	}
}
void display(Node* heads[])
{
	for (int i = 0; i < M; i++)
	{
		cout << "[" << i << "]: ";
		for (Node* p = heads[i]; p != NULL; p=p->pNext)
			cout << p->value << "\t";
		cout << endl;
	}
}

int main()
{
	Node* heads[8];
	initHash(heads);

	insertNode(heads, 8);
	insertNode(heads, 4);
	insertNode(heads, 9);
	insertNode(heads, 3);
	insertNode(heads, 15);
	insertNode(heads, 18);
	insertNode(heads, 26);

	DeleteNode(heads, 18);
	display(heads);


}