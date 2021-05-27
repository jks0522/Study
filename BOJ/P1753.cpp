#include <iostream>
#include <queue>

using namespace std;

vector<pair<int, int>> adj[20001];
vector<int> minimum(20001, 40000000);

struct cmp {
    bool operator()(pair<int, int> p1, pair<int, int> p2) {
        return p1.second > p2.second;
    }
};

void dijkstra(int v) {
    priority_queue<pair<int,int>, vector<pair<int, int>>, cmp> pq;
    minimum[v] = 0;
    pq.push({v, 0});

    while(!pq.empty()) {
        int node = pq.top().first;
        int distance = pq.top().second;
        pq.pop();

        if(minimum[node] < distance) continue;
        for(int i = 0; i < adj[node].size(); i++) {
            int next = adj[node][i].first;
            int nextDistance = distance + adj[node][i].second;
            if(nextDistance < minimum[next]) {
                minimum[next] = nextDistance;
                pq.push({next, nextDistance});
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e, k;
    cin >> v >> e >> k;

    for(int i = 0; i < e; i++) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        adj[v1].push_back({v2, w});
    }

    dijkstra(k);

    for(int i = 1; i <= v; i ++) {
        int num = minimum[i];
        if(num == 40000000)
            cout<<"INF\n";
        else
            cout << minimum[i] << '\n';
    }

    return 0;
}