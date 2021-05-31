#include <iostream>
#include <queue>

using namespace std;

int n, m;
int maze[100][100];

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, -1, 1};

// (0, 0) 부터 (n-1, m-1)까지 가는 모든 경우를 탐색해가며 최소 비용을 구함
// 이 때, 이미 저장되어 있는 값과 현재 값의 비교를 통해서 불필요한 탐색은 줄임
void bfs() {
    queue<pair<int, int>> q;
    // 각 칸에 도착하기 위해 부수는 벽의 최소 개수를 저장할 벡터
    vector<vector<int>> v(n, vector<int>(m, 10000));

    q.push({0, 0});
    v[0][0] = 0;

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        // 이웃한 칸을 비교해가며 v를 업데이트
        for(int i = 0; i < 4; i++) {
            int ty = y + dy[i];
            int tx = x + dx[i];
            if(tx >= 0 && tx <= m-1 && ty >= 0 && ty <= n-1) {
                // 이동할 칸이 벽이라면, 현재 칸까지 오는데 부순 벽의 개수에 1을 더한값과 비교
                // 이미 저장되어 있는 값보다 해당 값이 작으면 업데이트 후 큐에 push
                if(maze[ty][tx] == 1) {
                    if(v[ty][tx] > v[y][x] + 1) {
                        v[ty][tx] = v[y][x] + 1;
                        q.push({ty, tx});
                    }
                } else {
                    // 이동할 칸이 벽이 아니라면, 현재 칸까지 오는데 부순 벽의 개수와 비교
                    // 이미 저장되어 있는 값보다 해당 값이 작으면 업데이트 후 큐에 push
                    if(v[ty][tx] > v[y][x]) {
                        v[ty][tx] = v[y][x];
                        q.push({ty, tx});
                    }
                }
            }
        }
    }

    cout<<v[n-1][m-1]<<'\n'; // 결과 출력
}

int main(void) {
    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        for(int j =0; j < m; j++) {
            scanf("%1d", &maze[i][j]);
        }
    }

    bfs();
}