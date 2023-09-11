//#include<iostream>
//#include<set>
//using namespace std;
//// O(logn)
//// size: kich thuoc cua set
//// insert: them phan tu vao set
//// find : trả về it tại vị tri phan tu do, nếu phan tu do khong ton tai thi tra ve s.end()
////count: trả về số lần xuất hiện của phan tu do, và trả về 0 nếu không tim thay
// erase: xoa
//int main()
//{
//	set<int> s;
//	s.insert(100);
//	s.insert(200);
//	s.insert(300);
//	s.insert(200);
//	s.insert(300);
//	// set khong luu cac phan tu trung nhau nen size luc nay van la 3 va khi insert thi set se tu dong sx
//	cout << "Kich thuoc:" << s.size();
//	
//}
#include <iostream>
#include <set>
using namespace std;

int main()
{
	std::set<int> myset;
	std::set<int>::iterator it;

	// set some initial values:
	for (int i = 1; i <= 10; i++)
		myset.insert(i * 10);    // set: 10 20 30 40 50
	
	it = myset.find(20);
	myset.erase(it);
	myset.erase(myset.find(40));

	std::cout << "myset contains:";
	for (it = myset.begin(); it != myset.end(); ++it)
		std::cout << ' ' << *it;
	
	myset.erase(10);
	cout << endl;
	for (int x : myset)
		cout << x << " ";

	cout << endl;
	
	myset.erase(myset.find(50));
	for (int x : myset)
		cout << x << " ";

	for (auto v : myset)
		cout << v;
	// duyet nguoc lai
	for (auto it = myset.rbegin(); it != myset.rend(); it++)
		cout << *it<<" ";
	
	return 0;
}