#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> q;

int x4, y4, x2, y2;

int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

int bfs(vector<vector<int>> visit) {
    visit[y4][x4] = 1;
    q.push({y4, x4});

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if(y == y2 && x == x2) {
            while(!q.empty())
                q.pop();
            return visit[y][x]-1;
        }

        for(int i = 0; i < 8; i++) {
            int y3 = y + dy[i];
            int x3 = x + dx[i];
            if(y3 >= 0 && y3 < visit.size() && x3 >= 0 && x3 < visit[0].size() && visit[y3][x3] == 0 ) {
                q.push({y3, x3});
                visit[y3][x3] = visit[y][x] + 1;
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
        int l;
        cin >> l;
        vector<vector<int>> visit(l, vector<int>(l, 0));

        cin >> x4 >> y4 >> x2 >> y2;
        int answer = bfs(visit);
        cout<<answer<<"\n";
    }
}