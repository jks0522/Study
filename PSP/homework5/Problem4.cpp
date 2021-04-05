#include <cstdio>
#include <vector>

using namespace std;

// 소인수 분해를 빠르게
class Sieve {
public:
    int maximumValue;   // 최대값
    vector<bool> isPrime;   // 소수인지를 저장하는 벡터
    Sieve(int maximumValue) {
        this->maximumValue = maximumValue;
        this->isPrime.assign(maximumValue + 1, false);
        this->fillSieve();
    }
    
    /**
     * 소수인지 여부를 리턴해주는 메소드
     * 소수일 경우 true, 아닐경우 false 리턴
     */
    bool isPrimeNumber(int num) const {
        return this->isPrime[num];
    }

    // isPirme 배열의 값을 채우는 함수
    void fillSieve() {
        isPrime.assign(this->maximumValue, true); // 처음은 다 소수라고 생각
        isPrime[0] = isPrime[1] = false; // 0과 1은 소수가 아니다.

        // 2부터 최대값까지 검사하여 소수가 아닐경우 건너뛰고
        // 소수일 경우 제곱부터 배수들을 모두 소수가 아니라고 isPrime 벡터에 false값을 넣어 표시
        for(int num = 2; num <= maximumValue; num+=1) {
            if(isPrime[num] == false) {
                continue;
            }
            
            // num의 제곱은 int범위를 넘어갈 수가 있으므로 long long을 사용
            for(long long mul = (long long) num * num; mul <= maximumValue; mul+= num) {
                int index = (int) mul;
                isPrime[index] = false;
            }
        }
    }
};

/**
 * from 부터 to까지 sieve에서 소수를 모두 구해 담는 함수
 * from     검사를 시작할 숫자
 * to       검사를 마칠 숫자
 * Sieve& sieve     이용할 객체
 */
vector<int> getAllPrimeNumbers(int from, int to, const Sieve& sieve) {
    vector<int> primes; // 소수를 담을 벡터

    // from 부터 to까지의 소수를 primes 벡터에 저장
    for(int num = from; num <= to; num += 1) {
        if(sieve.isPrimeNumber(num)) {
            primes.push_back(num);
        }
    }

    return primes;  // 벡터 반환
}

void process(int caseIndex, const Sieve& sieve) {
    int L, R;   // 왼쪽끝값과 오른쪽끝값
    scanf("%d%d", &L, &R);

    vector<int> allPrimeNumbers = getAllPrimeNumbers(L, R, sieve);  // L부터 R까지의 소수를 얻어서 벡터에 저장

    printf("Case #%d:\n", caseIndex);   // 테스트케이스 번호 출력
    printf("%d\n", (int)allPrimeNumbers.size());    // L이상 R이하의 소수의 갯수 출력
}

int main() {
    const int MAX_VALUE = 1000000;  // 전처리 선언
    Sieve sieve = Sieve(MAX_VALUE); // 전처리 선언

    int caseSize;   // 테스트케이스 수
    scanf("%d", &caseSize);

    // 테스트케이스 수 만큼 입력과 출력을 반복함
    for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
        process(caseIndex, sieve);  
    }

    return 0;
}