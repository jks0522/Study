#include <iostream>
#include <queue>
using namespace std;

// n : 보드의 크기
// apple : 사과가 있는 위치는 true
// body : 뱀의 몸이 있으면 true
// snake : 뱀의 머리부터 꼬리까지의 위치를 저장하는 큐
// trans : 뱀의 방향 전환 정보를 저장하는 큐
// dy : 상, 우, 하, 좌 순으로 이동할때 y좌표 변화
// dx : 상, 우, 하, 좌 순으로 이동할때 x좌표 변화
int n;
bool apple[101][101], body[101][101];
queue<pair<int, int>> snake;
queue<pair<int, char>> trans;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void solve(void)
{
    // 방향을 나타내는 변수 dir을 우측 방향을 나타내는 인덱스 3으로 초기화
    int dir = 1;
    int sec = 0; // 게임이 끝날때까지 셀 초
    snake.push({1, 1});
    body[1][1] = true;
    while(true)
    {
        sec++;
        int y = snake.back().first + dy[dir];
        int x = snake.back().second + dx[dir];
        if(y > n || y <= 0 || x > n || x <= 0 || body[y][x])
            break;
        body[y][x] = true;
        snake.push({y, x});
        if(!apple[y][x])
        {
            body[snake.front().first][snake.front().second] = false;
            snake.pop();
        }
        else
            apple[y][x] = false;
        
        if(trans.front().first == sec)
        {
            char c = trans.front().second;
            if(c == 'L')
                dir = (dir + 3) % 4;
            else
                dir = (dir + 1) % 4;
            trans.pop();
        }
    }

    cout<<sec<<'\n';
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    
    int k;  // 사과의 개수
    cin >> k;

    for(int i=0; i<k; i++)
    {
        int r, c;   // r: 행, c: 열 번호
        cin >> r >> c;
        apple[r][c] = true;
    }

    int l;  // 방향 변환 횟수
    cin >> l;
    for(int i=0; i<l; i++)
    {
        int x;
        char c;
        cin >> x >> c;
        trans.push({x, c});
    }

    solve();

    return 0;
}