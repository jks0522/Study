#include <cstdio>

using namespace std;

const int MAX_TABLE_LENGTH = 10000; // 전화번호의 최대 수

/**
 * data[0] ~ data[n-1]까지의 히스토그램을 table 배열에 저장하는 함수
 * data     검사할 배열
 * n        data배열의 원소 수
 * table    숫자가 나온 횟수를 저장할 배열(히스토그램)
 */
void fillFrequencyTable(int data[], int n, int table[]) {
    // 배열을 0으로 초기화
    for(int i = 0; i < MAX_TABLE_LENGTH; i++)
    {
        table[i] = 0;
    }
    // data[0] ~ data[n-1]에서 색상의 빈도를 table 배열에 저장
    for(int i = 0; i < n; i++)
    {      
        table[data[i]]++;
    }

}

/**
 * 가장 많이 등장한 번호를 리턴하는 함수
 * data     검사할 배열
 * n        원소의 개수
 */
int getFrequentNumber(int data[], int n) {
    int frequent_number = 0; // 가장 많이 등장한 번호를 담기 위한 변수

    int table[MAX_TABLE_LENGTH]; // 0~9999까지 숫자의 횟수를 카운트하는 히스토그램
    fillFrequencyTable(data, n, table);  // table에 숫자가 나온 횟수를 저장

    for(int i = 0; i < MAX_TABLE_LENGTH; i++)
    {
        // 더 많이 나온 수가 있을 때 frequent_number 갱신
        if(table[i] > table[frequent_number])
            frequent_number = i;
    }

    return frequent_number; // 최빈값을 반환
}

int main() {
    int n;

    scanf("%d", &n); // 전화번호의 수를 입력받음
    int* data = new int[n]; // 전화번호를 담을 배열

    for (int i =0; i < n; i++) {
        scanf("%d", &data[i]);  // 전화번호를 한 줄씩 입력받음
    }

    int answer = getFrequentNumber(data, n); // 가장 많이 등장한 번호를 얻음

    printf("%04d", answer); // 0을 포함하여 공백없는 네 자리 숫자로 최빈값을 출력

    delete[] data; // 메모리 해제
    
    return 0;
}