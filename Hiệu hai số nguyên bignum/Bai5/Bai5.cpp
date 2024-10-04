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
}
void ChenSo(char s[], int k) {
	int size = strlen(s);
	for (int i = 0; i < k; i++) {
		s[size + i] = '0';
	}
	s[size + k] = '\0';
	Reverse(s);
}
void EditSize(char s1[], char s2[]) {
	int size1 = strlen(s1);
	int size2 = strlen(s2);
	if (size1 > size2) {
		ChenSo(s2, size1 - size2);
	}
	else {
		ChenSo(s1, size2 - size1);
	}
}
void Minus(char s1[], char s2[], char s3[]) {
	Reverse(s1);
	Reverse(s2);
	int size = strlen(s1);
	int memory = 0;
	for (int i = 0; i < size; i++) {
		int minus = (s1[i] - '0') - (s2[i] - '0') - memory;
		if (minus > 0) {
			s3[i] = minus + '0';
			memory = 0;
		}
		else if (minus < 0) {			
			s3[i] = minus + 10 + '0';
			memory = 1;
		}
	}
	Reverse(s3);
	s3[size] = '\0';
}
void Result(char s1[], char s2[], char s3[]) {
	char a = s1[0];
	char b = s2[0];
	int size = strlen(s3);
	if (strcmp(s1,s2) > 0) {
		Minus(s1, s2, s3);
	}
	else {
		Minus(s1, s2, s3);
		s3[size] = '-';
		s3[size + 1] = '\0';
		Reverse(s3);
	}
}
int main(){
	char s1[MAX], s2[MAX], s3[MAX];
	cout << "Nhap so bignum thu nhat: ";
	cin.getline(s1, MAX);
	cout << "Nhap so bignum thu hai: ";
	cin.getline(s2, MAX);
	EditSize(s1, s2);
	Minus(s1, s2, s3);
	cout << "Hieu hai so nguyen bignum la: " << s3;
}
