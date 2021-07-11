#include <iostream>
#include <vector>

using namespace std;

int n, m, k;

void solve(const vector<vector<int>>& a, const vector<vector<int>>& b, vector<vector<int>>& c) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            int sum = 0;
            for(int l = 0; l < m; l++) {
                sum += a[i][l]*b[l][j];
            }
            c[i][j] = sum;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            cout << c[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    cin >> m >> k;
    vector<vector<int>> b(m, vector<int>(k));
    vector<vector<int>> c(n, vector<int>(k));

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < k; j++) {
            cin >> b[i][j];
        }
    }

    solve(a, b, c);

    return 0;
}