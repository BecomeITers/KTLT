#include <iostream>
#include <climits>
#define MAX 100
using namespace std;
void Nhap(int array[][MAX], int &m, int &n) {
    cout << "Nhap so dong: ";
    cin >> m;
    cout << "Nhap so cot: ";
    cin >> n;
    cout << "Nhap ma tran: " << endl;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> array[i][j];
        }
    }
}
int TimDiemLoiMAX(int array[][MAX], int m, int n) {
    int X[4] = { 0,0,0,-1 };
    int Y[4] = { -1,1,1,0 };
    int maxnumber = INT_MIN;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int number = array[i][j];
            for (int k = 0; k < 4; k++) {
                if (array[i + X[i]][j + Y[i]] > number) {
                    number = array[i + X[i]][j + Y[i]];
                }
            }
            if (number > maxnumber) {
                maxnumber = number;
            }
        }
    }
    return maxnumber;
}
int main(){
    int array[MAX][MAX], m, n;
    Nhap(array, m, n);
    cout << "So lon nhat trong ma tran la:";
    cout << TimDiemLoiMAX(array, m, n);
    return 0;
}