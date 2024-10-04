#include <iostream>
#include <vector>
using namespace std;
int n, a[100], b[100] = { 0 };
void Xuat() {
	for (int i = 0; i < n; i++) {
		cout << a[i];
	}
	cout << endl;
}
void LietKe(int k) {
	if (k == n) {	
		Xuat();
	}
	else {
		for (int i = 0; i < n; i++) {
			if (b[i] == 0) { // Ta tạo thêm 1 mảng B để kiểm soát trong mảng A có số bị vòng lặp ko
				a[k] = i; 
				b[i] = 1; // khi ta thêm 1 số vào mảng A thì đồng thời vị trí ở mảng B sẽ chuyển thành số 1 tránh trường hợp trùng
				LietKe(k + 1);
				b[i] = 0; // Sau khi chạy đệ quy ta muốn chuyển đổi vị trí để tạo 1 mảng số khác vì ta phải gắn lại vị trí mảng B = 0
			}
		}
	}
}
int main() {
	cout << "Nhap gia tri n: ";
	cin >> n;
	cout << "Liet ke cac day hoan vi la: " << endl;
	LietKe(0);
}
