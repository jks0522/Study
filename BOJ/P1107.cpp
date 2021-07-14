#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int answer = -1, gNum;

int vtoi(const vector<int>& v) {
    int decimal = 1;
    int ret = 0;
    for(int i = v.size() -1; i >= 0; i--) {
        ret += v[i] * decimal;
        decimal *= 10;
    }
    return ret;
}

void solve(const vector<int>& goal, const vector<bool>& isBroken, vector<int>& selected) {
    int sNum = vtoi(selected);

    if(selected.size() == 0) {
        answer = abs(gNum - 100);
        if(!isBroken[0])
            answer = min(answer, gNum + 1);
    }
    if(answer == 0)
        return;
    if((selected.size() > 0 && selected.size() >= goal.size() -1) && selected.size() <= goal.size() + 1) {
        answer = min(answer, (int)selected.size() + abs(gNum- sNum));
        
        if(selected.size() == goal.size() + 1 || sNum > gNum)
            return;
    }

    int selectedNum = selected.size();
    for(int i = 0; i <= 9; i++) {
        if(!isBroken[i]) {
            selected.push_back(i);
            solve(goal, isBroken, selected);
            selected.pop_back();
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string n;
    cin >> n;

    vector<int> goal;
    for(int i = 0; i < n.size(); i++)
        goal.push_back(n[i] - '0');
    
    gNum = vtoi(goal);

    int m;
    cin >> m;

    vector<bool> isBroken(10);
    for(int i = 0; i < m; i++) {
        int num;
        cin >> num;
        isBroken[num] = true;
    }

    vector<int> selected;
    solve(goal, isBroken, selected);
    cout << answer << '\n';

    return 0;
}