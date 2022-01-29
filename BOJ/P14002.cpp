#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int n;
int cache[1001], A[1000], choices[1001];

int lis(int start)
{
    int& ret = cache[start+1];
    if(ret != -1) return ret;
    ret = 1;
    int bestNext = -1;
    for(int next = start+1; next < n; next++)
        if(start == -1 || A[start] < A[next])
        {
            int cand = lis(next) + 1;
            if(cand > ret)
            {
                ret = cand;
                bestNext = next;
            }
        }
    choices[start+1] = bestNext;
    return ret;
}

void reconstruct(int start, vector<int>& seq)
{
    if(start != -1) seq.push_back(A[start]);
    int next = choices[start+1];
    if(next != -1) reconstruct(next, seq);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(cache, -1, sizeof(cache));

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];

    cout<<lis(-1)-1<<'\n';
    vector<int> seq;
    reconstruct(-1, seq);

    for(int i = 0; i < seq.size(); i++)
        cout << seq[i] << ' ';
    cout << '\n';
    return 0;
}