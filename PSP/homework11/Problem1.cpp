#include <iostream>

using namespace std;

int maps[10][10];   // 10X10 인접 행렬
int visited[10]={0};    // 방문 여부
int num;    // 간선의 개수
// 인접행렬의 모든 원소를 0으로 초기화 하는 함수
void init() {
    for(int i = 0 ; i < 10; i++) 
        for(int j = 0; j < 10; j++)
            maps[i][j] = 0;
}

// 깊이우선탐색 함수
// v    노드 번호
void dfs(int v)
{
    cout<<v<<endl;  // 노드 v 출력
    visited[v] = 0; // v를 방문했으므로 방문 여부를 0으로 변경
    // v의 인접 노드 중 방문하지 않은 노드를 방문(재귀이용)
    for(int i = 0; i <= num; i++)
    {
        if(maps[v][i] && visited[i])
            dfs(i);
    }
}

int main(void)
{
    int v1,v2;
    init(); // 인접행렬을 0으로 초기화
    cin>>num;
    // 모든 간선들을 입력받고
    // 인접행렬과 방문여부를 그에 맞게 변경함
    for(int i =0; i<num; i++)
    {
        cin>>v1>>v2;
        maps[v1][v2] = maps[v2][v1] = 1;
        visited[v1] = visited[v2] = 1;
    }
    dfs(1); // 깊이우선탐색 수행
    
    return 0;
}