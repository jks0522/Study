#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v;

    for(int i = 0; i < n; i++) {
        v.push_back(i+1);
    }

    do {
        for(int i = 0; i < n; i++) {
            cout << v[i] << ' ';
        }
        cout << '\n';
    } while(next_permutation(v.begin(), v.end()));

    return 0;
}