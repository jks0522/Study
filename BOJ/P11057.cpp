#include <iostream>

using namespace std;

int dp[1001][10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i <= 9; i++)
        dp[1][i] = 1;

    for(int i = 2; i <= n; i++)
        for(int j = 0; j <= 9; j++)
            for(int k = j; k <= 9; k++)
                dp[i][j] = (dp[i][j] +  dp[i-1][k]) % 10007;

    int result = 0;
    for(int i = 0; i <= 9; i++)
        result = (result + dp[n][i]) % 10007;

    cout << result << '\n';

    return 0;
}