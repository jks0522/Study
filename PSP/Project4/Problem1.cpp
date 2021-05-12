#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
#include <queue>

using namespace std;

/**
 * 음식 클래스
 * time 음식을 먹는데 걸리는 시간(초)
 * index    음식의 인덱스
 */
class Food {
public:
    int time;
    int index;

    Food(int time, int index) {
        this->time = time;
        this->index = index;
    }
};

/**
 * 우선순위 큐에 사용할 비교 구조체
 * time이 작은 것 부터 정렬하기 위해 ">" 사용
 */
struct cmp{
    bool operator()(Food a, Food b) {
        return a.time > b.time;
    }
};

/**
 * 정답을 반환하는 함수
 * foodTimes    각 음식을 먹는데 걸리는 시간을 담고있는 벡터
 * k            방송이 중단된 시간
 * 
 * 다시 방송을 이어갈 때 몇번 음식부터 먹어야 하는지를 반환
 */
int solve(vector<int> foodTimes, long long k) {
    int answer = 0; // 정답을 담을 변수
    long long sum = 0;  // 모든 음식 섭취시간을 합할 변수

    // 음식을 섭취시간이 작은 것부터 정렬할 Food 우선순위 큐
    priority_queue<Food, vector<Food>, cmp> timesSort;
    // 우선순위 큐에 벡터의 섭취시간과 인덱스를 가지는 Food객체를 담음
    // 각 섭취시간을 sum에 모두 더함
    for(int i = 0; i < foodTimes.size(); i++) {
        timesSort.push(Food(foodTimes[i], i));
        sum += foodTimes[i];
    }
    
    // k가 sum보다 크거나 같으면 방송이 재개된 후에 더 먹을 음식이 없으므로 -1 반환
    if(sum <= k) 
        return -1;

    int size = foodTimes.size();    // 반복문에 사용할 크기
    int minus = 0;  // 이전의 섭취시간을 담을 변수

    /**
     * 모든 음식을 1초씩 섭취하면 k는 (음식의 수 * 1) 만큼 감소한다
     * 모든 음식을 섭취 시간이 가장 작은 음식의 시간만큼 섭취하면 (음식의 수 * 최소 섭취 시간) 만큼 k가 감소한다
     * 하나를 다 먹어치웠으므로 음식의 수가 1 감소한다
     * 다음 최소 섭취 시간은 (원래 섭취 시간 - 이전까지 섭취한 시간) 이다
     * 결국 ((원래 섭취 시간 - 이전까지 섭취한 시간) * 음식의 수)가 k에서 뺄 값이다
     * 이를 k가 0보다 작거나 같을 때까지 반복한다
     */
    for(int i = 0; i < size; i++) {
        if(k - ((long long)(timesSort.top().time - minus) * (size - i)) <= 0)
            break;
        k -= ((long long)(timesSort.top().time - minus) * (size - i));
        minus = timesSort.top().time;
        timesSort.pop();    // 음식 하나를 다 먹어치웠으므로 pop()해서 없애준다
    }

    // 남은 음식의 인덱스를 담을 벡터
    vector<int> pq;
    // 남은 음식의 인덱스를 모두 담는다
    while(!timesSort.empty()) {
        pq.push_back(timesSort.top().index);
        timesSort.pop();
    }
    sort(pq.begin(), pq.end()); // 인덱스를 오름차순으로 정렬

    // k를 pq의 size로 나눈 나머지가 다음에 먹어야할 음식이다
    // 정답은 1번 부터 시작이므로 1을 더해준다
    answer = pq[k % pq.size()] + 1; 

    return answer;  //결과 반환
}

int main(void) {
    int n;  // 음식의 개수
    cin >> n;

    vector<int> foodTimes; // 음식을 먹는데 필요한 시간을 담을 큐
    // n개의 음식을 각각 먹는데 필요한 시간을 입력 받음
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        foodTimes.push_back(num);
    }

    // 먹방을 시작한 후 몇 초가 지나고 방송이 중단되었는지를 나타내는 k
    // k는 2 * 10^13 이하의 자연수이므로 long long 타입으로 선언
    long long k;  
    cin >> k;

    clock_t start = clock();	// 입력을 다 받은 후 시작 시간 저장

    // 답을 구해서 answer에 대입함
    int answer = solve(foodTimes, k);

    // 정답 출력
    cout << answer << "\n";

    clock_t end = clock();	// 출력이 다 끝난 후 시간 저장

    // end와 start의 차이를 CLOCKS_PER_SEC로 나누어서 실행시간을 초단위로 출력
	printf("실행시간: %lf초", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}