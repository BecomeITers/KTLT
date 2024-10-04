#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int>A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	vector<int>dp(n);
	for (int i = 0; i < n; i++) {
		dp[i] = A[i];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (A[j] > A[i]) { // Điều kiện dãy ko tăng 
				dp[i] = max(dp[i], dp[j] + A[i]); // Cộng dãy ko tăng 
			}
		}
	}
	int max_sum = dp[0];
	for (int i = 0; i < n; i++) {
		max_sum = max(max_sum, dp[i]);
	}
	cout << max_sum;
}