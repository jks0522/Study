#include <iostream>
#include <vector>

using namespace std;

void printPicked(vector<int>& picked) {
    for(int i = 0; i < picked.size(); i++) {
        cout<<picked[i]<<" ";
    }
    cout<<"\n";
}

void pick(vector<int>& v, vector<int>& picked, int toPick, int index) {
    if(toPick == 0) {
        printPicked(picked);
        return;
    }

    for(int i = index; i < v.size(); i++) {
        picked.push_back(v[i]);
        pick(v, picked, toPick-1, i+1);
        picked.pop_back();
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(true) {
        vector<int> v;
        vector<int> picked;
        int k;
        cin>>k;
        if(k == 0) break;
        for(int i = 0; i < k; i++) {
            int num;
            cin >> num;
            v.push_back(num);
        }
        
        pick(v, picked, 6, 0);
        cout<<"\n";
    }

    return 0;
}