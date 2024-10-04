#include <iostream>
using namespace std;
bool ktsoam(int a[], int n) {
	int i = 0; 
	a[n] = 1;
	while (a[i] < 0) {
		i++;
	}
	return (i >= n);
}
int main(){
	int n;
	cin >> n;
	int a[100];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (ktsoam(a,n)) {
		cout << "Mang co chua toan so am";
	}
	else {
		cout << "Mang co so duong";
	}
	return 0;
}
