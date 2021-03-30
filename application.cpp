#include <cstdio>
#include <vector>

using namespace std;

const int MAX_SERIAL_NUMBER = 100000;

void fillFrequencyTable(const vector<int> &data, int n, vector<int> &table) {
    table.clear();
    table.resize(MAX_SERIAL_NUMBER + 1, 0);

    for(int i = 0; i < n; i++) {
        int serial = data[i];
        table[serial] += 1;
    }
}

vector<int> getUniqueElements(const vector<int> &data, int n) {
    // 유일한 원소들 배열, 비어있는 벡터 생성, 배열과 달리 고정사이즈가 아님
    vector<int> ret;

    //data에 대한 빈도수 테이블을 계산한다
    vector<int> table;
    fillFrequencyTable(data, n, table);

    for (int number =1; number <= MAX_SERIAL_NUMBER; number ++) {
        // 존재할 수 있는 모든 시리얼 넘버에 대해 차례로 조회한다.

        //전체 데이터에서 한 번만 등장한 number를 차례로 정답 리스트에 추가한다.
        if(table[number] == 1) {
            ret.push_back(number); // ret이라는 배열 마지막에 원소 추가
        }
    }

    // 오름차순 순서로 추가했기 때문에 ret에 대한 정렬은 불필요하다
    return ret;

}
int main() {
    int n;
    scanf("%d", &n);

    // 벡터 컨테이너: 자동으로 메모리가 할당되는 배열
    vector<int> data = vector<int>(n);


    for(int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

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