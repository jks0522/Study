#include <cstdio>
#include <time.h>
#include <deque>

using namespace std;

// 톱니바퀴를 가장 편하게 구현하기 위해 deque 사용
// deque은 앞과 뒤에 원소를 쉽게 추가/제거 할 수 있기때문에 
// 톱니바퀴의 회전에 따른 순서변화를 저장하기 용이함
// 이를 통해 항상 인덱스 0에는 톱니바퀴의 12시 방향이 오게 함
// 톱니바퀴 4개를 전역변수로 선언
deque<int> gear1;
deque<int> gear2;
deque<int> gear3;
deque<int> gear4;

/*
* 톱니바퀴 1을 회전시키는 함수
* direction 회전시킬 방향
*/
void rotateGear1(int direction) {
    if(direction == 1) {
        /*
        * 회전방향이 시계방향일 경우
        * 각 톱니바퀴의 맞닿은 부분을 검사하여 다른극이 몇번째 톱니바퀴까지 연결되어 있는지 검사
        * 같이 돌아가야할 톱니바퀴들을 알맞은 방향으로 회전시킴
        * 예) 1번: 시계방향일 경우, 2번: 반시계, 3번: 시계, 4번: 반시계
        * 회전은 deque의 push_back, push_front, front, back 메소드를 통해서 구현
        * 이를 통해 0번 인덱스에는 항상 회전 후 12시 톱니의 값이 오게됨
        */
        if(gear1[2] != gear2[6]) {
            if(gear2[2] != gear3[6]) {
                if(gear3[2] != gear4[6]) {
                    // 톱니바퀴4의 front값을 읽어 맨 끝에 추가
                    // 톱니바퀴4의 현재 front값을 제거
                    // 이를 통해 반시계방향 회전를 구현
                    gear4.push_back(gear4.front());
                    gear4.pop_front();
                }
                // 톱니바퀴3의 back값을 읽어 맨 앞에 추가
                // 톱니바퀴3의 현재 back값을 제거
                // 이를 통해 시계방향 회전을 구현
                gear3.push_front(gear3.back());
                gear3.pop_back();
            }
            gear2.push_back(gear2.front());
            gear2.pop_front();
        }
        gear1.push_front(gear1.back());
        gear1.pop_back();
    } else {    // 회전방향이 반시계 방향일 경우
        if(gear1[2] != gear2[6]) {
            if(gear2[2] != gear3[6]) {
                if(gear3[2] != gear4[6]) {
                    gear4.push_front(gear4.back());
                    gear4.pop_back();
                }
                gear3.push_back(gear3.front());
                gear3.pop_front();
            }
            gear2.push_front(gear2.back());
            gear2.pop_back();
        }
        gear1.push_back(gear1.front());
        gear1.pop_front();
    }
}

/*
* 톱니바퀴 2를 회전시키는 함수
* direction 회전시킬 방향
* 
* rotateGear1과 유사하므로 설명 생략
*/
void rotateGear2(int direction) {
    if(direction == 1) {
        // gear2 보다 왼쪽에 있는 기어(gear1) 조사
        if(gear1[2] != gear2[6]) {
            gear1.push_back(gear1.front());
            gear1.pop_front();
        }
        // gear2 보다 오른쪽에 있는 기어(gear3, gear4) 조사
        if(gear2[2] != gear3[6]) {
            if(gear3[2] != gear4[6]) {
                gear4.push_front(gear4.back());
                gear4.pop_back();
            }
            gear3.push_back(gear3.front());
            gear3.pop_front();
        }
        gear2.push_front(gear2.back());
        gear2.pop_back();
    } else {
        if(gear1[2] != gear2[6]) {
            gear1.push_front(gear1.back());
            gear1.pop_back();
        }
        if(gear2[2] != gear3[6]) {
            if(gear3[2] != gear4[6]) {
                gear4.push_back(gear4.front());
                gear4.pop_front();
            }
            gear3.push_front(gear3.back());
            gear3.pop_back();
        }
        gear2.push_back(gear2.front());
        gear2.pop_front();
    }
}

