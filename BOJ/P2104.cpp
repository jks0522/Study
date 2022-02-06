#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

const int LIMIT = 1000000000;
int result;

bool goStack(vector<string>& cmd, int input)
{
    stack<long long> st;
    st.push(input);
    for(int i = 0; i < cmd.size(); i++)
    {
        string s = cmd[i];
        if(s == "NUM")
            st.push(atoll(cmd[++i].c_str()));
        else if(s == "POP")
        {
            if(st.empty()) return false;
            st.pop();
        }    
        else if(s == "INV")
        {
            if(st.empty()) return false;
            long long top = st.top();
            st.pop();
            st.push(-top);
        }
        else if(s == "DUP")
        {
            if(st.empty()) return false;
            st.push(st.top());
        }
        else if(s == "SWP")
        {
            if(st.empty()) return false;
            long long first = st.top();
            st.pop();
            if(st.empty()) return false;
            long long second = st.top();
            st.pop();
            st.push(first);
            st.push(second);
        }
        else if(s == "ADD")
        {
            if(st.empty()) return false;
            long long first = st.top();
            st.pop();
            if(st.empty()) return false;
            first += st.top();
            st.pop();
            if(abs(first) > LIMIT) return false;
            st.push(first);
        }
        else if(s == "SUB")
        {
            if(st.empty()) return false;
            long long first = st.top();
            st.pop();
            if(st.empty()) return false;
            first = (st.top() - first);
            st.pop();
            if(abs(first) > LIMIT) return false;
            st.push(first);
        }
        else if(s == "MUL")
        {
            if(st.empty()) return false;
            long long first = st.top();
            st.pop();
            if(st.empty()) return false;
            long long second = st.top();
            st.pop();
            if(to_string(abs(first)).size() + to_string(abs(second)).size()-1 > 9 || abs(first * second) > LIMIT) return false;
            st.push(first * second);
        }
        else if(s == "DIV")
        {
            if(st.empty()) return false;
            long long first = st.top();
            st.pop();
            if(st.empty()) return false;
            long long second = st.top();
            st.pop();
            if(first > 0 && second > 0)
                st.push(second / first);
            else if(first < 0 && second < 0)
                st.push(abs(second) / abs(first));
            else if(first == 0)
                return false;
            else
                st.push(-(abs(second) / abs(first)));
        }
        else
        {
            if(st.empty()) return false;
            long long first = st.top();
            st.pop();
            if(st.empty()) return false;
            long long second = st.top();
            st.pop();
            if(first == 0)
                return false;
            else if(second > 0)
                st.push(second % abs(first));
            else
                st.push(-(abs(second) % abs(first)));
        }
    }

    if(st.size() != 1) return false;
    result = st.top();
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(true)
    {   
        string str;
        cin >> str;
        if(str != "QUIT")
        {
            vector<string> cmd;
            if(str != "END")
                cmd.push_back(str);
            
            while(str != "END")
            {
                cin >> str;
                if(str == "END") break;
                cmd.push_back(str);
            }

            int n;
            cin >> n;

            for(int i = 0; i < n; i++)
            {
                int input;
                cin >> input;
                if(goStack(cmd, input))
                    cout << result << '\n';
                else
                    cout << "ERROR\n";
            }
            cout << '\n';
        }
        else
            break;
    }

    return 0;
}