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
class queue
{
private:
	Node* pHead; // Con trỏ đầu hàng đợi
	Node* pTail; // Con trỏ cuối hàng đợi
public:

	queue() : pHead(NULL), pTail(NULL){};
	bool isEmpty()
	{
		return pHead == NULL;
	}

	// Đẩy một phần tử vào cuối hàng đợi.
	void push(int value)
	{
		Node* p = new Node(value);
		if (isEmpty()) {
			pHead = p;
			pTail = p;
		}
		pTail->next = p;
		pTail = p;
	}

	//Loại bỏ một phần tử ở đầu hàng đợi.
	void pop()
	{
		if (isEmpty()) {
			cout << "hang doi rong";
			return;
		}
		Node* p = pHead;
		pHead = pHead->next;
		if (pHead == NULL)
			pTail = NULL;
		delete p;
	}

	// tra ve phan tu dau hang doi
	int front()
	{
		return pHead->data;
	}
	// tra ve phan tu cuoi hang doi
	int bak()
	{
		return pTail->data;
	}
};
int main()
{
	queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.pop();
	cout<<q.front();

}