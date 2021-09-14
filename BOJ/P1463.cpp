#include <iostream>
#include <cstring>
using namespace std;

int cache[1000001];

int count(int x)
{
    if(x <= 1) return 0;
    int& ret = cache[x];
    if(ret != -1) return ret;
    if(x % 3 == 0) ret = count(x/3) + 1;
    if(x % 2 == 0) 
    {
        if(ret != -1)
            ret = min(ret, count(x/2) + 1);
        else
            ret = count(x/2) + 1;
    }
    if(ret != -1)
        ret = min(ret, count(x-1) + 1);
    else
        ret = count(x-1) + 1;
    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(cache, -1, sizeof(cache));

    int n;
    cin >> n;

    cout<<count(n)<<'\n';

    return 0;
}