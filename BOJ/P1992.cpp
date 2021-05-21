#include <iostream>
using namespace std;

int video[64][64];

string solve(int y, int x, int size) {
    int head = video[y][x];
    bool needDivide = false;
    for(int i = y; i < y+size; i++) {
        for(int j = x; j < x+size; j++) {
            if(video[i][j] != head) {
                needDivide = true;
                break;
            }
        }
        if(needDivide)
            break;
    }
    int half = size/2;

    if(needDivide) {
        return "(" + solve(y, x, half) + solve(y, x+half, half) + solve(y+half, x, half)
            + solve(y+half, x+half, half) + ")";
    } else {
        if(head)
            return "1";
        else
            return "0"; 
    }
}

int main(void) {
    int n;  // 영상의 크기
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%1d", &video[i][j]);
        }
    }

    string answer = solve(0, 0, n);
    cout<<answer<<"\n";

    return 0;
}