#include <iostream>
using namespace std;

int paper[2187][2187];
int minusOne = 0, zero =0, one = 0;

void solve(int y, int x, int size) {
    int head = paper[y][x];
    bool needDivide = false;
    for(int i = y; i < y+size; i++) {
        for(int j = x; j < x+size; j++) {
            if(paper[i][j] != head) {
                needDivide = true;
                break;
            }
        }
        if(needDivide)
            break;
    }
    int third = size/3;

    if(needDivide) {
        solve(y, x, third);
        solve(y, x+third, third);
        solve(y, x+2*third, third);
        solve(y+third, x, third);
        solve(y+third, x+third, third);
        solve(y+third, x+2*third, third);
        solve(y+2*third, x, third);
        solve(y+2*third, x+third, third);
        solve(y+2*third, x+2*third, third);
    } else {
        if(head == -1)
            minusOne++;
        else if(head == 0)
            zero++;
        else
            one++;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int num;
            cin >> num;
            paper[i][j] = num;
        }
    }

    solve(0, 0, n);
    cout<<minusOne<<"\n"<<zero<<"\n"<<one<<"\n";

    return 0;
}