#include <iostream>
#include <string>
#define SIZE 100
using namespace std;
int main(){
	string X, Y;
	cout << "NHap chuoi X: ";
	getline(cin, X);
	cout << "Nhap chuoi Y: ";
	getline(cin, Y);
	int n = X.size(), m = Y.size();
	int dp[SIZE][SIZE];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {  // So sánh 2 chuỗi dựa trên mảng 2 chiều
			if (i == 0 || j == 0) { // Tạo mảng i = j là 0
				dp[i][j] = 0;
			}
			else {
				if (X[i - 1] == Y[j - 1]) { // Phần tử đầu tiên trong chuỗi ( i - 1 && j - 1 vì khi i = 1 thì X[0] là phần tử đầu tiên )
					dp[i][j] = dp[i - 1][j - 1] + 1; // Quy hoạch động
				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // Quy hoạch động
				}
			}
		}
	}
		cout << "Do dai chuoi xau chung lon nhat la: " << dp[n][m] << endl;
		cout << "Quy trinh: " << endl;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
	}