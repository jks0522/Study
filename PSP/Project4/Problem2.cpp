#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

vector<vector<int>> board;

class Robot {
public:
    int x1, x2, y1, y2;

    Robot(int x1, int y1, int x2, int y2) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }

    void moveUp() {
        y1--;
        y2--;
    }

    void moveDown() {
        y1++;
        y2++;
    }

    void moveRight() {
        x1++;
        x2++;
    }

    void moveLeft() {
        x1--;
        x2--;
    }
};

int solve(vector<vector<int>> board) {
    int answer = 0;

    board[]

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