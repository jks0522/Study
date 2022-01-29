#include <iostream>
using namespace std;

int n;
int house[16][16], cache[16][16][3];

int solve(int y, int x, int dir)
{
    if(y == n-1 && x == n-1) return 1;
    if(y > n-1 || x > n-1) return 0;
    int& ret = cache[y][x][dir];
    if(ret != 0) return ret;
    if(dir == 0 && house[y][x+1] == 0)
        ret = solve(y, x+1, 0);
    else if(dir == 1)
    {
        if(house[y][x+1] == 0)
            ret = solve(y, x+1, 0);
        if(house[y+1][x] == 0)
            ret += solve(y+1, x, 2);
    }
    else if(dir == 2 && house[y+1][x] == 0)
        ret = solve(y+1, x, 2);
    if(house[y+1][x] == 0 && house[y][x+1] == 0 && house[y+1][x+1] == 0)
        ret += solve(y+1, x+1, 1);
    
    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> house[i][j];

    cout << solve(0, 1, 0) << '\n';

    return 0;
}