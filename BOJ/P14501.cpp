#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, maximum = 0;

void solve(const vector<pair<int, int>>& sch, int index, int sum) {
    if(index >= n) {
        maximum = max(maximum, sum);
        return;
    }
    for(int i = index; i < n; i++) {
        if(index + sch[index].first <= n)   
            sum += sch[index].second;
        solve(sch, index + sch[index].first, sum);
        if(index + sch[index].first <= n)
            sum -= sch[index].second;
        index++;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n;
    vector<pair<int, int>> sch(n);
    for(int i = 0; i < n; i++) {
        cin >> sch[i].first >> sch[i].second;
    }
    solve(sch, 0, 0);
    cout << maximum << '\n';

    return 0;
}