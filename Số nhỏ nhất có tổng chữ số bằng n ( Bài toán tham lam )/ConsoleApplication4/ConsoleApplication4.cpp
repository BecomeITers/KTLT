#include <iostream>
using namespace std;
int main() {
	// Ưu tiên chiều dài nhỏ nhất thì sử dụng nhiều số 9 nhất có thể
	int n; cin >> n;
	cout << "So nho nhat co tong chu so bang n la: ";
	if (n % 9 != 0) {
		cout << n % 9;
	}
	for (int i = 1; i <= n / 9; i++) {
		cout << 9;
	}
}