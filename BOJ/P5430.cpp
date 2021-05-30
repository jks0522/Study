#include <deque>
#include <queue>
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

void ac(string& command, deque<int>& deq) {
    bool reverse = false;
    for(int i = 0; i < command.size(); i++) {
        if(command[i] == 'R')
            reverse = !reverse;
        else {
            if(deq.empty()) {
                cout<<"error\n";
                return;
            }
            if(reverse) {
                deq.pop_back();
            } else {
                deq.pop_front();
            }
        }
    }
    cout << '[';
    if(!reverse) {
        for(int i = 0; i < deq.size(); i++) {
            cout<<deq[i];
            if(i != deq.size()-1)
                cout<<',';
        }
    } else {
        for(int i = deq.size()-1; i >= 0; i--) {
        cout<<deq[i];
            if(i != 0)
                cout<<',';
        }
    }

    cout << "]\n";

}

int main(void) {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        deque<int> deq;
        
        int n;
        string command, numList;
        cin >> command >> n >> numList;
        
        int temp = 0;
        for(int j = 1; j < numList.size(); j++) {
            if(n == 0) break;
            if(isdigit(numList[j])) {
                temp = temp * 10 + (numList[j]-'0');
            } else {
                deq.push_back(temp);
                temp = 0;
            }
        }

        ac(command, deq);
    }

    return 0;
}