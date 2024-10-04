#include <iostream>
#define SIZE 100
using namespace std;
void Xuat(int n, int A[]) {
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}
void DoiCho(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}
void LatNguoc(int A[], int x, int y) {
	while (x < y) {
		DoiCho(A[x], A[y]);
		x++;
		y--;
	}
}
void HoanVi(int n, int A[]) {
	for (int i = 0; i < n; i++) {
		A[i] = i;
	}
	Xuat(n, A);
	do {
		int k = n - 2;
		while (k >= 0 && A[k] > A[k + 1]) {
			k--;
		}
		if (k < 0) {
			break;
		}
		int l = n - 1;
		while (A[l] < A[k]) {
			l--;
		}
		DoiCho(A[k], A[l]);
		LatNguoc(A, k + 1, n - 1);
		Xuat(n, A);
	} while (true);
}
int main(){
	int n, A[SIZE];
	cout << "Nhap gia tri n: ";
	cin >> n;
	cout << "Cac day sinh hoan vi la: " << endl;
	HoanVi(n, A);
}