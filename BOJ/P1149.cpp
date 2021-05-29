#include <iostream>
#include <string.h>

using namespace std;

int n, house[1000][3];
int cache[1000][3];

int solve(int houseNum, int color) {
    if(houseNum == n-1) return house[houseNum][color];
    int& ret = cache[houseNum][color];
    if(ret != -1) return ret;
    if(color == 0)
        return ret = min(solve(houseNum+1,1), solve(houseNum+1, 2)) + house[houseNum][color];
    else if(color == 1)
        return ret = min(solve(houseNum+1,0), solve(houseNum+1, 2)) + house[houseNum][color];
    else
        return ret = min(solve(houseNum+1,0), solve(houseNum+1, 1)) + house[houseNum][color];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int r, g, b;
        cin >> r >> g >> b;
        house[i][0] = r;
        house[i][1] = g;
        house[i][2] = b;
    }

    memset(cache, -1, sizeof(cache));

    cout << min(solve(0, 0), min(solve(0, 1), solve(0, 2))) << '\n';

    return 0;
}