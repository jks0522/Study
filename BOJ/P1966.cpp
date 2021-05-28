#include <iostream>
#include <queue>

using namespace std;

int solve(priority_queue<pair<int, int>>& pq, int n, int m) {
    
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < n; i++) {
            int num;
            cin >> num;
            pq.push({num, i});
        }

        cout << solve(pq, n, m) << '\n';
    }
}