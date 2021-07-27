#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;  // 도시의 수
int w[10][10];  // 도시 간 비용을 저장하는 배열
int answer = 2000000000;

void solve(vector<int>& path, vector<bool>& visited, int currentLength)
{
    if(path.size() == n) {
        if(!(w[path.back()][path[0]] == 0)) {
            answer = min(answer, currentLength + w[path.back()][path[0]]);
        }
        return;
    }
            
    
    if(path.size() == 0)
    {
        for(int i = 0; i < n; i++)
        {
            visited[i] = true;
            path.push_back(i);
            solve(path, visited, 0);
            visited[i] = false;
            path.pop_back();
        }
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(visited[i]) continue;
        int here = path.back();
        if(w[here][i] == 0) continue;
        path.push_back(i);
        visited[i] = true;
        solve(path, visited, currentLength + w[here][i]);
        visited[i] = false;
        path.pop_back();
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> w[i][j];

    vector<int> path;
    vector<bool> visited(n);

    solve(path, visited, 0);

    cout << answer << '\n';

    return 0;
}