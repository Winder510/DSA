#include<iostream>
using namespace std;

//void heaptify(int arr[],int n,int i)
//{
//	int largest = i;
//	int left = 2 * i + 1;
//	int right = 2 * i + 2;
//	if (left<n && arr[left]>arr[largest]) {
//		largest = left;
//	}
//	if (right<n && arr[right]>arr[largest]) {
//		largest = right;
//	}
//	if (arr[largest] != arr[i]) {
//		swap(arr[largest], arr[i]);
//		heaptify(arr, n, largest);	
//	}
//
//}
//void heapsort(int arr[], int n)
//{
//	// Xay dung max heap
//	for (int i = n / 2 - 1; i >= 0; i--)
//		heaptify(arr, n, i);
//	//
//	for (int i = n - 1; i >= 0; i--)
//	{
//		swap(arr[i], arr[0]);
//		heaptify(arr, i, 0);
//	}
//	
//}


void heapify(int a[], int n, int i)
{
	int big = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l<n && a[l]>a[big])
		big = l;
	if (r<n && a[r]>a[big])
		big = r;
	if (big != i)
	{
		swap(a[big], a[i]);
		heapify(a, n, big);
	}

}




void heapsort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);

	for (int i = n - 1; i >= 0; i--)
	{
		swap(a[i], a[0]);
		heapify(a, i, 0);
	}

}



int main()
{
	int a[1100]={1,3,4,5,2,5,0};
	heapsort(a, 7);
	for (int i = 0; i < 7; i++)
		cout << a[i] << "  ";
	
}