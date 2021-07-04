#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(const vector<int>& v) {
    int answer = v[0], size = v.size();
    vector<int> temp(size);
    temp[0] = v[0];
    for(int i = 1; i < size; i++) {
        temp[i] = max(temp[i-1] + v[i], v[i]);
        answer = max(temp[i], answer);
    }

    cout << answer;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    solve(v);

    return 0;
}