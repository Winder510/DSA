  #include<iostream>
using namespace std;
// Cấu trúc cảu một node
struct Node
{
	int info;
	Node* next;
};
Node* CreateNode(int init_data)
{
	Node* p = new Node;
	if (p == NULL)
	{
		cout << "Het bo nho";
		return NULL;
	}
	p->info = init_data;
	p->next = NULL;      // node vừa tạo chưa thêm vào danh sách nên chưa liên kết với phần tử nào cả nên phần liên kết gán bằng NULL
	return p;
}
// cấu trúc 1 danh sách lk đơn
struct LinkedList
{
	Node* pHead;
	Node* pTail;
};
void createList(LinkedList& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

// them phan tu vao danh sach
void AddHead(LinkedList& l,Node* node)
{
	if (l.pHead == NULL) {
		l.pHead = node;
		l.pTail = node;
	}
	else {
		node->next = l.pHead;  
		l.pHead = node;
	}	
}

// them node vao cuoi
void AddTail(LinkedList& l, Node* node)
{
	if (l.pHead == NULL) {
		l.pHead = node;
		l.pTail = node;
	}
	else {
		l.pTail->next = node;
		l.pTail = node;
	}
}
// tim vi tri node
Node* SearchEle(LinkedList& l, int a)
{
	Node* p = l.pHead;
	while (p != NULL)
	{ 
		if (p->info == a)
		{
			break;
		}
		p = p->next;
	}
	return p;
}
// them node vao sau node q
void AddAfterQ(LinkedList& l, Node* p, Node* q)
{
	if (q != NULL)
	{
		p->next = q->next;
		q->next = p;
		if (l.pTail == q)
			l.pTail = p;

	}
	else
		AddHead(l, p);
}

// Xóa node đầu 
void delHead(LinkedList& l)
{
	if (l.pHead == NULL) return;
	else
	{
		Node* k = new Node;
		k = l.pHead; 
		l.pHead = l.pHead->next;
		k->next = NULL;
		delete k;
	}
}	
void delTail(LinkedList& l)
{
	Node* k = l.pHead;
	while (k != NULL)
	{
		if (k->next == l.pTail)
		{
			delete l.pTail;
			k->next = NULL;
			l.pTail = k;
		}
		k = k->next;
	}
}
void delEle(LinkedList& l, int x)
{
	if (l.pHead == NULL) return;
	else
	{
		Node* k = NULL;
		Node* p = l.pHead;
		while (p != NULL)
		{
			if (p->info == x) break;
			k = p;
			p = p->next;
		}
		if (p != NULL)
		{
			if (p == l.pHead)
			{
				delHead(l);
			}
			else
			{
				k->next = p->next;
				p->next = NULL;
				if (p == l.pTail) l.pTail = k;
				delete p;
			}
		}
	}
}
void Giai_Phong_Vung_Nho(LinkedList& l)
{
	Node* k = NULL;
	while (l.pHead != NULL)
	{	
		k = l.pHead;
		l.pHead = l.pHead->next;
		delete k;
	}
	
}


// Duyet
void Duyet(LinkedList l)
{
	Node* p = l.pHead;
	while (p != NULL)
	{
		cout << p->info<<" ";
		p = p->next;
	}
}


int Tim_Max(LinkedList l)
{
	int max = l.pHead->info;
	Node* k = l.pHead->next;
	while (k != NULL)
	{
		if (max < k->info) max = k->info;
		k = k->next;
	}
	return max;
}
void SapXep(LinkedList & l)
{
	for (Node* q = l.pHead; q->next != NULL; q = q->next)
		for (Node* p = q->next; p != NULL; p = p->next)
			if (q->info > p->info)
				swap(q->info,p->info);
}
void Reverse(LinkedList& list)
{
	Node* current = list.pHead;
	Node* next = NULL;
	Node* prev = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		if (prev->next == NULL)
			list.pTail = prev;
	}
	list.pHead = prev;
}
void ReversePartial(LinkedList& list, int h, int k)
{
	if (h >= k || list.pHead == NULL || list.pHead->next == NULL)
		return;

	Node* prevH = NULL;
	Node* current = list.pHead;

	// Tìm nút trước nút thứ h
	for (int i = 1; i < h && current != NULL; i++)
	{
		prevH = current;
		current = current->next;
	}

	// Nếu không tìm thấy nút thứ h hoặc nút thứ k, hoặc danh sách đã kết thúc
	if (current == NULL)
		return;

	Node* start = current; // Nút thứ h sau khi đảo ngược
	Node* prev = NULL;
	Node* next = NULL;

	// Đảo ngược phần danh sách từ nút thứ h đến nút thứ k
	for (int i = 0; i <= k - h && current != NULL; i++)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	// Kết nối lại các nút sau khi đảo ngược
	if (prevH != NULL)
		prevH->next = prev;
	else
		list.pHead = prev;

	start->next = current;

	// Nếu nút thứ k là nút cuối cùng, cập nhật pTail
	if (current == NULL)
		list.pTail = start;
}
int CountNode(LinkedList l)
{
	int dem = 0;
	Node* p = l.pHead;
	while (p != NULL)
	{
		dem++;
		p = p->next;
	}
	return dem;
}
void swapKth(LinkedList& l,int k)
{
	int length = CountNode(l);
	Node* x = l.pHead;
	Node* x_prev = NULL;
	for (int i = 1; i < k; i++)
	{
		x_prev = x;
		x = x->next;
	}
	Node* y = l.pHead;
	Node* y_prev = NULL;
	for (int i = 1; i < length-k+1; i++)
	{
		y_prev = y;
		y = y->next;
	}
	if (x_prev)
		x_prev->next = y;
	else
	{
		l.pHead = y;
		l.pTail = x;
	}
	if (y_prev)
		y_prev->next = x;
	else
	{
		l.pHead = x;
		l.pTail = y;
	}

	Node* tmp = x->next;
	x->next = y->next;
	y->next = tmp;
}
int main()
{
	LinkedList l;  
	createList(l);
	int x;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		AddTail(l, CreateNode(x));
	}
	int a,b;
	do
	{
		cout << "---------------------------------------------||-----------------------------------------"<<endl;
		cout << "0. Thoat chung trinh "<<endl;
		cout << "1.Them phan tu vao dau danh sach" << endl;
		cout << "2.Them phan tu vao cuoi danh sach"<<endl;
		cout << "3.Them mot phan tu a vao sau mot phan tu b trong danh sach"<<endl;
		cout << "4.Xoa phan tu dau danh sach" << endl;
		cout << "5.Xoa phan tu o cuoi ds" << endl;
		cout << "6.Xoa phan tu o phia sau 1 phan tu khac" << endl;
		cout << "7.Xuat danh sach lien ket don" << endl;
		cout << "8. Tim phan tu lon nhat:"<<endl;
		cout << "9.Sap xep dslk" << endl;
		cout << "10 Dao nguoc danh sach"<<endl;
		cout << "11. Dao nguoc mot phan " << endl;
		cout << "---------------------------------------------||-----------------------------------------"<<endl;

		cout << "Moi ban chon:";
		cin >> n;
		switch (n)
		{
		case 1: {
			cin >> x;
			Node* p = CreateNode(x);
			AddHead(l, p);
			break;
		}
		case 2: {
			cin >> x;
			Node* p = CreateNode(x);
			AddTail(l, p);
			break;
		}
		case 3: {
			
			cout << "\nNhap phan tu a:"; cin >> a;
			cout << "Nhap phan tu b:"; cin >> b;
			Node* q = SearchEle(l, b);
			Node* p = CreateNode(a);
			AddAfterQ(l, p, q);
			break;
		}
		case 4: {
			delHead(l);
			break;
		}
		case 5: {
			delTail(l);
			break;
		}
		case 6: {
			cin >> x; 
			delEle(l, x);
			break;
		}
		case 7: {
			Duyet(l);
			break;
		}
		case 8: {
			cout << "Phan tu lon nhat la:" << Tim_Max(l);
				break;
		}
		case 9: {
			SapXep(l);
			break;
		}
		case 10: {
			Reverse(l);
			cout << "l.pHead: " << l.pHead->info<<endl;
			cout << "l.pTail: " << l.pTail->info; break;
		}
		case 11: {
			int h, k;
			cin >> h>>k;
			ReversePartial(l, h, k);
			break;
		}
		case 12: {
			int m;
			cin >> m;
			swapKth(l, m);
			break;
		}
		}
	} while (n != 0);
	Giai_Phong_Vung_Nho(l);
	Duyet(l);
	
}	