#include <iostream>
using namespace std;

int n;
int board[100][100];
long long cache[100][100];

long long solve(int y, int x)
{
    if(y == n-1 && x == n-1) return 1;
    if(y > n-1 || x > n-1) return 0;
    if(board[y][x] == 0) return 0;
    long long& ret = cache[y][x];
    if(ret != 0) return ret;
    ret = solve(y+board[y][x], x) + solve(y, x+board[y][x]);
    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];

    cout << solve(0, 0) << '\n';

    return 0;
}