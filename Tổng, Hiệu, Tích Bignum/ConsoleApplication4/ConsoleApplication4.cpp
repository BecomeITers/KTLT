#include <iostream>
#include <string>
#include <algorithm>
#define ll long long
using namespace std;
string So(string s) {
	string res = "";
	ll size = s.size();
	int i = 0;
	while (i < size) {
		if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
			break;
		}
		res.push_back(s[i]);
		i++;
	}
	return res;
}
string Tong(string a, string b) {
	string res = "";
	ll size1 = a.size(), size2 = b.size();
	int size = max(size1, size2);
	while (size1 < size) {
		a = "0" + a;
		size1++;
	}
	while (size2 < size) {
		b = "0" + b;
		size2++;
	}
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int nho = 0;
	for (int i = 0; i < size; i++) {
		int tong = (a[i] - '0') + (b[i] - '0') + nho;
		res.push_back((tong % 10) + '0'); 
		nho = tong / 10;
	}
	if (nho > 0) {
		res.push_back(nho + '0');
	}
	reverse(res.begin(), res.end());
	return res;
}
string Tich(string a, string b) {
	ll size1 = a.size(), size2 = b.size();
	string res(size1 + size2, '0');
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	for (int i = 0; i < size1; i++) {
		int nho = 0;
		for (int j = 0; j < size2; j++) {
			int nhan = (a[i] - '0') * (b[j] - '0') + (res[i + j] - '0') + nho;
			nho = nhan / 10;
			res[i + j] = (nhan % 10) + '0';
		}
		if (nho > 0) {
			res[i + size2] += nho;
		}
	}
	reverse(res.begin(), res.end());
	size_t pos = res.find_first_not_of('0');
	if (pos != string::npos) {
		res = res.substr(pos);
	}
	else {
		res = "0";
	}
	return res;
}
string Hieu(string a, string b) {
	if (a == b) return "0";
	bool negative = false;
	if (a < b) {
		swap(a, b);
		negative = true;
	}
	ll size1 = a.size(), size2 = b.size();
	int size = max(size1, size2);
	while (size2 < size) {
		b = "0" + b;
		size2++;
	}
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	string res = "";
	int muon = 0;
	for (int i = 0; i < size; i++) {
		int sub = (a[i] - '0') - (b[i] - '0') - muon;
		if (sub < 0) {
			sub += 10;
			muon = 1;
		}
		else {
			muon = 0;
		}
		res.push_back(sub + '0');
	}
	reverse(res.begin(), res.end());
	size_t pos = res.find_first_not_of('0');
	if (pos != string::npos) {
		res = res.substr(pos);
	}
	else {
		res = "0";
	}
	if (negative) res = "-" + res;
	return res;
}
int main() {
	string s;
	cin >> s;
	ll size = s.size();
	string a = So(s);
	reverse(s.begin(), s.end());
	string b = So(s);
	reverse(b.begin(), b.end());
	string res = "";
	for (int i = 0; i < size; i++) {
		if (s[i] == '+') {
			res = Tong(a, b);
			break;
		}
		if (s[i] == '-') {
			res = Hieu(a, b);
			break;
		}
		if (s[i] == '*') {
			res = Tich(a, b);
			break;
		}
	}
	cout << res;
	return 0;
}