#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int N;  // 투표용지의 수
    cin >> N;

    // 후보자와 득표수를 저장할 Map
    map<string, int> frequencyMap;

    int maxFrequency = 0;   // 최다 득표수

    // 투표용지에서 이름이 나올 때마다 득표수 갱신
    for (int i = 0; i < N; i++) {
        string st;  // 후보자 이름
        cin >> st;
        frequencyMap[st]++; // key가 st인 value+1
        int k = frequencyMap[st];   // 후보 st의 현재 득표수
        if (k > maxFrequency) {
            // 현재 득표수가 최다 득표수보다 많을 경우 갱신
            maxFrequency = k;
        }
    }

    // 최다 득표수 출력
    cout << maxFrequency << endl;

    map<string, int>::iterator it;  // 이터레이터
    // 최다득표를 받은 후보들의 이름을 사전순으로 출력
    for(it = frequencyMap.begin(); it!= frequencyMap.end(); it++) {
        if(it->second == maxFrequency)
            printf("%s ", it->first.c_str());
    }
}