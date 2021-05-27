#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> adj[101];

int bfs(int v) {
    vector<bool> visit(n+1);
    queue<int> q;
    vector<int> level(n+1);

    q.push(v);
    visit[v] = true;
    level[v] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for(int i = 0; i < adj[node].size(); i++) {
            int next = adj[node][i];
            if(!visit[next]) {
                visit[next] = true;
                q.push(next);
                level[next] = level[node] + 1;
            }
        }
    }

    int answer = 0;

    for(int i = 1; i <= n; i++) {
        answer += level[i];
    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int answer = 999;
    int index = 0;

    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    for(int i = 1; i <= n; i++) {
        int result = bfs(i);
        if(answer > result) {
            answer = result;
            index = i;
        }
    }

    cout << index << '\n';

    return 0;
}
