/*
. Bài toán đổi tiền:
Có M loại tiền mệnh giá S1, S2, …, SM; số lượng mỗi loại không hạn chế. Cần xác định số cách đổi số tiền N đồng thành các tờ tiền trong M loại đã cho.
Ví dụ: N=4, M=3 và S = {1, 2, 3}. Có 4 cách đổi tiền: 4 tờ 1; 2 tờ 1 - 1 tờ 2; hai tờ 2; 1 tờ 1 - 1 tờ 3.
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {     
    int N, M;
    
    // N la so tien can doi
    // M la so menh gia tien 
    cin >> N >> M;
    vector<int> S(M);

    // nhap cac menh gia tien
    for (int i = 0; i < M; i++) {
        cin >> S[i]; 
    }
    vector<int> DP(N + 1);
    DP[0] = 1;
    for (int j = 0; j < M; j++) {
        for (int i = S[j]; i <= N; i++) {
            DP[i] += DP[i - S[j]];
        }
    }

    // Xuat ra so cach doi tien cua N
    cout << DP[N] << endl;
    return 0;
}