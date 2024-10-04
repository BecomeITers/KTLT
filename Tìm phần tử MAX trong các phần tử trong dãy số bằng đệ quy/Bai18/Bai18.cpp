#include <iostream>
using namespace std;
void DeQuy(int n, int &MAX) {
	if (n == 0) {
		return;
	}
	else {
		if (n % 10 > MAX) {
			MAX = n % 10;
		}
		DeQuy(n / 10, MAX);
	}
}
int main(){
	int n, MAX = 0;
	cout << "Nhap n: ";
	cin >> n;
	DeQuy(n, MAX);
	cout << "Phan tu lon nhat trong mang la: " << MAX;;
}
