#include<iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* next;

	Node(int value) {
		data = value;
		next = NULL;
	}
};
class stack {
private:
	Node* top;
public:
	stack() {
		top = NULL;
	}
	bool isEmpty(){
		return top == NULL;
	}
	void push(int value) {
		Node* p = new Node(value);
		if (isEmpty())
		{
			top = p;
		}
		else
		{
			p->next = top;
			top = p;
		}
	}
	// lay phan tu dau stack va xoa di
	int pop()
	{
		if (isEmpty())
		{
			return 0;
		}
		Node* p = top;
		top = top->next;
		int x = p->data;
		delete p;
		return x;
	}
	int size()
	{
		int cnt = 0;
		for (Node* p = top; p != NULL; p = p->next)
			cnt++;
		return cnt;
	}
	void Xuat()
	{
		for (Node* p = top; p != NULL; p = p->next)
			cout << p->data;
	}
};
int main()
{
	stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	stack q = s;
	s.pop();
	s.Xuat();
	cout << endl;
	q.Xuat();
}