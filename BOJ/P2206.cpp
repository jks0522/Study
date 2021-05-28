#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int map[1001][1001];
int step[2][1001][1001];
int n, m;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int bfs(int y, int x) {
    queue<pair<pair<int, int>, bool>> q;
    q.push({{y, x}, 0});
    step[0][y][x] = 1;

    while(!q.empty()) {
        y = q.front().first.first;
        x = q.front().first.second;
        bool broke = q.front().second;
        q.pop();

        if(y == n && x == m)
            break;

        for(int i = 0; i < 4; i++) {
            int y2 = y + dy[i];
            int x2 = x + dx[i];
            if(y2 >= 1 && y2 <= n && x2 >=1 && x2 <= m) {
                if(!broke) {
                    if(map[y2][x2] == 0 && step[0][y2][x2] == 0) {
                        step[0][y2][x2] = step[0][y][x] + 1;
                        q.push({{y2, x2}, 0});
                    } else if(map[y2][x2] == 1) {
                        step[1][y2][x2] = step[0][y][x] + 1;
                        q.push({{y2, x2}, 1});
                    }
                } else {
                    if(map[y2][x2] == 0 && step[1][y2][x2] == 0) {
                        step[1][y2][x2] = step[1][y][x] + 1;
                        q.push({{y2, x2}, 1});
                    }
                }
            }
        }
    }

    int answer = 0;
    if(step[0][n][m] != 0 && step[1][n][m] != 0) {
        answer = min(step[0][n][m], step[1][n][m]);
    } else if(step[0][n][m] != 0) {
        answer = step[0][n][m];
    } else if(step[1][n][m] != 0) {
        answer = step[1][n][m];
    } else
        answer = -1;
    return answer;
}

int main(void) {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    cout<<bfs(1, 1)<<'\n';

}