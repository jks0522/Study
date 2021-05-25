#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[1001];
bool visit[1001];
queue<int> q;

// visit 배열의 원소를 모두 0으로 초기화 하는 함수
void init() {
    for(int i = 0; i < 1001; i++) {
        visit[i] = 0;
    }
}

// 깊이우선탐색
void dfs(int v) {
    cout<<v<<" ";
    visit[v] = true;
    for(int i = 0; i < adj[v].size(); i++) {
        if(!visit[adj[v][i]]) {
            dfs(adj[v][i]);
        }
    }
}

// 너비우선탐색
void bfs(int v) {
    cout<<v<<" ";
    visit[v] = true;
    q.push(v);

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int i = 0; i < adj[node].size(); i++) {
            int next = adj[node][i];
            if(!visit[next]) {
                visit[next] = true;
                q.push(next);
                cout<<next<<" ";
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, v;
    cin >> n >> m >> v;

    for(int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    for(int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(v);
    cout<<"\n";
    init();
    bfs(v);

    return 0;
}