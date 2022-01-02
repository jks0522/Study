#include <iostream>
#include <cstring>
using namespace std;

bool chk;
int n, dist[16][16];
int cache[16][1<<16];

int path(int here, int visited)
{
    if(visited == (1 << n) - 1) 
    {
        if(dist[here][0] == 0)
            return 100000000;
        return dist[here][0];
    }
    int& ret = cache[here][visited];
    if(ret > 0) return ret;
    ret = 100000000;
    for(int next = 0; next < n; next++)
    {
        if(visited & (1 << next) || dist[here][next] == 0) continue;
        int cand = dist[here][next] + path(next, visited + (1 << next));
        ret = min(ret, cand);
    }
    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> dist[i][j];

    cout << path(0, 1) << '\n';

    return 0;
}