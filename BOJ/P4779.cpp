#include <iostream>
#include <cmath>

using namespace std;

void solve(int size, bool blank) {
    int split = size/3;
    if(size == 1) {
        if(blank)
            cout << ' ';
        else
            cout << '-';
    }
    else if(blank) {
        for(int i = 0; i < size; i++)
            cout << ' ';
    }
    else {
        solve(split, false);
        solve(split, true);
        solve(split, false);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(true) {
        int n;
        cin >> n;

        if(cin.eof())
            break;

        int size = pow(3, n);
        solve(size, false);
        cout << '\n';
    }

    return 0;
}