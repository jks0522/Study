#include <iostream>
#include <vector>

using namespace std;

int n;

char paint[100][100];
char wrong[100][100];
bool visit[100][100];
bool visit2[100][100];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void dfs(int y, int x) {
    visit[y][x] = true;
    
    for(int i = 0; i < 4; i++) {
        int x2 = x + dx[i];
        int y2 = y + dy[i];
        if(!visit[y2][x2] && paint[y2][x2] == paint[y][x] && x2 >= 0 && y2 >= 0 && x2 < n && y2 < n) {
            visit[y2][x2] = true;
            dfs(y2, x2);
        }
    }
}

void dfs2(int y, int x) {
    visit2[y][x] = true;
    
    for(int i = 0; i < 4; i++) {
        int x2 = x + dx[i];
        int y2 = y + dy[i];
        if(!visit2[y2][x2] && wrong[y2][x2] == wrong[y][x] && x2 >= 0 && y2 >= 0 && x2 < n && y2 < n) {
            visit2[y2][x2] = true;
            dfs2(y2, x2);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int normal = 0, weak = 0;

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char c;
            cin >> c;
            paint[i][j] = c;
            if(c == 'B')
                wrong[i][j] = c;
            else
                wrong[i][j] = 'R';
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!visit[i][j]) {
                dfs(i, j);
                normal++;
            }  
            if(!visit2[i][j]) {
                dfs2(i, j);
                weak++;
            }  
        }
    }

    cout<<normal<<" "<<weak<<'\n';


    return 0;
}