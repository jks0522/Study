#include <iostream>
using namespace std;

int n;
int house[16][16], C[16][16][3];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> house[i][j];

    C[0][1][0] = 1;

    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(j+1 < n && house[i][j+1] == 0)
                C[i][j+1][0] = C[i][j][0] + C[i][j][1];
            if(i+1 < n && j+1 < n && house[i][j+1] == 0 && house[i+1][j] == 0 && house[i+1][j+1] == 0)
                C[i+1][j+1][1] = C[i][j][0] + C[i][j][1] + C[i][j][2];
            if(i+1 < n && house[i+1][j] == 0)
                C[i+1][j][2] = C[i][j][1] + C[i][j][2];
        }
    }

    cout << C[n-1][n-1][0] + C[n-1][n-1][1] + C[n-1][n-1][2] << '\n';

    return 0;
}