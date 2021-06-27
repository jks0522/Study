#include <queue>
#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string left;
    string right;

    cin >> left;

    int m;
    cin >> m;

    for(int i = 0; i < m; i++) {
        char cmd;
        cin >> cmd;
        if(cmd == 'L') {
            if(!left.empty()) {
                right.push_back(left.back());
                left.pop_back();
            }
        } else if(cmd == 'D') {
            if(!right.empty()) {
                left.push_back(right.back());
                right.pop_back();
            }
        } else if(cmd == 'B') {
            if(!left.empty()) {
                left.pop_back();
            }
        } else {
            char c;
            cin >> c;
            left.push_back(c);
        }
    }

    for(int i = 0; i < left.size(); i++) {
        cout << left[i];
    }

    int size = right.size();
    for(int i = size - 1; i >= 0; i--) {
        cout << right[i];
    }

    return 0;
}