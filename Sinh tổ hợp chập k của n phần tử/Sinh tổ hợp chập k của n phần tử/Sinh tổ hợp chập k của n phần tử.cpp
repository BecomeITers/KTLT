#include <iostream>
#define SIZE 10
using namespace std;
int A[SIZE], dem = 1;
void Xuat(int k) {
	for (int i = 0; i < k; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}
void ToHop(int n, int k) {
	Xuat(k);
	do {
		int i = k; 
		while (i > 0 && A[i - 1] == n - k + i) { // Kiểm tra xem phần tử cuối cùng có đạt giá trị cao nhất chưa
			i--;
		}
		if (i == 0) { // Nếu các phần tử đã đạt đến dãy cuối cùng thì thoát khỏi vòng lặp
			break;
		}
		else {
			A[i - 1]++; // Nếu giá trị chưa đạt tới giá trị cao thì tăng giá trị cuối +1
			for (int j = i; j < k; j++) {
				A[j] = A[j - 1] + 1; // Các phần tử phía sau tăng thêm 1
			}
			Xuat(k);
			dem++;
		}
	} while (true);
}
int main(){
	int n, k;
	cout << "Nhap gia tri n: ";
	cin >> n;
	cout << "Nhap gia tri k: ";
	cin >> k;
	for (int i = 0; i < k; i++) {
		A[i] = i;
	}
	cout << "Cac day tap con cua to hop chap k cua n la: " << endl;
	ToHop(n, k);
	cout << "Vay co " << dem << " tap con";
}