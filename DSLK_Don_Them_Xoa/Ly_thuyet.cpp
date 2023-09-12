/* GV hướng dẫn: Huỳnh Thị Thanh Thương
Thời gian: ngày 03.04.2023
Môn học: CTDL&GT
*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -

//Định nghĩa cấu trúc của Danh sách liên kết đơn

struct node
{
    int info;   //thành phần chứa dữ liệu của node,
    //nếu node chứa thông tin của 1 SV thì khai báo SV info,
    //chứa dữ liệu kiểu gì thì khai báo kiểu đó
    node* pNext;//con trỏ trỏ tới node kế tiếp
};
struct List
{
    node* pHead, * pTail; // 2 con trỏ quản lý phần tử đầu và cuối của danh sách
};
/*
Mục đích: Hàm tạo ra 1 node mới. Vì node mới là biến động, ko có tên nên cần 1 con trỏ để quản lý
Input: Giá trị sẽ được lưu vào node mới
Output: Con trỏ quản lý node mới vừa tạo
*/
node* getNode(int x)
{
    node* p = new node; //xin cấp phát bộ nhớ cho 1 biến động kiểu node (nói cách khác là tạo ra 1 node mới)
    if (p == NULL) //vì không phải lúc nào xin cấp phát bộ nhớ cũng thành công nên để cẩn thận hơn, ta xử lý cả ngoại lệ này
        cout << "Full memory";
    else
    {
        p->info = x; // đưa dữ liệu vào info
        p->pNext = NULL; // nếu con trỏ ko khởi tạo thì có thể trỏ đi lung tung và gây rối loạn chương trình, nên cần khởi tạo con trỏ NULL
    }
    return p;
}
/*
Mục đích: Thêm 1 phần tử vào đầu danh sách
Input: Danh sách cần phải xử lý và giá trị sẽ được thêm vào
Output: Danh sách đã được cập nhật. Không cần trả về giá trị nào cả
Lưu ý: vì L có sự thay đổi sau khi làm việc với hàm nên cần tham chiếu & để L trong hàm addHead và L trong hàm main là 1.
Khi L trong hàm thay đổi thì L trong main cũng thay đổi theo
*/
void addHead(List& L, int x) //
{
   /* Tạo 1 node mới bằng cách gọi hàm getNode, hàm này trả về con trỏ nên phải khai báo 1 con trỏ p để nhận kết quả
        if (danh sách rỗng)
            Cho 2 con trỏ head và tail trỏ về node mới, lúc này danh sách có 1 node duy nhất
        else
        { //SV vẽ hình để hiểu rõ cách thức làm việc
            Vì p sẽ đứng đầu(đứng trước) nên đuôi của p trỏ về node đầu hiện tại
                Cần phải cập nhật con trỏ head để chương trình hiểu node đầu mới là p
        }
        */
}
void addTail(List& L, int x)
{
    Tạo 1 node mới bằng cách gọi hàm getNode, hàm này trả về con trỏ nên phải khai báo 1 con trỏ p để nhận kết quả
        if (danh sách rỗng)//muốn biết ds rỗng hay không chỉ cần dựa vào head, không nhất thiết addTail phải dùng tail để kiểm tra
            Cho 2 con trỏ head và tail trỏ về node mới, lúc này danh sách có 1 node duy nhất
        else
        { //SV vẽ hình để hiểu rõ cách thức làm việc

            Vì p sẽ đứng cuối(đứng sau) nên đuôi của node cuối(lúc này đang được tail quản lý) trỏ về p
                Cần phải cập nhật con trỏ tail để chương trình hiểu node cuối mới là p
        }
}
/*
Mục đích: Tìm vị trí đầu tiên mà số a xuất hiện trong danh sách,
sau đó thêm số b vào sau số này. Nếu số a không có trong danh sách, thêm b vào đầu danh sách
Input:
- Danh sách cần phải xử lý,
- 2 giá trị a và b
Output: Danh sách đã được cập nhật. Không cần trả về giá trị nào cả
Lưu ý: vì L có sự thay đổi sau khi làm việc với hàm nên cần tham chiếu & L
*/
void addAfter(List& L, int a, int b)
{
    node* k = searchEle(L, a);//Gọi hàm tìm kiếm a có trong L hay không,
    //kết quả trả về con trỏ trỏ tới node tìm thấy a, nếu không thấy thì k là NULL

    if (không tìm thấy a) Gọi hàm thêm b vào đầu ds
    else //tìm thấy a tại node được quản lý bởi k
    {
        Tạo 1 node mới bằng cách gọi hàm getNode, hàm này trả về con trỏ nên phải khai báo 1 con trỏ p để nhận kết quả
            //SV vẽ hình để hiểu rõ cách thức làm việc
            Đuôi của p trỏ về node đằng sau k
            Đuôi của node được quản lý bởi k trỏ về p
            //Xử lý ngoại lệ
            if (k là ở node cuối)// thì sau khi thêm node mới vào sau k thì node mới trở thành node cuối mới
                Cập nhật con trỏ tail trỏ về node cuối mới
    }
}
int main()
{
    List L; // Khai bao 1 danh sach
    Init(L); // Khoi tao danh sach bằng cách cho 2 con trỏ là NULL, nếu ko khởi tạo thì các con trỏ trỏ đi lung tung
    while (1) //vì đề ko cho biết số lượng phần tử n nên dùng while
    {
        /*Vì mỗi 1 dòng trong input có 2 số, tùy theo số đầu tiên là gì mà ta thực hiện thao tác tương ứng
        nên nhập số đầu trước rồi kiểm tra ngay luôn */
        cin >> x;
        if (x == 3) break;
        else  if (x == 0)
        {
            cin >> y;
            Gọi hàm thêm y vào đầu danh sách
        }
        else  if (x == 1)
        {
            cin >> y;
            Gọi hàm thêm y vào cuối danh sách
        }
        else if (x == 2)
        {
            cin >> y >> z;
            Gọi hàm thêm z vào sau y.
        }
        //SV CÓ THỂ DÙNG switch ...case cho gọn chương trình hơn
    }
    Xuất danh sách bằng cách cho 1 con trỏ p chạy lần lượt qua các phần tử, nếu p = NULL thì duyệt hết ds
        Muốn p chạy qua node đế tiếp thì p = p->next

}


