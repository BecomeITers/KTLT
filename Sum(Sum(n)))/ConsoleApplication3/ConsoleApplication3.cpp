#include <iostream>
#include <vector>
using namespace std;
vector <long long > A;
int Total(int n) {
	int total = 0;
	for (int i = 1; i <= n; i++) {
		total += i;
	}
	return total;
}
void Tinh(int n) {
	A.resize(n + 1);
	A[0] = 0;
	for (int i = 1; i <= n; i++) {
		A[i] = A[i - 1] + Total(i);
	}
}
int main(){
	int n;
	cin >> n;
	Tinh(n);
	cout << A[n];
}
