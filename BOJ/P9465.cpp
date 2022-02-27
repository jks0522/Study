#include <iostream>
#include <algorithm>

using namespace std;

int dp[2][3], sticker[2][100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        for(int j = 0; j < 2; j++)
            for(int k = 0; k < n; k++)
                cin >> sticker[j][k];

        dp[0][0] = sticker[0][0];
        dp[1][0] = sticker[1][0];
        dp[0][1] = dp[1][0] + sticker[0][1];
        dp[1][1] = dp[0][0] + sticker[1][1];
        for(int j = 2; j < n; j++)
        {
            dp[0][j%3] = max(dp[1][(j-2)%3], dp[1][(j-1)%3]) + sticker[0][j];
            dp[1][j%3] = max(dp[0][(j-2)%3], dp[0][(j-1)%3]) + sticker[1][j];
        }

        cout << max(dp[0][(n-1)%3], dp[1][(n-1)%3]) << '\n';
    }

    return 0;
}