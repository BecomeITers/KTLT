#include <iostream>
using namespace std;
int DeQuy(int n, int k) {
    if (k == 1) {
        return n;
    }
    else {
        if (n == k) {
            return 1;
        }
        else {
            return DeQuy(n - 1, k) + DeQuy(n - 1, k - 1);
        }
    }
    }
int main(){
    int a, b;
    cout << "Nhap gia tri n: ";
    cin >> a;
    cout << "Nhap gia tri k: ";
    cin >> b;
    if (a < b) {
        return NULL;
    }
    else{
        int result = DeQuy(a, b);
        cout << "To hop la: " << result;
    }
}
