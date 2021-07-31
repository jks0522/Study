#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, cnt = -1;
long long answer = -1;

void solve(int digit, vector<int>& v) {
    if(v.size() == digit) {
        cnt++;
        if(cnt == n) {
            answer = 0;
            for(int i = v.size() - 1; i >= 0; i--) {
                answer += v[digit - i - 1] * pow(10, i);
            }
        }
        return;
    }

    if(v.size() == 0) {
        for(int i = digit - 1; i <= 9; i++) {
            v.push_back(i);
            solve(digit, v);
            v.pop_back();
        }
    } else {
        for(int i = digit-v.size() - 1; i < v.back(); i++) {
            v.push_back(i);
            solve(digit, v);
            if(cnt == n)
                return;
            v.pop_back();
        }
    }
        
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    vector<int> v;

    for(int i = 1; i <= 10; i++) {
        if(cnt == n)
            break;
        solve(i, v);
    }

    cout << answer << '\n';

    return 0;
}