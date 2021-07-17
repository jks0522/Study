#include <iostream>
#include <vector>

using namespace std;

int board[9][9];
bool isSolved;

bool check(int y, int x) {
    int current = board[y][x];

    for(int i = 0; i < 9; i++) {
        if(i != x && board[y][i] == current) {
            return false;  
        }
    }

    for(int i = 0; i < 9; i++) {
        if(i != y && board[i][x] == current) {
            return false;
        }
    }

    for(int i = 0; i < 3; i++) {
        int ty = y/3*3 + i;
        for(int j = 0; j < 3; j++) {
            int tx = x/3*3 + j;
            if((ty != y || tx != x) && board[ty][tx] == current) {
                return false;
            }
        }
    }

    return true;
}

void solve(int y, int x) {
    if(y == 9 && x == 0) {
        isSolved = true;
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        return;
    }

    if(board[y][x] == 0) {
        for(int i = 1; i <= 9; i++) {
            if(isSolved)
                return;
            board[y][x] = i;
            if(check(y, x))
                solve(y + (x+1)/9, (x+1)%9);
            board[y][x] = 0;
        }
    } else {
        solve(y + (x+1)/9, (x+1)%9);
    }
}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    solve(0, 0);

    return 0;
}