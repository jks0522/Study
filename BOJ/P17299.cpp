#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int cnt[1000001];

void solve(const vector<int>& v) {
    stack<pair<int, int>> st;
    vector<int> answer(v.size());

    for(int i = 0; i < v.size(); i++) {
        int num = v[i];
        while(!st.empty()) {
            if(cnt[st.top().second] < cnt[num]) {
                answer[st.top().first] = num;
                st.pop();
            } else {
                break;
            }
        }

        st.push({i, v[i]});
    }

    while(!st.empty()) {
        answer[st.top().first] = -1;
        st.pop();
    }

    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; i++) {
        cin >> v[i];
        cnt[v[i]]++;
    }

    solve(v);

    return 0;
}