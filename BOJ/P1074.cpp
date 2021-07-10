#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, r, c, cnt = 0;
int dy[] = {0, 0, 1, 1};
int dx[] = {0, 1, 0, 1};

void solve(int y, int x, int size) {
    if(size == 2) {
        for(int i = 0; i < 4; i++) {
            cnt++;
            int cy = y + dy[i];
            int cx = x + dx[i];
            if(cy == r && cx == c) {
                cout << cnt-1 << '\n';
                return;
            }
        }
    } else {
        int half = size/2;
        if(r < y+half && c < x+half)
            solve(y, x, half);
        else if(r < y+half && c >= x+half) {
            cnt += half*half;
            solve(y, x+half, half);
        }
        else if(r >= y+half && c < x+half) {
            cnt += 2*half*half;
            solve(y+half, x, half);
        }
        else {
            cnt += 3*half*half;
            solve(y+half, x+half, half);
        }

    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> r >> c;
    int size = pow(2, n);

    solve(0, 0, size);

    return 0;
}