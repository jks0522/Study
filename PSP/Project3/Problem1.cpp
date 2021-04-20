#include <cstdio>
#include <vector>
#include <time.h>

using namespace std;

#define MAX_SSD 255*255*100; // SSD의 가능한 최대 값

int h, w; // h: 포개어진 이미지의 높이, w: 너비
int ssd = MAX_SSD;  // 출력할 ssd 값을 나중에 비교를 위해 가능한 최대값으로 초기화
int b3[101][101]; // b1, b2 이미지의 밝기 값 차이를 담을 배열
int result = 0; // 비교할 결과값을 저장하기 위한 변수

/**
 * 배열의 위에서 아래로 가며 경계선의 모든 경우를 탐색하는 함수
 * level    현재 열
 * index    현재 행
 */
void solveBoundary (int level, int index) {
    // 마지막 열일 경우
    if(level == h-1) {
        result += b3[level][index]; // 마지막값 추가
        if(result < ssd)    // 현재 구한게 최소 ssd면 ssd값 갱신
            ssd = result;
    } else {
        result += b3[level][index]; // 중간값 추가
        if(result >= ssd) {
            result -= b3[level][index];
            return; // 계산 도중 저장되어있는 ssd 보다 값이 커지면 더 계산할 필요 없으므로 return
        }
        // 맨왼쪽이 아니면 아래행의 왼쪽열 원소를 탐색
        if(index != 0) {
            solveBoundary(level+1, index-1);
        }
        solveBoundary(level+1, index);  // 아래칸의 원소를 탐색
        // 맨오른쪽이 아니면 아래행의 오른쪽열 원소를 탐색
        if(index != w-1) {
            solveBoundary(level+1, index+1);
        }
    } 
    result -= b3[level][index]; // 함수 빠져나올때 원소 값 하나 제거
}

int main() {
    scanf("%d %d", &h, &w);

    // b1, b2 이미지를 h*w 2차원 배열로 동적할당
    int b1[101][101];
    
    // b1 이미지의 밝기 값 입력
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            scanf("%d", &b1[i][j]);

    // b2 이미지의 밝기 값 입력 후 b1과 차이의 제곱을 b3에 저장
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++){
            int num;    // b2 이미지의 밝기 값
            scanf("%d", &num);  
            b3[i][j] = (b1[i][j] - num)*(b1[i][j] - num);   // b1과 b2 차이의 제곱을 b3에 저장
        }

    clock_t start = clock(); // 입력 이후 시작 시간 저장
    
    // 첫 번째 행의 첫번째 열부터 끝 열까지 반복
    for(int i = 0; i < w; i++) {
        solveBoundary(0, i);    // 함수호출을 통한 문제해결
    }
    printf("%d\n", ssd);    // 최소 ssd 출력

    clock_t end = clock(); // 코드가 끝난 시간 저장

    printf("실행시간: %lf초\n", (double)(end - start)/CLOCKS_PER_SEC);  // 실행시간 출력

    return 0;
}