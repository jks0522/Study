#include <cstdio>
#include <vector>

using namespace std;

const int MAX_N = 1000000; // N의 최대크기인 100만을 상수로 선언
vector<int> FIBONACCI_TABLE; // 벡터 컨테이너를 전역변수로 선언

/**
 * 피보나치 수열의 1~n 번째 항을 배열에 저장하여 반환해주는 함수
 * 단, 항의 가장 뒤 8자리만을 저장한다
 * 
 * 벡터 컨테이너를 반환
 */
vector<int> makeFibonacciTable(int n) {
    const int MOD = 100000000;  // 값의 8자리만을 남기기위해 이용할 상수

    // 피보나치 배열을 미리 선언해준다
    vector<int> ret(n + 1);
    ret[1] = 0; // 피보나치의 첫 번째 항은 0
    ret[2] = 1; // 피보나치의 두 번째 항은 1

    // 세 번째 항부터는 피보나치 함수의 정의를 이용해서 계산
    // f(n) = f(n - 1) + f(n - 2)
    for(int i = 3; i <= n; i++) {
        ret[i] = ret[i-1] + ret[i-2];

        // 뒤에 8자리만 남기기 위해 MOD로 나눈 나머지를 대입한다
        ret[i] %= MOD;
    }
    return ret;
}

/**
 * 피보나치 수열의 n번째 항을 반환하는 함수
 * 단, 항의 가장 뒤 8자리만을 반환한다
 */
int getFibo(int n) {
    int answer = FIBONACCI_TABLE[n]; // 피보나치 배열의 n번째 항
    return answer; 
}

int main() {
    FIBONACCI_TABLE = makeFibonacciTable(MAX_N); // MAX_N 까지의 피보나치 수열을 저장한 벡터를 할당

    int caseSize;
    scanf("%d", &caseSize); // 테스트케이스 수를 입력받음

    for(int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
        int n;
        scanf("%d", &n); // 자연수 n을 입력받음

        // 피보나치 수열의 n번째 항을 얻어서 출력
        int answer = getFibo(n);
        printf("%d\n", answer);
    }

    // 불필요한 배열 할당 해제
    FIBONACCI_TABLE.clear();

    return 0;
}