#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int solve(vector<int> foodTimes, long long k) {
    vector<int> ftcopy;
    
}

int main(void) {
    int n;  // 음식의 개수
    cin >> n;

    vector<int> foodTimes; // 음식을 먹는데 필요한 시간을 담을 큐
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        foodTimes.push_back(num);
    }

    // 먹방을 시작한 후 몇 초가 지나고 방송이 중단되었는지를 나타내는 k
    // k는 2 * 10^13 이하의 자연수이므로 long long 타입으로 선언
    long long k;  
    cin >> k;
}