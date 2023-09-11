/*
Định nghĩa cấu trúc dữ liệu lưu trữ thông tin máy
tính gồm: nhãn hiệu máy, tốc độ xử lý (tính theo
GHz) và giá bán. Cài đặt các hàm sau
a)sortByName(…) Sắp xếp danh sách máy theo thứ
tự tăng dần đối với nhãn hiệu
b)sortBySpeed(…) Sắp xếp danh sách máy theo thứ
tự giảm dần đối với tốc độ xử lý
c)sort(…) Sắp xếp danh sách máy theo thứ tự tăng
dần giá bán và trong trường hợp cùng giá thì xếp
theo thứ tự giảm dần tốc độ xử lý
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct infor
{
	string brand;
	double processing_speed;
	double price;
};
typedef struct infor infor;
void sortByName(vector<infor> &computer)
{
	sort(computer.begin(), computer.end(), [](const infor c1, const infor& c2)
		{
			return c1.brand < c2.brand;
		});
}
void sortBySpeed(vector<infor>& computer)
{
	sort(computer.begin(), computer.end(), [](const infor& c1, const infor& c2)
		{
			return c1.processing_speed < c1.processing_speed;
		});
}
void sort(vector<infor>& computer)
{
	sort(computer.begin(), computer.end(), [](const infor& c1, const infor& c2)
		{
			if (c1.price != c2.price)
				return c1.price < c2.price;
			else
				return c1.processing_speed > c2.processing_speed;

		});
}
int main()
{
	vector<infor> computers = {
		{"Dell", 3.2, 1200},
		{"Lenovo", 3.5, 1500},
		{"Apple", 3.6, 2000},
		{"Asus", 2.8, 1200},
		{"HP", 3.1, 900}
	};
	sort(computers);
	for (int i = 0; i < computers.size(); i++)
		cout << computers[i].brand;
}