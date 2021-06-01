#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void solve(string str, string explosion) {
    stack<pair<char, int>> s;
    vector<char> v;

    int length = explosion.size();
    int count = 0;

    for(int i = 0; i < str.size(); i++) {
        if(!s.empty()) count = s.top().second;
        if(str[i] == explosion[0]) {
            if(length == 1) {
                continue;
            }
            s.push({str[i], 1});

        }
        else if(str[i] == explosion[count]) {
            count++;
            s.push({str[i], count});
            if(count == length) {
                for(int j = 0; j < length; j++) {
                    s.pop();
                }
                if(s.empty())
                    count = 0;
                else
                    count = s.top().second;
            }
        } else {
            s.push({str[i], 0});
        }
    }

    if(s.empty())
        cout<<"FRULA"<<'\n';
    else {
        while(!s.empty()) {
            v.push_back(s.top().first);
            s.pop();
        }

        for(int i = v.size()-1; i >= 0; i--) {
            cout << v[i];
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str, explosion;
    cin >> str >> explosion;

    solve(str, explosion);

    return 0;
}