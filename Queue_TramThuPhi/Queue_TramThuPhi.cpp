#include <iostream>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <thread>  // Thư viện cho phép điều khiển luồng
#include <chrono> 

// Cấu trúc dữ liệu của một xe
struct Vehicle {
    int type;  // Loại xe (1: ôtô nhỏ, 2: ôtô trung bình, 3: ôtô lớn, 4: ôtô hạng nặng)
    int weight;  // Trọng lượng xe (tấn)
};

// Hằng số định nghĩa phí qua trạm
const int SMALL_CAR_FEE = 5000;
const int MEDIUM_CAR_FEE = 10000;
const int LARGE_CAR_FEE = 15000;
const int HEAVY_CAR_FEE = 20000;

// Hằng số định nghĩa thời gian thông xe qua trạm
const int SMALL_CAR_TIME = 10;
const int MEDIUM_CAR_TIME = 10;
const int LARGE_CAR_TIME = 15;
const int HEAVY_CAR_TIME = 15;

// Hằng số định nghĩa số cổng trạm
const int NUM_GATES = 4;

int main() {
    std::queue<Vehicle> gates[NUM_GATES];  // Mảng hàng đợi đại diện cho các cổng trạm thu phí
    int totalRevenue = 0;  // Tổng số tiền thu được của tất cả các cổng
    srand(time(0));  // Khởi tạo bộ sinh số ngẫu nhiên

    // Thực hiện mô phỏng hoạt động của trạm thu phí trong một khoảng thời gian
    for (int i = 0; i < 100; i++) {  // Giả sử mô phỏng trong 100 lượt xe qua trạm
        // Tạo một xe ngẫu nhiên
        Vehicle vehicle;
        vehicle.type = rand() % 4 + 1;  // Chọn ngẫu nhiên loại xe từ 1 đến 4

        // Đưa xe vào hàng đợi của cổng có ít xe nhất
        int minQueueSize = gates[0].size();
        int minQueueIndex = 0;
        for (int j = 1; j < NUM_GATES; j++) {
            if (gates[j].size() < minQueueSize) {
                minQueueSize = gates[j].size();
                minQueueIndex = j;
            }
        }
        gates[minQueueIndex].push(vehicle);

        // Thông báo xe đã vào hàng đợi
        std::cout << "Xe vao hang doi tai cong " << minQueueIndex + 1 << std::endl;
    }

    // Xử lý từng xe trong hàng đợi của các cổng
    for (int i = 0; i < NUM_GATES; i++) {
        while (!gates[i].empty()) {
            // Lấy xe ra khỏi hàng đợi
            Vehicle vehicle = gates[i].front();
            gates[i].pop();
            // Xử lý xe và tính toán phí thu
            int fee = 0;
            int time = 0;
            switch (vehicle.type) {
            case 1:
                fee = SMALL_CAR_FEE;
                time = SMALL_CAR_TIME;
                break;
            case 2:
                fee = MEDIUM_CAR_FEE;
                time = MEDIUM_CAR_TIME;
                break;
            case 3:
                fee = LARGE_CAR_FEE;
                time = LARGE_CAR_TIME;
                break;
            case 4:
                fee = HEAVY_CAR_FEE;
                time = HEAVY_CAR_TIME;
                break;
            }

            // Cập nhật tổng số tiền thu được
            totalRevenue += fee;

            // Thông báo xe đã qua trạm
            std::cout << "Xe qua trạm " << i + 1 << " - Loại xe: " << vehicle.type << " - Phí: " << fee << std::endl;

            // Simulate thời gian thông xe
            std::this_thread::sleep_for(std::chrono::seconds(time));
        }
    }

    // Hiển thị số lượng xe qua trạm và tổng số tiền thu được
    for (int i = 0; i < NUM_GATES; i++) {
        std::cout << "Cổng " << i + 1 << ": " << gates[i].size() << " xe" << std::endl;
    }
    std::cout << "Tổng số tiền thu được: " << totalRevenue << " đồng" << std::endl;

    return 0;
}   
