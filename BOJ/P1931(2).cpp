#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> vec(n);
    for(int i = 0; i < n; i++)
        cin >> vec[i].second >> vec[i].first;
    sort(vec.begin(), vec.end());

    int last = 0, count = 0;
    for(int i = 0; i < n; i++)
    {
        if(last <= vec[i].second)
        {
            last = vec[i].first;
            count++;
        }
    }

    cout << count << '\n';

    return 0;
}