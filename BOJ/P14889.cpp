#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, minimum=50000;
bool isA[20];

void solve(const vector<vector<int>>& team, vector<int>& a) {
    if(a.size() == n/2) {
        vector<int> b;
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < n; i++) {
            if(!isA[i])
                b.push_back(i);
        }
        for(int i = 0; i < n/2-1; i++) {
            for(int j = i+1; j < n/2; j++) {
                sum1 += team[a[i]][a[j]] + team[a[j]][a[i]];
                sum2 += team[b[i]][b[j]] + team[b[j]][b[i]];
            }
        }
        minimum = min(minimum, abs(sum2 - sum1));
        return;
    }

    int index = a.empty() ? 0 : a.back() + 1;
    for(int i = index; i < n; i++) {
        if(a.empty() && i >= n/2)
            break;
        a.push_back(i);
        isA[i] = true;
        solve(team, a);
        a.pop_back();
        isA[i] = false;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<vector<int>> team(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> team[i][j];
        }
    }

    vector<int> a;
    vector<int> b;

    solve(team, a);

    cout << minimum << '\n';

    return 0;
}