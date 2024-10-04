#include <iostream>
#define SIZE 100
using namespace std;
int n, A[SIZE][SIZE] = { 0 };
int d1[100], d2[100], cot[100], dem = 0;
void Xuat() {
    cout << "Phuong an thu " << dem++ << " la:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
void Try(int i) { // i là hàng
    for (int j = 0; j < n; j++) { // j là cột
        if (d1[i - j + n] == 0 && d2[i + j] == 0 && cot[j] == 0) { // Kiểm tra xem đường chéo xuôi và ngược và cột đã bị chặn bởi con hậu khác chưa
            A[i][j] = 1; // Ta đặt con hậu tại vị trí là 1
            // i - j + n là vị trí của đường chéo xuôi
            // i + j là vị trí của đường chéo ngược
            d1[i - j + n] = d2[i + j] = cot[j] = 1; // Sau đó ta sẽ đặt những ô đường chéo xuôi, ngược và cột là đã bị chặn
            if (i == n - 1) {
                Xuat();
            }
            else {
                Try(i + 1); // Đệ quy thuật toán quay lui
            }
            //backtrack
            A[i][j] = 0;
            d1[i - j + n] = d2[i + j] = cot[j] = 0;
        }
    }
}
int main() {
    cout << "Nhap n: ";
    cin >> n;
    Try(0);
    return 0;
}
