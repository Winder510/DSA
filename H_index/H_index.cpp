#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n; // số lượng bài báo
    cin >> n;
    int* a= new int[n]; // mảng chứa số lượng trích dẫn của các bài báo
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n, [](int a, int b) {
        return a > b;
        }); // sắp xếp mảng giảm dần
   
    int hIndex = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= i + 1) {
            hIndex = i + 1;
        }
        else {
            break;
        }
    }
    cout << hIndex << endl; // in ra giá trị h-index

    delete[]a;
    return 0;
}
