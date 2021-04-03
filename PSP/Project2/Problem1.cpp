#include <cstdio>
#include <time.h>

using namespace std;

/**
 * a를 b로 바꾸는 데 필요한 연산의 최소값을 구하고 거기에 1을 더한 값을 반환하는 함수
 * a    b로 바꿀 정수
 * b    a가 목표로 하는 정수
 */
int calculate(int a, int b) {
	int count = 1;  // 연산 횟수 + 1 을 저장하기 위해 1부터 시작

    // a에서 b로 바꾸는 과정을 b에서 a로 역으로 진행
    // b를 계산을 통해 줄여가면서 a보다 작거나 같아질 때까지 반복
	while (a < b) {
		if (b % 2 == 0) {
            // b가 짝수일 경우 a에서 2를 곱한 경우이므로 b를 2로 나눔
			b /= 2;
			count++;
		}
		else if (b % 10 == 1) {
            // b의 일의자리 숫자가 1일 경우 a의 가장 오른쪽에 1을 추가한 것이므로 b를 10으로 나눔
			b /= 10;
			count++;
		}
		else {
            // 위의 두 경우에 해당하지 않는 경우 만들 수 없으므로 -1을 리턴
			return -1;
		}
	}

    // b가 a와 같으면 a를 b로 바꿀 수 있다는 의미이므로 횟수+1 값인 count를 리턴
    // b가 a보다 작아졌으면 a를 b로 바꿀 수 없다는 의미이므로 -1을 리턴
	if (a == b)
		return count;
	else
		return -1;
}

int main()
{
	int a, b, result; // result: 결과값을 저장할 변수
	scanf("%d %d", &a, &b); // a, b값을 공백으로 구분하여 입력

	clock_t start = clock(); // 실행시간 측정 시작

	result = calculate(a, b);   // calculate 함수의 결과값을 result에 저장
	printf("%d\n", result); // result 출력

	clock_t end = clock();  // 실행시간 측정 종료
	printf("실행시간: %lf초", (double)(end - start) / CLOCKS_PER_SEC);  // 실행시간 초단위로 출력
	return 0;
}