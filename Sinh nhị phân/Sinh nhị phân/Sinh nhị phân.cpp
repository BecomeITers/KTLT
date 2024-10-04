#include <iostream>
#define SIZE 100
using namespace std;
void Xuat(int n, int A[]) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}
void NhiPhan(int n, int A[]) {
    int i;
    do {
        i = n - 1;
        Xuat(n, A);
        while (i >= 0 && A[i] == 1) {
            A[i] = 0;
            i--;
        }
        if (A[i] >= 0) {
            A[i] = 1;
        }
    } while (i >= 0);
}
int main(){
    int A[SIZE] = { 0 };
    int n;
    cout << "Nhap gia tri n: ";
    cin >> n;
    cout << "Day nhi phan cua n la: " << endl;
    NhiPhan(n, A);
}