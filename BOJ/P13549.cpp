#include <iostream>
#include <queue>

using namespace std;

void bfs(int n, int k) {
    vector<int> v(100001, 999999);
    queue<int> q;
    
    v[n] = 0;
    q.push(n);

    while(!q.empty()) {
        int current = q.front();
        q.pop();

        if(current == k) break;

        if(current * 2 <= 100000 && v[current*2] > v[current]) {
            q.push(current*2);
            v[current*2] = v[current];
        }

        if(current >= 1 && v[current-1] > v[current]+1) {
            q.push(current-1);
            v[current-1] = v[current] + 1;
        }

        if(current <= 99999 && v[current+1] > v[current]+1) {
            q.push(current+1);
            v[current+1] = v[current] + 1;
        }
    }
    cout<<v[k]<<'\n';
}

int main(void) {
    int n, k;
    cin >> n >> k;
    bfs(n, k);
}