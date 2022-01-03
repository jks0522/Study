#include <iostream>
using namespace std;

int n, triangle[500][500], cache[500][500];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j =0; j <= i; j++)
            cin >> triangle[i][j];

    for(int i = 0; i < n; i++)
        cache[n-1][i] = triangle[n-1][i];

    for(int i = n-2; i >= 0; i--)
        for(int j = 0; j < i+1; j++)
            cache[i][j] = max(cache[i+1][j], cache[i+1][j+1]) + triangle[i][j];

    cout << cache[0][0] << '\n';

    return 0;
}

