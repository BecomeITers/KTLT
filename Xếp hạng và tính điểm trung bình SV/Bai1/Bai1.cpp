#include <iostream>
#include<string>
#include<stdio.h>
using namespace std;
struct SV {
    int mssv;
    string hoten;
    int somon;
    double diem[100];
    double dtb;
};
void Nhap(SV& a) {
    cout << "Nhap ma so sinh vien: ";
    cin >> a.mssv;
    cin.ignore();
    cout << "Nhap ho va ten: ";
    getline(cin, a.hoten);
    cout << "Nhap so mon hoc: ";
    cin >> a.somon;
    cout << "Nhap diem so: " << "\n";
    for (int i = 0; i < a.somon; i++) {
        int index = i + 1;
        cout << "Diem so thu " << index << " : ";
        cin >> a.diem[i];
    }
}
double dtb(SV& a) {
    double tong = 0.0;
    for (int i = 0; i < a.somon; i++) {
        tong += a.diem[i];
    }
    return tong / a.somon;
}
void Check(SV& a) {
    int count = 0;
    for (int i = 0; i < a.somon; i++) {
        if (a.diem[i] < 5) {
            count++;
        }
    }
    cout << "Tong so mon hoc hoc lai la: " << count;
}
int main() {
    SV a;
    Nhap(a);
    cout << "Diem trung binh mon la: " << dtb(a) << "\n";
    Check(a);
    return 0;
}
