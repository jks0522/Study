#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class City {
public:
    int index;  // 도시의 인덱스
    int income; // 해당 도시의 소득

    City(int index, int income) {
        this->index = index;
        this->income = income;
    }

    // City의 대소관계를 비교하기 위한 연산자
    bool operator < (const City& o) const {
        return this->income < o.income;
    }
    bool operator > (const City& o) const {
        return this->income > o.income;
    }
};

/**
 * 연속한 k개의 도시로 이루어진 영역들 중 가장 큰 소득차를 가지는 영역의 소득차를 구하는 함수
 * n    도시의 수
 * k    한 조사 영역이 포함하는 연속한 도시의 수
 * cities   도시의 리스트인 벡터
 */
int getMaximumRangeDifference(int n, int k, const vector<City>& cities) {
    int answer = 0; // 가장 큰 소득차를 담을 변수

    // 소득이 가장 작은 도시부터 pop되는 우선순위 큐
    priority_queue<City, vector<City>, greater<City>> rangeMinimum;

    // 소득이 가장 높은 도시부터 pop되는 우선순위 큐
    priority_queue<City> rangeMaximum;

    // 처음부터 인덱스 k-2 까지의 도시를 두 큐에 넣음
    for(int i = 0; i < k - 1; i++) {
        rangeMaximum.push(cities[i]);   // 소득이 높은 순으로 정렬
        rangeMinimum.push(cities[i]);   // 소득이 낮은 순으로 정렬
    }

    // 인덱스 k-1 부터 도시를 하나 넣고 인덱스가 가장 빠른 도시를
    // 하나 제거하고 가장 큰 소득차를 구하는 과정을 반복
    for(int i = k - 1; i < n; i++) {
        rangeMaximum.push(cities[i]);   // 도시 하나를 추가
        rangeMinimum.push(cities[i]);   // 도시 하나를 추가
        // 소득차를 구하고자 하는 k개의 연속한 도시에 포함되지 않으면 제거
        while (rangeMaximum.top().index < i - k + 1) rangeMaximum.pop();
        while (rangeMinimum.top().index < i - k + 1) rangeMinimum.pop();
        // 기존에 구한 값과 새로운 값을 비교해서 더 큰 소득차를 answer에 저장
        answer = max(answer, rangeMaximum.top().income - rangeMinimum.top().income);
    }

    return answer;  // 가장 큰 소득차를 리턴
}

void process(int caseIndex) {
    int n, k;   // n: 도시의 수, k: 한 조사 영역이 포함하는 연속한 도시의 수
    cin >> n >> k;  // n과 k를 입력
    vector<City> cities;    // 도시의 리스트를 담을 벡터

    for(int i = 0; i < n; i+= 1) {
        int income; // i번째 도시의 수입
        cin >> income;  // 수입 입력
        cities.push_back(City(i, income));  // 도시의 인덱스와 수입을 cities 벡터에 push
    }

    // 연속한 k개의 도시로 이루어진 영역들 중 가장 큰 소득차를 가지는 영역의 소득차를 얻음
    int answer = getMaximumRangeDifference(n, k, cities);

    cout << answer << endl; // 가장 큰 소득차 출력
}

int main() {
    int caseSize;   // 테스트케이스 수
    cin >> caseSize;    // 테스트케이스 입력

    // 테스트케이스의 수 만큼 반복
    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
        process(caseIndex);
    }
}