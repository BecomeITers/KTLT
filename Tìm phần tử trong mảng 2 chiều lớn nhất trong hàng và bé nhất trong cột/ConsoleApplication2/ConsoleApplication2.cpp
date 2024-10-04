#include <iostream>
#include <algorithm>
#include <vector>
#include <climits> 
#define MAX 1000
using namespace std;
vector<int> Tim1(int A[][MAX], int n, int m) {
    vector<int> res(n, INT_MIN);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i] = max(res[i], A[i][j]);
        }
    }
    return res;
}
vector<int> Tim2(int A[][MAX], int n, int m) {
    vector<int> res(m, INT_MAX);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[j] = min(res[j], A[i][j]);
        }
    }
    return res;
}
int main() {
    int A[MAX][MAX];
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    int count = 0;
    vector<int> H1 = Tim1(A, n, m);
    vector<int> H2 = Tim2(A, n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == H1[i] && A[i][j] == H2[j]) {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
