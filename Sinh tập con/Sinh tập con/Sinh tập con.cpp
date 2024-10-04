#include <iostream>
#define SIZE 10
using namespace std;
int A[SIZE];
void Xuat(int k) {
	for (int i = 0; i < k; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}
void SinhTapCon(int n) {
	int k = 0;
	Xuat(k); // Xuất ra 0
	int i = 0;
	A[0] = 0;
	k = 1; // Đặt tại k = 1 để xuất ra được 2 số
	do {
		Xuat(k);   
		if (A[i] < n - 1) {
			A[i + 1] = A[i] + 1;
			i++;
			k++;
		}
		else {
			if (i == 0) {
				break;
			}
				i--;
				k--;
				A[i]++;
		}
	} while (true);
}
int main(){
	int n;
	cout << "Nhap gia tri n: ";
	cin >> n;
	cout << "Cac day tap con tu 0 den n - 1 la: ";
	SinhTapCon(n);
}
