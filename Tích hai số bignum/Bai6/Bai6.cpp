#include <iostream>
#include <cstring>
#define MAX 1000
#define ll long long
using namespace std;

void Reverse(char s[]) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

void Tich(char s1[], char s2[], char s3[]) {
    int len1 = strlen(s1), len2 = strlen(s2);
    Reverse(s1);
    Reverse(s2);

    for (int i = 0; i < len1; i++) {
        int carry = 0;
        for (int j = 0; j < len2; j++) {
            int mul = (s1[i] - '0') * (s2[j] - '0') + (s3[i + j] - '0') + carry;
            carry = mul / 10;
            s3[i + j] = (mul % 10) + '0';
        }
        if (carry > 0) {
            s3[i + len2] += carry;
        }
    }
    Reverse(s3);
}

int main() {
    char s1[MAX], s2[MAX], s3[MAX * 2];
    cin.getline(s1, MAX);
    cin.getline(s2, MAX);
    Tich(s1, s2, s3);
    for (int i = 1; i < strlen(s3); i++) {
        cout << s3[i];
    }
    return 0;
}
