#include <iostream>
#include <queue>
#include <string>
#include <conio.h>
#include <windows.h> // Thư viện để sử dụng hàm sleep()

using namespace std;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void SetColor(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}
void ShowCur(bool CursorVisibility)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
    SetConsoleCursorInfo(handle, &cursor);
}
int main() {
    queue<char> textQueue;
    string text = "     HeLLo World    ";

    // Thêm các ký tự vào hàng đợi
    for (int i = 0; i < text.length(); i++) {
        textQueue.push(text[i]);
    }
    int x=0, y=13;
    
    while (true) {
         ShowCur(0);  
         //system("cls");// Xóa màn hình để in ra vị trí mới của dòng chữ   
         SetColor(0,2);
         // In ra dòng chữ hiện tại

        gotoxy(40,12);
        queue<char> tempQueue = textQueue;
        while (!tempQueue.empty()) {
            cout << tempQueue.front();
            tempQueue.pop();
        }

        // Thay đổi vị trí của các ký tự trong hàng đợi
        char tempChar = textQueue.front();
        textQueue.pop();
        textQueue.push(tempChar);
        
        if (_kbhit()) { // Kiểm tra xem người dùng đã nhấn phím gì chưa
            char key = _getch();
            if (key == 'q') { // Nếu nhấn phím q thì thoát khỏi chương trình
                break;
            }
        }
        Sleep(100); // Tạm dừng 100ms để tạo hiệu ứng chạy
    }

    return 0;
}
