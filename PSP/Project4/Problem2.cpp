#include <iostream>
#include <vector>


using namespace std;

vector<vector<int>> board;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct Robot{
    int x1,y1,x2,y2;
    Robot(int x1, int y1, int x2, int y2) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }

    void Move(int d) {
        x1 += dx[d];
        y1 += dy[d];
        x2 += dx[d];
        y2 += dy[d];
    }

    void Rotate(int d) {
        
    }
};

int bfs(vector<int>& distance, vector<int>& parent) {
    
}

int solve(vector<vector<int>>& board) {
    int answer = 0;

    

    return answer;
}

int main(void) {
    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++ ) {
        for(int j = 0; j < n; j++) {
            int num;
            cin >> num;
            board[i][j] = num;
        }
    }

    int answer = solve(board);
}