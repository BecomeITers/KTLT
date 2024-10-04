#include <iostream>
#define SIZE 100
using namespace std;
int A[SIZE];
void SapXep(int n) {
	for (int i = 1; i < n; i++) {
		int key = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > key) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;
	}
}
int main() {
	int n;
	cout << "Nhap kich thuoc mang: ";
	cin >> n;
	cout << "Nhap gia tri mang: " << endl;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	SapXep(n);
	cout << "Ket qua sau khi sap xep la: " << endl;
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	return 0;
}
