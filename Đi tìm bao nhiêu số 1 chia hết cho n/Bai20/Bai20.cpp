#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Nhap gia tri n: ";
    cin >> n;
    int dem = 1;
    int kq = 1;
    while (kq % n != 0) {
        kq = (kq * 10 + 1) % n;
        dem++;
    }
    cout << "Vay co " << dem << " so 1 chia het cho " << n;
}
