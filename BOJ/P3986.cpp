#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, cnt = 0;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        stack<char> st;
        string s;
        cin >> s;

        for(int j = 0; j < s.size(); j++) {
            if(!st.empty() && st.top() == s[j])
                st.pop();
            else
                st.push(s[j]);
        }

        if(st.empty())
            cnt++;
    }


    cout << cnt << '\n';
    return 0;
}