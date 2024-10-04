#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int>& A, int l, int r) {
	int pivot = A[r]; // Đặt điểm đánh dấu ở phần tử cuối cùng
	int i = l - 1; // Vị trí tại bên trái ngoài cùng
	for (int j = l; j < r; j++) { // Từ trái đến phải
		if (A[j] <= pivot) { // Nếu phần tử bé hơn đánh dấu
			i++;    // Tăng vị trí
			swap(A[i], A[j]);  // Đổi phần tử ở vị trí i và vị trí j
		}
	}
	// Đặt pivot ở giữa 
	i++;
	swap(A[i], A[r]);
	return i;    // Đi tìm vị trí nằm giữa 
}
void QuickSort(vector<int>& A, int l, int r) {
	if (l >= r) {
		return;
	}
	else {
		int p = partition(A, l, r); // Đi tìm vị trí ở giữa 1 bên là lớn hơn pivot và bé hơn pivot
		QuickSort(A, l, p - 1); // Sắp xếp tăng dần ở bên trái
		QuickSort(A, p + 1, r); // Sắp xếp tăng dần ở bên phải
	}
}
int main() {
	int n;
	cout << "Nhap gia tri mang: ";
	cin >> n;
	vector<int>A(n);
	cout << "Nhap gia tri: " << endl;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	cout << "Ket qua sap xep tang dan la: " << endl;
	QuickSort(A, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
}
