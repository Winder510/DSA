#include <iostream>
using namespace std;

// Hàm đổi chỗ 2 phần tử

// Hàm chọn pivot và phân hoạch dãy
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Chọn phần tử cuối cùng làm pivot
    int i = (low - 1); // Khởi tạo chỉ số của phần tử nhỏ hơn pivot

    for (int j = low; j <= high - 1; j++) {
        // Nếu phần tử hiện tại nhỏ hơn hoặc bằng pivot
        if (arr[j] <= pivot) {
            i++; // Tăng chỉ số của phần tử nhỏ hơn pivot
            swap(arr[i], arr[j]); // Đổi chỗ phần tử i và j
        }
    }
    swap(arr[i + 1], arr[high]); // Đổi chỗ phần tử i+1 và pivot
     for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
     cout << endl;
    return (i + 1); // Trả về chỉ số của pivot
}

// Hàm đệ quy sắp xếp dãy
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Chọn pivot và phân hoạch dãy
        quickSort(arr, low, pi - 1); // Đệ quy sắp xếp dãy trước pivot
        quickSort(arr, pi + 1, high); // Đệ quy sắp xếp dãy sau pivot
    }
}

    //void quicksort(int a[], int left, int right) {
    //     int i, j, pivot;
    //    pivot = a[(left + right) / 2];
    //    cout << "pivot= " << pivot<<endl;
    //    i = left; j = right;
    //    while(i <= j) {
    //        while (a[i] < pivot) i++;
    //        while(a[j] > pivot) j--;
    //        if(i <= j) {
    //            swap(a[i],a[j]);
    //            i++; j--;
    //        }
    //    }
    //    for (int i = 0; i < 7; i++) {
    //                cout << a[i] << " ";
    //            }
    //    cout << endl;
    //    if(left < j)
    //        quicksort( a, left, j);
    //    if( i < right)
    //        quicksort( a,i, right);

    //}







//void QuickSort(int arr[], int l, int h)
//{
//    int pirot = arr[(l + h) / 2];
//    int i = l, j = h;
//    while (i <= j)
//    {
//        while (arr[i] < pirot)i++;
//        while (arr[j] > pirot)j--;
//        cout << i << " " << j<<endl;
//        if (i <= j)
//        {
//            swap(arr[i], arr[j]);
//            i++;
//            j--;
//        }
//    }
//    for (int i = 0; i < 7; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//    if (l < j)
//    {
//        QuickSort(arr, l, j);
//    }
//    if (i < h) QuickSort(arr, i, h);
//}
int main() {
    int arr[] = {30,25,40,10,15,50,20};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Mang sau khi sap xep: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
