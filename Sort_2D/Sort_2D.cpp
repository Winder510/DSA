#include<iostream>
#include<time.h>
#include<algorithm>
#include<vector>
using namespace std;
struct Diem
{
	int a, b;
};
void Nhap(vector<Diem>& arr, int n)
{
	for(int i=0;i<n;i++)
	cin >> arr[i].a >> arr[i].b;
}
void Xuat(vector<Diem> arr,int n)

{
	for (int i = 0; i < n; i++)
		cout << arr[i].a << " " << arr[i].b << endl;
}
bool Check(Diem P, Diem Q)
{
	if (P.a != Q.a)
		return P.a < Q.a;
	if (P.b != Q.b)
		return P.b > Q.b;
}
void merge(vector<Diem>&arr, int l, int m, int r)
{
	int L = m - l + 1;
	int R = r - m;

	vector<Diem> arr1(L);
	vector<Diem> arr2(R);

	for (int i = 0; i < L; i++)
		arr1[i] = arr[l+i];
	for (int j = 0; j < R; j++)
		arr2[j] = arr[m + j + 1];

	int i = 0;
	int j = 0;
	int k = l;
	while (i < L && j < R) {
		if (Check(arr1[i], arr2[j])) {
			arr[k] = arr1[i];
			i++; k++;
		}
		else {
			arr[k] = arr2[j];
			j++; k++;
		}
	}
	while (i < L) {
		arr[k] = arr1[i];
		k++;
		i++;
	}
	while (j < R) {
		arr[k] = arr2[j];
		k++;
		j++;
	}

}
void mergeSort(vector<Diem>& arr, int l, int r)
{
	if (l < r) {

		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}

}

int main()
{
	int n;
	cin >> n;
	vector<Diem> arr(n);
	Nhap(arr, n);
	mergeSort(arr, 0, n - 1);
	Xuat(arr, n);

}