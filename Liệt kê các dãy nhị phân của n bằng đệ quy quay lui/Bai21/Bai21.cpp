#include <iostream>
using namespace std;
int n, a[100]; // Đặt 2 biến ở ngoài đỡ phải gọi trong function
void Xuat() {
    cout << "Liet ke cac day nhi phan la: " << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
void LietKe(int k) {
    if (k == n) {
        Xuat();
    }
    else {
        for (int i = 0; i <= 1; i++) {
            a[k] = i;
            LietKe(k + 1);
        }
    }
}
int main(){
    cout << "Nhap gia tri n: ";
    cin >> n;
    LietKe(0); // Chạy khi phần tử mảng ban đầu là 0
}
//SƠ ĐỒ (khi n = 2): 
//Khi a[0] = 0 thì LietKe(1)
//LietKe(1) => a[1] = 0 thì LietKe(2) = > Xuat()
//LietKe(1) => a[1] = 1 thì LietKe(2) = > Xuat()
//Khi a[0] = 1 thì LietKe(1)
//LietKe(1) => a[1] = 0 thì LietKe(2) = > Xuat()
//LietKe(1) => a[1] = 1 thì LietKe(2) = > Xuat()

