    #include <iostream>
    #include <stack>
    #include <vector>
    using namespace std;

    long long solve(vector<long long>& h)
    {
        stack<int> st;
        h.push_back(0);
        long long ret = 0;
        for(int i = 0; i < h.size(); i++)
        {
            while(!st.empty() && h[st.top()] >= h[i])
            {
                int j = st.top();
                st.pop();
                int width = -1;
                if(st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;
                ret = max(ret, h[j] * width);
            }
            st.push(i);
        }
        return ret;
    }

    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        while(true)
        {
            int n;
            cin >> n;

            if(n == 0) break;
            vector<long long> h;
            h.reserve(n+1);
            for(int i = 0; i < n; i++)
            {
                long long height;
                cin >> height;
                h.push_back(height);
            }

            cout << solve(h) << '\n';
        }

        return 0;
    }