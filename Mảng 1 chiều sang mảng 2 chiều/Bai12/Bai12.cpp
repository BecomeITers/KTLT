#include <iostream>
#define MAX 100
using namespace std;
void Nhap(int array[], int& a, int& m, int& n) {
    cout << "Nhap so: ";
    cin >> a;
    cout << "Nhap day so: " << endl;
    for (int i = 0; i < a; i++) {
        cin >> array[i];
    }
    cout << "Nhap so hang: ";
    cin >> m;
    cout << "Nhap so cot: ";
    cin >> n;
}
void ChuyenDoi(int array[], int a, int array2D[][MAX], int m, int n) {
    for (int k = 0; k < a; k++) {
        int i = k / n;
        int j = k % n;
        array2D[i][j] = array[k];
    }
}
void Xuat(int array2D[][MAX], int rows, int cols) {
    cout << "Ma tran sau khi chuyen doi la: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << array2D[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    int array[10000], a, array2D[MAX][MAX], m, n;
    Nhap(array, a, m ,n);
    ChuyenDoi(array, a, array2D, m ,n);
    Xuat(array2D, m, n);
}
