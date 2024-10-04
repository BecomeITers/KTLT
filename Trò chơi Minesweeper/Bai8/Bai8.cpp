#include <iostream>
#define MAX 100
using namespace std;
void ChuyenVi(int array[][MAX], int m, int n) {
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (array[i][j] == 1) { // Nếu trong mảng ta nhập là 1 chuyển nó sang 9 là mìn
				array[i][j] = 9;
			}
		}
	}
}
void DatMin(int array[][MAX], int m, int n) {
	ChuyenVi(array, m, n);
	int X[8] = { -1,0,1,1,1,0,-1,-1 }; // Kỹ thuật loang
	int Y[8] = { 1,1,1,0,-1,-1,-1,0 }; // Kỹ thuật loang
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (array[i][j] == 0) {
				for (int k = 0; k < 8; k++) {
					if (array[i + X[k]][j + Y[k]] == 9) {
						array[i][j]++;  //Đếm số mìn
					}
				}
			}
		}
	}
}
void Check(int array[][MAX], int m, int n) {
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (array[i][j] != 1 && array[i][j] != 0) {
				return;
			}
		}
	}
}
void Xuat(int array[][MAX], int m, int n) {
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cout << array[i][j];
		}
		cout << endl;
	}
}
int main(){
	int array[MAX][MAX], m, n;
	cout << "Nhap hang: ";
	cin >> m;
	cout << "Nhap cot: ";
	cin >> n;
	cout << "Nhap ma tran: ";
	cout << "\n";
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> array[i][j]; // Chỉ nhập số 1 và số 0
		}
	}
	Check(array, m, n);
	DatMin(array, m, n);
	cout << endl;
	cout << "Bang ma tran minesweeper la: ";
	cout << endl;
	Xuat(array, m, n);
	return 0;
}
