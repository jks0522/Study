#include <iostream>
#include <vector>

using namespace std;

int n, k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    
    vector<int> v;
    v.reserve(n-k);

    string s;
    cin >> s;

    int cnt = 0;

    for(int i = 1; i <= n; i++)
    {
        int num = s[i-1] - '0';
        while(!v.empty() && cnt-i >= -k && v.back() < num)
        {
            v.pop_back();
            cnt--;
        }

        if(cnt >= n-k)
            break;
        v.push_back(num);
        cnt++;
    }

    for(int i = 0; i < v.size(); i++)
        cout << v[i];

    return 0;
}