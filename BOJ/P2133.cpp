#include <iostream>
using namespace std;

int dp[31];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    dp[0] = 0;
    dp[2] = 3;
    
    for(int i = 4; i <= n; i +=2)
    {
        dp[i] = dp[i-2]*3;
        for(int j = 4; j <= i; j += 2)
            dp[i] += dp[i-j]*2;
        dp[i] += 2;
    }

    cout << dp[n] << '\n';

    return 0;

}