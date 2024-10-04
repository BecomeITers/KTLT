#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;
struct Sach {
	string MaS;
	string TenS;
	string LoaiS;
	string NXB;
	string Tacgia;
	int Sotrang;
	double Gia_tien;
};
void Nhap(Sach a[100], int n) {
	for (int i = 0; i < n; i++) {
		getline(cin, a[i].MaS);
		getline(cin, a[i].TenS);
		getline(cin, a[i].LoaiS);
		getline(cin, a[i].NXB);
		getline(cin, a[i].Tacgia);
		cin >> a[i].Sotrang;
		cin >> a[i].Gia_tien;
	}
};
bool cmp1(Sach a, Sach b) {
	return a.Tacgia < b.Tacgia;
}
bool cmp2(Sach a, Sach b) {
	return a.LoaiS < b.LoaiS;
}
bool cmp3(Sach a, Sach b) {
	if (a.Tacgia != b.Tacgia) {
		return a.Tacgia < b.Tacgia;
	}
	else {
		return a.NXB < b.NXB;
	}
}
string SachMax(Sach a[100], int n) {
	int count = 0;
	int MAX = 0;
	string kq;
	for (int i = 0; i < n; i++) {
		count++;
		if (a[i].Tacgia != a[i + 1].Tacgia) {
			if (count > MAX) {
				MAX = count;
				kq = a[i].Tacgia;
			}
		}
		count = 0;
	}
	return kq;
}
string SoTrangMax(Sach a[100], int n) {
	int total = 0;
	int MAX = 0;
	string kq;
	for (int i = 0; i < n; i++) {
		total += a[i].Sotrang;
		if (a[i].Tacgia != a[i + 1].Tacgia) {
			if (total > MAX) {
				MAX = total;
				kq = a[i].Tacgia;
			}
			total = 0;
		}
	}
	return kq;
}
string LoaiSMax(Sach a[100], int n) {
	double total = 0.0;
	double MAX = 0;
	int index = 0;
	for (int i = 0; i < n; i++) {
		total += a[i].Gia_tien;
		index = i;
		if (a[i].LoaiS != a[i + 1].LoaiS) {
			if (total > MAX) {
				MAX = total;
			}
			total = 0.0;
		}
	}
		return a[index].LoaiS;
}
int main() {
	Sach a[100];
	int n;
	cin >> n;
	freopen("Sach.txt", "r", stdin);
	freopen("Sach.out", "w", stdout);
	Nhap(a, n);
	//sort(a, a + n, cmp1);
	//sort(a, a + n, cmp2);
	sort(a, a + n, cmp3);
	cout << "Tac gia co nhieu sach nhat la: " << SachMax(a, n) << "\n";
	cout << "Tac gia co tong so trang nhieu nhat la: " << SoTrangMax(a, n) << "\n";
	cout << "Loai sach co tong gia tri nhieu nhat la: " << LoaiSMax(a, n) << "\n";
	return 0;
}

