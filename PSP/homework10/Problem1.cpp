#include <stdio.h>
#include <map>

using namespace std;

int main() {
    int N;  // 정수의 개수
    scanf("%d", &N);

    // 각 <정수, 빈도수> 형태로 key-value를 저장할 Map 자료구조
    // frequencyMap : 이전에 입력된 정수들의 빈도수를 저장하고 있는 맵
    map<int, int> frequencyMap;

    // 정수의 개수 만큼 반복
    for(int i = 0; i < N; i++) {
        int X;  // 정수
        scanf("%d", &X);
        // 정수가 맵에 key로 없으면 추가, 있으면 value를 +1한 값으로 갱신
        frequencyMap[X]++;
        // 현재까지 입력 된 숫자의 종류 수, 이번에 입력된 숫자가 등장한 횟수 출력
        printf("%d %d\n", frequencyMap.size(), frequencyMap[X]);
    }

    return 0;
}