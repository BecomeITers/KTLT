#include <iostream>
using namespace std;
bool LS(int n, int A[], int x) {
	for (int i = 0; i < n; i++) {
		if (x == A[i]) {
			return true;
		}
	}
	return false;
}
int main() {
	int n, x, A[100];
	cout << "Nhap kich thuoc mang: ";
	cin >> n;
	cout << "Nhap so tim kiem: ";
	cin >> x;
	cout << "Nhap gia tri mang: " << endl;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	if (LS(n, A, x)) {
		cout << "Da tim thay so do";
	}
	else {
		cout << "Ko tim thay so do trong mang";
	}
	return 0;
}