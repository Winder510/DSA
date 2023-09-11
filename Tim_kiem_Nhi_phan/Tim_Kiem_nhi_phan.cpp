// Tìm kiếm nhị phân với mảng đã sắp xếp
#include<iostream>
using namespace std;
int binarytSearch(int a[], int left, int right, int x)
{
	if (right >= left)
	{
		int mid = left + (right - left) / 2;

		// Nếu phần tử ở giữa bằng x, trả về vị trí giữa
		if (a[mid] == x)
			return mid;

		// nếu phần tử ở giữa lớn hơn x, tìm kiếm ở nửa sau của mảng 
		if (a[mid] > x)
			return binarytSearch(a, left, mid - 1, x);
			
		
		// nếu phần tử ở giữa lớn hơn x, tìm kiếm ở nửa trước của mảng 
		return binarytSearch(a, mid + 1, right, x);

	}
	return -1;
}
int main()
{
	int a[] = { 1,4,6,8,9,10,19 };
	int n = sizeof(a) / sizeof(a[0]);
	cout<<binarytSearch(a, 0, n - 1, 10);

}