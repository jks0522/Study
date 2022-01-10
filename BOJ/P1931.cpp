#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int begint[100000], endt[100000];

int schedule()
{
    vector<pair<int, int>> vec;
    for(int i = 0; i < n; i++)
        vec.push_back(make_pair(endt[i], begint[i]));
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

    return count;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> begint[i] >> endt[i];

    cout << schedule() << '\n';

    return 0;
}