#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxValue = -1000000001, minValue = 1000000001;

void solve(const vector<int>& v, vector<int>& op, int index, int value) {
    if(index == v.size() - 1) {
        maxValue = max(maxValue, value);
        minValue = min(minValue, value);
        return;
    }

    for(int i = 0; i < 4; i++) {
        if(op[i] != 0) {
            int temp = value;
            if(i == 0) {
                value += v[index + 1];
                op[i]--;
            } else if(i == 1) {
                value -= v[index + 1];
                op[i]--;
            } else if(i == 2) {
                value *= v[index + 1];
                op[i]--;
            } else {
                value /= v[index + 1];
                op[i]--;
            }
            solve(v, op, index + 1, value);
            op[i]++;
            value = temp;
            
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> op(4);

    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for(int i = 0; i < 4; i++) {
        cin >> op[i];
    }

    solve(v, op, 0, v[0]);

    cout << maxValue << '\n' << minValue << '\n';


    return 0;
}