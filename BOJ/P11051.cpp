#include <iostream>

using namespace std;

int cache[1000][1000];

int bino(int n, int k) {
    if(k == 0 || n == k)
        return 1;
    if(cache[n][k] != 0)
        return cache[n][k];
    return cache[n][k] = (bino(n-1,k-1)%10007 + bino(n-1, k)%10007) % 10007;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    int answer = bino(n, k);

    cout<<answer<<'\n';
}