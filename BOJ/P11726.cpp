#include <iostream>
using namespace std;

int cache[1001];

int tiling(int n)
{
    if(n == 2) return 2;
    if(n == 1) return 1;
    if(n <= 0) return 0;
    int& ret = cache[n];
    if(ret != 0) return ret;

    ret = tiling(n-2) + tiling(n-1);
    return ret % 10007;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    cout << tiling(n) << '\n';
}