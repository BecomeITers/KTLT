#include <iostream>
using namespace std;
// Cách làm ko dùng đệ quy	
bool BS(int A[], int n, int x) {
	int l = 0, r = n - 1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (A[m] == x) {
			return true;  
		}
		else if (A[m] < x) {
			l = m + 1; // Bắt đầu từ mảng bên phải
		}
		else {
			r = m - 1; // Bắt đầu từ mảng bên trái
		}
	}
	return false;
}
// Cách làm dùng đệ quy
bool DeQuy(int A[], int l, int x, int r) {
	if (l > r) {
		return false;
	}
	int m = (l + r) / 2;
	if (A[m] == x) {
		return true;
	}
	else if (A[m] < x) {
		return DeQuy(A, m + 1, x, r);
	}
	else {
		return DeQuy(A, l, x, m - 1);
	}
}
int main(){
	int n, x, A[100];
	cout << "Nhap kich thuoc mang: ";
	cin >> n;
	cout << "Nhap so tim kiem: ";
	cin >> x;
	cout << "Nhap cac gia tri: " << endl;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	/*if (BS(A, n, x)) {
		cout << "Da tim thay so do";
	}
	else {
		cout << "Ko co so do trong mang";
	}*/
	int l = 0, r = n - 1;
	if (DeQuy(A,l,x,r)) {
		cout << "Da tim thay so do";
	}
	else {
		cout << "Ko co so do trong mang";
	}
	return 0;
}