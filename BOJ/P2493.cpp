#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stack<pair<int, int>> s;

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        if(s.empty()) {
            cout << "0 ";
            s.push({num, i});
        }
        else {
            while(true) {
                if(s.top().first >= num) {
                    cout << s.top().second << ' ';
                    s.push({num, i});
                    break;
                } else {
                    s.pop();
                    if(s.empty()) {
                        cout << "0 ";
                        s.push({num, i});
                        break;
                    }
                }
            }  
        }
    }

    return 0;
}