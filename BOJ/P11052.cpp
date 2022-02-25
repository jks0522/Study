#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int n;
int card[1001], cache[1001];

int solve(int num)
{
    if(num <= 1) return card[num];
    int& ret = cache[num];
    if(ret != 0) return ret;
    for(int i = 1; i <= num; i++)
        ret = max(ret, card[i] + solve(num - i));

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);  

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> card[i];

    cout << solve(n) << '\n';

    return 0;
}