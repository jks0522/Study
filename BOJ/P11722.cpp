#include <iostream>
#include <string.h>
using namespace std;

int n;
int cache[1001], A[1000];

int lis(int start)
{
    int& ret = cache[start+1];
    if(ret != -1) return ret;
    ret = 1;
    for(int next = start+1; next < n; next++)
        if(start == -1 || A[start] > A[next])
            ret = max(ret, lis(next) + 1);
    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(cache, -1, sizeof(cache));

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];

    cout<<lis(-1)-1<<'\n';

    return 0;
}