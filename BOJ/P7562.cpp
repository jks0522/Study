#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> q;

int x1, y1, x2, y2;

int bfs(vector<vector<int>> visit) {
    visit[y1][x1] = 1;
    q.push({y1, x1});

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        
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

        cin >> x1 >> y1 >> x2 >> y2;
        int answer = bfs(visit);
        cout<<answer<<"\n";
    }
}