/*----------------------------------------------------------------------------------------------------------------------------------------------------------*/


/* GV hướng dẫn: Huỳnh Thị Thanh Thương
Thời gian: ngày 03.04.2023
Môn học: CTDL&GT
*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -


/*
Mục đích: Xóa phần tử đầu tiên ra khỏi danh sách
Input:
- Danh sách cần phải xử lý
Output:
- Danh sách đã được cập nhật. Không cần trả về giá trị nào cả
Lưu ý:
- Xử lý các ngoại lệ sau: 1) Danh sách rỗng; 2) Xóa phần tử duy nhất trong DS thì DS trở nên rỗng

*/
void deleteHead(List& L)
{
    if (danh sách rỗng) return;   // Xử lý ngoại lê 1: Khi DS rỗng thì không làm gì cả, ko có node nào để xóa;
    //return mà ko có gì phía sau thì có nghĩa là kết thúc hàm
    Muốn xóa node nào thì tạo con trỏ p quản lý node đó
        Xóa node đầu thì node thứ 2 trở thành node đầu mới, phải cập nhật head
        Trước khi xóa node tại p thì cần cắt đứt mọi liên kết giữa node đó với các node khác, kẻo xóa dây chuyền
        delete p; //giải phóng vùng nhớ của node mà p trỏ tới (tức là xóa xong)
    /*  Xử lý  ngoại lệ 2: Nếu DS có 1 node duy nhất thì sau khi xóa, DS trở nên rỗng,
        head đã cập nhật về NULL bởi xử lý phía trên rồi
        còn tail thì chưa nên phải cập nhật luôn
    */
    if (ds trở nên rỗng)
        cập nhật tail cũng là NULL
}
/*
Mục đích: Xóa phần tử chứa giá trị x xuất hiện đầu tiên ra khỏi danh sách
Input:
- Danh sách cần phải xử lý
- Giá trị cần tìm và xóa
Output:
- Danh sách đã được cập nhật. Không cần trả về giá trị nào cả
Lưu ý: Xử lý các ngoại lệ sau:
1) Danh sách rỗng;
2) Không có x trong DS;
3) x là node đầu; gọi deleleHead
4) x là node cuối, sau khi xóa xong phải cập nhật node cuối mới
Có thể nghĩ đến 1 ngoại lệ khác là: Nếu xóa 1 node duy nhất thì ds trở nên rỗng,
tuy nhiên node duy nhất đó cũng là node đầu nên đã được xử lý trong khi hàm deleleHead

*/
void deleteEle(List& L, int x)
{
    if (danh sách rỗng) return;   // Xử lý ngoại lê 1:  DS rỗng thì không làm gì cả, ko có node nào để xóa
    /*Đầu tiên, cần phải tìm node chứa x
    Nếu tìm được con trỏ p trỏ tới node chứa x thì khi xóa node x, cần phải tạo kết nối từ node trước x tới node sau x
    Mà node trước x không có cách nào gọi ra được, nên cần dùng 1 kỹ thuật hỗ trợ đặc biệt:
    Trong quá trình cho p chạy qua các phần tử, cần có thêm 1 con trỏ khác chạy đồng hành cùng với p, gọi là k
    p chạy tới đâu thì k chạy theo sau đó, tuy nhiên phải luôn đảm bảo p chạy trước, k chạy liền kề phía sau
    */
    node* p = L.pHead, * k = NULL;       // vì k luôn đứng trước p nên khi p tại head thì k phải là NULL
    while (p còn chạy trong ds)
    {
        if (tìm thấy x) thì dừng vòng lặp
            k = p;                        // trước khi p chạy qua node kế tiếp thì cho k chạy tới p
        p = p->pNext;
    }
    if (không tìm thấy x)  return;   // Xử lý ngoại lê 2: ko tìm thấy x thì ko xóa, ko làm gì cả
    /*Chương trình chạy tới dòng lệnh này tức là p!=NULL, đã tìm thấy x tại p
    Tiến hành thủ tục xóa x
    */
    if (x là node đầu)                  // Xử lý ngoại lê 3: Xóa node đầu chứa x
        gọi hàm xóa node đầu
    else
    {
        Tạo kết nối từ node trước p là k tới node sau p là p->next
            Trước khi xóa node thì cần cắt đứt mọi liên kết giữa node đó với các node khác, kẻo xóa dây chuyền
            delete p;
        if (x là node cuối)              //Xử lý ngoại lê 4: x hay p là node cuối, sau khi xóa xong phải cập nhật node cuối mới là k
            cập nhật tail

    }

}
int main()
{
    List L;             // Khai bao 1 danh sach
    Init(L);            // Khoi tao danh sach bằng cách cho 2 con trỏ là NULL, nếu ko khởi tạo thì các con trỏ trỏ đi lung tung
    int x, y, z;
    while (1)           //vì đề ko cho biết số lượng phần tử n nên dùng while
    {
        /*Vì mỗi 1 dòng trong input có 1-3 số, tùy theo số đầu tiên là gì mà ta thực hiện thao tác tương ứng
        nên nhập số đầu trước rồi kiểm tra ngay luôn */
        cin >> x;
        if (x == 6) break;
        switch (x)
        {
        case 0:
        {   cin >> y;
        addHead(L, y);//Gọi hàm thêm y vào đầu danh sách
        break;
        }
        case 1:
        {   cin >> y;
        addTail(L, y);//Gọi hàm thêm y vào cuối danh sách
        break;
        }
        case 2:
        {   cin >> y >> z;
        addAfter(L, y, z);//Gọi hàm thêm z vào sau y.
        break;
        }
        case 3:
        {   cin >> y;
        deleteEle(L, y);
        break;
        }
        case 5:
        {   deleteHead(L);
        break;
        }

        }


    }
    if (L.pHead == NULL) cout << "blank";
    else
    {
        /*Xuất danh sách bằng cách cho 1 con trỏ p chạy lần lượt qua các phần tử,
        nếu p =NULL thì duyệt hết ds
        Muốn p chạy qua node kế tiếp thì p=p->next*/

    }



}