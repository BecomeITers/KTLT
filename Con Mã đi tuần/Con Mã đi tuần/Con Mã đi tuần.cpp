#include <iostream>
#include <cstdlib>
#define SIZE 15
using namespace std;
int n = 6, A[SIZE][SIZE] = { 0 }, dem = 0;
int X[8] = { -2,-2,-1,1,2,2,1,-1 };
int Y[8] = { -1,1,2,2,1,-1,-2,-2 };
void Xuat() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}
void DiTuan(int x, int y) {
	dem++;
	A[x][y] = dem;
	if (dem == n * n) {
		Xuat();
		exit(0);
	}
	for (int i = 0; i < 8; i++) {
		int xx = X[i] + x;
		int yy = Y[i] + y;
		if (xx >= 0 && xx < n && yy >= 0 && yy < n && A[xx][yy] == 0) {
			DiTuan(xx, yy);
		}
	}
	dem--;
	A[x][y] = 0;
}
int main(){
	int x, y;
	cout << "Nhap vi tri bat dau: " << "\n";
	cin >> x >> y;
	cout << "Dap an cua con Ma di tuan la: " << "\n";
	DiTuan(x, y);
}
