#include <iostream>
#define SIZE 100
using namespace std;
int A[SIZE];
int BS1(int n, int x) {
	int l = 0, r = n - 1;
	int res = -1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (A[m] == x) {
			res = m;
			r = m - 1;
		}
		else if (A[m] < x) {
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	return res;
}
int BS2(int n, int x) {
	int l = 0, r = n - 1;
	int res = -1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (A[m] == x) {
			res = m;
			l = m + 1;
		}      
		else if (A[m] < x) {
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	return res;
}
//BS2 sai test case 1 2 2 5 2 :V
int main(){
	int n, x;
	cout << "Nhap kich thuoc mang: ";
	cin >> n;
	cout << "Nhap gia tri tim kiem: ";
	cin >> x;
	cout << "Nhap gia tri cac mang: " << endl;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	cout << "Phan tu dau tien tim thay trong mang la: " << BS1(n, x) << endl;
	cout << "Phan tu cuoi tim thay trong mang la: " << BS2(n, x);
	return 0;
}