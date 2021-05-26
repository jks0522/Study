#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, count1;
int box[1000][1000];
vector<vector<int>>step(1000, vector<int>(1000, 1000000));
vector<pair<int,int>> tomato;
queue<pair<int,int>> q;


int bfs() {
    int answer = 0;
    for(int i = 0; i < tomato.size(); i++) {
        pair<int, int> p = tomato[i];
        q.push(p);
        step[p.first][p.second] = 0;
        count1++;
    }
    
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        int y = p.first;
        int x = p.second;

        if(y != 0) {
            if(box[y-1][x] == 0 && step[y-1][x] == 1000000) {
                q.push({y-1, x});
                step[y-1][x] = step[y][x] + 1;
                answer = max(answer, step[y-1][x]);
                count1++;
            }
        }
        if(y != n-1) {
            if(box[y+1][x] == 0 && step[y+1][x] == 1000000) {
                q.push({y+1, x});
                step[y+1][x] = step[y][x] + 1;
                answer = max(answer, step[y+1][x]);
                count1++;
            }
        }
        if(x != 0) {
            if(box[y][x-1] == 0 && step[y][x-1] == 1000000) {
                q.push({y, x-1});
                step[y][x-1] = step[y][x] + 1;
                answer = max(answer, step[y][x-1]);
                count1++;
            }
        }
        if(x != m-1) {
            if(box[y][x+1] == 0 && step[y][x+1] == 1000000) {
                q.push({y, x+1});
                step[y][x+1] = step[y][x] + 1;
                answer = max(answer, step[y][x+1]);
                count1++;
            }
        }
    }
    return answer;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int count2 = 0;

    cin >> m >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int num;
            cin >> num;
            box[i][j] = num;
            if(num == 1)
                tomato.push_back({i, j});
            else if(num == -1)
                count2++;
        }
    }

    int answer = bfs();
    
    if(count1 != n*m - count2)
        cout<<"-1\n";
    else
        cout<<answer<<"\n";

    return 0;
}