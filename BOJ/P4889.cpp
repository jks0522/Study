#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cnt = 1;

    while(true)
    {
        string str;
        cin >> str;
        if(str[0] == '-')
            break;
        
        int clcnt = 0, opcnt = 0;
        stack<char> st;
        
        for(int i = 0; i < str.size(); i++)
        {
            char bracket = str[i];
            if(bracket == '{')
            {
                st.push(bracket);
                opcnt++;
            }
            else
            {
                if(!st.empty() && st.top() == '{')
                {
                    st.pop();
                    opcnt--;
                }
                else
                {
                    st.push(bracket);
                    clcnt++;
                }
            }
        }

        cout << cnt << ". ";
        if(st.size() == 0)
            cout << "0\n";
        else
        {
            if(opcnt == 0 || clcnt == 0)
                cout << (opcnt + clcnt) / 2 << '\n';
            else if(opcnt % 2 == 0 && clcnt % 2 == 0)
                cout << (opcnt + clcnt) / 2 << '\n';
            else
                cout << (2 + (--opcnt + --clcnt) / 2) << '\n';
        }

        cnt++;
    }

    return 0;
}