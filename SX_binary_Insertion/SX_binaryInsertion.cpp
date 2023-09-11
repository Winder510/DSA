#include <iostream>
using namespace std;

// Binary search to find the correct position for insertion
int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return left;
}

// Binary Insertion Sort function
void binaryInsertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        // Find the correct position for insertion using binary search
        int insertPos = binarySearch(arr, 0, j, key);

        // Shift elements to the right to make space for the key
        while (j >= insertPos) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert the key at the correct position
        arr[j + 1] = key;
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);

    binaryInsertionSort(arr, size);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}
