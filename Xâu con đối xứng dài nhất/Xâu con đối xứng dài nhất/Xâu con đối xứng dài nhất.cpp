#include <iostream>
#include <string>
#define SIZE 100
using namespace std;
int main(){
	cout << "Nhap chuoi: ";
	string s;
	getline(cin, s);
	int n = s.size();
	bool F[SIZE][SIZE]; // Tạo mảng 2 chiều xét true false
	memset(F, false, sizeof(F)); // Tạo mảng 2 chiều là false hết
	for (int i = 1; i <= n; i++) {
		F[i][i] = true; // Tạo mảng tập con có chiều dài 1 luôn đối xứng là true
	}
	int ans = 1;
	for (int len = 2; len <= n; len++) { // Duyệt từ độ dài 2 đến độ dài n
		for (int i = 1; i <= n - len + 1; i++) { // Duyệt từ vị trí đầu tiên đến phần tử cuối ( Phần tử đầu tiên )
			int j = i + len - 1; // Phần tử cuối cùng
			if (len == 2 && s[i] == s[j]) { // Nếu độ dài là 2 và phần tử đầu và cuối bằng nhau thì nó đối xứng
				F[i][j] = true;
			}
			else {
				F[i][j] = F[i + 1][j - 1] && (s[i] == s[j]); // Nếu độ dài lơn hơn 2 thì phần tử i + 1 và j - 1 xem true hay false đồng thời 
			}
			if (F[i][j]) {
				ans = max(ans, len); // Nếu có đối xứng thì in ra độ dài xâu con đối xứng dài nhất
			}
		}
	}
	cout << "Do dai xau con doi xung dai nhat la: " << ans;
	return 0;
}