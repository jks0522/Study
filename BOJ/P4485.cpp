#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, -1, 1};

int solve(const vector<vector<int>>& cave, int n) {
    queue<pair<int, int>> q;
    vector<vector<int>> visit(n, vector<int>(n, -1));
    
    visit[0][0] = cave[0][0];
    q.push({0, 0});

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int cy = y + dy[i];
            int cx = x + dx[i];

            if(cy >= 0 && cy <= n-1 && cx >= 0 && cx <= n-1 && (visit[cy][cx] == -1 || visit[cy][cx] > visit[y][x] + cave[cy][cx])) {
                visit[cy][cx] = visit[y][x] + cave[cy][cx];
                q.push({cy, cx});
            }
        }
    }

    return visit[n-1][n-1];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num = 0;

    while(true) {
        int n;
        cin >> n;

        if(n == 0)
            break;

        num++;

        vector<vector<int>> cave(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> cave[i][j];
            }
        }

        cout << "Problem " << num << ": " << solve(cave, n) << "\n";
        
    }

    return 0;
}