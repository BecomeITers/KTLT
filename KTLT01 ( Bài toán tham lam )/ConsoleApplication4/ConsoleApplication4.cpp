#include <iostream>
#include <algorithm>
#define ll long long
const int N = 1e5 + 5;
using namespace std;
bool SapXep(int first, int second) {
	return first > second;
}
int main() {
	int A[N];
	int n; cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	sort(A, A + n, SapXep);
	ll result = 0;
	for (int i = 0; i < n; i++) {
		result += A[i];
	}
	for (int i = 2; i < n; i +=3 ) {
		result -= A[i];
	}
	cout << result;
}