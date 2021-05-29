#include <iostream>
#include <string.h>

using namespace std;

int n, triangle[500][500];
int cache[500][500];

int solve(int y, int x) {
    if(y == n-1) return triangle[y][x];
    int& ret = cache[y][x];
    if(ret != -1) return ret;
    return ret = max(solve(y+1, x), solve(y+1, x+1)) + triangle[y][x];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(cache, -1, sizeof(cache));

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            int num;
            cin >> num;
            triangle[i][j] = num;
        }
    }

    cout << solve(0, 0) << '\n';

    return 0;
}