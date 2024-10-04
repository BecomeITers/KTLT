#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;
void Reverse(char s[]) {
	int size = strlen(s);
	for (int i = 0; i < size / 2; i++) {
		char temp = s[i];
		s[i] = s[size - i - 1];
		s[size - i - 1] = temp;
	}
	s[size] = '\0';
}
void Xoaso0(char s[]) {
	Reverse(s);
	int i = strlen(s) - 1;
	while (i < strlen(s) && s[i] == '0') {
		i--;
		s[i + 1] = '\0';
	}
	Reverse(s);
}
void Chia(char s1[], char s2[], long long k) {
	int number = 0;
	int size = strlen(s1);
	for (int i = 0; i < size; i++) {
		int tinh = number * 10 + (s1[i] - '0');
		s2[i] = (tinh / k) + '0';
		number = tinh % k;
	}
	s2[size] = '\0';
	Xoaso0(s2);
}
int main(){
	char s1[MAX], s2[MAX];
	long long k;
	cout << "Nhap so bignum thu nhat: ";
	cin.getline(s1, MAX);
	cout << "Nhap so nguyen bi chia: ";
	cin >> k;
	Chia(s1, s2, k);
	cout << "Ket qua phep tinh chia la: " << s2;
}
