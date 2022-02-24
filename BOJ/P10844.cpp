#include <iostream>
using namespace std;

const int MOD = 1000000000;

int dp[101][10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    for(int i = 0; i <= 9; i++)
        dp[1][i] = 1;
    
    for(int i = 2; i <= n; i++)
    {
        for(int j = 0; j <= 9; j++)
        {
            if(j == 9)
                dp[i][j] = dp[i-1][j-1] % MOD;
            else if(j == 0)
                dp[i][j] = dp[i-1][j+1] % MOD;
            else
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD;
        }
    }

    int result = 0;
    for(int i = 1; i <= 9; i++)
        result = (result + dp[n][i]) % MOD;

    cout << result << '\n';

    return 0;
}