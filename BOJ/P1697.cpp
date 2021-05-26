#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 999999

int n, m;
vector<int> second(200002, MAX);
queue<int> q;

int bfs() {
    q.push(n);
    second[n] = 0;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        if(node == m)
            break;

        int next = node-1;
        if(next >= 0 && second[next] > second[node] + 1) {
            second[next] = second[node] + 1;
            q.push(next);
        }
        next = node+1;
        if(second[next] > second[node] + 1) {
            second[next] = second[node] + 1;
            q.push(next);
        }
        next = node*2;
        if(next <= 100000 && second[next] > second[node] + 1) {
            second[next] = second[node] + 1;
            q.push(next);
        }
    }

    return second[m];
}

int main(void) {
    cin >> n >> m;

    int answer = bfs();

    cout<<answer;
    return 0;
}