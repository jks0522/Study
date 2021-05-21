#include <iostream>
#include <vector>
using namespace std;

int **paper;
int white = 0;
int blue = 0;

void solve(int y, int x, int size) {
    int head = paper[y][x];
    bool needDivide = false;
    for(int i = y; i < y+size; i++) {
        for(int j = x; j < x+size; j++) {
            if(paper[i][j] != head) {
                needDivide = true;
                break;
            }
            if(i == y+size-1 && j == x+size-1) {
                if(head == 0)
                    white++;
                else
                    blue++;
                return;
            }
        }
        if(needDivide)
            break;
    }

    int half = size/2;
    solve(y, x, half);
    solve(y, x+half, half);
    solve(y+half, x, half);
    solve(y+half, x+half, half);
}

int main(void) {
    int n;
    cin>>n;

    paper = new int*[n];
    for(int i = 0; i < n; i++) {
        paper[i] = new int[n];
        for(int j = 0; j < n; j++) {
            int num;
            cin >> num;
            paper[i][j] = num;
        }
    }

    solve(0, 0, n);

    cout<<white<<"\n"<<blue<<"\n";
}