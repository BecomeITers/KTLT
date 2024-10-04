#include <iostream>
using namespace std;
int DeQuy(int n) {
	if (n == 0) {
		return 0;
	}
	else {
		return n % 10 + DeQuy(n/10);
	}
}
int main(){
	int n;
	cout << "Nhap n: ";
	cin >> n;
	int result = DeQuy(n);
	cout << "Tinh tong trong day so bang de quy la: " << result;
	return 0;
}