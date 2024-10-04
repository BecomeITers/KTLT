#include <iostream>
#define SIZE 100
using namespace std;
int n, k, A[SIZE];
void Xuat() {
	for (int i = 1; i <= k; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}
void LietKe(int i) {
	// i = 1: A[0] + 1 = 0 + 1= 1
	for (int j = A[i - 1] + 1; j <= n - k + i; j++) { // Điều kiện vòng lặp bắt buộv khi sinh tổ hợp chập k của n 
		A[i] = j;
		if (i == k) {
			Xuat();
		}
		else {
			LietKe(i + 1);
		}
	}
}
int main(){
	A[0] = 0;
	cout << "Nhap gia tri n: ";
	cin >> n;
	cout << "Nhap gia tri k: ";
	cin >> k;
	cout << "Sinh to hop chap k cua n phan tu la: " << endl;
	LietKe(1);
}