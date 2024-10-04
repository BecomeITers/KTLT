#include <iostream>
#define MAX 100
using namespace std;
void Nhap(int array[][MAX], int& m, int& n) {
	cout << "Nhap so dong: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	cout << "Nhap ma tran: " << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> array[i][j];
		}
	}
}
void ChuyenDoi(int array[][MAX], int m, int n, int haha[]) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int index = i * n + j;
			haha[index] = array[i][j];
		}
	}
}
void Xuat(int haha[], int size) {
	for (int i = 0; i < size; i++) {
		cout << haha[i] << " ";
	}
}
int main(){
	int array[MAX][MAX], m, n, haha[10000];
	Nhap(array, m, n);
	int size = m * n;
	ChuyenDoi(array, m, n, haha);
	cout << "Mang 2 chieu sang mang 1 chieu la: " << endl;
	Xuat(haha, size);
	return 0;
}
