#include <cstdio>

const int MAX_SEAT_NUMBER = 1000; // 최대 좌석 수
const int MAX_COLOR_NUMBER = 100; // 최대 색상 수

// 좌석들을 한 번 색칠하는 이벤트에 대한 정보
class Painting {
public:
    int left; // 가장 왼쪽 좌석 번호
    int right; // 가장 오른쪽 좌석 번호
    int color; // 색상

    Painting() {}

    Painting(int left, int right, int color) {
        this->left = left;
        this->right = right;
        this->color = color;
    }
};

/**
 * data[0] ~ data[n-1]까지의 히스토그램을 table 배열에 저장하는 함수
 * data     검사할 배열
 * n        data배열의 원소 수
 * table    숫자가 나온 횟수를 저장할 배열(히스토그램)
 */
void fillFrequencyTable(int data[], int n, int table[]) {
    // 배열을 0으로 초기화
    for(int i =0; i < MAX_COLOR_NUMBER; i++) {
        table[i] = 0;
    }

    // data[0] ~ data[n-1]에서 색상의 빈도를 table 배열에 저장
    for(int i = 0; i < n; i++) {
        int color = data[i];
        table[color] += 1;
    }
}

/**
 * 가장 많이, 가장 적은 좌석이 칠해진 색의 번호를 출력하는 함수
 * n    좌석의 수
 * m    색칠을 할 방법의 수
 * paintings    색칠한 이벤트 정보
 */
void solve(int n, int m, const Painting *paintings) {
    int *seats = new int[n]; // n개의 좌석을 나타내는 배열 선언
    for (int i = 0; i < n; i++) {
        seats[i] = 0; // 처음 좌석은 전부 0번 색으로 칠해져 있다.
    }

    // 색칠 정보들이 주어진 순서대로 각 좌석을 색칠(색상 대입)한다.
    for(int i = 0; i < m; i++) {
        // 모든 색칠 정보 p
        const Painting &p = paintings[i];

        // 각 페인팅 정보마다 좌석의 색을 업데이트
        // p에서 얻은 왼쪽 끝부터 오른쪽 끝까지 색칠
        for(int j = p.left; j <= p.right; j++) {
            seats[j] = p.color;
        }
    }

    int *table = new int[MAX_COLOR_NUMBER]; // 색의 최대 크기만큼 빈도수 배열 선언
    fillFrequencyTable(seats, n, table); // 색의 빈도수를 얻음

    int minColor = seats[0]; // 가장 적게 등장한 색상
    int maxColor = seats[0]; // 가장 많이 등장한 색상

    for(int color = 0; color < MAX_COLOR_NUMBER; color += 1) {
        if(table[color] == 0 ) {
            // 한번도 등장하지 않은 색깔은 건너뜀
            continue;
        }

        // 한 번 이상 등장한 모든 색깔 color에 대하여
        if(table[minColor] > table[color]) {
            // 가장 적게 등장한 색이 아직 없거나 color가 더 적게 등장한 경우
            minColor = color;
        }
        if (table[maxColor] < table[color]) {
            // 가장 많이 등장한 색이 아직 없거나, color가 더 많이 등장한 경우
            maxColor = color;
        }
    }

    printf("%d\n", maxColor); // 가장 많은 좌석이 칠해진 색의 번호 출력
    printf("%d\n", minColor); // 가장 적은 좌석이 칠해진 색의 번호 출력

    delete[] table; // 메모리 해제
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m); // 좌석의 수 n, 색칠할 방법의 수 m 입력

    // paintings[i] := i번째에 일어난 색칠 이벤트의 정보
    Painting *paintings = new Painting[n];

    for(int i = 0; i < m; i++) {
        scanf("%d", &paintings[i].left); // 색칠할 가장 왼쪽 좌석 번호
        scanf("%d", &paintings[i].right); // 색칠할 가장 오른쪽 좌석 번호
        scanf("%d", &paintings[i].color); // 좌석에 칠할 색깔의 번호

        // 좌석의 번호는 1번부터 시작하므로, 0 ~ (n-1)범위로 맞추기 위하여 1씩 빼준다
        paintings[i].left -= 1;
        paintings[i].right -= 1;
    }

    // 문제의 정답을 구한다
    solve(n, m, paintings);

    return 0;
}