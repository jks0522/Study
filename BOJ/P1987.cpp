#include <iostream>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

vector<int> v(26, 0);
char board[21][21];
int r, c, answer= 1, step=1;


int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};


void dfs(int y, int x) {
    v[board[0][0]- 'A'] = 1;

    for(int i = 0; i < 4; i++) {
        int y2 = y + dy[i];
        int x2 = x + dx[i];
        if(v[board[y2][x2] - 'A'] == 0 && x2 < c && y2 < r && x2 >= 0 && y2 >= 0) {
            v[board[y2][x2] - 'A'] = 1;
            step++;
            answer = max(step, answer);
            dfs(y2, x2);
            v[board[y2][x2] - 'A'] = 0;
            step--;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> r >> c;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            char c;
            cin >> c;
            board[i][j] = c;
        }
    }

    dfs(0, 0);
    cout<<answer<<'\n';
}