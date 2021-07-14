#include <iostream>
#include <vector>

using namespace std;

bool maxSolved = false;
bool minSolved = false;

void solveMax(const vector<char>& a, vector<int>& selected, vector<bool>& isUsed) {
    int sLength = selected.size();
    if(sLength == a.size() + 1) {
        for(int i = 0; i < sLength; i++) {
            cout<<selected[i];
        }
        cout<<'\n';
        maxSolved = true;
        return;
    }

    for(int i = 9; i >= 0; i--) {
        if(maxSolved)
            return;
        if(isUsed[i])
            continue;
        if(sLength == 0) {
            selected.push_back(i);
            isUsed[i] = true;
            solveMax(a, selected, isUsed);
            selected.pop_back();
            isUsed[i] = false;
        } else {
            int prev = selected.back();
            char c = a[sLength - 1];
            if(c == '>') {
                if(prev > i) {
                    selected.push_back(i);
                    isUsed[i] = true;
                    solveMax(a, selected, isUsed);
                    selected.pop_back();
                    isUsed[i] = false;
                } else
                    continue;
            } else {
                if(prev < i) {
                    selected.push_back(i);
                    isUsed[i] = true;
                    solveMax(a, selected, isUsed);
                    selected.pop_back();
                    isUsed[i] = false;
                } else
                    continue;
            }
        }
    }
}

void solveMin(const vector<char>& a, vector<int>& selected, vector<bool>& isUsed) {
    int sLength = selected.size();
    if(sLength == a.size() + 1) {
        for(int i = 0; i < sLength; i++) {
            cout<<selected[i];
        }
        cout<<'\n';
        minSolved = true;
        return;
    }

    for(int i = 0; i <= 9; i++) {
        if(minSolved)
            return;
        if(isUsed[i])
            continue;
        if(sLength == 0) {
            selected.push_back(i);
            isUsed[i] = true;
            solveMin(a, selected, isUsed);
            selected.pop_back();
            isUsed[i] = false;
        } else {
            int prev = selected.back();
            char c = a[sLength - 1];
            if(c == '>') {
                if(prev > i) {
                    selected.push_back(i);
                    isUsed[i] = true;
                    solveMin(a, selected, isUsed);
                    selected.pop_back();
                    isUsed[i] = false;
                } else
                    continue;
            } else {
                if(prev < i) {
                    selected.push_back(i);
                    isUsed[i] = true;
                    solveMin(a, selected, isUsed);
                    selected.pop_back();
                    isUsed[i] = false;
                } else
                    continue;
            }
        }
    }
}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<char> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<bool> isUsed(10);
    vector<int> selected;

    solveMax(a, selected, isUsed);

    for(int i = 0; i < 10; i++) {
        isUsed[i] = false;
    }
    solveMin(a, selected, isUsed);

    return 0;
}