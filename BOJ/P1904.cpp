#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 15746;
int cache[1000001];

int tiling(int n)
{
    if(n <= 1) return 1;
    int& ret = cache[n];
    if(ret != 0) return ret;
    return ret = (tiling(n-2) + tiling(n-1)) % MOD;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    cout<<tiling(n)<<'\n';
    return 0;
}