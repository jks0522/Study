#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stack<pair<int, int>> s;    // first: 인덱스, second: 값

    int n;
    cin >> n;

    vector<int> v(n, 0);

    for(int i = 0 ; i < n ; i++ ){
        int num;
        cin >> num;

        while(!s.empty() && s.top().second <= num) {
            v[s.top().first] = i - s.top().first - 1;
            s.pop();
        }

        s.push({i, num});
    }

    while(!s.empty()) {
        v[s.top().first] = n - 1 - s.top().first;
        s.pop();
    }

    long long answer = 0;

    for(int i = 0; i < n; i++) {
        answer += v[i];
    }

    cout << answer << '\n';

    return 0;
}