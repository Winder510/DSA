#include <iostream>
using namespace std;

//void insertionSort(int arr[], int n) {
//    int i, j, key;
//    for (int i = 1; i < n; i++)
//    {
//        int key = arr[i];
//        int j = i - 1;                                    
//        while (j >= 0 && key < arr[j])
//        {
//            arr[j + 1] = arr[j];
//            j--;
//        }
//        arr[j + 1] = key;
//    }
//}
//




void insertionSort(int a[],int n)
{
    int j, key;
    for (int i = 1; i < n; i++)
    {
        j = i - 1;
        key = a[i];
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}


int main() {
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
    // O(n^2)
}
