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

    vector<int> v(n, -1);

    for(int i = 0 ; i < n ; i++ ){
        int num;
        cin >> num;

        while(!s.empty() && s.top().second < num) {
            v[s.top().first] = num;
            s.pop();
        }

        s.push({i, num});
    }

    for(int i = 0; i < n; i++) {
        cout << v[i] << ' ';
    }
}