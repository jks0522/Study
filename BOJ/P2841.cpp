#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, p, result = 0;
    cin >> n >> p;

    stack<int> st[6];
    for(int i = 0; i < n; i++)
    {
        int line, fret;
        cin >> line >> fret;

        while(!st[line-1].empty() && st[line-1].top() > fret)
        {
            st[line-1].pop();
            result++;
        }
        if(!st[line-1].empty() && st[line-1].top() == fret)
            continue;
        st[line-1].push(fret);
        result++;
    }

    cout << result << '\n';

    return 0;
}