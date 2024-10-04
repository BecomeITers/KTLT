#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n, S;
	cout << "Nhap kich thuoc mang: ";
	cin >> n;
	cout << "Nhap so: ";
	cin >> S;
	cout << "Nhap gia tri mang: " << endl;
	vector<int>A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	vector<bool> dp(S + 1, false); // Cho mảng dp ban đầu là false hết
	dp[0] = true; // Đặt giá trị đầu tiên mảng dp là true
	for (int i = 0; i < n; i++) {
		for (int j = S; j >= A[i]; j--) { // Ta xét từ con số S cho đến giá trị A[i]
			if (dp[j - A[i]] == true) {  // Nếu A[j - giá trị A ở vị trí i] là true thì tại giá trị j cho true còn false thì cho false 
				dp[j] = true;
			}
		}
	}
	if (dp[S]) {
		cout << "Co day tap con tong bang S";
	}
	else {
		cout << "Ko co day tap con tong bang";
	}
}