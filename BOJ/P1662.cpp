#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    stack<int> st;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ')')
        {
            int result = 0;
            while(st.top() != -1)
            {
                result += st.top();
                st.pop();
            }
            st.pop();
            result *= st.top();
            st.pop();
            st.push(result);
        }
        else if(s[i] == '(')
        {
            st.pop();
            st.push(s[i-1] - '0');
            st.push(-1);
        }
        else
            st.push(1);
    }

    int result = 0, size = st.size();

    for(int i = 0; i < size; i++)
    {
        result += st.top();
        st.pop();
    }

    cout << result << '\n';

    return 0;
}