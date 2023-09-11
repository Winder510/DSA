#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* pLeft;
	Node* pRight;
};
typedef struct Node* TREE;
void CreateTree(TREE& T)
{
	T = NULL;
}
Node* CreateNode(int x)
{
	Node* p;
	p = new Node;
	if (p == NULL)
	{
		cout << "Khoi tao that bai";
		return p;
	}
	else
	{
		p->data = x;
		p->pRight = NULL;
		p->pLeft = NULL;
	}
	return p;
}

void insertNode(TREE& T, int x)
{
	if (T == NULL)
	{
		Node* p = new Node;
		p->data = x;
		p->pLeft = p->pRight = NULL;
		T = p;
	}
	else if (T->data > x)
	{
		insertNode(T->pLeft, x);
	}
	else if (T->data < x)
	{
		insertNode(T->pRight, x);
	}
	else
		return;
}
void Xuat_NLR(TREE T)
{
	if (T != NULL)
	{
		cout << T->data << " ";
		Xuat_NLR(T->pLeft);
		Xuat_NLR(T->pRight);
	}
}
void Xuat_NRL(TREE T)
{
	if (T != NULL)
	{
		cout << T->data << " ";
		Xuat_NRL(T->pRight);
		Xuat_NRL(T->pLeft);
	}
}
void Xuat_LNR(TREE T) // tang dan
{
	if (T != NULL)
	{
		Xuat_NRL(T->pLeft);
		cout << T->data << " ";
		Xuat_LNR(T->pRight);

	}
}
void Xuat_RNL(TREE T) // giam dan
{
	if (T != NULL)
	{
		Xuat_RNL(T->pRight);
		cout << T->data << " ";
		Xuat_RNL(T->pLeft);

	}
}
void Xuat_LRN(TREE T)
{
	if (T != NULL)
	{
		Xuat_LRN(T->pLeft);
		Xuat_LRN(T->pRight);
		cout << T->data << " ";

	}
}
void Xuat_RLN(TREE T)
{
	if (T != NULL)
	{
		Xuat_RLN(T->pRight);
		Xuat_RLN(T->pLeft);
		cout << T->data << " ";

	}
}

