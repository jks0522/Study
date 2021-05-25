#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> adj[101];
bool visit[101];
queue<int> q;

// 너비우선탐색
int bfs(int v) {
    int answer = 0;
    visit[v] = true;
    q.push(v);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int i = 0; i < adj[node].size(); i++) {
            int next = adj[node][i];
            if(!visit[next]) {
                q.push(next);
                visit[next] = true;
                answer++;
            }
        }
    }
    return answer;
}

int main(void) {
    int n, m;   // n: 컴퓨터의 수(정점), m: 컴퓨터 쌍의 수(간선)
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    
    int answer = bfs(1);
    cout << answer << "\n";

    return 0;
}