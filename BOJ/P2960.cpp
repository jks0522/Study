#include <iostream>
using namespace std;

int n, k;
bool isDeleted[1001];

int eratosthenes()
{
    int count = 0;
    for(int i = 2; i <= n; i++)
    {
        if(!isDeleted[i])
        {
            for(int j = i; j <= n; j += i)
            {
                if(!isDeleted[j])
                {
                    isDeleted[j] = true;
                    count++;
                }
                if(count == k) return j;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    cout << eratosthenes() << '\n';

    return 0;
}