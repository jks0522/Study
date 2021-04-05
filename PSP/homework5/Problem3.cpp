#include <cstdio>
#include <vector>

using namespace std;

/**
 * n의 소인수들을 구해서 벡터로 반환하는 함수
 * n    소인수를 구할 자연수
 */
vector<int> factorize(int n) {
    vector<int> factors;    // 소인수들을 담을 벡터

    // 소인수는 2부터 루트n까지만 검사하면 되므로 루트를 없애기위해 제곱을 사용한다
    for(int div = 2; div * div <= n; div++) {
        while(n % div == 0) {
            // 소인수가 발견되었을 시 factors벡터에 추가
            factors.push_back(div);
            

            n /= div;   // n을 소인수로 나눈후 다시 반복
        }
    }
    if (n > 1) {
        // 반복문을 빠져나온후 n이 1보다 크면 자기자신이 소인수 이므로 n을 그대로 push_back해준다
        factors.push_back(n);
    }

    return factors; // 벡터 반환
}

void process(int caseIndex) {
    int n;  // 소인수분해를 할 자연수 n
    scanf("%d", &n);

    vector<int> factors = factorize(n); // n의 소인수들을 구하여 factors 벡터에 저장

    printf("#%d:\n", caseIndex);    // 케이스 번호 출력
    // 공백으로 구분하여 모든 소인수 들을 출력한다
    for (int i = 0; i < factors.size(); ++i) {
        if ( i > 0) {
            printf(" ");
        }
        printf("%d", factors[i]);
    }
    printf("\n");
}

int main() {
    int caseSize;   // 테이트케이스 수
    scanf("%d", &caseSize);

    // 테스트케이스 수만큼 process 함수를 통해 입력과 출력을 반복
    for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
        process(caseIndex);
    }
}