bool Search(TREE t, int x)
{

	if (t != NULL)
	{
		if (x > t->data)
			Search(t->pRight, x);
		else if (x < t->data)
			Search(t->pLeft, x);
		else
			return 1;
	}
	else
		return 0;
}
void Node_2_con(TREE t)
{
	if (t != NULL)
	{
		if (t->pLeft != NULL && t->pRight != NULL)
		{
			cout << t->data << " ";
		}
		Node_2_con(t->pLeft);
		Node_2_con(t->pRight);
	}
}
void Node_1_con(TREE t)
{
	if (t != NULL)
	{
		if ((t->pLeft != NULL && t->pRight == NULL)|| (t->pLeft == NULL && t->pRight != NULL))
		{
			cout << t->data << " ";
		}
		Node_1_con(t->pLeft);
		Node_1_con(t->pRight);
	}
}
void Node_la(TREE t)
{
	if (t != NULL)
	{
		if (t->pLeft == NULL && t->pRight == NULL)
		{
			cout << t->data << " ";
		}
		Node_la(t->pLeft);
		Node_la(t->pRight);
	}
}
int findMax(TREE t) {
	if (t == NULL) {
		return -1; // Trả về -1 nếu cây rỗng
	}

	while (t->pRight != NULL) {
		t = t->pRight;
	}

	return t->data;
}
int findMin(TREE t) {
	if (t == NULL) {
		return -1; // Trả về -1 nếu cây rỗng
	}

	while (t->pLeft != NULL) {
		t = t->pLeft;
	}

	return t->data;
}
void FindAndReplace1(TREE& p, TREE& tree)
{
	if (tree->pLeft != NULL) // chưa phải nhỏ nhất (trái nhất)
		FindAndReplace1(p, tree->pLeft); // tiếp tục tìm
	else // tree là nút trái nhất
	{
		p->data = tree->data; // copy data
		p = tree; // trỏ nút p vào nút tree sẽ làm thế mạng bị xóa
		tree = tree->pRight; // nút trái không còn tuy nhiên nút phải có thể còn nên ta phải nối chúng lại
	}
}
void FindAndReplace2(TREE& p, TREE& tree)
{
	if (tree->pRight != NULL) // chưa phải nhỏ nhất (trái nhất)
		FindAndReplace2(p, tree->pRight); // tiếp tục tìm
	else // tree là nút trái nhất
	{
		p->data = tree->data; // copy data
		p = tree; // trỏ nút p vào nút tree sẽ làm thế mạng bị xóa
		tree = tree->pLeft; // nút trái không còn tuy nhiên nút phải có thể còn nên ta phải nối chúng lại
	}
}
void DeleteNode(TREE& t, int x)
{
	if (t != NULL)
	{
		if (x > t->data)
			DeleteNode(t->pRight, x);
		else if (x < t->data)
			DeleteNode(t->pLeft, x);
		else // nút hiện tại (root) là nút cần xóa
		{
			Node* p = t; // lưu lại nút cần xóa tránh bị ghi đè
			if (t->pLeft == NULL)
				t = t->pRight; // trường hợp 1
			else if (t->pRight == NULL)
				t = t->pLeft; // trường hợp 2
			else
				//FindAndReplace1(p, t->pRight); // cách 1
				FindAndReplace2(p, t->pLeft); // cách 2
			delete p; // xóa nút
		}
	}
	else
	{
		cout << "Not found!\n"; // Không tìm thấy phần tử cần xóa
	}
}
int ChieuCao(TREE t)
{
	if (t == NULL || (t->pLeft == NULL && t->pRight == NULL))
		return 0;
	else
	{
		int a = ChieuCao(t->pLeft);
		int b = ChieuCao(t->pRight);
		if (a < b) return b + 1;
		return a + 1;
	}
}
int DemNode(TREE t)
{
	if (t == NULL) return 0;
	else
	{
		return 1 + DemNode(t->pLeft) + DemNode(t->pRight);
	}
}
int DemNode2Con(TREE t)
{
	if (t == nullptr) return 0;
	if (t->pLeft != NULL && t->pRight != NULL)
		return 1 + DemNode2Con(t->pLeft) + DemNode2Con(t->pRight);
	return DemNode2Con(t->pLeft) + DemNode2Con(t->pRight);
} 
int DemNode1Con(TREE t)
{
	if (t == nullptr) return 0;
	if ((t->pLeft == NULL && t->pRight != NULL) || (t->pLeft != NULL && t->pRight == NULL))
		return 1;
	return DemNode1Con(t->pLeft) + DemNode1Con(t->pRight);
}
int main()	
{
	TREE t;
	CreateTree(t);
	int n;
	/*do
	{

		cout << "\n\n\t\t-----------MENU-----------";
		cout << "\n1. Them vao cay";
		cout << "\n2.Xuat theo NLR";
		cout << "\n3.Xuat theo NRL";
		cout << "\n4.Xuat theo LNR";
		cout << "\n5.Xuat theo RNL";
		cout << "\n6.Xuat theo LRN";
		cout << "\n7.Xuat theo RLN";
		cout << "\n8.Tim xem x xuat hien khong?";
		cout << "\n9.Tim MAx";
		cout << "\n 10.Tim MIN";
		cout << "11. Xoa Node";
		cout << "\n\n\t\t-------------------------------"; 
		cout << "\nNhap lua chon:"; 
		cin >> n;
		if (n == 1)
		{
			int x;
			cout << "Nhap vao phan tu: ";
			cin >> x;
			insertNode(t, x);

		}
		else if (n == 2) {
			Xuat_NRL(t);
			system("pause");
		}
		else if (n == 3) {
			Xuat_NLR(t);
			system("pause");

		}
		else if (n == 4) {

			Xuat_LNR(t);
			system("pause");

		}
		else if (n == 5) {

			Xuat_RNL(t);
			system("pause");

		}

		else if (n == 6) {
			Xuat_LRN(t);
			system("pause");

		}
		else if (n == 7) {
			Xuat_RLN(t);
			system("pause");

		}
		else if (n == 8) {
			int x;
			cin >> x;
			cout << Search(t, x);
			system("pause");

		}
		else if (n == 9) {
			cout << "MAX:" << findMax(t);
			system("pause");

		}
		else if (n == 10) {
			cout << "Min:" << findMin(t);
			system("pause");
		}
		else if (n == 11) {
			int x;
			cout << "Nhap phan tu muon xoa:";
			cin >> x;
			DeleteNode(t, x);
		}
		
		else if (n == 0) {
			break;
		}
	} while (true);*/

		insertNode(t, 45);
		insertNode(t, 12);
		insertNode(t, 56);
		insertNode(t, 13);
		insertNode(t, 54);
		insertNode(t, 78);
		insertNode(t, 86);
	
	cout << "Chieu cao cua cay: " << ChieuCao(t)<<endl;
	cout << "So Node cua cay la: " << DemNode(t) << endl;
	cout << "So Node 2 con la: " << DemNode2Con(t)<<endl;
	cout << "So node 1 con la: " << DemNode1Con(t) << endl;
}