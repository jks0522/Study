#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int> lessQ;  // 중앙값 보다 작은 값들을 담는 우선순위 큐
    priority_queue<int, vector<int>, greater<int>> largeQ; // 중앙값 보다 큰 값들을 담는 우선순위 큐

    int median; // 중앙값

    int t;  // 테스트케이스 개수
    cin >> t;

    for(int i = 1; i <= t; i++) {
        int num;
        cin >> num;

        if(i == 1) {
            median = num;
        }
        else if(i%2 == 0) {
            if(num < median) {
                largeQ.push(median);
                lessQ.push(num);
                median = lessQ.top();
                lessQ.pop();
            } else if(num > median) {
                largeQ.push(num);
            } else {
                largeQ.push(num);
            }
        } else {
            if(num < median) {
                lessQ.push(num);
            } else if(num > median) {
                lessQ.push(median);
                largeQ.push(num);
                median = largeQ.top();
                largeQ.pop();
            } else {
                lessQ.push(num);
            }
        }

        cout<<median<<'\n';
    }

    return 0;
}