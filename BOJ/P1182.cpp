#include <iostream>
#include <vector>

using namespace std;

int n,s, cnt;

void solve(const vector<int>& v, int index, int sum) {
    if(index == n+1) return;
    if(index != 0 && sum == s) cnt++;
    
    for(int i = index; i < n; i++) {
        solve(v, i+1, sum + v[i]);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> s;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    solve(v, 0, 0);

    cout << cnt << '\n';

    return 0;
}