#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int maze[100][100];
bool visit[100][100];
vector<vector<int>>step(100, vector<int>(100, 10000));
queue<pair<int,int>> q;


int bfs(int y, int x) {
    visit[y][x] = true;
    q.push({y, x});
    step[y][x] = 1;
    
    while(!q.empty()) {
        int count = 0;
        pair<int, int> p = q.front();
        q.pop();

        y = p.first;
        x = p.second;

        if(x == m-1 && y == n-1) {
            return step[y][x];
        }

        if(y != 0) {
            if(!visit[y-1][x] && maze[y-1][x] == 1) {
                q.push({y-1, x});
                visit[y-1][x] = true;
                step[y-1][x] = min(step[y-1][x], step[y][x] + 1);
            }
        }
        if(y != n-1) {
            if(!visit[y+1][x] && maze[y+1][x] == 1) {
                q.push({y+1, x});
                visit[y+1][x] = true;
                step[y+1][x] = min(step[y+1][x], step[y][x] + 1);
            }
        }
        if(x != 0) {
            if(!visit[y][x-1] && maze[y][x-1] == 1) {
                q.push({y, x-1});
                visit[y][x-1] = true;
                step[y][x-1] = min(step[y][x-1], step[y][x] + 1);
            }
        }
        if(x != m-1) {
            if(!visit[y][x+1] && maze[y][x+1] == 1) {
                q.push({y, x+1});
                visit[y][x+1] = true;
                step[y][x+1] = min(step[y][x+1], step[y][x] + 1);
            }
        }
    }
}

int main(void) {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%1d", &maze[i][j]);
        }
    }

    int answer = bfs(0, 0);
    cout<<answer<<"\n";
}