#include <iostream>
#include <string.h>
using namespace std;

int n, k;
int weight[100], value[100];
int cache[100001][100];

int pack(int capacity, int item)
{
    if(item == n) return 0;
    int& ret = cache[capacity][item];
    if(ret != -1) return ret;

    ret = pack(capacity, item + 1);
    if(capacity >= weight[item])
        ret = max(ret, pack(capacity-weight[item], item + 1) + value[item]);
    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < 100001; i++)
        memset(cache[i], -1, sizeof(cache[i]));
    
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> weight[i] >> value[i];

    cout << pack(k, 0) << '\n';

    return 0;
}