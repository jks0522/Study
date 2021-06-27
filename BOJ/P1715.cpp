#include <queue>
#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> pq;

    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        pq.push(num);
    }

    long long answer = 0;

    while(true) {
        if(pq.size() == 1)
            break;
        int pack1 = pq.top();
        pq.pop();
        int pack2 = pq.top();
        pq.pop();
        answer += pack1 + pack2;
        pq.push(pack1 + pack2);
    }

    cout << answer << '\n';

    return 0;
}