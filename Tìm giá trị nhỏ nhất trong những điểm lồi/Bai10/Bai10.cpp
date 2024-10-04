#include <iostream>
#define MAX 100
using namespace std;

void Nhap(int array[][MAX], int& m, int& n) {
    cout << "Nhap dong: ";
    cin >> m;
    cout << "Nhap cot: ";
    cin >> n;
    cout << "Nhap ma tran: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> array[i][j];
        }
    }
}

bool TimDiemLoi(int array[][MAX], int m, int n) {
    int X[4] = { 0, 0, 1, -1 };
    int Y[4] = { -1, 1, 0, 0 };
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                int newX = i + X[k];
                int newY = j + Y[k];
                if (newX >= 0 && newX < m && newY >= 0 && newY < n) {
                    if (array[newX][newY] >= array[i][j]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int VitriGTNN(int a[], int count) {
    int MIN = a[0];
    int index = 0;
    for (int i = 0; i < count; i++) {
        if (a[i] < MIN) {
            MIN = a[i];
            index = i;
        }
    }
    return index;
}

int TimViTriDiemLoiMin(int array[][MAX], int m, int n, int A[], int B[]) {
    int value[1000000] = {};
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (TimDiemLoi(array, m, n)) {
                value[count] = array[i][j];
                A[count] = i;
                B[count] = j;
                count++;
            }
        }
    }
    int result = VitriGTNN(value, count);
    return result;
}

int main() {
    int array[MAX][MAX], m, n;
    int A[1000000], B[1000000];
    Nhap(array, m, n);
    int a = TimViTriDiemLoiMin(array, m, n, A, B);
    cout << A[a] << " " << B[a];
    return 0;
}
