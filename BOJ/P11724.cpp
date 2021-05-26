#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[1001];
bool visit[1001];

void dfs(int v) {
    visit[v] = true;
    for(int i = 0; i < adj[v].size(); i++) {
        if(!visit[adj[v][i]])
            dfs(adj[v][i]);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    int answer = 0;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    for(int i = 1; i <= n; i++) {
        if(!visit[i]) {
            dfs(i);
            answer++;
        }
    }

    cout<<answer<<'\n';
}