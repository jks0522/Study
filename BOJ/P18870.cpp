#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int count = 0;
    cin>>n;

    vector<int> v1;
    vector<int> v2;
    map<int, int> m;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v1.push_back(num);
    }

    v2 = v1;

    sort(v2.begin(), v2.end());
    for(int i = 0; i < n; i++) {
        if(i == 0 || v2[i] != v2[i-1]) {
            m[v2[i]] = count;
            count++;
        }
    }

    for(int i = 0; i < n; i++) {
        cout<<m[v1[i]]<<" ";
    }

    return 0;
}