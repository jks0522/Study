#include <set>
#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    set<int> s;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        s.insert(num);
    }

    set<int>::iterator iter;
    for(iter = s.begin(); iter != s.end(); iter++) {
        cout << *iter << ' ';
    }
    cout << '\n';

    return 0;
}