/*
* 톱니바퀴 3을 회전시키는 함수
* direction 회전시킬 방향
*
* rotateGear1과 유사하므로 설명 생략
*/
void rotateGear3(int direction) {
    if(direction == 1) {
        if(gear3[2] != gear4[6]) {
            gear4.push_back(gear4.front());
            gear4.pop_front();
        }
        if(gear2[2] != gear3[6]) {
            if(gear1[2] != gear2[6]) {
                gear1.push_front(gear1.back());
                gear1.pop_back();
            }
            gear2.push_back(gear2.front());
            gear2.pop_front();
        }
        gear3.push_front(gear3.back());
        gear3.pop_back();
    } else {
        if(gear3[2] != gear4[6]) {
            gear4.push_front(gear4.back());
            gear4.pop_back();
        }
        if(gear2[2] != gear3[6]) {
            if(gear1[2] != gear2[6]) {
                gear1.push_back(gear1.front());
                gear1.pop_front();
            }
            gear2.push_front(gear2.back());
            gear2.pop_back();
        }
        gear3.push_back(gear3.front());
        gear3.pop_front();
    }
}

/*
* 톱니바퀴 4를 회전시키는 함수
* direction 회전시킬 방향
*
* rotateGear1과 유사하므로 설명 생략
*/
void rotateGear4(int direction) {
    if(direction == 1) {
        if(gear3[2] != gear4[6]) {
            if(gear2[2] != gear3[6]) {
                if(gear1[2] != gear2[6]) {
                    gear1.push_back(gear1.front());
                    gear1.pop_front();
                }
                gear2.push_front(gear2.back());
                gear2.pop_back();
            }
            gear3.push_back(gear3.front());
            gear3.pop_front();
        }
        gear4.push_front(gear4.back());
        gear4.pop_back();
    } else {
        if(gear3[2] != gear4[6]) {
            if(gear2[2] != gear3[6]) {
                if(gear1[2] != gear2[6]) {
                    gear1.push_front(gear1.back());
                    gear1.pop_back();
                }
                gear2.push_back(gear2.front());
                gear2.pop_front();
            }
            gear3.push_front(gear3.back());
            gear3.pop_back();
        }
        gear4.push_back(gear4.front());
        gear4.pop_front();
    }
}

int main() {
    int t;  // 회전 횟수
    int result = 0; // 최종 결과값
    int *gear;  // 회전시킨 톱니바퀴의 번호를 저장할 포인터
    int *direction; // 회전시킨 톱니바퀴의 회전방향을 저장할 포인터

    // 톱니바퀴 1부터 4까지의 상태를 입력받아 저장하는 반복문들
    for(int j = 0; j < 8; j++) {
        int n = 0;
        scanf("%1d", &n);   // %1d를 이용해 숫자하나씩 입력받음
        gear1.push_back(n); // 톱니바퀴1 deque뒤에 n값을 추가
    }
    for(int j = 0; j < 8; j++) {
        int n = 0;
        scanf("%1d", &n);
        gear2.push_back(n);
    }
    for(int j = 0; j < 8; j++) {
        int n = 0;
        scanf("%1d", &n);
        gear3.push_back(n);
    }
    for(int j = 0; j < 8; j++) {
        int n = 0;
        scanf("%1d", &n);
        gear4.push_back(n);
    }

    scanf("%d", &t);    // 회전 횟수 입력

    gear = new int[t];  // 회전시킨 톱니바퀴 번호를 저장할 t크기의 배열을 할당
    direction = new int[t]; // 톱니바퀴 회전방향을 저장할 t크기의 배열을 할당

    for(int i = 0 ; i < t; i++) {
        scanf("%d %d", &gear[i], &direction[i]);    // t개의 회전방법만큼 각각 값을 입력받음
    }

    clock_t start = clock();    // 시간 측정 시작

    for(int i =0 ; i < t; i++) {
        // i번째 회전방법의 톱니바퀴 회전 번호와 회전방향을 통해 알맞은 rotateGear 함수 호출
        if(gear[i] == 1)
            rotateGear1(direction[i]);
        else if(gear[i] == 2)
            rotateGear2(direction[i]);
        else if(gear[i] == 3)
            rotateGear3(direction[i]);
        else
            rotateGear4(direction[i]);
    }

    // 각 deque의 0번 인덱스는 12시 방향의 톱니를 의미함
    // N극 일경우 값이 0이므로 곱해도 0이 된다
    // 따라서 S극인 경우에만 0이 아닌 값이 더해짐
    result = gear1[0] * 1 + gear2[0] * 2 + gear3[0] * 4 + gear4[0] * 8;
    printf("%d\n", result); // 결과값 출력

    clock_t end = clock();  // 시간 측정 종료
	printf("실행시간: %lf초", (double)(end - start) / CLOCKS_PER_SEC);  // 실행시간 초단위로 출력

    delete[] gear;  // 메모리 해제
    delete[] direction; // 메모리 해제

    return 0;
}