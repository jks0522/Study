#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int matrix[1025][1025];  // 행렬을 가능한 최대크기로 선언

/**
 * 행과 열을 받아서 2x2 정사각형의 2번째로 큰 수를 반환하는 함수
 * i    행
 * j    열
 */
int pooling(int i, int j) {
    vector<int> v;  // 2x2 사각형 내의 숫자를 저장할 벡터

    // matrix[i][j] 부터 2x2 정사각형 범위의 숫자들을 벡터에 저장
    for(int a = i; a < i+2; a++)
        for(int b = j; b < j+2; b++)
            v.push_back(matrix[a][b]);
    
    sort(v.begin(), v.end());   // 벡터정렬
    return v[2];    // 두 번째로 큰 값 반환
}

int main() {
    int n;  // 정사각형 한 변의 길이
    scanf("%d", &n);

    // 행렬 원소 입력
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    // 222-풀링을 사각형의 크기가 1x1 될때까지 반복하는 부분
    while(true) {
        // 행과 열을 2씩 증가시키며 2x2 행렬의 첫 원소의 행과 열을 pooling 함수의 인수로 전달
        // pulling의 결과로 나온 2번째로 큰 값을 행과 열의 절반 위치에 저장
        // 이런식으로 하면 행렬의 크기를 줄여가는 것과 마찬가지다
        for(int i = 0; i < n; i+=2)
            for(int j = 0; j < n; j+=2)
                matrix[i/2][j/2] = pooling(i, j);

        n /= 2; // 검사할 사각형 크기 절반으로 줄임
        
        // n이 0이면 1x1로 만들었을 때 값이 matrix[0][0]에 계산된 상태
        if (n == 0) {
            printf("%d", matrix[0][0]);
            break;
        }
    }

    return 0;
}