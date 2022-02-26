#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int cache[1000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int num;
            cin >> num;
            if(j > 0)
                cache[j] = max(cache[j], cache[j-1]) + num;
            else
                cache[j] += num;
        }
    }

    cout << cache[m-1] << '\n';

    return 0;
}