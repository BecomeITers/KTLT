#include <iostream>
using namespace std;
int DeQuy(int a, int b) {
	if (b == 0) {
		return 1;
	}
	else {
		return a * DeQuy(a, b - 1);
	}
}
int main(){
	int a, b;
	cout << "Nhap a: ";
	cin >> a;
	cout << "Nhap b: ";
	cin >> b;
	cout << "Ket qua luy thua sau khi dung de quy la: ";
	int result = DeQuy(a, b);
	cout << result;
}
