#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int map[25][25];
bool visit[25][25];
queue<pair<int,int>> q;
vector<int> v;
int number;

void bfs(int y, int x) {
    visit[y][x] = true;
    q.push({y, x});
    
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        y = p.first;
        x = p.second;
        if(y != 0) {
            if(!visit[y-1][x] && map[y-1][x] == 1) {
                v[number]++;
                q.push({y-1, x});
                visit[y-1][x] = true;
            }
        }
        if(y != 24) {
            if(!visit[y+1][x] && map[y+1][x] == 1) {
                v[number]++;
                q.push({y+1, x});
                visit[y+1][x] = true;
            }
        }
        if(x != 0) {
            if(!visit[y][x-1] && map[y][x-1] == 1) {
                v[number]++;
                q.push({y, x-1});
                visit[y][x-1] = true;
            }
        }
        if(x != 24) {
            if(!visit[y][x+1] && map[y][x+1] == 1) {
                v[number]++;
                q.push({y, x+1});
                visit[y][x+1] = true;
            }
        }
    }
}

int main(void) {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(map[i][j] == 1 && !visit[i][j]) {
                v.push_back(1);
                bfs(i, j);
                number++;
            }
        }
    }

    sort(v.begin(), v.end());

    printf("%d\n", v.size());
    for(int i = 0; i < v.size(); i++) {
        printf("%d\n", v[i]);

    }
    return 0;
}