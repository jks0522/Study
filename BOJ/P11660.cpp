#include <iostream>
using namespace std;

int n, m;
int sum[1024][1024];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int num;
            cin >> num;
            if(j > 0)
                sum[i][j] = sum[i][j-1];
            if(i > 0)
                sum[i][j] += sum[i-1][j];
            if(i > 0 && j > 0) sum[i][j] -= sum[i-1][j-1];
            sum[i][j] += num;
        }
    }

    for(int i = 0; i < m; i++)
    {
        int x1, x2, y1, y2, result = 0;
        cin >> x1 >> y1 >> x2 >> y2;

        result = sum[x2-1][y2-1];
        if(y1-1 > 0) result -= sum[x2-1][y1-2];
        if(x1-1 > 0) result -= sum[x1-2][y2-1];
        if(x1-1 > 0 && y1-1 > 0) result += sum[x1-2][y1-2];
        cout << result << '\n';
    }

    return 0;
}