#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, index = 0;
    long long cnt = 0;
    stack<pair<long long, int>> st;

    cin >> n;

    vector<int> same(n, 1);

    for(int i = 0; i < n; i++)
    {
        long long num;
        cin >> num;

        while(!st.empty())
        {
            if(st.top().first == num)
            {
                if(st.size() > same[st.top().second])
                    cnt += (same[st.top().second] + 1);
                else
                    cnt += same[st.top().second];
                same[i]=same[st.top().second] + 1;
                break;
            }
            else if(st.top().first > num)
            {
                cnt++;
                index++;
                break;
            }
            else
            {
                st.pop();
                index--;
                cnt++;
            }
        }

        st.push({num, i});
    }

    cout << cnt << '\n';

    return 0;
}