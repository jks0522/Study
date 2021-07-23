#include <iostream>
#include <vector>
using namespace std;

int answer, v[11][11], picked[11];

void solve(int position, int sum)
{
    if(position == 11)
    {
        if(sum > answer)
            answer = sum;
        return;
    }

    for(int i = 0; i < 11; i++)
    {
        if(v[i][position] != 0 && !picked[i])
        {
            picked[i] = true;
            solve(position + 1, sum + v[i][position]);
            picked[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int c;  // 테스트케이스 개수
    cin >> c;

    for(int i = 0; i < c; i++)
    {
        for(int j = 0; j < 11; j++)
            for(int k = 0; k < 11; k++)
                cin >> v[j][k];

        solve(0, 0);
        cout << answer << '\n';

        answer = 0;
    }

    return 0;
}