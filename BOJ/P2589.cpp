#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, answer;
char map[50][50];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void solve(int y, int x) {
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    q.push({y, x});
    dist[y][x] = 0;

    while(!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(map[ny][nx] == 'L' && dist[ny][nx] == -1 && ny >= 0 && ny < n && nx >= 0 && nx < m) {
                q.push({ny, nx});
                dist[ny][nx] = dist[cy][cx] + 1;
                answer = max(answer, dist[ny][nx]);
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++)
            map[i][j] = s[j];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == 'L')
                solve(i, j);
        }
    }

    cout << answer << '\n';

    return 0;
}