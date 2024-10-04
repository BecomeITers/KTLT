#include <iostream>
#include <cstring>
#define SIZE 100
using namespace std;
void Nhap(int& n, int& S, int w[], int v[]) {
	cout << "Nhap so luong vat: ";
	cin >> n;
	cout << "Nhap gioi han cua ba lo: ";
	cin >> S;
	cout << "Nhap can nang cua vat: " << endl;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	cout << "Nhap gia tri cua vat: " << endl;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
}
int main() {
	int n, S;
	int w[SIZE], v[SIZE];
	int dp[SIZE][SIZE];
	Nhap(n, S, w, v);
	memset(dp, 0, sizeof(dp)); // Tạo mảng 2 chiều dp đều bằng 0
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= S; j++) {
			dp[i][j] = dp[i - 1][j]; // Không lựa chọn vật thứ i vào trong balo 
			if (j >= w[i]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);  // Có thể đưa vật thứ i vào trong balo
			}
		}
	}
	/*
	Quy trình:
	Vd: w = {2 ,1, 4, 3}
		v = {3, 3, 4, 2}
		  1 2 3 4 5 6
	   1  0 3 3 3 3 3
	   2  3 3 6 6 6 6
	   3  3 3 6 6 7 7
	   4  3 3 6 6 7 8

	*/
	cout << "Tong gia tri lon nhat ma ba lo co the chiu tai: " << dp[n][S] << endl;
	cout << "In ra quy trinh: " << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= S; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}