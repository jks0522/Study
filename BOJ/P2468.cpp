#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, -1, 1};

int bfs(vector<vector<int>>& v, int n, int height) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visit(n, vector<bool>(n, false));
    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!visit[i][j] && v[i][j] > height) {
                q.push({i, j});
                visit[i][j] = true;
                count++;

                while(!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    for(int i = 0; i < 4; i++) {
                        int cy = y + dy[i];
                        int cx = x + dx[i];
                        if(cy >= 0 && cy <= n-1 && cx >= 0 && cx <= n-1 && !visit[cy][cx] && v[cy][cx] > height) {
                            visit[cy][cx] = true;
                            q.push({cy, cx});
                        }
                    }
                }
            }
        }
    }

    return count;
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, min = 100, max = 0, answer = 0;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
            if(v[i][j] < min)
                min = v[i][j];
            if(v[i][j] > max)
                max = v[i][j];
        }
    }

    for(int i = min-1; i < max; i++) {
        int result = bfs(v, n, i);
        if(result >= answer)
            answer = result;
    }

    cout << answer << '\n';

    return 0;
}