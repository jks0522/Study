#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[10001], wine[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> wine[i];
    
    dp[1] = wine[1];
    dp[2] = dp[1] + wine[2];

    for(int i = 3; i <= n; i++)
    {
        dp[i] = max(dp[i-3] + wine[i-1] + wine[i], dp[i-2] + wine[i]);
        dp[i] = max(dp[i-1], dp[i]);
    }

    cout << dp[n] << endl;

    return 0;
}