#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> getPartialMatch(const string& P)
{
    int m = P.size();
    vector<int> pi(m, 0);

    int begin = 1, matched = 0;
    while(begin + matched < m)
    {
        if(P[begin + matched] == P[matched])
        {
            matched++;
            pi[begin + matched - 1] = matched;
        }
        else
        {
            if(matched == 0)
                begin++;
            else
            {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }

    return pi;
}

vector<int> kmpSearch(const string& T, const string& P)
{
    vector<int> pi = getPartialMatch(P);
    vector<int> ret;
    
    int n = T.size(), m = P.size();
    int begin = 0, matched = 0;
    while(begin <= n - m)
    {
        if(matched < m && T[begin + matched] == P[matched])
        {
            matched++;
            if(matched == m) ret.push_back(begin + 1);
        }
        else
        {
            if(matched == 0)
                begin++;
            else
            {
                begin += matched - pi[matched - 1];
                matched = pi[matched -1];
            }
        }
    }

    return ret;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string T, P;
    getline(cin, T);
    getline(cin, P);

    vector<int> result = kmpSearch(T, P);
    cout << result.size() << '\n';
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << '\n';

    return 0;
}