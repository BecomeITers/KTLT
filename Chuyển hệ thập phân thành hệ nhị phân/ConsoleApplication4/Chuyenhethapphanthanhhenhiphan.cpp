#include <iostream>
#include <vector>
using namespace std;
void Xuat(vector<int>& A) {
	for (int i = A.size() - 1; i >= 0; i--) {
		cout << A[i];
	}
	cout << endl;
}
// Cách chuyển hệ thập phân thành hệ nhị phân là chia 2 lấy dư 
int main(){
	int n; cin >> n;
	vector<int> A;
	for (int i = 1; i <= n; i++) {
		int temp = i;
		while (temp > 0) {
			A.push_back(temp % 2);
			temp /= 2;
		}
		Xuat(A);
		A.clear();
	}
}
