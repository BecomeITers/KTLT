#include <iostream>
#include <vector>
using namespace std;
void Xuat(int n, vector<int>& B) {
	cout << "Do dai day con tang dai nhat la: " << endl; //Lưu ý đây ko phải là dãy con của số cho sẵn mà là độ dài của nó thôi
	for (int i = 0; i < B.size(); i++) {
		cout << B[i] << " ";
	}
}
int main(){
	int n;
	cout << "Nhap kich thuoc mang: ";
	cin >> n;
	vector<int>A(n);
	cout << "Nhap cac gia tri mang: " << endl;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	vector<int>B(n, 1); // Tạo mảng B với toàn số 1
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) { // Đi dò xem phần tử đằng sau A[i] có bé hơn A[i] ko
			if (A[i] > A[j]) {
				B[i] = max(B[i], B[j] + 1);
			}
		}
	}
	/*Quy trình
		1 3 2 8 4 5 A
	1 1 1 1 1 1 B Vòng lặp thứ 1
	1 2 1 1 1 1 B Vòng lặp thứ 2
	1 2 2 1 1 1 B Vòng lặp thứ 3
	1 2 2 3 1 1 B Vòng lặp thứ 4
	1 2 2 3 3 1 B Vòng lặp thứ 5
	1 2 2 3 3 4 B Vòng lặp thứ 6*/
	cout << "Do dai mang theo day tang dan la: " << *max_element(B.begin(), B.end()) << endl;
	Xuat(n, B);
}