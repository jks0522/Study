#include <cstdio>
#include <vector>

using namespace std;

const int MAX_SERIAL_NUMBER = 100000; // 시리얼 번호의 최대값을 상수로 선언

/**
 * data[0] ~ data[n-1]까지의 히스토그램을 table 벡터에 저장하는 함수
 * data     검사할 벡터
 * n        data벡터의 원소 수
 * table    숫자가 나온 횟수를 저장할 벡터(히스토그램)
 */
void fillFrequencyTable(const vector<int> &data, int n, vector<int> &table) {
    table.clear();  // 모든 원소 제거
    table.resize(MAX_SERIAL_NUMBER + 1, 0); // 크기를 MAX_SERIAL_NUMBER + 1 로 변경하고 모두 0으로 초기화

    // data[0] ~ data[n-1] 까지 숫자가 나온 횟수를 table에 저장
    for(int i = 0; i < n; i++) {
        int serial = data[i];
        table[serial] += 1;
    }
}

/**
 * data[0] ~ data[n-1]에서 중복되지 않은 원소를 반환
 * 단, 오름차순으로 정렬되어 있어야 함
 * data     검사할 벡터
 * n        원소의 갯수
 */
vector<int> getUniqueElements(const vector<int> &data, int n) {
    vector<int> ret; // 벡터 생성

    vector<int> table; // 빈도수를 담을 벡터
    fillFrequencyTable(data, n, table); // data[0] ~ data[n-1]에서 빈도수를 table 벡터에 담음

    for (int number =1; number <= MAX_SERIAL_NUMBER; number ++) {
        // 존재할 수 있는 모든 시리얼 넘버에 대해 차례로 조회한다.

        //한 번만 등장한 number를 차례로 ret 벡터에 추가
        if(table[number] == 1) {
            ret.push_back(number); // ret이라는 배열 마지막에 원소 추가
        }
    }

    // 오름차순 순서로 추가했기 때문에 ret에 대한 정렬은 불필요
    return ret;

}
int main() {
    int n;
    scanf("%d", &n); // 데이터 수를 입력받음

    // 벡터 컨테이너
    vector<int> data = vector<int>(n);

    // n개의 시리얼 번호를 공백으로 구분하여 입력받음
    for(int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }
    
    // 유일한 수를 오름차순으로 가지고 있는 벡터를 받음
    const vector<int> answer = getUniqueElements(data, n); 
    
    // 각 원소들을 출력한다
    for (int i = 0; i < answer.size(); i++) {
        if ( i > 0) {
            // 첫 번째 원소가 아니라면 앞에 공백을 하나 추가한다
            printf(" ");
        }
        printf("%d", answer[i]);
    }

    return 0;
}