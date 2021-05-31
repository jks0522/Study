#include <iostream>
#include <queue>

using namespace std;

int f, s, g, u, d;

void bfs() {
    vector<int> v(f, -1);
    queue<int> q;
    q.push(s-1);
    v[s-1] = 0;

    while(!q.empty()) {
        int current = q.front();
        if(current == g-1) break;
        q.pop();

        int up = current + u;
        int down = current - d;

        if(up <= f-1 && v[up] == -1) {
            v[up] = v[current] + 1;
            q.push(up);
        }

        if(down >= 0 && v[down] == -1) {
            v[down] = v[current] + 1;
            q.push(down);
        }
    }

    if(v[g-1] == -1)
        cout<<"use the stairs\n";
    else
        cout<<v[g-1]<<'\n';
}

int main(void) {
    cin >> f >> s >> g >> u >> d;
    bfs();
}