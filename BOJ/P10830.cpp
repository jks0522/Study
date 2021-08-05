#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> matrix;

matrix operator * (const matrix &a, const matrix& b) {
    int n = a.size();
    matrix result(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++)
                result[i][j] += (a[i][k] * b[k][j]);
            
            result[i][j] %= 1000;
        }

    return result;
}

matrix identityMatrix(int n) {
    matrix m(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i == j)
                m[i][j] = 1;

    return m;
}

matrix solve(matrix& m, long long b) {
    if(b == 0) return identityMatrix(m.size());
    if(b % 2 > 0) return solve(m, b-1) * m;
    matrix half = solve(m, b/2);
    return half * half;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long b;
    cin >> n >> b;

    matrix m(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> m[i][j];

    matrix result = solve(m, b);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << result[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}