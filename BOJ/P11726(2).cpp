#include <iostream>
using namespace std;

int C[4];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    C[0] = 0;
    C[1] = 1;
    C[2] = 2;
    for(int i = 3; i <= n; i++)
        C[i%4] = (C[(i-1)%4] + C[(i-2)%4]) % 10007;
    
    cout << C[n%4] << '\n';

    return 0;
}