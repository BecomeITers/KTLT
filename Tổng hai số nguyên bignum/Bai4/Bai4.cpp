#include <iostream>
#include <cctype>
#include <cstring>
#define MAX 100
using namespace std;
void Check(char s[]) {
	for (int i = 0; i < strlen(s); i++) {
		if (isalpha(s[i])) {
			cout << "Nhap sai";
			exit(1);
		}
	}
}
void Reverse(char s[]) {
	for (int i = 0; i < strlen(s) / 2; i++) {
		char temp = s[i];
		s[i] = s[strlen(s) - i - 1];
		s[strlen(s) - i - 1] = temp;
	}
}
void Chen(char s[], int k) {
	Reverse(s);
	int length = strlen(s);
	for (int i = 0; i < k; i++) {
		s[length + i] = '0';
	}
	s[length + k] = '\0';
	Reverse(s);
}
void EditSize(char s1[], char s2[]) {
	int size1 = strlen(s1);
	int size2 = strlen(s2);
	if (size1 > size2) {
		Chen(s2, size1 - size2);
	}
	else {
		Chen(s1, size2 - size1);
	}
}
void Total(char s1[], char s2[], char s3[]) {
	Reverse(s1);
	Reverse(s2);
	int memory = 0;
	int size = strlen(s1);
	for (int i = 0; i < size; i++) {
		int total = (s1[i] - '0') + (s2[i] - '0') + memory;
		if (total < 10) {
			s3[i] = total + '0';
			memory = 0;
		}
		else {
			memory = 1;
			total %= 10;
			s3[i] = total + '0';
		}
		if (memory == 1) {
			s3[i + 1] = '1';
			size++;
		}
	}
	s3[size] = '\0';
	Reverse(s3);
}
int main(){
	char s1[MAX], s2[MAX], s3[MAX];
	cout << "Nhap day so thu nhat: ";
	cin.getline(s1, MAX);
	cout << "Nhap day so thu hai: ";
	cin.getline(s2, MAX);
	Check(s1);
	Check(s2);
	EditSize(s1, s2);
	Total(s1, s2, s3);
	//for (int i = 0; i < strlen(s3); i++) {
		//s3[i] = s3[i + 1];
	//}
	cout << "Tong 2 so big num la: " << s3;
}