#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> cheese;


int n, m;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, -1, 1};



void bfs(vector<vector<int>>& map) {
    queue<pair<int, int>> q;
    vector<vector<int>> v(n, vector<int>(m, 0));

    q.push({0,0});
    v[0][0] = 1;

    while(!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny >= 0 && ny <= n-1 && nx >= 0 && nx <= m-1) {
                if(map[ny][nx] == 0 && v[ny][nx] == 0) {
                    v[ny][nx] = 1;
                    q.push({ny, nx});
                } else if(map[ny][nx] == 1) {
                    v[ny][nx]++;
                }
            } 
        }
    }

    int size = cheese.size();
    for(int i = 0; i < size; i++) {
        if(v[cheese.front().first][cheese.front().second] >= 1) {
            map[cheese.front().first][cheese.front().second] = 0;
        } else {
            cheese.push(cheese.front());
        }
        cheese.pop();
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
            if(map[i][j] == 1)
                cheese.push({i, j});
        }
    }
    
    int answer = 0;
    int count;
    while(!cheese.empty()) {
        count = cheese.size();
        bfs(map);
        answer++;
    }

    cout << answer << '\n' << count << '\n';
}