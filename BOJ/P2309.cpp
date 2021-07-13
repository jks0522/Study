#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> height(9);

bool finish = false;

void solve(vector<int>& picked, int index, int toPick, int sum) {
    if(toPick == 0) {
        if(sum != 100)
            return;
        else {
            priority_queue<int, vector<int>, greater<int>> pq;
            for(int i = 0; i < 7; i++) {
                pq.push(picked[i]);
            }
            for(int i = 0; i < 7; i++) {
                cout << pq.top() << '\n';
                pq.pop();
            }

            finish = true;
            return;
        }
    }
    for(int i = index; i < 9; i++) {
        if(sum+height[i] > 100)
            continue;
        picked.push_back(height[i]);
        solve(picked, i+1, toPick-1, sum+height[i]);
        picked.pop_back();

        if(finish)
            return;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < 9; i++) {
        cin >> height[i];
    }
    vector<int> picked;

    solve(picked, 0, 7, 0);

    return 0;
}