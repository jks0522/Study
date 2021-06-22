#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int dy[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dx[] = {0, 0, -1, 1, -1, 1, -1, 1};

int solve(vector<vector<int>>& v, int h, int w) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visit(h, vector<bool> (w, false));

    int count = 0;

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(v[i][j] == 1 && !visit[i][j]) {
                q.push({i, j});
                visit[i][j] = true;
                count++;

                while(!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    for(int i = 0; i < 8; i++) {
                        int cy = y + dy[i];
                        int cx = x + dx[i];
                        if(cy >= 0 && cy <= h-1 && cx >= 0 && cx <= w-1 && v[cy][cx] == 1 && !visit[cy][cx] ) {
                            q.push({cy, cx});
                            visit[cy][cx] = true;
                        }
                    }
                }
            }
        }
    }
    return count;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(true) {
        int w, h;
        cin >> w >> h;

        if(w == 0 && h == 0)
            break;

        vector<vector<int>> v(h, vector<int>(w, 0));

        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cin >> v[i][j];
            }
        }

        cout << solve(v, h, w) << '\n';

    }


    return 0;
}