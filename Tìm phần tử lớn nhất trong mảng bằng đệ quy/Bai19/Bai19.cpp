#include <iostream>
#define MAX 100
using namespace std;
void Nhap(int array[], int& n) {
	cout << "Nhap n: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}
}
int TimMax(int array[], int n) {
	if (n == 1) {
		return array[0];
	}
	else {
		int x = TimMax(array, n - 1);
		if (array[n - 1] > x) {
			return array[n - 1];
		}
		else {
			return x;
		}
	}
}
int main(){
	int array[MAX], n;
	Nhap(array, n);
	int result = TimMax(array, n);
	cout << result;
}
