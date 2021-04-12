#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 세 카드에 적힌 숫자의 합으로 표현할 수 있는 당첨번호들을 담은 벡터를 반환하는 함수
 * n    사용할 카드의 수
 * m    당첨번호의 수
 * cards    사용할 카드번호 배열
 * targets  당첨번호의 배열
 */
vector<int> getPossibleTargets(int n, int m, int * cards, int * targets) {
    vector<int> possibleTargets;    // 만들 수 있는 당첨번호들

    sort(cards, cards + n); // cards 배열 정렬

    for(int i = 0; i < m; ++i) {
        int k = targets[i]; // 타겟으로 삼을 당첨번호
        bool possible = false;  // 가능한지를 저장할 변수

        for(int j = 0; j < n; ++j) {
            int x = cards[j];   // 첫 번째 카드번호를 cards배열에서 고름
            for(int p = 0; p <= j; p += 1) {
                int y = cards[p];   // 두 번째 카드번호를 cards배열에서 고름
                int z = k - ( x + y);   // (x + y + z) = k가 되는 z값

                // 바이너리 서치를 이용하여 z가 cards 배열에 있는지 검사
                // z가 cards에 있다면 당첨번호를 만들 수 있음
                if(binary_search(cards, cards + n, z) == true) {
                    possible = true;
                    break;
                }
            }
            // 당첨번호 k를 만들 수 있다고 결정되었으면 break로 탈출
            if(possible) {
                break;
            }
        }
        // 뽑은 세 개의 번호로 k를 만들 수 있다면 벡터에 추가
        if(possible) {
            possibleTargets.push_back(k);
        }
    }

    sort(possibleTargets.begin(), possibleTargets.end());   // 오름차순으로 정렬
    return possibleTargets; // 벡터를 반환
}

int main() {
    int n;  // 사용할 카드의 수
    int m;  // 당첨 번호의 수
    scanf("%d %d", &n, &m);

    int* cards = new int[n];    // n개의 카드번호를 원소로 가지는 배열 선언
    int* targets = new int[m];  // m개의 당첨번호를 원소로 가지는 배열 선언

    // 사용할 카드들을 입력받음
    for (int i = 0; i < n; i++) {
        scanf("%d", &cards[i]);
    }

    // 당첨 번호들을 입력받음
    for (int i = 0; i < m; i++) {
        scanf("%d", &targets[i]);
    }

    vector<int> answers = getPossibleTargets(n, m, cards, targets);
    
    // answers가 비어있다면 "NO" 출력
    if (answers.size() == 0)
    {
        printf("NO");
    }
    else{
        // answers의 원소를 공백으로 구분하여 출력
        for (int i = 0; i < answers.size(); i++)
        {
            if (i > 0)
            {
                printf(" ");
            }
            printf("%d", answers[i]);
        }
    }

    // 메모리 해제
    delete[] cards;
    delete[] targets;

    return 0;
}