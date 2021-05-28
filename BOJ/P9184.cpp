#include <iostream>
#include <string.h>

using namespace std;

int cache[21][21][21];

int w(int a, int b, int c) {
    if(cache[a][b][c] != 0) {
        return cache[a][b][c];
    }
    if(a <= 0 || b <= 0 || c <= 0)
        return cache[a][b][c] = 1;
    if(a < b && b < c)
        return cache[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    else
        return cache[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(true) {
        int a, b, c;
        cin >> a >> b >> c;

        if(a == -1 && b == -1 && c == -1)
            return 0;
    
        cout << "w(" << a << ", " << b << ", " << c << ") = ";

        if(a <= 0 || b <= 0 || c <= 0)
            a = b = c = 0;
        if(a > 20 || b > 20 || c > 20)
            a = b = c = 20;
        cout << w(a, b, c) << '\n';
    }

    return 0;
}