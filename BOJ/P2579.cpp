#include <iostream>
#include <algorithm>
using namespace std;

int n, ans = 0;
int stair[301];
int dp[301][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> stair[i];

    dp[0][0] = dp[1][0] = 0;
    dp[1][0] = dp[1][1] = stair[1];

    for(int i = 2; i <= n; i++)
    {
        dp[i][0] = max(dp[i-2][0], dp[i-2][1]) + stair[i];
        dp[i][1] = dp[i-1][0] + stair[i];
    }

    cout << max(dp[n][0], dp[n][1]) << '\n';

    return 0;
}