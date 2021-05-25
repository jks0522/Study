#include <iostream>
#include <queue>

using namespace std;

int map[10][10] = {0};  // 인접행렬
int visit[10] = {0};    // 방문여부
queue<int> q;   // 너비우선탐색에 이용할 큐
int num, edge_num;  // 정점의 수, 간선의 수

// 너비우선탐색 함수
// v    너비우선탐색을 시작할 정점
void bfs(int v) {
    cout<<v<<"\n";  // 시작 정점 출력
    q.push(v);  // 큐에 v를 넣음
    visit[v] = 1;   // v를 방문했으므로 visit[v]를 1로 변경
    // 더 이상 방문할 정점이 없을 때까지 반복
    while(!q.empty()){
        int node = q.front();   // node에 현재 방문중인 정점을 대입
        q.pop();    // 큐에서 정점 하나를 꺼냄
        // 인접 정점 중 방문하지 않은 정점을 번호 순으로 출력하고
        // 방문여부를 1로 변경 후 큐에 집어넣음
        for(int i=1; i <= num; i++) {
            if(map[node][i]==1 && visit[i] ==0) {
                visit[i] = 1;
                cout<<i<<"\n";
                q.push(i);
            }
        }
    }
}

int main(){
    cin>>num>>edge_num; // 정점, 간선의 개수 입력
    // 간선들을 입력받으며 인접행렬을 변경
    for(int i = 0; i < edge_num; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        map[v1][v2] = map[v2][v1] = 1;
    }
    bfs(1); // 1부터 너비우선탐색 시행
    return 0;
}