#include<iostream>
using namespace std;
#define LH -1 //cây con trái cao hơn
#define EH 0 //cây con trái bằng cây con phải
#define RH 1 //cây con phải cao hơn
struct AVLNODE {
	int key;
	char balFactor; //chỉ số cân bằng
	AVLNODE* pLeft;
	AVLNODE* pRight;
};
typedef AVLNODE* AVLTREE;

void CreateAVLTree(AVLTREE t)
{
	t = NULL;
}
int height(AVLNODE* p)
{

	if (p == NULL) return 0;

	return 1 + max(height(p->pLeft), height(p->pRight));
}
void setBalFactor(AVLNODE* p)
{
	int l = height(p->pLeft);
	int r = height(p->pRight);
	if ((l - r) > 0)
		p->balFactor = LH;
	else if ((l - r) < 0)
		p->balFactor = RH;
	else
		p->balFactor = EH;
}
void LL(AVLTREE& T) {
	AVLNODE* T1 = T->pLeft;
	T->pLeft = T1->pRight;
	T1->pRight = T;
	switch (T1->balFactor) {
	case LH: T->balFactor = EH;
		T1->balFactor = EH; break;
	case EH: T->balFactor = LH;
		T1->balFactor = RH; break;
	}
	T = T1;
}
int main()
{

}