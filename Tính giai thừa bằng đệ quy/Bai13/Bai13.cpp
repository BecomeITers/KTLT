#include <iostream>
using namespace std;
int DeQuy(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n * DeQuy(n - 1);
    }
}
int main(){
    int n;
    cout << "Nhap n: ";
    cin >> n;
    int result = DeQuy(n);
    cout << "Giai thua sau khi de quy la: ";
    cout << result;
}
