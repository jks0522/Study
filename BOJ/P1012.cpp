#include <iostream>
#include <queue>

using namespace std;

int field[50][50];
bool visit[50][50];
queue<pair<int, int>> q;

void init() {
    for(int i = 0; i < 50; i++) {
        for(int j = 0; j < 50; j++) {
            field[i][j] = 0;
            visit[i][j] = 0;
        }
    }
}

void bfs(int y, int x) {
    visit[y][x] = true;
    q.push({y, x});
    
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        y = p.first;
        x = p.second;
        if(y != 0) {
            if(!visit[y-1][x] && field[y-1][x] == 1) {
                q.push({y-1, x});
                visit[y-1][x] = true;
            }
        }
        if(y != 49) {
            if(!visit[y+1][x] && field[y+1][x] == 1) {
                q.push({y+1, x});
                visit[y+1][x] = true;
            }
        }
        if(x != 0) {
            if(!visit[y][x-1] && field[y][x-1] == 1) {
                q.push({y, x-1});
                visit[y][x-1] = true;
            }
        }
        if(x != 49) {
            if(!visit[y][x+1] && field[y][x+1] == 1) {
                q.push({y, x+1});
                visit[y][x+1] = true;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int m, n, k;
        int answer = 0;
        cin >> m >> n >> k;

        for(int j = 0; j < k; j++) {
            int v1, v2;
            cin >> v1 >> v2;
            field[v2][v1] = 1;
        }

        for(int y = 0; y < n; y++) {
            for(int x = 0; x < m; x++) {
                if(field[y][x] == 1 && !visit[y][x]) {
                    bfs(y, x);
                    answer++;
                }
            }
        }

        cout<<answer<<"\n";
        init();
    }

    return 0;
}