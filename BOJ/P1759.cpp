#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l, c;

void solve(const vector<char>& v, vector<char>& picked, int index, int vowel, int conso) {
    if(picked.size() == l) {
        if(vowel >= 1 && conso >= 2) {
            for(int i = 0; i < l; i++) {
                cout << picked[i];
            }
            cout << '\n';
            return;
        } else {
            return;
        }
    }

    for(int i = index; i < c; i++) {
        picked.push_back(v[i]);
        if(v[i] == 'i' || v[i] == 'a' || v[i] == 'e' || v[i] == 'o' || v[i] == 'u')
            vowel++;
        else
            conso++;
        solve(v, picked, i+1, vowel, conso);
        if(v[i] == 'i' || v[i] == 'a' || v[i] == 'e' || v[i] == 'o' || v[i] == 'u')
            vowel--;
        else
            conso--;
        picked.pop_back();
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> l >> c;

    vector<char> v(c);
    for(int i = 0; i < c; i++)
        cin >> v[i];
    
    sort(v.begin(), v.end());

    vector<char> picked;
    solve(v, picked, 0, false, 0);

    return 0;
}