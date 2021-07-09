#include <deque>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        deque<char> left;
        deque<char> right;
        string s;
        cin >> s;

        for(int j = 0; j < s.size(); j++) {
            char c = s[j];

            if(c == '<') {
                if(!left.empty()) {
                    right.push_front(left.back());
                    left.pop_back();
                }
            } else if(c == '>') {
                if(!right.empty()) {
                    left.push_back(right.front());
                    right.pop_front();
                }
            } else if(c == '-') {
                if(!left.empty()) {
                    left.pop_back();
                }
            } else
                left.push_back(c);
        }

        int size = left.size();
        for(int i = 0; i < size; i++) {
            cout << left.front();
            left.pop_front();
        }

        size = right.size();
        for(int i = 0; i < size; i++) {
            cout << right.front();
            right.pop_front();
        }

        cout << '\n';
    }

    return 0;
}