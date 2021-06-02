#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

/**
 * 문자열을 입력받고 두 글자씩 끊어서 유효한 쌍만 벡터에 저장하는 함수
 * str      두 글자 쌍을 저장할 벡터
 */
void init(vector<pair<char, char>>& str) {
    int count = 0;  // 유효한지를 검사하기 위해 쓸 변수
    char temp;  // 이전 문자

    // 개행문자가 입력될 때까지 입력을 반복
    while(true) {
        char c; // 입력 받을 문자를 담을 변수
        scanf("%c", &c);
        if(c == '\n') break;    // 개행문자일 경우 반복문 탈출
        else if(c >= 'a' && c <= 'z') {
            count++;    // 유효한 글자이므로 count를 1증가
            // count가 2일 경우, 유효한 두 글자 쌍을 읽었다는 의미이므로
            // count를 1로 만들고 이전 문자와 현재 문자를 대문자로 변환 후 pair로 벡터에 저장
            if(count == 2) {
                count = 1;
                str.push_back({temp, toupper(c)});
            }
            temp = toupper(c);  // count가 1인 경우, 아직 쌍이 아니므로 temp에만 저장하고 넘어감
        } else if(c >= 'A' && c <= 'Z') {
            count++;
            // 소문자를 읽었을 때와 같은 방식
            if(count == 2) {
                count = 1;
                str.push_back({temp, c});
            }
            temp = c;
        } else {
            // 특수문자나 숫자일 경우 유효하지 않으므로 count를 0으로 초기화
            count=0;
        }
    }
}

/** vector<pair<char, char>>를 정렬할 때 쓸 비교 함수
 * 첫번째 문자로 오름차순 정렬
 * 첫번째 문자가 같을 경우 두번째 문자로 오름차순 정렬
 */
bool cmp(pair<char, char> a, pair<char, char> b) {
    if(a.first == b.first) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

/**
 * 두 벡터의 문자쌍을 비교해가며 답을 구하는 함수
 * v1       첫 번째 벡터
 * v2       두 번째 벡터
 * 
 * 최종 출력값을 리턴
 */
int solve(vector<pair<char, char>>& v1, vector<pair<char, char>>& v2) {
    // index1: v1 탐색에 쓸 인덱스, index2: v2 탐색에 쓸 인덱스, count: 교집함 원소의 개수
    int index1=0, index2=0, count=0;
    // 두 벡터 중 하나의 탐색이 끝날때까지 반복
    while(index1 < v1.size() && index2 < v2.size()) {
        // 문자쌍이 같을 경우 index1과 index2를 증가시키고 교집합 원소의 개수를 1 증가
        if(v1[index1] == v2[index2]) {
            index1++;
            index2++;
            count++;
        } else if(v1[index1] < v2[index2]) {
            // v2의 문자쌍이 사전상 더 뒤에 위치할 경우 index1을 1 증가
            index1++;
        } else {
            // v1의 문자쌍이 사전상 더 뒤에 위치할 경우 index2를 1 증가
            index2++;
        }
    }
    // 두 집합이 모두 공집합일 경우, 자카드 유사도는 1이므로 1*65536=65536을 리턴
    if(v1.size() == 0 && v2.size() == 0)
        return 65536;
    // 교집합/합집합 * 65536 후 소수점아래를 버린 값 리턴
    return (int)(((double)count)/((v1.size()-count)+v2.size()) * 65536);
}

int main(void) {
    // 문자쌍을 저장할 벡터
    vector<pair<char, char>> v1, v2;

    // init함수를 호출하여 문자열을 입력받고 유효한 쌍을 벡터에 채움
    init(v1);
    init(v2);

    clock_t start = clock(); //시작 시간 저장
    
    // 벡터를 문자쌍의 오름차순으로 정렬
    sort(v1.begin(), v1.end(), cmp);
    sort(v2.begin(), v2.end(), cmp);

    // solve함수 호출을 통해 정답 계산후 출력
    cout<<solve(v1,v2)<<'\n';

    clock_t end = clock(); // 코드가 끝난 시간 저장

    // 걸린 시간을 초 단위로 출력
    printf("실행시간: %lf초\n", (double)(end - start)/CLOCKS_PER_SEC);

    return 0;
}